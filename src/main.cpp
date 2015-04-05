#include "includes/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    mainWindow Window;
    Window.show();
    return app.exec();
}
