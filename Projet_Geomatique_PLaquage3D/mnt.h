#ifndef MNT_H
#define MNT_H
#include <string>
#include <QVector3D>
#include <QVector2D>
#include <QImage>
#include <QtOpenGL>
#include <iostream>
#include <QGLWidget>

using namespace std;

class mnt
{

public:

    mnt();
    void loadXYZ(const QString& chemin);
    void getdatafromXYZ();
    void loadTexture(const QString& textureName);
    void drawMnt();
    double getxmin();
    double getymin();
    double getzmin();
    double getxmax();
    double getymax();
    double getzmax();
    QVector<QVector3D>  getmontab();
    ~mnt();

private:
    double xmax;
    double ymax;
    double zmax;
    double xmin;
    double ymin;
    double zmin;
    int points_suivant_x;
    int arretes_suivant_x;
    int arretes_suivant_y;
    int points_suivant_y;
    QVector<QVector3D>  m_tabDonnees;
    QVector<QVector3D>  m_tab_lines;
    QVector<QVector2D>  m_tab_texture;
    QVector<QVector2D>  m_tab_texture_ordonne;
    QVector<QVector3D> tabcube;

};


#endif // MNT_H
