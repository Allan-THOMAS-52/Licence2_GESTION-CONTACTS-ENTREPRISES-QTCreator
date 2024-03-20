/**
 * @file InteractionFinale.hpp
 */
#ifndef INTERACTIONS_INTERTACHEASSO_INTERTACHEASSO_HPP_
#define INTERACTIONS_INTERTACHEASSO_INTERTACHEASSO_HPP_

#include <iostream>
#include <memory>

#include "../../tache/Tache.hpp"
#include "../Interaction.hpp"

class InterTacheAsso{

	public:
		/**
		 * @brief constructeur de InteractionFinale
		 */
		InterTacheAsso(std::shared_ptr<Interaction> const& pInt,std::shared_ptr<Tache> const& pTache);

		/**
		 * @brief accesseur de m_todo
		 */
		std::shared_ptr<Tache> getTache() const;
		/**
		 * @brief accesseur de m_interaction
		 */
		std::shared_ptr<Interaction> getInteraction() const;
		/**
		 * @brief mutateur de m_todo
		 */
		void setTache(std::shared_ptr<Tache> const& pTache);
		/**
		 * @brief mutateur de m_interaction
		 */
		void setInteraction(std::shared_ptr<Interaction> const& pInter);


		 /**
		 * @brief Permet d'utiliser l'operateur << pour afficher les associations
		 */
		void afficheAsso(std::ostream & flux) const;


		/**
		 * @brief surcharge de l'operateur d'egalite
		 */
		bool operator==(InterTacheAsso const& pAsso) const;
		/**
		 * @brief surcharge de l'operateur de difference
		 */
		bool operator!=(InterTacheAsso const& pAsso) const;
		/**
		 * @brief Surcharge de l'operateur << pour afficher les liens
		 */
		friend std::ostream & operator<<(std::ostream & flux,InterTacheAsso const& pAsso);

        /**
		 * @brief Destructeur de la classe InterTacheAsso
		 */
		~InterTacheAsso();

	private:
		std::shared_ptr<Tache> m_todo;
		std::shared_ptr<Interaction> m_interaction;
};

#endif /* INTERACTIONS_INTERTACHEASSO_INTERTACHEASSO_HPP_ */
