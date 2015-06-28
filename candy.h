#ifndef CANDY_H
#define CANDY_H

#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>

class candy : public QObject
{
    Q_OBJECT

public:
    candy(QWidget *parent, int color, int row, int col);
    ~candy();
    int type;
    const int R;
    const int C;
    QPushButton *button;

    void setboard(int t);
public slots:
    void button_clicked();

signals:
    void send(int r,int c);
};

#endif // CANDY_H
