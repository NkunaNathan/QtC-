#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "companylist.h"
#include "profit.h"
#include "nonprofit.h"
#include "companylistreview.h"
#include<QTextBrowser>
#include<QMessageBox>
#include<QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dateCreated->setDate(QDate::currentDate());
//    ui->numEmployees->setValue (0);
}

void MainWindow::on_windowDisplay(){
    ui->textEdit->clear ();
    CompanyListReview output(list.getList ());
//    output.outputConsole ();
    QStringList strList = output.displayList ();
    foreach (QString str, strList) {
//        QMessageBox::information (0, "Results", QString("%1").arg (str));
        ui->textEdit->append (str);
    }
}
void MainWindow::clearWidgets (){
    ui->companyName->clear ();
    ui->dateCreated->setDate(QDate::currentDate());
    ui->numEmployees->setValue (0);
    ui->charityStatus->setChecked(false);
    ui->companyName->setFocus();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_profitRadio_clicked()
{
    ui->charityStatus->setDisabled (true);
}


void MainWindow::on_nonprofitRadio_clicked()
{
    ui->charityStatus->setEnabled (true);
}

void MainWindow::on_addCompanies_clicked()
{
    if(ui->profitRadio->isChecked ()){
//        QMessageBox::information (0, "Results", QString("Profit %1").arg (ui->numEmployees->value ()));
//        ui->charityStatus->setDisabled (true);
        QString name = ui->companyName->text ().toCaseFolded ();
        if(name.isEmpty ()){
            QMessageBox::information (0, "Warning", "Company Name can not be empty");
        }else{
            QDate date = ui->dateCreated->date ();
            int employees = int(ui->numEmployees->value ());
//            QMessageBox::information (0, "Results", QString("employee %1").arg (employees));
            Profit* profit = new Profit(name,date,employees);
            list.addCompany(profit);
        }
        on_windowDisplay();
        clearWidgets ();
    }
    else if(ui->nonprofitRadio->isChecked ()){
//        QMessageBox::information (0, "Results", QString("Non Profit %1").arg (ui->nonprofitRadio->isChecked ()));
//        ui->charityStatus->setEnabled (true);
        QString name = ui->companyName->text ().toCaseFolded ();
        if(name.isEmpty ()){
            QMessageBox::information (0, "Warning", "Company Name can not be empty");
        }
        else{
            QDate date = ui->dateCreated->date ();
            int employees = ui->numEmployees->value ();
            bool charitable = ui->charityStatus->isChecked ();
            NonProfit* nonProfit = new NonProfit(name, date, employees,charitable);
            list.addCompany(nonProfit);
        }
        on_windowDisplay();
        clearWidgets ();
    }
    else{
        QMessageBox::information (0, "Warning", "Select company type to proceed");
        return;
    }

}
