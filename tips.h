#ifndef TIPS_H
#define TIPS_H

#include <QString>
#include <QVector>


class Tips
{
public:
    Tips();
    QString getTips();
private:
    int tipNum;
    QVector<QString> tips;
};

#endif // TIPS_H
