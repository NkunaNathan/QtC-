#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include "profit.h"
#include "nonprofit.h"

#include "companywriter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    loadProfitListRead ();
    loadNonProfitListRead ();

}

void MainWindow::clearWidgets (){
    ui->namelineEdit->clear ();
    ui->dateEdit->setDate (QDate::currentDate ());
    ui->employeesSpinBox->setValue (0);
    ui->charitableBox->setChecked (false);
    ui->namelineEdit->setFocus ();
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_profitradioButton_clicked()
{
    ui->charitableBox->setDisabled (true);
}

void MainWindow::on_nonProfitRadioButton_clicked()
{
    ui->charitableBox->setEnabled (true);
}

void MainWindow::on_leftDisplay (){
    ui->profitDisplayBox->clear ();
    CompanyWriter pOut(list.getProfitList ());
    QStringList pList = pOut.displayDataL ();
    foreach (QString pSt, pList) {
        ui->profitDisplayBox->append (pSt);
    }
}

void MainWindow::displayCompanyData (){
    if(ui->profitradioButton->isChecked ()){
        on_leftDisplay ();
    }else
        on_rightDisplay ();
}
void MainWindow::on_rightDisplay (){
    ui->npDisplayBox->clear ();
    CompanyWriter npOut(list.getNonProfitList ());
    QStringList npList = npOut.displayDataR ();
    foreach (QString npSt, npList) {
        ui->npDisplayBox->append (npSt);
    }
}


void MainWindow::on_addCompanies_clicked()
{
    if(ui->profitradioButton->isChecked ()){
        //Profit *profit = new Profit;
        QString name = ui->namelineEdit->text ().toCaseFolded ();
        if(name.isEmpty ()){
            QMessageBox::information (0, "Warning", "Company Name can not be empty");
        }else{
            QDate date = ui->dateEdit->date ();
            int employees = ui->employeesSpinBox->value ();
            Profit * profit = new Profit(name, date, employees);
            list.addCompany (profit);
        }
        displayCompanyData ();
//        on_rightDisplay ();
        clearWidgets ();

    }else if(ui->nonProfitRadioButton->isChecked ()){
//        NonProfit *nonprofit = new NonProfit;
        QString name = ui->namelineEdit->text ().toCaseFolded ();
        if(name.isEmpty ()){
            QMessageBox::information (0, "Warning", "Company Name can not be empty");
        }else{
            QDate date = ui->dateEdit->date ();
            int employees  = ui->employeesSpinBox->value ();
            bool charitable = ui->charitableBox->isChecked ();
            NonProfit *nonprofit = new NonProfit(name, date, employees, charitable);
            list.addCompany (nonprofit);
        }
        displayCompanyData ();
//        on_leftDisplay ();
        clearWidgets ();

    }else{
        QMessageBox::information (0, "Warning", "Select company type to proceed");
        return;
    }
}


void MainWindow::loadProfitListRead (){
    QFile pFile("profit.txt");
    if(!pFile.open (QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&pFile);
    while(!in.atEnd ()){
        QString line = in.readLine ();
        ui->profitDisplayBox->append (line);
//        process_line(line);
    }
    pFile.close ();
}

void MainWindow::loadNonProfitListRead (){
    QFile npFile("nonprofit.txt");
    if(!npFile.open (QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&npFile);
    while(!in.atEnd ()){
        QString line = in.readLine ();
        ui->npDisplayBox->append (line);
    }
    npFile.close ();
}
