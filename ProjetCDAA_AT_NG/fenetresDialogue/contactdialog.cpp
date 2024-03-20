#include "contactdialog.hpp"
#include "ui_contactdialog.h"

ContactDialog::ContactDialog(QWidget *parent):QDialog(parent),
    ui(new Ui::ContactDialog){

    ui->setupUi(this);

}

ContactDialog::~ContactDialog(){
    delete ui;
}

Ui::ContactDialog* ContactDialog::getUI() const{
    return ui;
}
