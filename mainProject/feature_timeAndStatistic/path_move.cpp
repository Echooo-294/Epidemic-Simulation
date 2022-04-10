#include "cstdlib"
#include <QTime>
#include <QPoint>
#include <cmath>
//产生随机数
int arand()
{
    static QTime t=QTime::currentTime();
    QTime T=QTime::currentTime();
    int i=T.msecsTo(t);
    qsrand(i);

    int randNum=qrand();
    t=T;
    return randNum;
}

QPoint movelittle(QPoint p1, QPoint p2)
{
    //获取符号
    int dX=p2.x()-p1.x()/abs(p2.x()-p1.x());
    int dY=p2.y()-p1.y()/abs(p2.y()-p1.y());

    int ratio=dY/dX;
    int x=p1.x(),y=p1.y();
    switch(arand()%7)
    {
    case 0:{//反方向
        int r=arand()%100;
        if(x>50) x=x-r*dX;
        if(x>50) y=y-r*ratio*dY;
            }
    case 1:{//一侧
        int r=arand()%100;
        x=x+r*dX;
        if(y>50) y=y-r*ratio*dY;
            }
    case 2:{//另一侧
        int r=arand()%100;
        if(x>50) x=x-r*dX;
        if(x>50) y=y+r*ratio*dY;
            }
    default:{//正方向
        int r=arand()%100;
        x=x+r*dX;
        y=x+r*ratio*dY;
            }

    }
    QPoint temp(x,y);
    return temp;
}

