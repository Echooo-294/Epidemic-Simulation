/*
 * @Description: 建筑类的声明
 * @Author: 巾可
 * @Date: 2022-03-03
 * @Last Modified by: 巾可
 * @Last Modified time: 2022-03-12
 */

#include "space.h"

Space::Space(QObject *parent) : QObject(parent),accessible(true)
{
    //初始化时默认可以进入
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

int Space::getWidth() const
{
    return width;
}

void Space::setWidth(int value)
{
    width = value;
}

int Space::getLength() const
{
    return length;
}

void Space::setLength(int value)
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

int Space::area()const
{
    return length * width;
}
void Space::addResident(const Resident& r)
{

}
