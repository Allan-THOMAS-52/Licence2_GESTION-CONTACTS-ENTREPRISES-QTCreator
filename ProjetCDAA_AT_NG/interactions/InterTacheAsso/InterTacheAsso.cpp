/**
 * @file InteractionFinale.cpp
 */

#include "../InterTacheAsso/InterTacheAsso.hpp"

//---------------------------------------CONSTRUCTEUR/DESTRUCTEUR----------------------------------

InterTacheAsso::InterTacheAsso(std::shared_ptr<Interaction> const& pInt,std::shared_ptr<Tache> const& pTache):
		m_todo(pTache),m_interaction(pInt){

}

InterTacheAsso::~InterTacheAsso(){

}

//----------------------------------------ACESSEURS/MUTATEURS---------------------------------------

std::shared_ptr<Tache> InterTacheAsso::getTache() const{return m_todo;}
std::shared_ptr<Interaction> InterTacheAsso::getInteraction() const{return m_interaction;}

void InterTacheAsso::setTache(std::shared_ptr<Tache> const& pTache){m_todo=pTache;}
void InterTacheAsso::setInteraction(std::shared_ptr<Interaction> const& pInter){m_interaction=pInter;}

//----------------------------------------METODES-------------------------------------------------

void InterTacheAsso::afficheAsso(std::ostream& flux) const{
	flux << m_todo->getContenu() << *m_interaction << std::endl;
}



//----------------------------------------OPERATEURS-----------------------------------------------

bool InterTacheAsso::operator==(InterTacheAsso const& pAsso) const{
	return *m_todo == *pAsso.m_todo && *m_interaction == *pAsso.m_interaction;
}

bool InterTacheAsso::operator!=(InterTacheAsso const& pAsso) const{
	return !(*this == pAsso);
}

std::ostream& operator<<(std::ostream& flux,InterTacheAsso const& pAsso){
	pAsso.afficheAsso(flux);
	return flux;
}
