/**
 * @file Erreur.hpp
 */
#ifndef UTILS_ERREUR_HPP_
#define UTILS_ERREUR_HPP_

#include <string>

class Erreur: public std::exception{

	public:

		/**
		 * @brief Constructeur de la classe Erreur
		 */
		Erreur(short int const& pENum,short int const& pENiv,std::string const& pEStr) throw():
			m_erreurNum(pENum),m_erreurNiveau(pENiv),m_erreurString(pEStr){}


		virtual short int getNum() const throw(){return m_erreurNum;}

		virtual short int getNiveau() const throw(){return m_erreurNiveau;}

		/**
		 * @brief description de l'erreur
		 */
		virtual const char* what() const throw(){return m_erreurString.c_str();}

		/**
		 * @brief Destructeur de Erreur
		 */
		virtual ~Erreur() throw(){}


	private:

		short int m_erreurNum;	    //numero de l'erreur
		short int m_erreurNiveau;   //niveau de l'erreur
		std::string m_erreurString; //description de l'erreur

};



#endif /* UTILS_ERREUR_HPP_ */
