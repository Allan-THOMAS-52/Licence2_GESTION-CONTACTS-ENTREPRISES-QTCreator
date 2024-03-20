#ifndef CONTACTDIALOG_HPP
#define CONTACTDIALOG_HPP

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class ContactDialog; }
QT_END_NAMESPACE

class ContactDialog : public QDialog{

    Q_OBJECT

    public:

        explicit ContactDialog(QWidget *parent = nullptr);
        ~ContactDialog();

        Ui::ContactDialog* getUI() const;

    private:

        Ui::ContactDialog *ui;

};


#endif // CONTACTDIALOG_H
