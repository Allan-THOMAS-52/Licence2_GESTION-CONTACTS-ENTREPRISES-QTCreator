/**
 * @file Contact.hpp
 */
#ifndef CONTACTS_CONTACT_HPP_
#define CONTACTS_CONTACT_HPP_

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <memory>

#include "../interactions/InterTacheAsso/InterTacheAsso.hpp"
#include "../utils/sDate.hpp"

class Contact{
  public:

	/**
	 * @brief Constructeur de la classe Contact
	 */
	 Contact(std::string const& pNom,std::string const& pPrenom,
				std::string const& pEntreprise,std::string const& pMail,
                std::string const& pTelephone,std::string const& pPhoto,struct sDate const& pDate);


	 /**
	 * @brief accesseur de m_nom
	 */
	std::string getNom() const;
	/**
	 * @brief accesseur de m_prenom
	 */
	std::string getPrenom() const;
	/**
	 * @brief mutateur de m_nom
	 */
	void setNom(std::string const& pNom);
	/**
	 * @brief mutateur de m_prenom
	 */
	void setPrenom(std::string const& pPrenom);
	 /**
	 * @brief accesseur de m_dateCreation
	 */
	struct sDate getDateCreation() const;
	/**
	 * @brief mutateur de m_dateCreation
	 */
	void setDateCreation(struct sDate const& pDate);
	/**
	 * @brief accesseur de m_entreprise
	 */
	std::string getEntreprise() const;
	/**
	 * @brief mutateur de m_entreprise
	 */
	void setEntreprise(std::string const& pEnt);
	/**
	 * @brief accesseur de m_interactions
	 */
	std::vector<std::shared_ptr<InterTacheAsso>> getInteractions() const;
	/**
	 * @brief mutateur de m_interactions
	 */
	void setInteractions(std::vector<std::shared_ptr<InterTacheAsso>> const& pInter);
	/**
	 * @brief accesseur de m_mail
	 */
	std::string getMail() const;
	/**
	 * @brief mutateur de m_mail
	 */
	void setMail(std::string const& pMail);
	/**
	 * @brief accesseur de m_telephone
	 */
	std::string getTelephone() const;
	/**
	 * @brief mutateur de m_telephone
	 */
	void setTelephone(std::string const& pTel);
	/**
	 * @ accesseur de m_photo
	 */
	std::string getPhoto() const;
	/**
	 * @ accesseur de m_photo
	 */
	void setPhoto(std::string const& pPhoto);


	/**
	 * @brief Permet d'utiliser l'opérateur << pour afficher les informations d'un contact
	 */
	void afficheContact(std::ostream& flux) const;
	/**
	 * @brief Affiche l'ensemble des liens Interaction-Tache du contact
	 */
	void afficheInteractions() const;
	/**
	 * @brief Ajoute une interaction dans la liste
	 */
	void ajouteInteraction(std::shared_ptr<InterTacheAsso> const& pInt);
	/**
	 * @brief Trie les interactions par date
	 */
	void triDateLiens();



	/**
	 * @brief Surcharge de l'opérateur << pour afficher les informations d'un contact
	 */
	friend std::ostream& operator<<(std::ostream& flux, Contact const& pContact);
	/**
	 * @brief surcharge de l'operateur d'egalite
	 */
	bool operator==(Contact const& pContac) const;
	/**
	 * @brief surcharge de l'operateur de difference
	 */
	bool operator!=(Contact const& pContact) const;


    /**
     * @brief Destructeur de la classe Contact
     */
    ~Contact();


  private:

    std::string m_nom;
	std::string m_prenom;
    std::string m_entreprise;
	std::string m_mail;
	std::string m_telephone;
	std::string m_photo;

	struct sDate m_dateCreation;

	std::vector<std::shared_ptr<InterTacheAsso>> m_interactions;


};
#endif
