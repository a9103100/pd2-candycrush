#include "candy.h"
#include <QDebug>
#include <QObject>

candy::candy(QWidget *parent, int color, int row, int col):
    R(row),C(col)
{
    button=new QPushButton(parent);
    button->setGeometry(50+col*50,100+row*50,50,50);
    //button->setText(QString::number(color));
    type=color;
    setboard(type);
    connect(button,SIGNAL(clicked()),this,SLOT(button_clicked()));
}

candy::~candy()
{
    delete button;
}


void candy::button_clicked()
{
    //qDebug()<<(C)<<(R);
    emit send(R,C);

}

void candy::setboard(int t)
{
    switch (t) {
    case 1:
        button->setIcon(QIcon(QPixmap(":/picture/candypic/Original/Blue.png")));
        button->setIconSize(button->size());
        break;
    case 2:
        button->setIcon(QIcon(QPixmap(":/picture/candypic/Original/Green.png")));
        button->setIconSize(button->size());
        break;
    case 3:
        button->setIcon(QIcon(QPixmap(":/picture/candypic/Original/Red.png")));
        button->setIconSize(button->size());
        break;
    case 4:
        button->setIcon(QIcon(QPixmap(":/picture/candypic/Original/Yellow.png")));
        button->setIconSize(button->size());
        break;
    case 5:
        button->setIcon(QIcon(QPixmap(":/picture/candypic/Colour Bomb/ColourBomb.png")));
        button->setIconSize(button->size());
        break;
    case 11:
        button->setIcon(QIcon(QPixmap(":/picture/candypic/Striped/Striped_blue_v.png")));
        button->setIconSize(button->size());
        break;
    case 12:
        button->setIcon(QIcon(QPixmap(":/picture/candypic/Striped/Striped_green_v.png")));
        button->setIconSize(button->size());
        break;
    case 13:
        button->setIcon(QIcon(QPixmap(":/picture/candypic/Striped/Striped_red_v.png")));
        button->setIconSize(button->size());
        break;
    case 14:
        button->setIcon(QIcon(QPixmap(":/picture/candypic/Striped/Striped_yellow_v.png")));
        button->setIconSize(button->size());
        break;
    case 21:
        button->setIcon(QIcon(QPixmap(":/picture/candypic/Striped/Striped_blue_h.png")));
        button->setIconSize(button->size());
        break;
    case 22:
        button->setIcon(QIcon(QPixmap(":/picture/candypic/Striped/Striped_green_h.png")));
        button->setIconSize(button->size());
        break;
    case 23:
        button->setIcon(QIcon(QPixmap(":/picture/candypic/Striped/Striped_red_h.png")));
        button->setIconSize(button->size());
        break;
    case 24:
        button->setIcon(QIcon(QPixmap(":/picture/candypic/Striped/Striped_yellow_h.png")));
        button->setIconSize(button->size());
        break;
    case 31:
        button->setIcon(QIcon(QPixmap(":/picture/candypic/Wrapped/Wrapped_blue.png")));
        button->setIconSize(button->size());
        break;
    case 32:
        button->setIcon(QIcon(QPixmap(":/picture/candypic/Wrapped/Wrapped_green.png")));
        button->setIconSize(button->size());
        break;
    case 33:
        button->setIcon(QIcon(QPixmap(":/picture/candypic/Wrapped/Wrapped_red.png")));
        button->setIconSize(button->size());
        break;
    case 34:
        button->setIcon(QIcon(QPixmap(":/picture/candypic/Wrapped/Wrapped_yellow.png")));
        button->setIconSize(button->size());
        break;
    default:
        break;
    }
}

