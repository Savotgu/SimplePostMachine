#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <includes/postlogic.h>
#include <QWidget>
#include <QTimer>
#include <QtWidgets>
#include <typeinfo>

class PostLogic;
namespace Ui {
class mainWindow;
}

class mainWindow : public QWidget
{
    Q_OBJECT

public slots:
    void clean();
    void start();
    void print();
    /*void completo(QString str);//
signals:
    void completou(QString str);*/

public:
    void mainFunction(QString qText);
    void onfBtn();
    void printText(auto qText);
    void printNewLine(auto qText);
    explicit mainWindow(QWidget *parent = 0);
    ~mainWindow();

private:
    QList<std::string> lista;
    QTimer *timer;
    PostLogic nLogic;
    Ui::mainWindow *ui;
    QString text;
};

#endif // MAINWINDOW_H
