/**
 * @file Tache.cpp
 */

#include "../tache/Tache.hpp"

//---------------------------------------CONSTRUCTEUR/DESTRUCTEUR----------------------------------

Tache::Tache(struct sDate const& pDate,std::string const& pContenu):
	m_dateC(pDate),m_contenu(pContenu){
}

Tache::Tache(short int const& pJour,short int const& pMois,short int const& pAnnee,
		std::string const& pIntitule,std::string const& pCont){

	struct sDate dateInter(pJour,pMois,pAnnee,pIntitule);
	m_dateC = dateInter;
	m_contenu = pCont;

}

Tache::Tache(){
	struct sDate now(01,01,2023,"test");
	m_dateC = now;
	m_contenu = "";
}

Tache::~Tache(){

}

//----------------------------------------ACESSEURS/MUTATEURS---------------------------------------

struct sDate Tache::getDateC() const{return m_dateC;}

void Tache::setDate(struct sDate const& pDate){m_dateC = pDate;}

std::string Tache::getContenu() const{return m_contenu;}

void Tache::setContenu(std::string const& pCont){m_contenu = pCont;}

//----------------------------------------METHODES-------------------------------------------------




//----------------------------------------OPERATEURS-----------------------------------------------

bool Tache::operator==(Tache const& pTache) const{
	return m_dateC == pTache.m_dateC && m_contenu == pTache.m_contenu;
}

bool Tache::operator!=(Tache const& pTache) const{
	return !(*this == pTache);
}

