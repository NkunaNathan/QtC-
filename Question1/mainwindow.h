#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "profit.h"
#include "nonprofit.h"
#include "company.h"
#include "companylist.h"
#include<QtAlgorithms>
#include<QList>

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
    void on_windowDisplay();

    void clearWidgets();

    void on_profitRadio_clicked();

    void on_nonprofitRadio_clicked();

    void on_addCompanies_clicked();

//    void on_numemployees_clicked();
private:
    Ui::MainWindow *ui;
    CompanyList list;
};

#endif // MAINWINDOW_H
