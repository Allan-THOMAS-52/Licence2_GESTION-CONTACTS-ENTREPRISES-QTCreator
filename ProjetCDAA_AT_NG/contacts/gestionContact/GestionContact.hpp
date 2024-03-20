/**
 * @file GestionContact.hpp
 */
#ifndef CONTACTS_GESTIONCONTACT_GESTIONCONTACT_HPP_
#define CONTACTS_GESTIONCONTACT_GESTIONCONTACT_HPP_

#include "../Contact.hpp"

#include <algorithm>
#include <memory>
#include <vector>
#include <iostream>
#include <string>
#include <cctype>

class GestionContact{

  public:

    /**
     * @brief Constructeur de la classe GestionContact
     */
    GestionContact(std::vector<std::shared_ptr<Contact>> const& pCont,
            std::vector<std::shared_ptr<struct sDate>> const& pDates);
    /**
     * @brief Constructeur par defaut de la classe GestionContact
     */
    GestionContact();


    /**
     * @brief accesseur de m_personnes
     */
    std::vector<std::shared_ptr<Contact>> getContacts() const;
    /**
     * @brief mutateur de m_personnes
     */
    void setContacts(std::vector<std::shared_ptr<Contact>> const& pCont);
    /**
     * @brief accesseur de m_datesModifs
     */
    std::vector<std::shared_ptr<struct sDate>> getDatesModifs() const;
    /**
     * @brief mutateur de m_datesModifs
     */
    void setDatesModifs( std::vector<std::shared_ptr<struct sDate>> const& pDates);
    /**
     * @brief accesseur de m_datesSuppression
     */
    std::vector<std::shared_ptr<struct sDate>> getDatesSupp() const;
    /**
     * @brief mutateur de m_datesSuppression
     */
    void setDatesSupp( std::vector<std::shared_ptr<struct sDate>> const& pDates);


    /**
     * @brief supprime la premiere occurence d'un nom
     */
    void supprimerPremierParNom(std::string const& pName);

    /**
     * @brief supprime toutes les occurences d'un nom
     */
    void supprimerTousParNom(std::string const& pName);

    /**
     * @brief supprime une personne en particulier
     */
    void supprimerParComparaison(Contact const& pCont,struct sDate const& pDate);

    /**
     * @brief Ajoute une personne a la fin de m_personnes
     */
    void creerFiche(std::shared_ptr<Contact> const& pCont,struct sDate& pDate);

    /**
     * @brief Ajoute une personne a la fin de m_personnes
     */
    void creerFiche(std::string const& pNom,std::string const& pPrenom,
                    std::string const& pEntreprise,std::string const& pMail,
                    std::string const& pTelephone,std::string const& pPhoto,struct sDate& pDate);

    /**
     * @brief Permet d'utiliser l'operateur << pour afficher les personnes de la liste
     */
    void afficheContacts(std::ostream & flux) const;

    /**
     * @brief Renvoie la date de la derniere suppression d'une fiche contact
     */
    struct sDate getDateDerniereSupr() const;

    /**
     * @brief permet d'ajouter une date de modification
     */
    void ajoutDateModif(struct sDate const& pDate);

    //-------TRI DES CONTACTS---------

    /**
     * @brief tri des contacts par ordre alphabetique
     */
    void triParAlphaB();

    /**
     * @brief tri des contacts par date de creation
     */
    void triParDate(bool const& pCroissant);


    //-------CHERCHER UN CONTACT---------

    /**
     * @brief Renvoie les contacts correspondants au nom en parametre
     */
    std::vector<std::shared_ptr<Contact>> getContactsParNom(std::string const& pNom) const;
    /**
     * @brief Renvoie les contacts d'une entreprise passee en parametre
     */
    std::vector<std::shared_ptr<Contact>> getContactsParEntreprise(std::string const& pEntr) const;
    /**
     * @brief Renvoie les contacts correspondants au nom en parametre
     */
    std::vector<std::shared_ptr<Contact>> getContactsParIntervDate(struct sDate const& pDate1,
            struct sDate const& pDate2) const;
    /**
     * @brief Renvoie les contacts crees a la date en parametre
     */
    std::vector<std::shared_ptr<Contact>> getContactsParDateCreation(struct sDate const& pDate) const;


    //-----------------------------------


    /**
     * @brief surcharge de l'operateur + pour ajouter une Personne a la liste
     */
    GestionContact operator+(std::shared_ptr<Contact> const& pCont);
    /**
     * @brief surcharge de l'operateur - pour retirer une Personne a la liste
     */
    GestionContact operator-(std::shared_ptr<Contact> const& pCont);
    /**
     * @brief surchage de l'operateur = pour affecter : gp = gp'
     */
    void operator=(GestionContact const& pGest);
    /**
     * @brief Surcharge de l'operateur << pour afficher les personnes
     */
    friend std::ostream & operator<<(std::ostream & flux,GestionContact const& pGes);


    /**
     * @brief Destructeur de la classe GestionPersonnes
     */
    ~GestionContact();


  private:

    std::vector<std::shared_ptr<Contact>> m_contacts;
    std::vector<std::shared_ptr<struct sDate>> m_datesModifs;
    std::vector<std::shared_ptr<struct sDate>> m_datesSuppression;

};
#endif
