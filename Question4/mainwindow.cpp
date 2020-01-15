#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QString>

#include <QFileDialog>
#include <QFile>

#include <QTextStream>
#include <QTextCursor>

#include <QMessageBox>
#include <QDate>

//static variable
QRegExp MainWindow::dateExp("(\\d(\\s+|\\.|-|/)\\w{3}(\\s+|\\.|-|/)\\d{4})|(\\d(\\s+|\\.|-|/)\\w+(\\s+|\\.|-|/)\\d{4})|(\\d{2}(\\s+|\\.|-|/)\\d{2}(\\s+|\\.|-|/)\\d{4})|(\\d{4}(\\s+|\\.|-|/)\\d{2}(\\s+|\\.|-|/)\\d{2})");
//("(\\d\\s+\\w{3}\\s+(\\d\\d\\d\\d))"); test expression

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle ("Regular Expressions");
    dateDoc = new QTextDocument(this);
    ui->regExButton->setEnabled (false);
    ui->displayBox->clear();

    connect (ui->fileButton, SIGNAL(clicked()), this, SLOT(filePicker ()));
    connect (ui->regExButton, SIGNAL(clicked()), this,SLOT(regExEvalute()));
}

void MainWindow::filePicker (){
//    ui->displayBox->clear();
    QString pickedFile = QFileDialog::getOpenFileName (this, "Open File", "." , "Text Files (*.txt)");
    QFile dateFile(pickedFile);
    if(!dateFile.open (QIODevice::ReadOnly)){
        QMessageBox::critical (this, "Error", "Could not locate or open file", QMessageBox::Ok);
        return;
    }
    QTextStream input(&dateFile);
    while(!input.atEnd ()){
        QString line = input.readLine ();
        ui->displayBox->append (line);
    }
//    ui->regExButton->setEnabled (true);
    dateFile.close ();
    ui->regExButton->setEnabled (true);


}

void MainWindow::regExEvalute (){
//    QTextStream cout(stdout);
    dateDoc = ui->displayBox->document ();
    QTextCharFormat format;
    format.setFontItalic (true);
    format.setFontUnderline (true);
    format.setFontWeight (95);
    format.setUnderlineColor (QColor(0, 0, 255, 127));
    QTextCursor cursor(dateDoc);
    QRegularExpression re("(?<year>\\d\\d\\d\\d)");
    QRegularExpressionMatch match;
    while(!cursor.atEnd () && !cursor.isNull ()){
        cursor = dateDoc->find (dateExp, cursor);
        if(!cursor.isNull ()){
            QString word;
            cursor.movePosition (QTextCursor::WordRight, QTextCursor::KeepAnchor, dateExp.matchedLength ());
            word = cursor.selectedText ();
//            QMessageBox::information (this, "Word", QString("%1").arg (word));
            match = re.match (word);
//            QString year = match.captured ("year");
//            QMessageBox::information (this, "See year", QString("%1").arg (year));
           //does not go to below yet
            if(match.hasMatch ()){
                QString year = match.captured ("year");
//                QMessageBox::information (this, "Year", QString("%1").arg (year));
                int ycast = year.toInt ();
                if(1900<= ycast && ycast <= 2099){
//                    cout << QString("%1").arg (cursor.selectedText ()) << endl;
                    cursor.mergeCharFormat (format);
                }
            }

        }
    }
    QMessageBox::information (this, "Status", "Done checking", QMessageBox::Ok);

}

MainWindow::~MainWindow()
{
    delete ui;
}
