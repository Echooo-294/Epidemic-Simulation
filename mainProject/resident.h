#ifndef RESIDENT_H
#define RESIDENT_H

#include <QObject>

class Resident : public QObject
{
    Q_OBJECT
public:
    explicit Resident(QObject *parent = nullptr);
private:

signals:

};

#endif // RESIDENT_H
