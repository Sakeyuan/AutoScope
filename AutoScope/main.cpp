#include "autoscope.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    qRegisterMetaType<ProjectNode>("ProjectNode");

    QApplication a(argc, argv);
    AutoScope w;
    w.show();
    return a.exec();
}
