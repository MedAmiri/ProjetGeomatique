#ifndef OBJET_H
#define OBJET_H

#include <QString>
#include <QVector>
#include <QString>
#include <math.h>
#include <assimp/Importer.hpp>
#include <assimp/mesh.h>
#include <assimp/scene.h>
#include<QVector3D>
using namespace std;

class objet
{
public:

    objet();
    objet(objet & objet);
    ~objet();
    void loadobjet(const string& filename); // charger le modele dans un scene
    void getData(aiMesh *mesh); // récuperer les sommets, les indices et les textures.
    float getxMin();
    float getxMax();
    float getyMin();
    float getyMax();
    float getzMin();
    float getzMax();
    void drawobjet();
    void adapterObjet();//float x, float y, float z);
    void segment_intersection();
    void plaquerobjet();
    void drawobjetfinal();
    //----------------------
    void drawobjetcouper();
    void plaquercube(QVector<QVector3D> segment,QVector<QVector3D>  interspoints);
    bool insommets(QVector3D p,QVector<QVector3D> vertex);

private :

    float xMax;// =0;
    float yMax;// =0;
    float zMax;// =0;
    float xMin;// =0;
    float yMin;// =0;
    float zMin;// =0;
    QVector<float> sommets;
    QVector<float>sommets_plaquage;
    QVector<float> normals;
    QVector<float> textures;
    QVector<unsigned int> index;
    QVector<QVector3D> tabcube;
    QVector<QVector3D> segmentAB;
    QVector<QVector3D> segmentBC;
    QVector<QVector3D> segmentCD;
    QVector<QVector3D> segmentDA;


};


#endif // OBJET_H
