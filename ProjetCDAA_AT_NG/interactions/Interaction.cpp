/**
 * @file Interaction.cpp
 */

#include "Interaction.hpp"

//---------------------------------------CONSTRUCTEUR/DESTRUCTEUR----------------------------------

Interaction::Interaction(struct sDate const& pDate,std::string const& pCont):
		m_dateC(pDate),m_contenu(pCont){

}

Interaction::Interaction(short int const& pJour,short int const& pMois,short int const& pAnnee,
		std::string const& pIntitule,std::string const& pCont){

	struct sDate dateInter(pJour,pMois,pAnnee,pIntitule);
	m_dateC = dateInter;
	m_contenu = pCont;
}

Interaction::Interaction() {
	struct sDate nowD;
	m_dateC = nowD;
	m_contenu = "";
}

Interaction::~Interaction() {

}

//----------------------------------------ACESSEURS/MUTATEURS---------------------------------------

struct sDate Interaction::getDate() const{return m_dateC;}
std::string Interaction::getContenu() const{return m_contenu;}

void Interaction::setDate(struct sDate const& pDate){m_dateC=pDate;}
void Interaction::setContenu(std::string const& pCon){m_contenu=pCon;}

//----------------------------------------METHODES-------------------------------------------------

void Interaction::afficheInteraction(std::ostream & flux) const{
	flux << m_contenu << "," << m_dateC.day << "/" << m_dateC.month << "/" << m_dateC.year << std::endl;
}

//----------------------------------------OPERATEURS-----------------------------------------------

std::ostream & operator<<(std::ostream & flux,Interaction const& pInt){
	pInt.afficheInteraction(flux);
	return flux;
}

bool Interaction::operator==(Interaction const& pInter) const{
		return 	m_dateC == pInter.m_dateC && m_contenu == pInter.m_contenu;
}

bool Interaction::operator!=(Interaction const& pInter) const{
	return !(*this == pInter);
}

