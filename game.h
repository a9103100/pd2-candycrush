#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QMainwindow>
#include <QObject>
#include <time.h>
#include "result.h"
#include "candy.h"
#include "stripedh.h"
#include "stripedp.h"
#include "wrapped.h"
#include "explode.h"

namespace Ui {
class game;
}

class game : public QWidget
{
    Q_OBJECT

public:
    explicit game(QMainWindow *parent,result *r);
    ~game();
    candy *randomcandy(int row, int col);
    void checkstart();
    void givecandy();
    void setstart();

    void setboard();
    //void judgeLR(int rowL, int colL, int rowR, int colR);
    //void judgeUD(int rowL, int colL, int rowR, int colR);
    void judge();
    void resettagsty();
    void eliminate();
    int checktag();
    void removecandy();
    void movedown();
    void move();
    void all();
    void special(int row, int col, int a);
    candy *c[10][8];
    int ball(int row, int col);
    void bomb(int row, int col);
    void vertical(int row, int col);
    void horizontal(int row, int col);
public slots:
    void gain(int row, int col);
private slots:
    void on_restart_clicked();
signals:
    void quit(int star,int score);
private:
    Ui::game *ui;
    int count;  //數點擊次數
    int tmp, tmpr, tmpc; //紀錄第一次點的type跟位置
    int sty[10][8][2];  //判斷類型
    int tag[10][8][2]; //判斷可否消
    int num;  //數空格子
    int movenum;
    int score;
    int star;

};

#endif // GAME_H
