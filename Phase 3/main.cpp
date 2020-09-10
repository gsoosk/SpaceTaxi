#include "login.h"
#include "Functions.h"
#include <QApplication>
#include "client_socket.h"
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;


    w.show();

    return a.exec();
}
