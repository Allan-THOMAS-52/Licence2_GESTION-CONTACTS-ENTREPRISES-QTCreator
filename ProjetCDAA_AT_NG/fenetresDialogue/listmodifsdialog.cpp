#include "listmodifsdialog.hpp"
#include "ui_listmodifsdialog.h"

ListModifsDialog::ListModifsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListModifsDialog)
{
    ui->setupUi(this);
}

ListModifsDialog::~ListModifsDialog(){
    delete ui;
}

Ui::ListModifsDialog* ListModifsDialog::getUi() const{return ui;}

void ListModifsDialog::on_ButFermer_clicked(){
    close();
}

