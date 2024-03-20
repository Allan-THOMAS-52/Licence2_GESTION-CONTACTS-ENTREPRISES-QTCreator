/**
 * @file Date.hpp
 */
#ifndef UTILS_SDATE_HPP_
#define UTILS_SDATE_HPP_

#include <string>
#include <iostream>

/**
 * @struct sDate
 * @brief struct representant une date
 * Contient des short int pour economiser des octets ( 2 octets economises par rapport a un int )
 */
struct sDate{
    short int day;
    short int month;
    short int year;
    std::string intitule;

    /**
     * @brief constructeur de sDate
     */
    sDate(short int const& pDay,short int const& pMonth,short int const& pYear,std::string const& pInt):
            day(pDay),month(pMonth),year(pYear),intitule(pInt){	}

    sDate():day(0),month(0),year(0),intitule(""){ }

    /**
     * @brief fonction pour afficher la date
     */
    void afficheDate(std::ostream& flux) const{
        flux << day << "/" << month << "/" << year << std::endl;
    }

    /**
     * @brief fonction toString pour l'export en json
     */
    std::string toString(){
        std::string s = std::to_string(day);
        s += "/";
        s += std::to_string(month);
        s += "/";
        s += std::to_string(year);
        return s;
    }

    /**
     * @brief surcharge de l'operateur d'affectation
     */
    void operator=(struct sDate const& pDate){
        day = pDate.day;
        month = pDate.month;
        year = pDate.year;
    };

    /**
     * @brief surcharge de l'operateur d'egalite
     */
    bool operator==(struct sDate const& pDate) const{
        return day==pDate.day && month==pDate.month && year==pDate.year;
    }

    /**
     * @brief surcharge de l'operateur de difference
     */
    bool operator!=(struct sDate const& pDate) const{return !(*this == pDate);}

    /**
     * @brief surcharge de l'operateur <
     *  test si date-1 plus vieille que date-2
     */
    bool operator<(struct sDate const& pDate) const{

        if (year == pDate.year) {
            if (month == pDate.month) {
                return day < pDate.day;
            }
            return month < pDate.month;
        }
        return year < pDate.year;

    }

    /**
     * @brief surcharge de l'operateur >
     *  test si date-1 plus recente que date-2
     */
    bool operator>(struct sDate const& pDate) const{
        return !(*this < pDate);
    }

    /**
     * @brief surcharge de l'operateur <=
     * test si date-1 plus vieille ou egale a date-2
     */
    bool operator<=(struct sDate const& pDate) const{
        if (year == pDate.year) {
                if (month == pDate.month) {
                    return day <= pDate.day;
                }
                return month <= pDate.month;
            }
            return year <= pDate.year;
    }

    /**
     * @brief surcharge de l'operateur >=
     * test si date-1 plus recente ou egale a date-2
     */
    bool operator>=(struct sDate const& pDate) const{
        return !(*this <= pDate);
    }


    /**
     * @brief surcharge de l'operateur <<
     */
    friend std::ostream& operator<<(std::ostream& flux,struct sDate const& pDate){
        pDate.afficheDate(flux);
        return flux;
    }


    /**
     * @brief Destructeur de la classe sDate
     */
    ~sDate(){ };

};

#endif /* UTILS_SDATE_HPP_ */
