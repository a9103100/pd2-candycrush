#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QWidget>
#include <QObject>
#include "game.h"
#include "result.h"

namespace Ui {
class Widget;
}

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit Widget(QMainWindow *parent = 0);
    ~Widget();

private slots:

    void on_startgame_clicked();

private:
    Ui::Widget *ui;
    game *gamewindow;
    result *resultwindow;
};

#endif // WIDGET_H
