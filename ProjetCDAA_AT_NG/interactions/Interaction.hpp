/**
 * @file Interaction.hpp
 */
#ifndef INTERACTIONS_INTERACTION_HPP_
#define INTERACTIONS_INTERACTION_HPP_

#include <memory>
#include <ctime>
#include <string>
#include <iostream>

#include "../utils/sDate.hpp"

class Interaction{

	public:

		/**
		 * @brief 1er Constructeur de la class Interaction
		 */
		Interaction(struct sDate const& pDate,std::string const& pCont);
		/**
		 * @brief 2eme Constructeur de la class Interaction
		 */
		Interaction(short int const& pJour,short int const& pMois,
				short int const& pAnnee,std::string const& pIntitule,std::string const& pCont);
		/**
		 * @brief Constructeur par defaut de la class Interaction
		 */
		Interaction();

		/**
		 * @brief accesseur de m_dateC
		 */
		struct sDate getDate() const;
		/**
		 * @brief accesseur de m_contenu
		 */
		std::string getContenu() const;

		/**
		 * @brief mutateur de m_dateC
		 */
		void setDate(struct sDate const& pDate);
		/**
		 *@brief mutateur de m_contenu
		 */
		void setContenu(std::string const& pCon);


		/**
		 * @brief Permet d'utiliser l'opérateur << pour afficher les informations d'une Iteraction
		 */
		void afficheInteraction(std::ostream& flux)	 const;

		/**
		 * @brief Surcharge de l'opérateur << pour afficher les informations d'une Iteraction
		 */
		friend std::ostream& operator<<(std::ostream& flux,Interaction const& pInt);
		/**
		 * @brief Surcharge de l'opérateur d'egalite
		 */
		bool operator==(Interaction const& pInter) const;
		/**
		 * @brief Surcharge de l'opérateur de difference
		 */
		bool operator!=(Interaction const& pInter) const;


		/**
		 * @brief Destructeur de la classe Interaction
		 */
		~Interaction();

	private:

		struct sDate m_dateC;
		std::string m_contenu;

};



#endif
