#include "qtquerytesterwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Studiofuga");
    QCoreApplication::setOrganizationDomain("studiofuga.com");
    QCoreApplication::setApplicationName("QtXQueryTester");

    QtQueryTesterWindow w;
    w.show();
    return a.exec();
}
