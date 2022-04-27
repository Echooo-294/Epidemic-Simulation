/*
 * @Description: 空间类的声明
 * @Author: 巾可
 * @Date: 2022-03-03
 * @Last Modified by: 巾可
 * @Last Modified time: 2022-03-26
 */

#ifndef SPACE_H
#define SPACE_H


#include <QObject>
#include <QPoint>

class Space : public QObject
{
    Q_OBJECT
public:
    explicit Space(char t,double l,double w,QString n,QPoint p);
    int getCapacity() const;
    void setCapacity(int value);//设置和获取容纳量

    double getLength() const;
    void setLength(double value);//设置和获取长度

    double getWidth() const;
    void setWidth(double value);//设置和获取宽度

    QString getName() const;
    void setName(const QString &value);//设置和获取名字

    QPoint getPosition() const;
    void setPosition(const QPoint &value);//设置和获取坐标

    bool isAccessible() const;
    void setAccessible(bool value);//设置和获取能否进入

    int getRestRoom() const;
    void restRoomDec();//剩余容量-1
    void restRoomInc();//剩余容量+1

    double getInfectionRro() const;
    void setInfectionRro(double value);//设置和获取传播概率

    int getMoveMode() const;
    void setMoveMode(int value);

    double area()const;//返回面积
    //void addResident(const Resident&);//居民进入函数，居民类可以作为参数

    char getType() const;
    void setType(char value);
private:
    char type;//建筑种类--R：居民楼；W：写字楼；H：医院；Z：隔离区；O：开发空间
    int capacity;//容量
    double length,width;//长宽
    QString name;//建筑名称
    QPoint position;//坐标
    bool accessible;//是否可进入--人满或特殊政策下不可进入
    int restRoom;//剩余容量
    double infectionRro;//传播概率--居民楼：传播概率=1；写字楼：传播概率=0.8
    //医院：即传播概率=0;隔离区：即传播概率=0;开放空间:传播概率=0.5
    int moveMode;//人的移动方式--0：不移动（比如医院和隔离区）；1：上下左右各1/4的概率随机运动；2：路上定向运动

signals:

};

#endif // SPACE_H
