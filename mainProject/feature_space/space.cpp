#include "space.h"

Space::Space(QObject *parent) : QObject(parent)
{

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
int Space::restRoom()const
{

}
void Space::addResident(int num)
{

}
