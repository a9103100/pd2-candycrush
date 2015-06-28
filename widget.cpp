#include "widget.h"
#include "ui_widget.h"
#include <QMainWindow>
#include <QWidget>

Widget::Widget(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    gamewindow=NULL;
    resultwindow=new result(this);
}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_startgame_clicked()
{
    gamewindow=new game(this,resultwindow);
    this->setCentralWidget(gamewindow);

}
