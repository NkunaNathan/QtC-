#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "companylist.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void clearWidgets();

    void on_profitradioButton_clicked();

    void on_nonProfitRadioButton_clicked();

    void on_addCompanies_clicked();

    void on_leftDisplay();

    void displayCompanyData();

    void on_rightDisplay();

    void loadProfitListRead();

    void loadNonProfitListRead();


private:
    Ui::MainWindow *ui;
    CompanyList list;

};

#endif // MAINWINDOW_H
