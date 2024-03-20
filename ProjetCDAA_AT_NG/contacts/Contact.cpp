
#include "Contact.hpp"

//---------------------------------------CONSTRUCTEUR/DESTRUCTEUR----------------------------------

Contact::Contact(std::string const& pNom,std::string const& pPrenom,
                 std::string const& pEntreprise,std::string const& pMail,
                 std::string const& pTelephone,std::string const& pPhoto,struct sDate const& pDate):
		m_nom(pNom),m_prenom(pPrenom),m_entreprise(pEntreprise),
        m_mail(pMail),m_telephone(pTelephone),m_photo(pPhoto),m_dateCreation(pDate){
}

Contact::~Contact() {

}

//----------------------------------------ACESSEURS/MUTATEURS---------------------------------------

std::string Contact::getNom() const{return m_nom;}

std::string Contact::getPrenom() const{return m_prenom;}

void Contact::setNom(std::string const& pNom){m_nom=pNom;}

void Contact::setPrenom(std::string const& pPrenom){m_prenom=pPrenom;}

struct sDate Contact::getDateCreation() const{return m_dateCreation;}

void Contact::setDateCreation(struct sDate const& pDate){m_dateCreation = pDate;}

std::string Contact::getEntreprise() const{return m_entreprise;}

void Contact::setEntreprise(std::string const& pEnt){m_entreprise = pEnt;}

std::vector<std::shared_ptr<InterTacheAsso>> Contact::getInteractions() const{return m_interactions;}

void Contact::setInteractions(std::vector<std::shared_ptr<InterTacheAsso>> const& pInter){m_interactions = pInter;}

std::string Contact::getMail() const{return m_mail;}

void Contact::setMail(std::string const& pMail){m_mail = pMail;}

std::string Contact::getTelephone() const{return m_telephone;}

void Contact::setTelephone(std::string const& pTel){m_telephone = pTel;}

std::string Contact::getPhoto() const{return m_photo;}

void Contact::setPhoto(std::string const& pPhoto){m_photo = pPhoto;}

//----------------------------------------METHODES-------------------------------------------------

void Contact::afficheContact(std::ostream& flux) const{
	flux << m_nom << "," << m_prenom << "," << m_entreprise << "," << m_mail << "," << m_telephone
			 << "," << m_dateCreation.day << "/" << m_dateCreation.month << "/" << m_dateCreation.year << std::endl;
}

void Contact::afficheInteractions() const{
	for(auto it = m_interactions.begin(); it!=m_interactions.end();++it){
		(*it)->afficheAsso(std::cout);
	}
}

void Contact::ajouteInteraction(std::shared_ptr<InterTacheAsso> const& pInt){
	m_interactions.emplace_back(pInt);
}

void Contact::triDateLiens(){
	/*
	 *  Tri par date de m_interactions.
	 *  On utilise l'algorithme sort(), qui trie selon une fonction lambda notre vector m_interactions.
	 *  Dans la fonction lambda, on regarde si une date p1 et plus vieille qu'une date p2, puis sort() les tris
	 */
	std::sort(m_interactions.begin(), m_interactions.end(),
			[]( std::shared_ptr<InterTacheAsso> const& p1 , std::shared_ptr<InterTacheAsso> const& p2 ) {
	        return p1->getInteraction()->getDate() < p2->getInteraction()->getDate();
	 });
}

//----------------------------------------OPERATEURS-----------------------------------------------

std::ostream& operator<<(std::ostream& flux, Contact const& pContact){
	pContact.afficheContact(flux);
	return flux;
}

bool Contact::operator==(Contact const& pContact) const{
		return 	m_nom == pContact.m_nom && m_prenom == pContact.m_prenom &&
				m_entreprise == pContact.m_entreprise && m_mail == pContact.m_mail &&
				m_telephone == pContact.m_telephone &&	m_dateCreation == pContact.m_dateCreation;
}

bool Contact::operator!=(Contact const& pContact) const{
	return !(*this == pContact);
}


