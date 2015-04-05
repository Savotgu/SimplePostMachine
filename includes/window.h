#ifndef WINDOW_H
#define WINDOW_H

//#include "includes/renderarea.h"
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <string>

//class RenderArea;

class Window : public QWidget{
    Q_OBJECT
private:
    QPushButton * starBtn;
    QPushButton * cleanBtn;
    QLineEdit * valueLine;
    QLineEdit * resultLine;
    QLabel * eqLbl;
    QLabel * reLbl;
public slots:
    void clickStartMachine();
    void clickAllStop();

public:
    Window();
    void alterResult(QLineEdit *lineEdit, const QString textResult);
};

#endif // WINDOW

