#include "mainwindow.hpp"

#include "ui_mainwindow.h"
#include "ui_contactdialog.h"
#include "ui_listmodifsdialog.h"

#include "utils/JsonUtils.hpp"
#include "utils/sDate.hpp"
#include "fenetresDialogue/contactdialog.hpp"
#include "fenetresDialogue/listmodifsdialog.hpp"


MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow){

    ui->setupUi(this);

    m_selectedItem = nullptr;

    ui->ButModContact->setEnabled(false);
    ui->ButSuprContact->setEnabled(false);

    ui->lineDate->setAlignment(Qt::AlignCenter);
    ui->lineDate1->setAlignment(Qt::AlignCenter);
    ui->lineDate2->setAlignment(Qt::AlignCenter);



    afficheListeContacts();

}

MainWindow::~MainWindow(){
    delete ui;
}



void MainWindow::afficheListeContacts(){

    if(!m_gestionContact.getContacts().empty()){

        ui->ListeContacts->clear();

        for( std::shared_ptr<Contact> const& contact : m_gestionContact.getContacts()){

            QString contactInfos = QString::fromStdString(contact->getNom()) + " " +
                QString::fromStdString(contact->getPrenom()) + " " + "de chez " +
                QString::fromStdString(contact->getEntreprise());

            QListWidgetItem* item = new QListWidgetItem(contactInfos);

            //on stocke un pointer vers le contact associe a l'item
            QVariant data;
            data.setValue(contact);
            item->setData(Qt::UserRole,data);

            ui->ListeContacts->addItem(item);
        }

    }

}

void MainWindow::afficheListeResultats(std::vector<std::shared_ptr<Contact>> const& pContacts){

    ui->ListeContacts->clear();

    for( std::shared_ptr<Contact> const& contact : pContacts){

        QString contactInfos = QString::fromStdString(contact->getNom()) + " " +
            QString::fromStdString(contact->getPrenom()) + " " + "de chez " +
            QString::fromStdString(contact->getEntreprise());

        QListWidgetItem* item = new QListWidgetItem(contactInfos);

        //on stocke un pointer vers le contact associe a l'item
        QVariant data;
        data.setValue(contact);
        item->setData(Qt::UserRole,data);

        ui->ListeContacts->addItem(item);
    }

}



void MainWindow::addContactToList(std::shared_ptr<Contact> const& pContact){

    QString contactInfos = QString::fromStdString(pContact->getNom()) + " " +
        QString::fromStdString(pContact->getPrenom()) + " " +
        QString::fromStdString(pContact->getEntreprise());

    QListWidgetItem* item = new QListWidgetItem(contactInfos);

    ui->ListeContacts->addItem(item);
}

void MainWindow::deleteSelectedContactFromList(){

    QListWidgetItem* selectedItem = ui->ListeContacts->currentItem();

    if(selectedItem){

        QVariant data = selectedItem->data(Qt::UserRole);

        std::shared_ptr<Contact> selectedContact = data.value<std::shared_ptr<Contact>>();

        std::string pIntitule = "Suppression du contact: ";

        pIntitule += selectedContact->getNom() + " " + selectedContact->getPrenom() + " de chez " + selectedContact->getEntreprise();

        struct sDate dateSupr(QDate::currentDate().day(),QDate::currentDate().month(),QDate::currentDate().year(),pIntitule);

        m_gestionContact.supprimerParComparaison(*selectedContact,dateSupr);

        ui->ListeContacts->takeItem(ui->ListeContacts->row(selectedItem));

        delete selectedItem;
    }

}



void MainWindow::recherche(){

    if(ui->RadioNom->isChecked()){

        if( !( ui->LineNom->text().isEmpty()) ) {

            QString parametre = ui->LineNom->text();

            afficheListeResultats(m_gestionContact.getContactsParNom(parametre.toStdString()));

        }else{
            QMessageBox messageErreur;
            messageErreur.setIcon(QMessageBox::Critical);
            messageErreur.setWindowTitle("Error");
            messageErreur.setText("Veuillez renseigner un nom");
            messageErreur.setWindowModality(Qt::WindowModal);
            messageErreur.setParent(this, Qt::Dialog);
            messageErreur.exec();
        }

    }else if(ui->RadioEntr->isChecked()){

        if( !( ui->LineEntr->text().isEmpty()) ) {

            QString parametre = ui->LineEntr->text();

            afficheListeResultats(m_gestionContact.getContactsParEntreprise(parametre.toStdString()));

        }else{
            QMessageBox messageErreur;
            messageErreur.setIcon(QMessageBox::Critical);
            messageErreur.setWindowTitle("Error");
            messageErreur.setText("Veuillez renseigner une entreprise");
            messageErreur.setWindowModality(Qt::WindowModal);
            messageErreur.setParent(this, Qt::Dialog);
            messageErreur.exec();
        }

    }else if(ui->RadioDate->isChecked()){

        if( !( ui->lineDate->text().isEmpty()) ) {

            struct sDate date(m_dateRecherche.day(),m_dateRecherche.month(),m_dateRecherche.year(),"");

            afficheListeResultats(m_gestionContact.getContactsParDateCreation(date));

        }else{
            QMessageBox messageErreur;
            messageErreur.setIcon(QMessageBox::Critical);
            messageErreur.setWindowTitle("Error");
            messageErreur.setText("Veuillez renseigner une date");
            messageErreur.setWindowModality(Qt::WindowModal);
            messageErreur.setParent(this, Qt::Dialog);
            messageErreur.exec();
        }

    }else if(ui->RadioInterDate->isChecked()){

        if( !ui->lineDate1->text().isEmpty() && !ui->lineDate2->text().isEmpty() ) {

            struct sDate date1(m_dateInterv1.day(),m_dateInterv1.month(),m_dateInterv1.year(),"");
            struct sDate date2(m_dateInterv2.day(),m_dateInterv2.month(),m_dateInterv2.year(),"");

            afficheListeResultats(m_gestionContact.getContactsParIntervDate(date1,date2));

        }else{
            QMessageBox messageErreur;
            messageErreur.setIcon(QMessageBox::Critical);
            messageErreur.setWindowTitle("Error");

            if(ui->lineDate1->text().isEmpty() && ui->lineDate2->text().isEmpty()){

                messageErreur.setText("Veuillez renseigner un intervalle");

            }else if(ui->lineDate1->text().isEmpty() && !ui->lineDate2->text().isEmpty()){

                messageErreur.setText("Veuillez renseigner un debut d'intervalle");

            }else if(ui->lineDate2->text().isEmpty() && !ui->lineDate1->text().isEmpty()){

                messageErreur.setText("Veuillez renseigner une fin d'intervalle");

            }
            messageErreur.setWindowModality(Qt::WindowModal);
            messageErreur.setParent(this, Qt::Dialog);
            messageErreur.exec();
        }

    }

}



//-----------------SLOTS-----------------

void MainWindow::on_ButRechercher_clicked(){recherche();}

void MainWindow::on_ButResetRecherche_clicked(){

    afficheListeContacts();

    ui->RadioNom->setChecked(false);
    ui->RadioEntr->setChecked(false);
    ui->RadioDate->setChecked(false);
    ui->RadioInterDate->setChecked(false);

    ui->LineNom->setText("");
    ui->LineEntr->setText("");
    ui->lineDate->setText("");
    ui->lineDate1->setText("");
    ui->lineDate2->setText("");

    ui->Calendrier->setSelectedDate(QDate::currentDate());

    ui->ButModContact->setEnabled(false);
    ui->ButSuprContact->setEnabled(false);

}



void MainWindow::on_ButDate_clicked(){

    m_dateRecherche = ui->Calendrier->selectedDate();

    ui->lineDate->setText(m_dateRecherche.toString("dd-MM-yyyy"));
}

void MainWindow::on_ButDate1_clicked(){

    if(!m_dateInterv2.isValid()){

        m_dateInterv1 = ui->Calendrier->selectedDate();

        ui->lineDate1->setText(m_dateInterv1.toString("dd-MM-yyyy"));

    }else{

        if(!(ui->Calendrier->selectedDate() > m_dateInterv2) ){

            m_dateInterv1 = ui->Calendrier->selectedDate();

            ui->lineDate1->setText(m_dateInterv1.toString("dd-MM-yyyy"));

        }else{

            QMessageBox* messageErreur = new QMessageBox();
            messageErreur->setIcon(QMessageBox::Critical);
            messageErreur->setWindowTitle("Error");
            messageErreur->setText("Le debut de l'intervalle est plus recent que la fin de l'intervalle");
            messageErreur->exec();
            delete messageErreur;

        }

    }

}

void MainWindow::on_ButDate2_clicked(){

    if(!m_dateInterv1.isValid()){

        m_dateInterv2 = ui->Calendrier->selectedDate();

        ui->lineDate2->setText(m_dateInterv2.toString("dd-MM-yyyy"));

    }else{

        if(!(ui->Calendrier->selectedDate() < m_dateInterv1) ){

            m_dateInterv2 = ui->Calendrier->selectedDate();

            ui->lineDate2->setText(m_dateInterv2.toString("dd-MM-yyyy"));

        }else{

            QMessageBox* messageErreur = new QMessageBox();
            messageErreur->setIcon(QMessageBox::Critical);
            messageErreur->setWindowTitle("Error");
            messageErreur->setText("La fin de l'intervalle est plus vieille que le debut de l'intervalle");
            messageErreur->exec();
            delete messageErreur;

        }

    }

}



void MainWindow::on_ButTriAlpha_clicked(){
    m_gestionContact.triParAlphaB();
    afficheListeContacts();
    ui->ButModContact->setEnabled(false);
    ui->ButSuprContact->setEnabled(false);
}

void MainWindow::on_ButTriDate_clicked(){
    m_gestionContact.triParDate(true);
    afficheListeContacts();
    ui->ButModContact->setEnabled(false);
    ui->ButSuprContact->setEnabled(false);
}

void MainWindow::on_ButListeModifs_clicked(){

    ListModifsDialog* listModDialog = new ListModifsDialog(this);

    if(!m_gestionContact.getDatesModifs().empty()){


        std::vector<std::shared_ptr<struct sDate>> datesModifications;

        if(!m_gestionContact.getDatesSupp().empty()){

            for( std::shared_ptr<struct sDate> const& pDateS : m_gestionContact.getDatesSupp() ){
                datesModifications.emplace_back(pDateS);
            }

        }

        for( std::shared_ptr<struct sDate> const& pDateM : m_gestionContact.getDatesModifs()){
            datesModifications.emplace_back(pDateM);
        }


        auto compareByDate = []( std::shared_ptr<struct sDate> const& date1, std::shared_ptr<struct sDate> const& date2) {
                return *date1 < *date2 ; // ordre croissant
        };

        std::sort(datesModifications.begin(), datesModifications.end(), compareByDate);

        for (std::shared_ptr<struct sDate> const& pDate : datesModifications){
            QString infoDate = QString::number(pDate->day) + "/" +
                QString::number(pDate->month) + "/" +
                QString::number(pDate->year) + " -> " +
                QString::fromStdString(pDate->intitule) + "\n";
            listModDialog->getUi()->listeModifs->append(infoDate);
        }



        if(!m_gestionContact.getDatesSupp().empty()){

            struct sDate date = m_gestionContact.getDateDerniereSupr();

            std::string derniereSupr = std::to_string(date.day) + "/" + std::to_string(date.month)+
                    "/" + std::to_string(date.year) + " -> " + date.intitule;

            listModDialog->getUi()->lineLastDate->setText(QString::fromStdString(derniereSupr));
        }

    }

    listModDialog->exec();

    delete listModDialog;

}



void MainWindow::on_ButSuprContact_clicked(){
    deleteSelectedContactFromList();
    afficheListeContacts();

    ui->ButModContact->setEnabled(false);
    ui->ButSuprContact->setEnabled(false);

}

void MainWindow::on_ButAjoutContact_clicked(){

    ContactDialog* ajoutDialog = new ContactDialog(this);
    ajoutDialog->setFixedSize(690,360);

    short int result = ajoutDialog->exec();

    if(result == QDialog::Accepted){

        std::string nom = ajoutDialog->getUI()->lineNomD->text().toStdString();
        std::string prenom = ajoutDialog->getUI()->linePrenomD->text().toStdString();
        std::string entreprise = ajoutDialog->getUI()->lineEntreD->text().toStdString();
        std::string mail = ajoutDialog->getUI()->lineMailD->text().toStdString();
        std::string telephone = ajoutDialog->getUI()->lineTelD->text().toStdString();
        std::string photo = ajoutDialog->getUI()->linePhotoD->text().toStdString();

        struct sDate date(QDate::currentDate().day(),QDate::currentDate().month(),QDate::currentDate().year(),"Creation fiche contact");

        // on transforme les initales en majuscules

            char firstNom = nom[0];
            char firstPrenom = prenom[0];

            firstNom = std::toupper(firstNom);
            firstPrenom = std::toupper(firstPrenom);

            nom[0] = firstNom;
            prenom[0] = firstPrenom;

        std::shared_ptr<Contact> newContact = std::make_shared<Contact>(nom,prenom,entreprise,mail,telephone,photo,date);

        m_gestionContact.creerFiche(newContact,date);

        afficheListeContacts();

    }

    delete ajoutDialog;

}

void MainWindow::on_ButModContact_clicked(){

    ContactDialog* modifDialog = new ContactDialog(this);
    modifDialog->getUI()->groupBox->setTitle("Modification de contact");
    modifDialog->setFixedSize(690,360);

    QListWidgetItem* selectedItem = ui->ListeContacts->currentItem();

    if(selectedItem){

        QVariant data = selectedItem->data(Qt::UserRole);

        std::shared_ptr<Contact> selectedContact = data.value<std::shared_ptr<Contact>>();

        modifDialog->getUI()->lineNomD->setText(QString::fromStdString(selectedContact->getNom()));
        modifDialog->getUI()->linePrenomD->setText(QString::fromStdString(selectedContact->getPrenom()));
        modifDialog->getUI()->lineEntreD->setText(QString::fromStdString(selectedContact->getEntreprise()));
        modifDialog->getUI()->lineMailD->setText(QString::fromStdString(selectedContact->getMail()));
        modifDialog->getUI()->lineTelD->setText(QString::fromStdString(selectedContact->getTelephone()));
        modifDialog->getUI()->linePhotoD->setText(QString::fromStdString(selectedContact->getPhoto()));

        int result = modifDialog->exec();

        if(result == QDialog::Accepted){

            std::string nom = modifDialog->getUI()->lineNomD->text().toStdString();
            std::string prenom = modifDialog->getUI()->linePrenomD->text().toStdString();
            std::string entreprise = modifDialog->getUI()->lineEntreD->text().toStdString();
            std::string mail = modifDialog->getUI()->lineMailD->text().toStdString();
            std::string telephone = modifDialog->getUI()->lineTelD->text().toStdString();
            std::string photo = modifDialog->getUI()->linePhotoD->text().toStdString();

            std::string date = "Modifiaction du contact: ";
            date += nom + " ";

            struct sDate dateModif(QDate::currentDate().day(),QDate::currentDate().month(),QDate::currentDate().year(),date);

            selectedContact->setNom(nom);
            selectedContact->setPrenom(prenom);
            selectedContact->setEntreprise(entreprise);
            selectedContact->setMail(mail);
            selectedContact->setTelephone(telephone);
            selectedContact->setPhoto(photo);

        }

        afficheListeContacts();

    }

    delete modifDialog;

    ui->ButModContact->setEnabled(false);
    ui->ButSuprContact->setEnabled(false);

}



void MainWindow::on_ListeContacts_itemClicked(QListWidgetItem* item){
    m_selectedItem = item;
}

void MainWindow::on_ListeContacts_itemSelectionChanged(){
    QListWidgetItem* selectedItem = ui->ListeContacts->currentItem();
    bool isItemSelected = selectedItem != nullptr;
    ui->ButModContact->setEnabled(isItemSelected);
    ui->ButSuprContact->setEnabled(isItemSelected);
}



void MainWindow::on_ButModTodo_clicked(){

}

void MainWindow::on_ButSupTodo_clicked(){

}

void MainWindow::on_ButAjTodo_clicked(){

}


void MainWindow::on_actionImporter_contacts_triggered(){

    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Import contacts"), "", tr("All Files (*)"));

    if (!fileName.isEmpty()) {

        m_gestionContact.setContacts(loadContactsFromJson(fileName.toStdString()));

        QDate dateC = QDate::currentDate();

        struct sDate dateImport(dateC.day(),dateC.month(),dateC.year(),"Import contacts via le fichier '");

        QFileInfo fileInfo(fileName);

        dateImport.intitule += fileInfo.fileName().toStdString();
        dateImport.intitule += "'";

        m_gestionContact.ajoutDateModif(dateImport);

        afficheListeContacts();

    }

}

void MainWindow::on_actionExporter_contacts_triggered(){

    QString fileName = QFileDialog::getSaveFileName(this, "Export contacts", "/home/username/Documents", "All Files (*)");

    if (!fileName.isEmpty()) {

        exportContactsToJson(m_gestionContact.getContacts(),fileName.toStdString());

        QDate dateC = QDate::currentDate();

        struct sDate dateExport(dateC.day(),dateC.month(),dateC.year(),"Export contacts vers le fichier '");

        QFileInfo fileInfo(fileName);

        dateExport.intitule += fileInfo.fileName().toStdString();
        dateExport.intitule += "'";

        m_gestionContact.ajoutDateModif(dateExport);

        QFile file(fileName);

    }

}






















