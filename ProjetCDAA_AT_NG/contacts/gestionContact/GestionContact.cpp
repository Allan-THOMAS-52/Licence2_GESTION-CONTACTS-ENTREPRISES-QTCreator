/**
 * @file GestionPersonne.cpp
 */

#include "GestionContact.hpp"


//---------------------------------------CONSTRUCTEUR/DESTRUCTEUR----------------------------------

GestionContact::GestionContact(std::vector<std::shared_ptr<Contact>> const& pCont,
        std::vector<std::shared_ptr<struct sDate>> const& pDates):
    m_contacts(pCont),m_datesModifs(pDates){

}

GestionContact::GestionContact(){}

GestionContact::~GestionContact(){}

//----------------------------------------ACESSEURS/MUTATEURS---------------------------------------

std::vector<std::shared_ptr<Contact>> GestionContact::getContacts() const{return m_contacts;}

void GestionContact::setContacts(std::vector<std::shared_ptr<Contact>> const& pCont){
    //on vide le conteneur
    m_contacts.clear();
    //on met les Contacts de pCont dans m_contacts
    m_contacts = pCont;
}

std::vector<std::shared_ptr<struct sDate>> GestionContact::getDatesModifs() const{return m_datesModifs;}

void GestionContact::setDatesModifs( std::vector<std::shared_ptr<struct sDate>> const& pDates){
    //on vide le conteneur
    m_datesModifs.clear();
    //on met les dates de pCont dans m_datesModifs
    m_datesModifs = pDates;
}

std::vector<std::shared_ptr<struct sDate>> GestionContact::getDatesSupp() const{return m_datesSuppression;}

void GestionContact::setDatesSupp( std::vector<std::shared_ptr<struct sDate>> const& pDates){
    //on vide le conteneur
    m_datesSuppression.clear();
    //on met les dates de pCont dans m_datesModifs
    m_datesSuppression = pDates;
}


//----------------------------------------METHODES-------------------------------------------------

void GestionContact::supprimerPremierParNom(std::string const& pName){
    //iterateur pour parcourir m_personnes
    for(auto it = m_contacts.begin(); it !=m_contacts.end();++it){
        if ( (*it)->getNom() == pName) {
            // on supprime le contact
            m_contacts.erase(it);
            // on ajoute une date de modification dans m_datesModifs
            m_datesSuppression.emplace_back(std::make_shared<struct sDate>(1, 1, 2015,"Suppression premier nom fiche contact"));
            //on sort de la fonction si on a efface le contact
            return;
        }
    }
}

void GestionContact::supprimerTousParNom(std::string const& pName){
    /*
     * on efface toutes les occurences du contact avec l'idiome erase-remove.
     * pas la meme methode que removeFirstByName() car du fait que m_contacts
     * contient des pointeurs, l'utilisation de erase() peut poser probleme
     * avec l'iterateur qui devient invalide.
     */
    m_contacts.erase(
        std::remove_if(m_contacts.begin(), m_contacts.end(),
            [pName](std::shared_ptr<Contact> const& p) {
                return p->getNom() == pName;
            }
        ),
        m_contacts.end()
    );

    // on ajoute une date de modification dans m_datesModifs
    m_datesSuppression.emplace_back(std::make_shared<struct sDate>(1, 1,2018,"Suppression des memes noms fiche contact"));
}


void GestionContact::supprimerParComparaison(Contact const& pCont,struct sDate const& pDate){
    //iterateur pour parcourir m_contacts
    for(auto it = m_contacts.begin(); it !=m_contacts.end();++it){
        if ( *(*it) == pCont) { // operateur == de Contact
            // on supprime le contact
            m_contacts.erase(it);
            // on ajoute une date de modification dans m_datesModifs
            m_datesSuppression.emplace_back(std::make_shared<struct sDate>(pDate));
            //on sort de la fonction si on a efface le contact
            return;
        }
    }
}

void GestionContact::creerFiche(std::shared_ptr<Contact> const& pCont,struct sDate& pDate){
    /*
     * on utilise emplace_back() au lieu de push_back() car emplace_back()
     * ne fait pas de copie temporaire => plus efficace pour les types definits
     * comme Contact.
     */

    pDate.intitule = "Creation du contact: " + pCont->getNom() + " " + pCont->getPrenom() + " de chez " + pCont->getEntreprise();

    m_contacts.emplace_back(pCont);
    // on ajoute une date de modification dans m_datesModifs
    m_datesModifs.emplace_back(std::make_shared<struct sDate>(pDate));
}

void GestionContact::creerFiche(std::string const& pNom,std::string const& pPrenom,
                std::string const& pEntreprise,std::string const& pMail,
                std::string const& pTelephone,std::string const& pPhoto,struct sDate& pDate){

    pDate.intitule = "Creation du contact: " + pNom + " " + pPrenom + " de chez " + pEntreprise;

    std::shared_ptr<Contact> pCont = std::make_shared<Contact>(pNom,pPrenom,pEntreprise,
                    pMail,pTelephone,pPhoto,pDate);

    m_contacts.emplace_back(pCont);

    // on ajoute une date de modification dans m_datesModifs
    m_datesModifs.emplace_back(std::make_shared<struct sDate>(pDate));

}

void GestionContact::afficheContacts(std::ostream& flux) const{
    //parcours les contact de m_contact
    for(std::shared_ptr<Contact> const& p : m_contacts){
        flux << *p << std::endl;
    }
}

struct sDate GestionContact::getDateDerniereSupr() const {

    std::shared_ptr<struct sDate> derniereDate = std::make_shared<struct sDate>(0,0,0,"");

    if(m_datesSuppression.size() == 1){

        return *m_datesSuppression.at(0);

    }else{

        for (auto const& datePtr : m_datesSuppression){

            // si on est pas a la fin du vector et que la date pointee est plus recente que derniereDate
            if (!derniereDate || *datePtr > *derniereDate){
                derniereDate = datePtr;
            }

        }

        // on renvoie la date pointee par derniereDate
        if(derniereDate){
            return *derniereDate;
        }else{
            // on retourne une date par defaut si rien n'est trouve
            return sDate(0, 0, 0, "");
        }
    }

}

void GestionContact::ajoutDateModif(struct sDate const& pDate){
    m_datesModifs.emplace_back(std::make_shared<struct sDate>(pDate));
}

//-------TRI DES CONTACTS---------

/*
 * on utilise ici des fonctions de la STL telles que std::copy_if car elles sont
 * optimisees et polivalentes ( plus opti de d'utiliser des for avec des iterateurs
 * a travers les vectors )
 */

void GestionContact::triParAlphaB() {
    // si m_contacts n'est pas vide
    if(!m_contacts.empty()){
        // fonction custom de comparaison de noms de contacts
        auto compareByName = [](std::shared_ptr<Contact> const& contact1, std::shared_ptr<Contact> const& contact2) {
            return contact1->getNom() < contact2->getNom();
        };

        // tri m_contacts en utilisant la fonction custom de comparaison
        std::sort(m_contacts.begin(), m_contacts.end(), compareByName);

    }
}

void GestionContact::triParDate(bool const& pCroissant) {
    // si m_contacts n'est pas vide
    if(!m_contacts.empty()){
        // fonction lambda de comparaison de dates de creation des contacts
        auto compareByDate = [pCroissant]( std::shared_ptr<Contact> const& contact1, std::shared_ptr<Contact> const& contact2) {
            if (pCroissant) {
                return contact1->getDateCreation() < contact2->getDateCreation() ; // ordre croissant
            } else {
                return contact1->getDateCreation()  > contact2->getDateCreation() ; // ordre decroissant
            }
        };

        // tri m_contacts en utilisant la fonction lambda de comparaison
        std::sort(m_contacts.begin(), m_contacts.end(), compareByDate);

    }
}


//-------CHERCHER UN CONTACT---------

/*
 * meme chose que pour trier les contacts, on utilise la STL
 */

std::vector<std::shared_ptr<Contact>> GestionContact::getContactsParNom(std::string const& pNom) const{

    std::vector<std::shared_ptr<Contact>> results;

    // si m_contacts n'est pas vide
    if(!m_contacts.empty()){

        std::copy_if(m_contacts.begin(), m_contacts.end(), std::back_inserter(results),
                 [pNom](std::shared_ptr<Contact> const& contact) {
                     return contact->getNom() == pNom;
                 }
        );

    }
    return results;
}

std::vector<std::shared_ptr<Contact>> GestionContact::getContactsParEntreprise(std::string const& pEntr) const{

    std::vector<std::shared_ptr<Contact>> results;

    // si m_contacts n'est pas vide
    if(!m_contacts.empty()){

        std::copy_if(m_contacts.begin(), m_contacts.end(), std::back_inserter(results),
                 [pEntr](std::shared_ptr<Contact> const& contact) {
                     return contact->getEntreprise() == pEntr;
                 }
        );

    }
    return results;
}

std::vector<std::shared_ptr<Contact>> GestionContact::getContactsParIntervDate(struct sDate const& pDate1,
            struct sDate const& pDate2) const{

    std::vector<std::shared_ptr<Contact>> results;

    // si m_contacts n'est pas vide
    if(!m_contacts.empty()){

        std::copy_if(m_contacts.begin(), m_contacts.end(), std::back_inserter(results),
                 [pDate1,pDate2](std::shared_ptr<Contact> const& contact) {
                     return contact->getDateCreation() >= pDate1 && contact->getDateCreation() <= pDate2;
                 }
        );

    }
    return results;
}

std::vector<std::shared_ptr<Contact>> GestionContact::getContactsParDateCreation(struct sDate const& pDate) const{

    std::vector<std::shared_ptr<Contact>> results;

    // si m_contacts n'est pas vide
    if(!m_contacts.empty()){

        std::copy_if(m_contacts.begin(), m_contacts.end(), std::back_inserter(results),
                [pDate](std::shared_ptr<Contact> const& contact) {
                    return contact->getDateCreation() == pDate;
                }
        );

    }
    return results;
}


//----------------------------------------OPERATEURS-----------------------------------------------
/*
GestionContact GestionContact::operator+(std::shared_ptr<Contact> const& pCont){
    creerFiche(pCont);
    //on retourne l'instance courante
    return *this;
}
*/
/*
GestionContact GestionContact::operator-(std::shared_ptr<Contact> const& pCont){
    supprimerParComparaison(*pCont);
    //on retourne l'instance courante
    return *this;
}
*/
void GestionContact::operator=(GestionContact const& pGest){
    //on vide les conteneurs
    m_contacts.clear();
    m_datesModifs.clear();

    //on met les Contacts de pGest dans m_contacts
    m_contacts = pGest.m_contacts;
    //on met les dates de modification de pGest dans m_datesModifs
    m_datesModifs = pGest.m_datesModifs;
}

std::ostream& operator<<(std::ostream& flux,GestionContact const& pGes){
    pGes.afficheContacts(flux);
    return flux;
}

