/*
 * @Description: 空间类的声明
 * @Author: 巾可
 * @Date: 2022-03-03
 * @Last Modified by: 巾可
 * @Last Modified time: 2022-03-26
 */

#include "space.h"
#include <QDebug>

Space::Space(char t,double l,double w,QString n,QPoint p) : QObject(nullptr),capacity(10000),accessible(true),restRoom(10000)
{
    //初始化时默认可以进入,容量和剩余容量为10000
    setName(n);
    setType(t);
    setLength(l);
    setWidth(w);
    setPosition(p);

    switch (t) {
    //居民楼
    case 'R':{
        setMoveMode(1);
        setInfectionRro(1.0);
        qDebug()<<"R";
        break;
    }
    //写字楼
    case 'W':{
        setMoveMode(1);
        setInfectionRro(0.8);
        qDebug()<<"W";
        break;
    }
    //医院
    case 'H':{
        setMoveMode(1);
        setInfectionRro(0);
        qDebug()<<"H";
        break;
    }
    //隔离区
    case 'Z':{
        setMoveMode(0);
        setInfectionRro(0);
        qDebug()<<"Z";
        break;
    }
    //开放区域（包括道路）
    case 'O':{
        setMoveMode(2);
        setInfectionRro(0.5);
        qDebug()<<"O";
        break;
    }
    }
}

char Space::getType() const
{
    return type;
}
void Space::setType(char value)
{
    type = value;
}

int Space::getMoveMode() const
{
    return moveMode;
}
void Space::setMoveMode(int value)
{
    moveMode = value;
}

double Space::getInfectionRro() const
{
    return infectionRro;
}
void Space::setInfectionRro(double value)
{
    infectionRro = value;
}

int Space::getRestRoom() const
{
    return restRoom;
}
void Space::setRestRoom(int value)
{
    restRoom = value;
}

bool Space::isAccessible() const
{
    return accessible;
}
void Space::setAccessible(bool value)
{
    accessible = value;
}

QPoint Space::getPosition() const
{
    return position;
}
void Space::setPosition(const QPoint &value)
{
    position = value;
}

QString Space::getName() const
{
    return name;
}
void Space::setName(const QString &value)
{
    name = value;
}

double Space::getWidth() const
{
    return width;
}
void Space::setWidth(double value)
{
    width = value;
}

double Space::getLength() const
{
    return length;
}
void Space::setLength(double value)
{
    length = value;
}

int Space::getCapacity() const
{
    return capacity;
}
void Space::setCapacity(int value)
{
    capacity = value;
}

double Space::area()const
{
    return length * width;
}
void Space::addResident(const Resident& r)
{

}
