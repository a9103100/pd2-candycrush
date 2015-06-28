#include "game.h"
#include "ui_game.h"
#include <QDebug>
#include <QLabel>

game::game(QMainWindow *parent,result *r) :
    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);

    srand(time(NULL));
    for(int i=0;i<10;i++){
        for(int j=0;j<8;j++){
             c[i][j]=randomcandy(i,j); 
             connect(c[i][j],SIGNAL(send(int,int)),this,SLOT(gain(int,int)));
        }
    }
    setstart();
    count=0;
    movenum=25;
    star=0;
    score=0;
    ui->move->display(movenum);
    ui->score->display(score);

}



game::~game()
{
    emit quit(star,score);
    delete ui;
}

candy *game::randomcandy(int row, int col)
{
    candy *p;
    int temp;
    temp=(rand()%4)+1;
    p=new candy(this,temp,row,col);
    return p;
}

void game::checkstart()
{
    int i, j;
    for(i=0;i<10;i++){
        for(j=0;j<6;j++){
            if(c[i][j]->type!=0){
                if(c[i][j]->type==c[i][j+1]->type&&c[i][j]->type==c[i][j+2]->type)
                    c[i][j]->type=0;
            }
        }
    }  //向右檢查
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(c[i][j]->type!=0){
                if(c[i][j]->type==c[i+1][j]->type&&c[i][j]->type==c[i+2][j]->type)
                    c[i][j]->type=0;
            }
        }
    }  //向下檢查
}//檢查一開始還有沒有空格

void game::givecandy()
{
    int i, j;
    for(i=0;i<10;i++){
        for(j=0;j<8;j++){
            if(c[i][j]->type==0){
                c[i][j]->type=(rand()%4)+1;
                c[i][j]->setboard(c[i][j]->type);
            }
        }
    }
}//若初始版面有空格，給新糖果

void game::setstart()
{
    int num;
    do{
        num=0;
        checkstart();
        for(int i=0;i<10;i++){
            for(int j=0;j<8;j++){
                if(c[i][j]->type==0)
                    num++;
            }
        }
        givecandy();
    }
    while(num>0);
}//初始版面

void game::gain(int row, int col)
{
    //c[row][col]->button->setStyleSheet("background-color: rgb(205, 201, 201);");
    //qDebug()<<(col)<<(row);
    count=count+1;
    if(count==2){
        if((row==tmpr+1&&col==tmpc)||(row==tmpr-1&&col==tmpc)){
            //qDebug()<<(count)<<(c[row][col]->type);
            c[tmpr][tmpc]->type=c[row][col]->type;
            c[row][col]->type=tmp;
            c[row][col]->setboard(c[row][col]->type);
            c[tmpr][tmpc]->setboard(c[tmpr][tmpc]->type);
            count=0;
            /*qDebug()<<"換後"<<(c[row][col]->type);
            qDebug()<<"x"<<(col)<<"y"<<(row);
            qDebug()<<"換後"<<(c[tmpr][tmpc]->type);
            qDebug()<<"x"<<(tmpc)<<"y"<<(tmpr);*/
            resettagsty();
            judge();
            eliminate();
            if(checktag()==0&&ball(row,col)!=1&&ball(tmpr,tmpc)!=1){
                c[row][col]->type=c[tmpr][tmpc]->type;
                c[tmpr][tmpc]->type=tmp;
                c[row][col]->setboard(c[row][col]->type);
                c[tmpr][tmpc]->setboard(c[tmpr][tmpc]->type);
            }
            else if(checktag()>0&&ball(row,col)!=1&&ball(tmpr,tmpc)!=1){

                removecandy();
                movenum=movenum-1;
            }
            else if(ball(row,col)==1){
                for(int i=0;i<10;i++){
                    for(int j=0;j<8;j++){
                        if(i!=tmpr&&j!=tmpc){
                        if(c[i][j]->type%10==c[tmpr][tmpc]->type%10){
                            c[i][j]->type=0;

                            score=score+5;
                        }
                        }
                    }
                }
                c[row][col]->type=0;

                score=score+10;
                movenum=movenum-1;
            }
            else if(ball(tmpr,tmpc)==1){
                for(int i=0;i<10;i++){
                    for(int j=0;j<8;j++){
                        if(i!=row&&j!=col){
                        if(c[i][j]->type==c[row][col]->type){
                            c[i][j]->type=0;

                            score=score+5;
                        }
                        }
                    }
                }
                c[tmpr][tmpc]->type=0;

                score=score+5;
                movenum=movenum-1;
            }
        }
        else if((col==tmpc+1&&row==tmpr)||(col==tmpc-1&&row==tmpr)){
            //qDebug()<<(count)<<(c[row][col]->type);
            c[tmpr][tmpc]->type=c[row][col]->type;
            c[row][col]->type=tmp;
            c[row][col]->setboard(c[row][col]->type);
            c[tmpr][tmpc]->setboard(c[tmpr][tmpc]->type);
            count=0;
            /*qDebug()<<"換後"<<(c[row][col]->type);
            qDebug()<<"x"<<(col)<<"y"<<(row);
            qDebug()<<"換後"<<(c[tmpr][tmpc]->type);
            qDebug()<<"x"<<(tmpc)<<"y"<<(tmpr);*/
            resettagsty();
            judge();
            eliminate();
            if(checktag()==0&&ball(row,col)!=1&&ball(tmpr,tmpc)!=1){
                c[row][col]->type=c[tmpr][tmpc]->type;
                c[tmpr][tmpc]->type=tmp;
                c[row][col]->setboard(c[row][col]->type);
                c[tmpr][tmpc]->setboard(c[tmpr][tmpc]->type);
            }
            else if(checktag()>0&&ball(row,col)!=1&&ball(tmpr,tmpc)!=1){
                removecandy();
                movenum=movenum-1;
            }
            else if(ball(row,col)==1){
                for(int i=0;i<10;i++){
                    for(int j=0;j<8;j++){
                        if(i!=tmpr&&j!=tmpc){
                        if(c[i][j]->type%10==c[tmpr][tmpc]->type%10){
                            c[i][j]->type=0;

                            score=score+5;
                        }
                        }
                    }
                }
                 c[row][col]->type=0;

                 score=score+10;
                 movenum=movenum-1;
            }
            else if(ball(tmpr,tmpc)==1){
                for(int i=0;i<10;i++){
                    for(int j=0;j<8;j++){
                        if(i!=row&&j!=col){
                        if(c[i][j]->type==c[row][col]->type){
                            c[i][j]->type=0;

                            score=score+5;
                        }
                        }
                    }
                }
                c[tmpr][tmpc]->type=0;

                score=score+10;
                movenum=movenum-1;
            }
        }
        else{
            count=1;
        }
    }
    if(count==1){
        tmp=c[row][col]->type;
        tmpr=row;
        tmpc=col;
        //qDebug()<<(count)<<(c[row][col]->type);
    }
    all();
    if(movenum<0){
        ui->move->display(0);

    }
    if(movenum>-1){
        ui->move->display(movenum);
    }
    ui->score->display(score);
    if(score>2000){
        ui->star1->setPixmap(QPixmap(":/picture/0.png"));
    }
    if(score>3000){
        ui->star2->setPixmap(QPixmap(":/picture/0.png"));
    }
    if(score>3500){
        ui->star3->setPixmap(QPixmap(":/picture/0.png"));
    }
    if(movenum<1){
        if(score>2000&&score<3001){
            star=1;
        }
        if(score>3000&&score<3501){
            star=2;
        }
        if(score>3500){
            star=3;
        }
        QLabel *label=new QLabel ("", 0);
            label->setGeometry( 400, 400, 500, 500 );
            label->setPixmap(QPixmap(":/picture/7.jpg"));
            label->setScaledContents(true);
            label->show();
       emit quit(star,score);
    }

}//左右交換

void game::resettagsty()
{
    for(int i=0;i<10;i++){
        for(int j=0;j<8;j++){
            tag[i][j][0]=0; //橫的
            tag[i][j][1]=0; //直的
            sty[i][j][0]=0;
            sty[i][j][1]=0;
        }
    }
}//歸零

int game::ball(int row,int col)
{
    if(c[row][col]->type==5){
        return 1;
    }
    else{
        return -1;
    }
}



int game::checktag(){
    int c=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<8;j++){
            for(int k=0;k<2;k++){
                if(tag[i][j][k]==1)
                    c=c+1;
            }
        }
    }
    return c;
}//看交換時要不要換回來

void game::judge()
{
    int i,j;
    int p=0;
    int q=0;
    for(i=0;i<10;i++){
        for(j=0;j<6;j++){
            if((c[i][j]->type)%10==(c[i][j+1]->type)%10&&(c[i][j]->type)%10==(c[i][j+2]->type)%10){
               tag[i][j][0]=1;
               tag[i][j+1][0]=1;
               tag[i][j+2][0]=1;
                p=j+2;
               do{
                    if(c[i][j]->type%10==c[i][p]->type%10){
                      tag[i][p][0]=1;
                      p=p+1;
                    }
               }
               while(p<8&&c[i][j]->type%10==c[i][p]->type%10);
            }
        }
    }//判斷紀錄同種顏色的可消除糖果(橫)

    /*for(i=0;i<10;i++){
        qDebug()<<(tag[i][0][0])<<(tag[i][1][0])<<(tag[i][2][0])<<(tag[i][3][0])<<(tag[i][4][0])<<(tag[i][5][0])<<(tag[i][6][0])<<(tag[i][7][0]);
    }
    qDebug()<<"";*/

    for(j=0;j<8;j++){
        for(i=0;i<8;i++){
            if(c[i][j]->type%10==c[i+1][j]->type%10&&c[i][j]->type%10==c[i+2][j]->type%10){
               tag[i][j][1]=1;
               tag[i+1][j][1]=1;
               tag[i+2][j][1]=1;
               q=i+2;
               do{
                    if(c[i][j]->type%10==c[q][j]->type%10){
                      tag[q][j][1]=1;
                      q=q+1;
                    }
                 }
               while(q<10&&c[i][j]->type%10==c[q][j]->type%10);
            }
        }
    }//判斷同種顏色的可消除糖果(直的)

    /*for(i=0;i<10;i++){
        qDebug()<<(tag[i][0][1])<<(tag[i][1][1])<<(tag[i][2][1])<<(tag[i][3][1])<<(tag[i][4][1])<<(tag[i][5][1])<<(tag[i][6][1])<<(tag[i][7][1]);
    }*/
}//紀錄可消去糖果

void game::eliminate()
{
    int have[3];
    int k=0;
    for(int i=0;i<3;i++){
        have[i]=1;
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<7;j++){
            if(tag[i][j][0]==1&&c[i][j]->type%10==c[i][j+1]->type%10){
                have[k]=have[k]+1;
            }
            if(tag[i][j][0]==1&&c[i][j]->type%10!=c[i][j+1]->type%10){
                sty[i][j][0]=have[k];
                have[k]=1;
                k=k+1;
            }
            if(j==6&&tag[i][j][0]==1&&c[i][j]->type%10==c[i][j+1]->type%10){
                sty[i][j+1][0]=have[k];
                have[k]=1;
            }
        }
        k=0;
    }//橫的判斷有幾個相鄰
    for(int j=0;j<8;j++){
        for(int i=0;i<9;i++){
            if(tag[i][j][1]==1&&c[i][j]->type%10==c[i+1][j]->type%10){
                have[k]=have[k]+1;
            }
            if(tag[i][j][1]==1&&c[i][j]->type%10!=c[i+1][j]->type%10){
                sty[i][j][1]=have[k];
                have[k]=1;
                k=k+1;
            }
            if(i==8&&tag[i][j][1]==1&&c[i][j]->type%10==c[i+1][j]->type%10){
                sty[i+1][j][1]=have[k];
                have[k]=1;
            }
            k=0;
        }
    }//直的判斷有幾個相鄰
    for(int i=0;i<10;i++){
        for(int j=0;j<8;j++){
            if(i>0&&i<9){
                if((tag[i][j][0]==1&&tag[i][j][1]==1&&c[i][j]->type%10==c[i+1][j]->type%10)||(tag[i][j][0]==1&&tag[i][j][1]==1&&c[i][j]->type%10==c[i-1][j]->type%10)){
                    if(sty[i][j][0]<5&&sty[i][j][1]<5){
                        sty[i][j][0]=10;
                        sty[i][j][1]=10;
                    }//不是球的話，就是炸彈
                }
            }
            if(i==0){
                if(tag[i][j][0]==1&&tag[i][j][1]==1&&c[i][j]->type%10==c[i+1][j]->type%10){
                    if(sty[i][j][0]<5&&sty[i][j][1]<5){
                        sty[i][j][0]=10;
                        sty[i][j][1]=10;
                    }
                }
            }
            if(i==9){
                if(tag[i][j][0]==1&&tag[i][j][1]==1&&c[i][j]->type%10==c[i-1][j]->type%10){
                    if(sty[i][j][0]<5&&sty[i][j][1]<5){
                        sty[i][j][0]=10;
                        sty[i][j][1]=10;
                    }
                }
            }
        }
    }
    /*for(int i=0;i<10;i++){
        qDebug()<<(sty[i][0][0])<<(sty[i][1][0])<<(sty[i][2][0])<<(sty[i][3][0])<<(sty[i][4][0])<<(sty[i][5][0])<<(sty[i][6][0])<<(sty[i][7][0])<<" "<<(sty[i][0][1])<<(sty[i][1][1])<<(sty[i][2][1])<<(sty[i][3][1])<<(sty[i][4][1])<<(sty[i][5][1])<<(sty[i][6][1])<<(sty[i][7][1]);
    }
    qDebug()<<"";*/
}//判斷各類型糖果與可消去的糖果

void game::removecandy()
{
    for(int i=0;i<10;i++){
        for(int j=0;j<8;j++){
            if(c[i][j]->type!=0){
            if((tag[i][j][0]==1&&(sty[i][j][0]==0||sty[i][j][0]==3))||(tag[i][j][1]==1&&(sty[i][j][1]==0||sty[i][j][1]==3))){
                special(i,j,0);

                score=score+5;
            }
            else if(sty[i][j][0]==4){
                //c[i][j]->type=c[i][j]->type+20;
                //c[i][j]->setboard(c[i][j]->type);
                special(i,j,c[i][j]->type+20);
            }
            else if(sty[i][j][1]==4){
                //c[i][j]->type=c[i][j]->type+10;
                //c[i][j]->setboard(c[i][j]->type);
                special(i,j,c[i][j]->type+10);
            }
            else if(sty[i][j][0]>4&&sty[i][j][0]!=10){
                //c[i][j]->type=5;
                //c[i][j]->setboard(c[i][j]->type);
                special(i,j,5);
            }
            else if(sty[i][j][1]>4&&sty[i][j][1]!=10){
                //c[i][j]->type=5;
                //c[i][j]->setboard(c[i][j]->type);
                special(i,j,5);
            }
            else if(sty[i][j][0]==10||sty[i][j][1]==10){
                //c[i][j]->type=c[i][j]->type+30;
                //c[i][j]->setboard(c[i][j]->type);
                special(i,j,c[i][j]->type+30);
            }
            }

        }
    }
}//消掉糖果或形成特殊糖果

void game::move()
{
    num=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<8;j++){
            if(c[i][j]->type==0)
                num=num+1;
        }
    }
}//檢測是否還有空位

void game::movedown()
{
    for(int j=0;j<8;j++){
        if(c[0][j]->type==0){
            c[0][j]->type=rand()%4+1;
            c[0][j]->setboard(c[0][j]->type);
        }
    }
    for(int j=0;j<8;j++){
        for(int i=1;i<10;i++){
            if(c[i][j]->type==0){
                if(c[i-1][j]->type!=0){
                    c[i][j]->type=c[i-1][j]->type;
                    c[i-1][j]->type=0;
                    c[i][j]->setboard(c[i][j]->type);
                    c[i-1][j]->setboard(c[i-1][j]->type);
                }
            }
        }
    }
}//移下來並在第一列產生新糖果

void game::all()
{
    do{
        movedown();
        resettagsty();
        judge();
        eliminate();
        removecandy();
        move();
    }
    while(num!=0);

    /*for(int i=0;i<10;i++){
        qDebug()<<(c[i][0]->type)<<(c[i][1]->type)<<(c[i][2]->type)<<(c[i][3]->type)<<(c[i][4]->type)<<(c[i][5]->type)<<(c[i][6]->type)<<(c[i][7]->type);
    }
    qDebug()<<"";*/
}//執行掉下來所有動作

void game::special(int row, int col,int a)
{
    /*explode *sh;
    explode *sp;
    explode *w;
    sh=new stripedh;
    sp=new stripedp;
    w=new wrapped;*/
    if((c[row][col]->type/10)==1){
        //sp->explosion(row,col,c);
        vertical(row,col);
    }
    else if((c[row][col]->type/10)==2){
        //sh->explosion(row,col,c);
        horizontal(row,col);
    }
    else if((c[row][col]->type/10)==3){
        //w->explosion(row,col,c);
        bomb(row,col);
        score=score+50;
    }
    else if((c[row][col]->type/10)==0){
        c[row][col]->type=a;
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<8;j++){
            c[i][j]->setboard(c[i][j]->type);
        }
    }
}

void game::bomb(int row, int col)
{
    int L, R, U, D;
    L=col-1;
    R=col+1;
    U=row-1;
    D=row+1;
    if(L<0){L=col;}
    if(R>7){R=col;}
    if(U<0){U=row;}
    if(D>9){D=row;}
    c[row][col]->type=0;

    if(c[U][L]->type/10==1){
        vertical(U,L);
    }
    if(c[U][L]->type/10==2){
        horizontal(U,L);
    }
    if(c[U][L]->type/10==3){
        bomb(U,L);
    }
    if(c[U][L]->type/10==0)
        {c[U][L]->type=0;}


    if(c[U][col]->type/10==1){
        vertical(U,col);
    }
    if(c[U][col]->type/10==2){
        horizontal(U,col);
    }
    if(c[U][col]->type/10==3){
        bomb(U,col);
    }
    if(c[U][col]->type/10==0){
        c[U][col]->type=0;
    }

    if(c[U][R]->type/10==1){
        vertical(U,R);
    }
    if(c[U][R]->type/10==2){
        horizontal(U,R);
    }
    if(c[U][R]->type/10==3){
        bomb(U,R);
    }
    if(c[U][R]->type/10==0){
        c[U][R]->type=0;
    }

    if(c[row][L]->type/10==1){
        vertical(row,L);
    }
    if(c[row][L]->type/10==2){
        horizontal(row,L);
    }
    if(c[row][L]->type/10==3){
        bomb(row,L);
    }
    if(c[row][L]->type/10==0){
        c[row][L]->type=0;
    }

    if(c[row][R]->type/10==1){
        vertical(row,R);
    }
    if(c[row][R]->type/10==2){
        horizontal(row,R);
    }
    if(c[row][R]->type/10==3){
        bomb(row,R);
    }
    if(c[row][R]->type/10==0){
        c[row][R]->type=0;
    }

    if(c[D][L]->type/10==1){
        vertical(D,L);
    }
    if(c[D][L]->type/10==2){
        horizontal(D,L);
    }
    if(c[D][L]->type/10==3){
        bomb(D,L);
    }
    if(c[D][L]->type/10==0){
        c[D][L]->type=0;
    }

    if(c[D][col]->type/10==1){
        vertical(D,col);
    }
    if(c[D][col]->type/10==2){
        horizontal(D,col);
    }
    if(c[D][col]->type/10==3){
        bomb(D,col);
    }
    if(c[D][col]->type/10==0){
        c[D][col]->type=0;
    }

    if(c[D][R]->type/10==1){
        vertical(D,R);
    }
    if(c[D][R]->type/10==2){
        horizontal(D,R);
    }
    if(c[D][R]->type/10==3){
        bomb(D,R);
    }
    if(c[D][R]->type/10==0){
        c[D][R]->type=0;
    }
}

void game::vertical(int row, int col)
{
    c[row][col]->type=0;
    for(int i=0;i<10;i++){
        if(c[i][col]->type/10==1){
            vertical(i,col);
        }
        if(c[i][col]->type/10==2){
            horizontal(i,col);
        }
        if(c[i][col]->type/10==3){
            bomb(i,col);
        }
        if(c[i][col]->type/10==0){
           c[i][col]->type=0;
        }
        score=score+5;
    }
}

void game::horizontal(int row, int col)
{
    c[row][col]->type=0;
    for(int i=0;i<8;i++){
        if(c[row][i]->type/10==1){
            vertical(row,i);
        }
        if(c[row][i]->type/10==2){
            horizontal(row,i);
        }
        if(c[row][i]->type/10==3){
            bomb(row,i);
        }
        if(c[row][i]->type/10==0){
           c[row][i]->type=0;
        }

        score=score+5;
    }
}

void game::on_restart_clicked()
{
    for(int i=0;i<10;i++){
        for(int j=0;j<8;j++){
            c[i][j]->type=0;
        }
    }
    setstart();
    count=0;
    movenum=25;
    score=0;
    star=0;
    ui->move->display(movenum);
    ui->score->display(score);
}
