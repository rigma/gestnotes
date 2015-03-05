#ifndef CONNECTIONWINDOW_H
#define CONNECTIONWINDOW_H

#include <QWidget>

namespace Ui {
class ConnectionWindow;
}

class ConnectionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectionWindow(QWidget *parent = 0);
    ~ConnectionWindow();

private:
    Ui::ConnectionWindow *_ui;
};

#endif // CONNECTIONWINDOW_H
