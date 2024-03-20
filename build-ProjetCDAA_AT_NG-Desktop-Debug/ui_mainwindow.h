/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionImporter_contacts;
    QAction *actionExporter_contacts;
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *RadioNom;
    QLineEdit *LineNom;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *RadioEntr;
    QLineEdit *LineEntr;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *RadioDate;
    QLineEdit *lineDate;
    QPushButton *ButDate;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *RadioInterDate;
    QLineEdit *lineDate1;
    QLineEdit *lineDate2;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *ButRechercher;
    QPushButton *ButResetRecherche;
    QPushButton *ButDate1;
    QPushButton *ButDate2;
    QCalendarWidget *Calendrier;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *ButTriDate;
    QPushButton *ButTriAlpha;
    QPushButton *ButListeModifs;
    QListWidget *ListeContacts;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *ButAjoutContact;
    QPushButton *ButSuprContact;
    QPushButton *ButModContact;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *textBrowser_2;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *ButAjTodo;
    QPushButton *ButSupTodo;
    QPushButton *ButModTodo;
    QMenuBar *menuBar;
    QMenu *menuJSON;
    QButtonGroup *BoutonsRecherche;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1149, 739);
        actionImporter_contacts = new QAction(MainWindow);
        actionImporter_contacts->setObjectName(QString::fromUtf8("actionImporter_contacts"));
        actionExporter_contacts = new QAction(MainWindow);
        actionExporter_contacts->setObjectName(QString::fromUtf8("actionExporter_contacts"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(10, 0, 1131, 361));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setItalic(false);
        groupBox->setFont(font);
        groupBox->setLayoutDirection(Qt::LeftToRight);
        horizontalLayoutWidget_2 = new QWidget(groupBox);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 30, 1121, 331));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        RadioNom = new QRadioButton(horizontalLayoutWidget_2);
        BoutonsRecherche = new QButtonGroup(MainWindow);
        BoutonsRecherche->setObjectName(QString::fromUtf8("BoutonsRecherche"));
        BoutonsRecherche->addButton(RadioNom);
        RadioNom->setObjectName(QString::fromUtf8("RadioNom"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(RadioNom->sizePolicy().hasHeightForWidth());
        RadioNom->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setItalic(false);
        RadioNom->setFont(font1);
        RadioNom->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_5->addWidget(RadioNom);

        LineNom = new QLineEdit(horizontalLayoutWidget_2);
        LineNom->setObjectName(QString::fromUtf8("LineNom"));
        sizePolicy1.setHeightForWidth(LineNom->sizePolicy().hasHeightForWidth());
        LineNom->setSizePolicy(sizePolicy1);
        LineNom->setFont(font);

        horizontalLayout_5->addWidget(LineNom);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        RadioEntr = new QRadioButton(horizontalLayoutWidget_2);
        BoutonsRecherche->addButton(RadioEntr);
        RadioEntr->setObjectName(QString::fromUtf8("RadioEntr"));
        RadioEntr->setFont(font1);
        RadioEntr->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_4->addWidget(RadioEntr);

        LineEntr = new QLineEdit(horizontalLayoutWidget_2);
        LineEntr->setObjectName(QString::fromUtf8("LineEntr"));
        sizePolicy1.setHeightForWidth(LineEntr->sizePolicy().hasHeightForWidth());
        LineEntr->setSizePolicy(sizePolicy1);
        LineEntr->setFont(font);

        horizontalLayout_4->addWidget(LineEntr);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        RadioDate = new QRadioButton(horizontalLayoutWidget_2);
        BoutonsRecherche->addButton(RadioDate);
        RadioDate->setObjectName(QString::fromUtf8("RadioDate"));
        RadioDate->setFont(font1);
        RadioDate->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_3->addWidget(RadioDate);

        lineDate = new QLineEdit(horizontalLayoutWidget_2);
        lineDate->setObjectName(QString::fromUtf8("lineDate"));
        sizePolicy1.setHeightForWidth(lineDate->sizePolicy().hasHeightForWidth());
        lineDate->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(lineDate);

        ButDate = new QPushButton(horizontalLayoutWidget_2);
        ButDate->setObjectName(QString::fromUtf8("ButDate"));
        ButDate->setFont(font1);

        horizontalLayout_3->addWidget(ButDate);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        RadioInterDate = new QRadioButton(horizontalLayoutWidget_2);
        BoutonsRecherche->addButton(RadioInterDate);
        RadioInterDate->setObjectName(QString::fromUtf8("RadioInterDate"));
        RadioInterDate->setFont(font1);
        RadioInterDate->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_8->addWidget(RadioInterDate);

        lineDate1 = new QLineEdit(horizontalLayoutWidget_2);
        lineDate1->setObjectName(QString::fromUtf8("lineDate1"));
        lineDate1->setPlaceholderText(QString::fromUtf8("dd-mm-yyyy"));

        horizontalLayout_8->addWidget(lineDate1);

        lineDate2 = new QLineEdit(horizontalLayoutWidget_2);
        lineDate2->setObjectName(QString::fromUtf8("lineDate2"));

        horizontalLayout_8->addWidget(lineDate2);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        ButRechercher = new QPushButton(horizontalLayoutWidget_2);
        ButRechercher->setObjectName(QString::fromUtf8("ButRechercher"));
        ButRechercher->setFont(font1);
        ButRechercher->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_9->addWidget(ButRechercher);

        ButResetRecherche = new QPushButton(horizontalLayoutWidget_2);
        ButResetRecherche->setObjectName(QString::fromUtf8("ButResetRecherche"));
        ButResetRecherche->setFont(font1);
        ButResetRecherche->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_9->addWidget(ButResetRecherche);

        ButDate1 = new QPushButton(horizontalLayoutWidget_2);
        ButDate1->setObjectName(QString::fromUtf8("ButDate1"));
        ButDate1->setFont(font1);
        ButDate1->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_9->addWidget(ButDate1);

        ButDate2 = new QPushButton(horizontalLayoutWidget_2);
        ButDate2->setObjectName(QString::fromUtf8("ButDate2"));
        ButDate2->setFont(font1);
        ButDate2->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_9->addWidget(ButDate2);


        verticalLayout_3->addLayout(horizontalLayout_9);


        horizontalLayout_2->addLayout(verticalLayout_3);

        Calendrier = new QCalendarWidget(horizontalLayoutWidget_2);
        Calendrier->setObjectName(QString::fromUtf8("Calendrier"));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setItalic(false);
        Calendrier->setFont(font2);

        horizontalLayout_2->addWidget(Calendrier);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 380, 1131, 331));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        ButTriDate = new QPushButton(horizontalLayoutWidget);
        ButTriDate->setObjectName(QString::fromUtf8("ButTriDate"));
        ButTriDate->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_6->addWidget(ButTriDate);

        ButTriAlpha = new QPushButton(horizontalLayoutWidget);
        ButTriAlpha->setObjectName(QString::fromUtf8("ButTriAlpha"));
        ButTriAlpha->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_6->addWidget(ButTriAlpha);

        ButListeModifs = new QPushButton(horizontalLayoutWidget);
        ButListeModifs->setObjectName(QString::fromUtf8("ButListeModifs"));
        ButListeModifs->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_6->addWidget(ButListeModifs);


        verticalLayout->addLayout(horizontalLayout_6);

        ListeContacts = new QListWidget(horizontalLayoutWidget);
        ListeContacts->setObjectName(QString::fromUtf8("ListeContacts"));
        QFont font3;
        font3.setPointSize(13);
        ListeContacts->setFont(font3);

        verticalLayout->addWidget(ListeContacts);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        ButAjoutContact = new QPushButton(horizontalLayoutWidget);
        ButAjoutContact->setObjectName(QString::fromUtf8("ButAjoutContact"));
        ButAjoutContact->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_7->addWidget(ButAjoutContact);

        ButSuprContact = new QPushButton(horizontalLayoutWidget);
        ButSuprContact->setObjectName(QString::fromUtf8("ButSuprContact"));
        ButSuprContact->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_7->addWidget(ButSuprContact);

        ButModContact = new QPushButton(horizontalLayoutWidget);
        ButModContact->setObjectName(QString::fromUtf8("ButModContact"));
        ButModContact->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_7->addWidget(ButModContact);


        verticalLayout->addLayout(horizontalLayout_7);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        textBrowser_2 = new QTextBrowser(horizontalLayoutWidget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));

        verticalLayout_2->addWidget(textBrowser_2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        ButAjTodo = new QPushButton(horizontalLayoutWidget);
        ButAjTodo->setObjectName(QString::fromUtf8("ButAjTodo"));
        ButAjTodo->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_10->addWidget(ButAjTodo);

        ButSupTodo = new QPushButton(horizontalLayoutWidget);
        ButSupTodo->setObjectName(QString::fromUtf8("ButSupTodo"));
        ButSupTodo->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_10->addWidget(ButSupTodo);

        ButModTodo = new QPushButton(horizontalLayoutWidget);
        ButModTodo->setObjectName(QString::fromUtf8("ButModTodo"));
        ButModTodo->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_10->addWidget(ButModTodo);


        verticalLayout_2->addLayout(horizontalLayout_10);


        horizontalLayout->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1149, 23));
        menuJSON = new QMenu(menuBar);
        menuJSON->setObjectName(QString::fromUtf8("menuJSON"));
        menuJSON->setCursor(QCursor(Qt::PointingHandCursor));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuJSON->menuAction());
        menuJSON->addAction(actionImporter_contacts);
        menuJSON->addAction(actionExporter_contacts);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion de contacts", nullptr));
        actionImporter_contacts->setText(QCoreApplication::translate("MainWindow", "Importer contacts", nullptr));
        actionExporter_contacts->setText(QCoreApplication::translate("MainWindow", "Exporter contacts", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Recherche de contacts par :", nullptr));
        RadioNom->setText(QCoreApplication::translate("MainWindow", " Nom :", nullptr));
        RadioEntr->setText(QCoreApplication::translate("MainWindow", "Entreprise :", nullptr));
        RadioDate->setText(QCoreApplication::translate("MainWindow", "Date de creation :", nullptr));
        lineDate->setPlaceholderText(QCoreApplication::translate("MainWindow", "dd-mm-yyyy", nullptr));
        ButDate->setText(QCoreApplication::translate("MainWindow", "Selectionner date", nullptr));
        RadioInterDate->setText(QCoreApplication::translate("MainWindow", "Cree entre :", nullptr));
        lineDate2->setPlaceholderText(QCoreApplication::translate("MainWindow", "dd-mm-yyyy", nullptr));
        ButRechercher->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        ButResetRecherche->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        ButDate1->setText(QCoreApplication::translate("MainWindow", "Debut intervalle", nullptr));
        ButDate2->setText(QCoreApplication::translate("MainWindow", "Fin intervalle", nullptr));
        ButTriDate->setText(QCoreApplication::translate("MainWindow", "Tri par date de creation", nullptr));
        ButTriAlpha->setText(QCoreApplication::translate("MainWindow", "Tri alphabetique", nullptr));
        ButListeModifs->setText(QCoreApplication::translate("MainWindow", "Liste des modifications", nullptr));
        ButAjoutContact->setText(QCoreApplication::translate("MainWindow", "Ajouter contact", nullptr));
        ButSuprContact->setText(QCoreApplication::translate("MainWindow", "Supprimer contact", nullptr));
        ButModContact->setText(QCoreApplication::translate("MainWindow", "Modifier contact", nullptr));
        ButAjTodo->setText(QCoreApplication::translate("MainWindow", "Ajouter chose a faire", nullptr));
        ButSupTodo->setText(QCoreApplication::translate("MainWindow", "Supprimer chose a faire", nullptr));
        ButModTodo->setText(QCoreApplication::translate("MainWindow", "Modifier chose a faire", nullptr));
        menuJSON->setTitle(QCoreApplication::translate("MainWindow", "JSON", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
