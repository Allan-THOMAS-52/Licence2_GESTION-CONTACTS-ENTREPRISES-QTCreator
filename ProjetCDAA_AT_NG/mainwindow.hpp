#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QDebug>
#include <QDate>
#include <QMessageBox>
#include <QFileDialog>
#include <memory>
#include <QVariant>
#include <QListWidgetItem>
#include <QDialog>

#include "contacts/gestionContact/GestionContact.hpp"
#include "contacts/Contact.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

Q_DECLARE_METATYPE(std::shared_ptr<Contact>)

class MainWindow : public QMainWindow{

    Q_OBJECT

    public:

        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

        void afficheListeContacts();
        void afficheListeResultats(std::vector<std::shared_ptr<Contact>> const& pContacts);

        void addContactToList(std::shared_ptr<Contact> const& pContact);
        void deleteSelectedContactFromList();

        void recherche();

    private slots:

        void on_ButRechercher_clicked();
        void on_ButResetRecherche_clicked();

        void on_ButDate_clicked();
        void on_ButDate1_clicked();
        void on_ButDate2_clicked();

        void on_ButTriAlpha_clicked();
        void on_ButTriDate_clicked();
        void on_ButListeModifs_clicked();

        void on_ButSuprContact_clicked();

        void on_ButAjoutContact_clicked();
        void on_ButModContact_clicked();

        void on_ListeContacts_itemClicked(QListWidgetItem* item);
        void on_ListeContacts_itemSelectionChanged();

        void on_ButModTodo_clicked();
        void on_ButSupTodo_clicked();
        void on_ButAjTodo_clicked();

        void on_actionImporter_contacts_triggered();
        void on_actionExporter_contacts_triggered();

    private:

        Ui::MainWindow* ui;

        GestionContact m_gestionContact;

        QDate m_dateRecherche;
        QDate m_dateInterv1;
        QDate m_dateInterv2;

        QListWidgetItem* m_selectedItem;

};

#endif // MAINWINDOW_HPP
