#include "includes/window.h"
//#include "includes/renderarea.h"
#include <QtWidgets>

const int idRole = Qt::UserRole;

Window::Window()
{
    //renderArea = new RenderArea;
    eqLbl = new QLabel();
    reLbl = new QLabel();
    valueLine = new QLineEdit();
    resultLine = new QLineEdit();
    starBtn = new QPushButton();
    cleanBtn = new QPushButton();
    
    QRegExp rx("[0-9][\\*\\/\\+\\-][0-9]");
    valueLine->setValidator(new QRegExpValidator(rx));

    QRegExp rx("([0-9])[\\*\\/\\+\\-][0-9]");
    valueLine->setValidator(new QRegExpValidator(rx));

    eqLbl->setText("String:");
    eqLbl->setBuddy(valueLine);
    reLbl->setText("Result:");
    reLbl->setBuddy(resultLine);
    starBtn->setText("Start");
    cleanBtn->setText("Stop and Clean");

    resultLine->setDisabled(1);
    
    connect(starBtn,SIGNAL(clicked()),this,SLOT(clickStartMachine()));
    connect(cleanBtn,SIGNAL(clicked()),this,SLOT(clickAllStop()));


    connect(starBtn,SIGNAL(clicked()),this,SLOT(clickStartMachine()));
    connect(cleanBtn,SIGNAL(clicked()),this,SLOT(clickAllStop()));

    QVBoxLayout * mainLayout = new QVBoxLayout;
    QHBoxLayout * bottonLayout = new QHBoxLayout;
    QVBoxLayout * firstLayout = new QVBoxLayout;
    //mainLayout->addWidget(renderArea);
    firstLayout->addWidget(eqLbl);
    firstLayout->addWidget(valueLine);
    firstLayout->addWidget(reLbl);
    firstLayout->addWidget(resultLine);
    bottonLayout->addLayout(firstLayout);
    bottonLayout->addWidget(starBtn);
    bottonLayout->addWidget(cleanBtn);
    mainLayout->addLayout(bottonLayout);
    setLayout(mainLayout);

    setWindowTitle("Post Machine");
}

void Window::alterResult(QLineEdit * lineEdit,const QString textResult)
{
    lineEdit->setText(textResult);
}

void Window::clickStartMachine()
{
    QString text;
    int x,y;
    text=valueLine->text();
    x = text.mid(0,1).toInt();
    y = text.mid(2,1).toInt();
    if(text.at(1)=='+')
        x = x+y;
    text.clear();
    text=QString::number(x);
    alterResult(resultLine,text);
}

void Window::clickAllStop()
{
    alterResult(valueLine,"");
    alterResult(resultLine,"");
}

