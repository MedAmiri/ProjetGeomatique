#include "plan.h"
#include <QVector>
#include <QVector3D>

Plan::Plan()
{
}
//retourner la normale d'un plan constitué de deux vecteurs
QVector<float> Plan::normale(QVector3D pointA,QVector3D pointB,QVector3D pointC)
{
    float vect1[3],vect2[3],a,b,c;
    QVector<float> normale;

        vect1[0]=pointB.x()-pointA.x();
        vect1[1]=pointB.y()-pointA.y();
        vect1[2]=pointB.z()-pointA.z();

        vect2[0]=pointC.x()-pointA.x();
        vect2[1]=pointC.y()-pointA.y();
        vect2[2]=pointC.z()-pointA.z();

        a=vect1[1]*vect2[2]-vect1[2]*vect2[1];
        b=vect1[2]*vect2[0]-vect1[0]*vect2[2];
        c=vect1[0]*vect2[1]-vect1[1]*vect2[0];

        normale.push_back(a);
        normale.push_back(b);
        normale.push_back(c);

return normale;

}

//retourner un point avec une altitude réelle
QVector<float> Plan::planeEquation(QVector3D pointA0,QVector3D pointX,QVector<float> normale)
{
    float x=pointX.x();
    float y=pointX.y();
    float z=pointX.z();

    QVector<float> result;
    if(z==-99){

    z=pointA0.z()-((normale[1]*(pointX.x()-pointA0.x())+normale[2]*(pointX.y()-pointA0.y()))/3);
    }
    result.push_back(x);
    result.push_back(y);
    result.push_back(z);
return result;
}
