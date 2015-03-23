#include "includes/window.h"
//#include "includes/renderarea.h"
#include <QtWidgets>

const int idRole = Qt::UserRole;

Window::Window()
{
    renderArea = new RenderArea;
    eqLbl = new QLabel();
    reLbl = new QLabel();
    valueLine = new QLineEdit();
    resultLine = new QLineEdit();
    starBtn = new QPushButton();
    cleanBtn = new QPushButton();
    
    QRegExp rx("[0-9][\\*\\/\\+\\-][0-9]");
    valueLine->setValidator(new QRegExpValidator(rx));

    eqLbl->setText("String:");
    eqLbl->setBuddy(valueLine);
    reLbl->setText("Result:");
    reLbl->setBuddy(resultLine);
    starBtn->setText("Start");
    cleanBtn->setText("Stop and Clean");

    resultLine->setDisabled(1);

    QVBoxLayout * mainLayout = new QVBoxLayout;
    QHBoxLayout * bottonLayout = new QHBoxLayout;
    QVBoxLayout * firstLayout = new QVBoxLayout;
    mainLayout->addWidget(renderArea);
    firstLayout->addWidget(eqLbl);
    firstLayout->addWidget(valueLine);
    firstLayout->addWidget(reLbl);
    firstLayout->addWidget(resultLine);
    bottonLayout->addLayout(firstLayout);
    bottonLayout->addWidget(starBtn);
    bottonLayout->addWidget(cleanBtn);
    mainLayout->addLayout(bottonLayout);
    setLayout(mainLayout);

    setWindowTitle("Post Machinbe");
}

void Window::alterResult(const QString textResult)
{
    resultLine->setText(textResult);
}

void Window::clickStartMachine()
{

}

void Window::clickAllStop()
{
    alterResult("aabb");
}

