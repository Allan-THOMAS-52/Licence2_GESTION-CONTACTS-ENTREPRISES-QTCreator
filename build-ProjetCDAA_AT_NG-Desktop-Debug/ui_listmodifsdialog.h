/********************************************************************************
** Form generated from reading UI file 'listmodifsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTMODIFSDIALOG_H
#define UI_LISTMODIFSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListModifsDialog
{
public:
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *listeModifs;
    QLabel *label;
    QLineEdit *lineLastDate;
    QPushButton *ButFermer;

    void setupUi(QDialog *ListModifsDialog)
    {
        if (ListModifsDialog->objectName().isEmpty())
            ListModifsDialog->setObjectName(QString::fromUtf8("ListModifsDialog"));
        ListModifsDialog->setWindowModality(Qt::WindowModal);
        ListModifsDialog->resize(554, 386);
        groupBox = new QGroupBox(ListModifsDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 521, 341));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        groupBox->setFont(font);
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 40, 501, 291));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listeModifs = new QTextBrowser(verticalLayoutWidget);
        listeModifs->setObjectName(QString::fromUtf8("listeModifs"));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(false);
        listeModifs->setFont(font1);

        verticalLayout->addWidget(listeModifs);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineLastDate = new QLineEdit(verticalLayoutWidget);
        lineLastDate->setObjectName(QString::fromUtf8("lineLastDate"));
        lineLastDate->setFont(font1);
        lineLastDate->setReadOnly(true);

        verticalLayout->addWidget(lineLastDate);

        ButFermer = new QPushButton(ListModifsDialog);
        ButFermer->setObjectName(QString::fromUtf8("ButFermer"));
        ButFermer->setGeometry(QRect(220, 350, 87, 26));
        ButFermer->setCursor(QCursor(Qt::PointingHandCursor));

        retranslateUi(ListModifsDialog);

        QMetaObject::connectSlotsByName(ListModifsDialog);
    } // setupUi

    void retranslateUi(QDialog *ListModifsDialog)
    {
        ListModifsDialog->setWindowTitle(QCoreApplication::translate("ListModifsDialog", "Liste des modifications des contacts", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ListModifsDialog", "Liste des modifications de la liste de contacts", nullptr));
        label->setText(QCoreApplication::translate("ListModifsDialog", "Date de la derniere suppression:", nullptr));
        ButFermer->setText(QCoreApplication::translate("ListModifsDialog", "Fermer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListModifsDialog: public Ui_ListModifsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTMODIFSDIALOG_H
