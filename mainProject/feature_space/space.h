#ifndef SPACE_H
#define SPACE_H

#include <QObject>
#include <QPoint>

class Space : public QObject
{
    Q_OBJECT
public:
    explicit Space(QObject *parent = nullptr);

public:
    int capacity;//容量
    int length,width;//长宽
    QString name;//建筑名称
    QPoint position;//坐标
    bool accessible;//是否可进入，人满或特殊政策下不可进入
public:
    int getCapacity() const;
    void setCapacity(int value);//设置和获取容纳量

    int getLength() const;
    void setLength(int value);//设置和获取长度

    int getWidth() const;
    void setWidth(int value);//设置和获取宽度

    QString getName() const;
    void setName(const QString &value);//设置和获取名字

    QPoint getPosition() const;
    void setPosition(const QPoint &value);//设置和获取坐标

    bool isAccessible() const;
    void setAccessible(bool value);//设置和获取能否进入

    int area()const;//返回面积
    int restRoom()const;//返回剩余容量
    void addResident(int num);//居民进入,num为进入人数

signals:

};

#endif // SPACE_H
