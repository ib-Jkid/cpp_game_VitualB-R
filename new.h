#ifndef NEW_H
#define NEW_H

#include <QObject>

class New : public QObject
{
    Q_OBJECT
public:
    explicit New(QObject *parent = nullptr);

signals:

};

#endif // NEW_H
