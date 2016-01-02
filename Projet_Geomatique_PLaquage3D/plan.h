#ifndef PLAN_H
#define PLAN_H
#include<vector>

#include <QVector>
#include <QVector3D>

class Plan
{
public:
    Plan();
    QVector<float> normale(QVector3D pointA,QVector3D pointB,QVector3D pointC);
    QVector<float> planeEquation(QVector3D pointA0,QVector3D pointX,QVector<float> normale);
};

#endif // PLAN_H
