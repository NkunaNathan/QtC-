#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextDocument>

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
    void filePicker();
    void regExEvalute();

private:
    Ui::MainWindow *ui;
    QTextDocument* dateDoc;
    static QRegExp dateExp;
};

#endif // MAINWINDOW_H
