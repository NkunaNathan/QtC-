#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QStringListModel>
#include <QListView>
#include <QListWidget>
#include <QStringList>

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
    void on_addBook_clicked();

    void on_deleteBook_clicked();

    void on_listView_clicked();

private:
    Ui::MainWindow *ui;

    QStringListModel *model; //QStringListModel is used to store a simple list of QString items.
//    QListView *modelview; /*A QListView presents items stored
//    in a model, either as a simple non-hierarchical list, or as a collection of icons*/

};

#endif // MAINWINDOW_H
