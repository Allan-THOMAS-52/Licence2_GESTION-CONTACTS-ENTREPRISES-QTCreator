QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    contacts/Contact.cpp \
    contacts/gestionContact/GestionContact.cpp \
    fenetresDialogue/contactdialog.cpp \
    fenetresDialogue/listmodifsdialog.cpp \
    interactions/InterTacheAsso/InterTacheAsso.cpp \
    interactions/Interaction.cpp \
    main.cpp \
    mainwindow.cpp \
    tache/Tache.cpp

HEADERS += \
    contacts/Contact.hpp \
    contacts/gestionContact/GestionContact.hpp \
    fenetresDialogue/contactdialog.hpp \
    fenetresDialogue/listmodifsdialog.hpp \
    interactions/InterTacheAsso/InterTacheAsso.hpp \
    interactions/Interaction.hpp \
    librairies/nlohmann/json.hpp \
    librairies/nlohmann/json_fwd.hpp \
    mainwindow.hpp \
    tache/Tache.hpp \
    utils/Erreur.hpp \
    utils/JsonUtils.hpp \
    utils/sDate.hpp

FORMS += \
    fenetresDialogue/contactdialog.ui \
    fenetresDialogue/listmodifsdialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    testJSON.json
