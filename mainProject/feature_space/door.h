#ifndef DOOR_H
#define DOOR_H

#include <QObject>

class Door : public QObject
{
    Q_OBJECT
public:
    explicit Door(QObject *parent = nullptr);

signals:

};

#endif // DOOR_H
