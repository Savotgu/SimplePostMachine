#include "includes/mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QtWidgets>
#include <QTimer>
#include <QDebug>
#include <thread>

mainWindow::mainWindow(QWidget *parent):QWidget(parent),ui(new Ui::mainWindow)
{

    ui->setupUi(this);
    ui->textOp->setFont(QFont("Arial",12));
    ui->lineOp->setFocus();
    QRegExp rx("[0-9][\\*\\/\\+\\-][0-9]");
    ui->textOp->setStyleSheet("color:black;background-color:white;");
    ui->lineResult->setStyleSheet("color:black;background-color:white;");
    ui->lineOp->setValidator(new QRegExpValidator(rx));
    connect(ui->btnClean, SIGNAL(clicked()),this,SLOT(clean()));
    connect(ui->btnStart, SIGNAL(clicked()),this,SLOT(start()));
}

void mainWindow::mainFunction(QString qText)
{
    std::string sText;
    for(int i(0);i<qText.mid(0,1).toInt();i++){
        printText("a");
        sText=sText + "a";
    }

    for(int i(0);i<qText.mid(2,1).toInt();i++){
        printText("b");
        sText=sText + "b";
    }
    printText("#\n");
    sText=sText+"#";
    if(qText.at(1)=='+')
    {
        while(sText.back()=='#')
        {
            ui->lineResult->setText(QString::number(ui->lineResult->text().toInt()+nLogic.sum(sText)));
            printNewLine(sText);
        }
    }else if(qText.at(1)=='-')
    {
        while(sText.back()=='#'){
            ui->lineResult->setText(QString::number(ui->lineResult->text().toInt()+nLogic.sub(sText)));
            printNewLine(sText);
        }
    }else if(qText.at(1)=='*')
    {
        while(sText.back()=='#')
        {
            ui->lineResult->setText(QString::number(ui->lineResult->text().toInt()+nLogic.mul(sText)));
            printNewLine(sText);
        }
    }else
    {
        while(sText.back()=='#')
        {
            ui->lineResult->setText(QString::number(ui->lineResult->text().toInt()+nLogic.div(sText)));
            printNewLine(sText);
        }
    }

}

void mainWindow::onfBtn()
{
    if(ui->btnClean->isEnabled())
    {
        ui->btnClean->setEnabled(0);
        ui->btnStart->setEnabled(0);
        ui->lineOp->setEnabled(0);
    }
    else
    {
        ui->btnClean->setEnabled(1);
        ui->btnStart->setEnabled(1);
        ui->lineOp->setEnabled(1);
    }
}

void mainWindow::clean()
{
    ui->textOp->clear();
    ui->lineOp->clear();
    ui->lineResult->clear();
}

void mainWindow::start()
{
    if(ui->lineOp->text().size()==3){
        ui->textOp->clear();
        ui->lineResult->clear();
        onfBtn();
        mainFunction(ui->lineOp->text());
        onfBtn();
    }
}

mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::printText(auto qText)
{
    ui->textOp->textCursor().insertText(QString::fromStdString(qText));
}

void mainWindow::printNewLine(auto qText)
{
    ui->textOp->textCursor().insertText(QString::fromStdString(qText)+'\n');
}
