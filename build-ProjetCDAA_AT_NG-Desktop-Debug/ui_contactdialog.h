/********************************************************************************
** Form generated from reading UI file 'ajoutcontactdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTDIALOG_H
#define UI_CONTACTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContactDialog{

public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLineEdit *lineNomD;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *linePrenomD;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *lineEntreD;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineMailD;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *lineTelD;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLineEdit *linePhotoD;

    void setupUi(QDialog *ContactDialog)
    {
        if (ContactDialog->objectName().isEmpty())
            ContactDialog->setObjectName(QString::fromUtf8("AjoutContactDialog"));
        ContactDialog->resize(691, 356);
        buttonBox = new QDialogButtonBox(ContactDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(270, 320, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(ContactDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 671, 301));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        groupBox->setFont(font);
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 30, 651, 261));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label);

        lineNomD = new QLineEdit(verticalLayoutWidget);
        lineNomD->setObjectName(QString::fromUtf8("lineNomD"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineNomD->sizePolicy().hasHeightForWidth());
        lineNomD->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(lineNomD);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_2);

        linePrenomD = new QLineEdit(verticalLayoutWidget);
        linePrenomD->setObjectName(QString::fromUtf8("linePrenomD"));
        sizePolicy.setHeightForWidth(linePrenomD->sizePolicy().hasHeightForWidth());
        linePrenomD->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(linePrenomD);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_3);

        lineEntreD = new QLineEdit(verticalLayoutWidget);
        lineEntreD->setObjectName(QString::fromUtf8("lineEntreD"));
        sizePolicy.setHeightForWidth(lineEntreD->sizePolicy().hasHeightForWidth());
        lineEntreD->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(lineEntreD);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_4);

        lineMailD = new QLineEdit(verticalLayoutWidget);
        lineMailD->setObjectName(QString::fromUtf8("lineMailD"));
        sizePolicy.setHeightForWidth(lineMailD->sizePolicy().hasHeightForWidth());
        lineMailD->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(lineMailD);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_5);

        lineTelD = new QLineEdit(verticalLayoutWidget);
        lineTelD->setObjectName(QString::fromUtf8("lineTelD"));
        sizePolicy.setHeightForWidth(lineTelD->sizePolicy().hasHeightForWidth());
        lineTelD->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineTelD);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_6);

        linePhotoD = new QLineEdit(verticalLayoutWidget);
        linePhotoD->setObjectName(QString::fromUtf8("linePhotoD"));
        sizePolicy.setHeightForWidth(linePhotoD->sizePolicy().hasHeightForWidth());
        linePhotoD->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(linePhotoD);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ContactDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ContactDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ContactDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ContactDialog);
    } // setupUi

    void retranslateUi(QDialog *AjoutContactDialog)
    {
        AjoutContactDialog->setWindowTitle(QCoreApplication::translate("AjoutContactDialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AjoutContactDialog", "Creation de contact", nullptr));
        label->setText(QCoreApplication::translate("AjoutContactDialog", "Nom :", nullptr));
        label_2->setText(QCoreApplication::translate("AjoutContactDialog", "Prenom :", nullptr));
        label_3->setText(QCoreApplication::translate("AjoutContactDialog", "Entreprise :", nullptr));
        label_4->setText(QCoreApplication::translate("AjoutContactDialog", "Mail :", nullptr));
        label_5->setText(QCoreApplication::translate("AjoutContactDialog", "Telephone :", nullptr));
        label_6->setText(QCoreApplication::translate("AjoutContactDialog", "URL photo :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ContactDialog: public Ui_ContactDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTCONTACTDIALOG_H
