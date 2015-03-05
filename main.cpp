#include <QApplication>

#include <view/connectionwindow.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ConnectionWindow connection;
    connection.show();

    return app.exec();
}
