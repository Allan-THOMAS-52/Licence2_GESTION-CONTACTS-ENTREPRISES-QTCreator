#ifndef LISTMODIFSDIALOG_HPP
#define LISTMODIFSDIALOG_HPP

#include <QDialog>

namespace Ui {
class ListModifsDialog;
}

class ListModifsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ListModifsDialog(QWidget *parent = nullptr);
    ~ListModifsDialog();

    Ui::ListModifsDialog* getUi() const;

private slots:
    void on_ButFermer_clicked();

private:
    Ui::ListModifsDialog* ui;
};

#endif // LISTMODIFSDIALOG_HPP
