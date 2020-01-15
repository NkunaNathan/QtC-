#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QStringList>
#include <QAbstractItemView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle ("Book Title");
    model = new QStringListModel(this);
    ui->listView->setModel (model);
    ui->listView->setEditTriggers (QAbstractItemView::AnyKeyPressed | QAbstractItemView::DoubleClicked);
//    ui->insertTitle->setFocus ();
    ui->addBook->setFocus ();
    model->sort (0);

    connect (ui->listView,SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_listView_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
//add books
void MainWindow::on_addBook_clicked()
{
    model->sort (0);
    QStringList booklist = model->stringList ();
    QString bookTitle = ui->insertTitle->text ();
    bool bookExist = false;
    foreach (QString book, booklist) {
        if(bookTitle.toLower () == book.toLower ()){
            bookExist = true;
            break;
        }
    }if(!bookTitle.isEmpty () && bookExist == false){
        int rows = model->rowCount ();
        model->insertRows (rows,1);
        QModelIndex indexvalue = model->index (rows);
        model->setData (indexvalue, ui->insertTitle->text ());
        // Enable item selection and put it edit mode
        ui->listView->setCurrentIndex(indexvalue);

        ui->listView->edit(indexvalue);
    }else{
        QMessageBox::information (this, "Warning", "Book title can't be empty  or Book title already exist");
    }
    model->sort (0);

    ui->insertTitle->clear ();
    ui->insertTitle->setFocus ();
}
// deleting books
void MainWindow::on_deleteBook_clicked()
{
//    list->currentIndex ()
    QModelIndex indexDelete = ui->listView->currentIndex ();
    QString itemBook = indexDelete.data (Qt::DisplayRole).toString ();
    if(indexDelete.isValid ()){
        int react = QMessageBox::warning (this, "Removing", QString("You\'re about to delete\n \"%1\" continue?").arg(itemBook),QMessageBox::Yes | QMessageBox::No);
        if(QMessageBox::Yes == react){
            int deleteRow = indexDelete.row ();
            model->removeRow (deleteRow);
        }else
            return;
    }else
        return;
}

//edit book in a listview
void MainWindow::on_listView_clicked (){
    // Get the position
//    int row = model->rowCount ();
    int row = ui->listView->currentIndex().row();

    QModelIndex index = model->index (row);

    // Enable item selection and put it edit mode
    ui->listView->setCurrentIndex(index);
    QString text;
    if(ui->listView->selectionModel ()->isSelected (index) == true){
        ui->listView->setEditTriggers ( QAbstractItemView::DoubleClicked);
        text = index.data (Qt::EditRole).toString ();
//        can't seem to edit data and store it before searching to find out if it exist
    }
//    QMessageBox::information (this,"Text Change",text);
}

