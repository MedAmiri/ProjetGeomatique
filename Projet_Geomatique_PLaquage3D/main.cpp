#include "interface.h"
#include "objet.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    interface w;
    w.setWindowTitle(" ");
    w.show();

    return a.exec();
}
