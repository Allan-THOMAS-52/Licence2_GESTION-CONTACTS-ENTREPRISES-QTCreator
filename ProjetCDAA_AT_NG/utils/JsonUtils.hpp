/**
 * @file JsonUtils.hpp
 */
#ifndef JSONUTILS_HPP
#define JSONUTILS_HPP

#include "../librairies/nlohmann/json.hpp"
#include "../contacts/Contact.hpp"
#include "sDate.hpp"

#include <fstream>
#include <memory>
#include <vector>
#include <sstream>


/**
 * @brief loadContactsFromJson , permet de lire des fichiers json pour ajouter des contacts
 * @param pPath , chemin du fichier a lire
 * @return liste des contacts lu dans le fichier
 */
std::vector<std::shared_ptr<Contact>> loadContactsFromJson(std::string const& pPath){

    std::vector<std::shared_ptr<Contact>> listeContacts;

    std::ifstream file(pPath);

    if(!file){
        std::cerr << "Erreur: impossible d'ouvrir le fichier" << std::endl;
        return {};
    }

    nlohmann::json jsonData;

    try {
       file >> jsonData;
    } catch (const nlohmann::json::exception& e) {
       std::cerr << "Erreur de parsing JSON: " << e.what() << std::endl;
       return {};
    }

    for(nlohmann::json const& contactData : jsonData){

        std::string dateStr = contactData["dateCreation"];

        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(dateStr);

        while (std::getline(tokenStream, token, '/')) {
            tokens.push_back(token);
        }

        struct sDate date(std::stoi(tokens[0]),std::stoi(tokens[1]),std::stoi(tokens[2]),"");

        std::shared_ptr<Contact> contactPtr = std::make_shared<Contact>(contactData["nom"],contactData["prenom"],contactData["entreprise"],contactData["mail"],
                contactData["telephone"],contactData["URLphoto"],date);

        listeContacts.emplace_back(contactPtr);
    }

    return listeContacts;
}

/**
 * @brief exportContactsToJson , permet d'exporter des contacts en fichier json
 * @param contacts , les contacts a exporter ; pPath , chemin du fichier vesr lequel ecrire
 */
void exportContactsToJson(std::vector<std::shared_ptr<Contact>> const& contacts,std::string const& pPath){

    using json = nlohmann::json;

    json jsonData = json::array();

    for (auto const& contact : contacts) {

        json contactData;

        contactData["nom"] = contact->getNom();
        contactData["prenom"] = contact->getPrenom();
        contactData["entreprise"] = contact->getEntreprise();
        contactData["mail"] = contact->getMail();
        contactData["telephone"] = contact->getTelephone();
        contactData["URLphoto"] = contact->getPhoto();
        contactData["dateCreation"] = contact->getDateCreation().toString();

        jsonData.push_back(contactData);
    }

    std::ofstream outFile(pPath);
    if (outFile.is_open()) {
        outFile << std::setw(4) << jsonData;  // Pretty print with indentation
        outFile.close();
    } else {
        std::cerr << "Erreur: impossible d'ouvrir le fichier pour l'export" << std::endl;
    }

}










#endif // JSONUTILS_HPP
