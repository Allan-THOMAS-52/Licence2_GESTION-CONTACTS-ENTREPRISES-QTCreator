#ifndef TACHE_TACHE_H
#define TACHE_TACHE_H

#include <string>

#include "../utils/sDate.hpp"

class Tache{
  public:

    /**
     * @brief 1er Constructeur de la classe Todo
     */
	Tache(const sDate & pDate, const std::string & pContenu);
    /**
     * @brief 2eme Constructeur de la classe Todo
     */
	Tache(short int const& pJour,short int const& pMois,short int const& pAnnee,
    		std::string const& pIntitule,std::string const& pCont);
    /**
	 * @brief Constructeur par defaut de la classe Todo
	 */
	Tache();

    /**
	 * @brief Accesseur de m_dateC
	 */
    struct sDate getDateC() const;

    /**
	 * @brief Mutateur de m_dateC
	 */
    void setDate(const sDate & pDate);

    /**
	 * @brief Accesseur de m_contenu
	 */
    std::string getContenu() const;

    /**
	 * @brief Mutateur de m_contenu
	 */
    void setContenu(const std::string & pCont);

    /**
	 * @brief surcharge de l'operateur d'egalite
	 */
    bool operator==(Tache const& pTache) const;

    /**
	 * @brief surcharge de l'operateur de difference
	 */
    bool operator!=(Tache const& pTache) const;

    /**
	 * @brief Destructeur de la classe Todo
	 */
    ~Tache();


  private:

    struct sDate m_dateC;
    std::string m_contenu;

};
#endif
