#include "wrapped.h"

wrapped::wrapped()
{

}

wrapped::~wrapped()
{

}

void wrapped::explosion(int row, int col,candy *a[10][8])
{
    /*int L, R, U, D;
    L=col-1;
    R=col+1;
    U=row-1;
    D=row+1;
    if(L<0){L=col;}
    if(R>7){R=col;}
    if(U<0){U=row;}
    if(D>9){D=row;}
    explode *e;
    a[row][col]->type=0;

    if(a[U][L]->type/10==1){
        e=new stripedp;
        e->explosion(U,L,a);
    }
    if(a[U][L]->type/10==2){
        e=new stripedh;
        e->explosion(U,L,a);
    }
    if(a[U][L]->type/10==3){
        e=new wrapped;
        e->explosion(U,L,a);
    }
    if(a[U][L]->type/10==0)
        {a[U][L]->type=0;}


    if(a[U][col]->type/10==1){
        e=new stripedp;
        e->explosion(U,L,a);
    }
    if(a[U][col]->type/10==2){
        e=new stripedh;
        e->explosion(U,L,a);
    }
    if(a[U][col]->type/10==3){
        e=new wrapped;
        e->explosion(U,L,a);
    }
    if(a[U][col]->type/10==0){
        a[U][col]->type=0;
    }

    if(a[U][R]->type/10==1){
        e=new stripedp;
        e->explosion(U,L,a);
    }
    if(a[U][R]->type/10==2){
        e=new stripedh;
        e->explosion(U,L,a);
    }
    if(a[U][R]->type/10==3){
        e=new wrapped;
        e->explosion(U,L,a);
    }
    if(a[U][R]->type/10==0){
        a[U][R]->type=0;
    }

    if(a[row][L]->type/10==1){
        e=new stripedp;
        e->explosion(U,L,a);
    }
    if(a[row][L]->type/10==2){
        e=new stripedh;
        e->explosion(U,L,a);
    }
    if(a[row][L]->type/10==3){
        e=new wrapped;
        e->explosion(U,L,a);
    }
    if(a[row][L]->type/10==0){
        a[row][L]->type=0;
    }

    if(a[row][R]->type/10==1){
        e=new stripedp;
        e->explosion(U,L,a);
    }
    if(a[row][R]->type/10==2){
        e=new stripedh;
        e->explosion(U,L,a);
    }
    if(a[row][R]->type/10==3){
        e=new wrapped;
        e->explosion(U,L,a);
    }
    if(a[row][R]->type/10==0){
        a[row][R]->type=0;
    }

    if(a[D][L]->type/10==1){
        e=new stripedh;
        e->explosion(U,L,a);
    }
    if(a[D][L]->type/10==2){
        e=new stripedh;
        e->explosion(U,L,a);
    }
    if(a[D][L]->type/10==3){
        e=new wrapped;
        e->explosion(U,L,a);
    }
    if(a[D][L]->type/10==0){
        a[D][L]->type=0;
    }

    if(a[D][col]->type/10==1){
        e=new stripedp;
        e->explosion(U,L,a);
    }
    if(a[D][col]->type/10==2){
        e=new stripedh;
        e->explosion(U,L,a);
    }
    if(a[D][col]->type/10==3){
        e=new wrapped;
        e->explosion(U,L,a);
    }
    if(a[D][col]->type/10==0){
        a[D][col]->type=0;
    }

    if(a[D][R]->type/10==1){
        e=new stripedp;
        e->explosion(U,L,a);
    }
    if(a[D][R]->type/10==2){
        e=new stripedh;
        e->explosion(U,L,a);
    }
    if(ac[D][R]->type/10==3){
        e=new wrapped;
        e->explosion(U,L,a);
    }
    if(a[D][R]->type/10==0){
        a[D][R]->type=0;
    }*/
}

