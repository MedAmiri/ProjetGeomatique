#include "mnt.h"
#include <QGLWidget>
#include<objet.h>
#include "plaquage.h"
#include"objet.h"
#include<global.h>


mnt::mnt()
{
}

mnt::~mnt(){

}

void mnt::loadXYZ(const QString& chemin){

    QVector3D p;

    m_tabDonnees.clear();
    m_tab_lines.clear();
    m_tab_texture.clear();
    m_tab_texture_ordonne.clear();

    int nbPoint = 0;
    int colonne = 0;
    int ligne = 0;
    xmin = 1000000000;
    ymin = 1000000000;
    zmin = 1000000000;
    xmax = 0;
    ymax = 0;
    zmax = 0;
    QFile fichier(chemin);

    if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream flux(&fichier);



        while(!flux.atEnd())
        {

            double x,y,z;
            flux >> x >> y >> z ;


                if(x>xmax)
                    {
                        xmax=x;
                        ++colonne;
                    }

                if(y>ymax)
                    {
                        ymax=y;

                    }

                if(z>zmax)
                    {
                        zmax=z;
                    }

                if(x<xmin)
                    {
                        if(x != 0){
                            xmin=x;
                        }
                    }

                if(y<ymin)
                    {
                        if(y != 0){
                            ymin=y;
                        }
                    }

                if(z<zmin)
                     {
                         if (z != 0){
                             zmin=z;
                         }
                     }
            p.setX(x);
            p.setY(y);
            p.setZ(z);
            m_tabDonnees.push_back(p);
            ++nbPoint;

         }
        fichier.close();
        ligne = nbPoint / colonne;
        points_suivant_x = ligne;
        //cout << "nb ligne " << ligne << endl;
        points_suivant_y = colonne;
        arretes_suivant_x= ligne -1;
        arretes_suivant_y = colonne -1;
        getdatafromXYZ();

    }

    else{
        cerr << "Ouverture Impossible" << endl;
    }


}
void mnt::getdatafromXYZ(){

    // Tableaux ordonné de points pour dessiner des Lines--------------------------------------------
      for (int x = 0; x < arretes_suivant_x; ++x)
        {
            for (int y = 0; y < arretes_suivant_y; ++y)
            {
                int i = x * points_suivant_y + y;

                m_tab_lines.push_back(m_tabDonnees[i]);
                m_tab_lines.push_back(m_tabDonnees[i+points_suivant_y]);
                m_tab_lines.push_back(m_tabDonnees[i+1]);

                m_tab_lines.push_back(m_tabDonnees[i+1]);
                m_tab_lines.push_back(m_tabDonnees[i+points_suivant_y]);
                m_tab_lines.push_back(m_tabDonnees[i+1+points_suivant_y]);


            }
        }

     //Tableau des coordonnées de la texture

   QVector2D m_coordonnees_texture;
       for(int x = 0; x < points_suivant_x; ++x)
       {
           for(int y = 0; y < points_suivant_y; ++y)
           {
               // calcul de la position des point sur la texture

               m_coordonnees_texture.setX(1.0 * y / arretes_suivant_y);
               m_coordonnees_texture.setY(1.0 - 1.0 * x / arretes_suivant_x);
               m_tab_texture.push_back(m_coordonnees_texture);
           }
       }
       // Tableau ordonné des coordonnees de la texture
       for (int x = 0; x < arretes_suivant_x; ++x)
         {
             for (int y = 0; y < arretes_suivant_y; ++y)
             {
                 int i = x * points_suivant_y + y;

                 m_tab_texture_ordonne.push_back(m_tab_texture[i]);
                 m_tab_texture_ordonne.push_back(m_tab_texture[i+points_suivant_y]);
                 m_tab_texture_ordonne.push_back(m_tab_texture[i+1]);

                 m_tab_texture_ordonne.push_back(m_tab_texture[i+1]);
                 m_tab_texture_ordonne.push_back(m_tab_texture[i+points_suivant_y]);
                 m_tab_texture_ordonne.push_back(m_tab_texture[i+1+points_suivant_y]);

             }
         }
       // texture loading
       //glEnable(GL_TEXTURE_2D); // Active les textures 2D
      // loadTexture("../Projet_Geomatique_PLaquage3D/texturet.png");

   }

void mnt::loadTexture(const QString& textureName)
{

    glEnable(GL_TEXTURE_2D); // Active les textures 2D
    QImage glTexture;
    QImage qtTexture;
    GLuint texture;
    qtTexture.load(textureName);
    glTexture = QGLWidget::convertToGLFormat( qtTexture );
    glGenTextures( 1, &texture);
    glBindTexture( GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexImage2D( GL_TEXTURE_2D, 0, 4, glTexture.width(), glTexture.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, glTexture.bits());
}

void mnt::drawMnt()
{
    // fonction du rendu

    QColor(255,255,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, m_tab_lines.constData());
    glTexCoordPointer(2,GL_FLOAT,0,m_tab_texture_ordonne.constData());
    glDrawArrays(GL_TRIANGLES, 0, m_tab_lines.size());
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);


}

double mnt::getxmin(){
    //cout << "teste xmin " << xmin << endl;
    return xmin;
}

double mnt::getymin(){
    //cout << "teste ymin " << ymin << endl;
    return ymin;
}

double mnt::getzmin(){
    //cout << "teste zmin " << zmin << endl;
    return zmin;
}

double mnt::getxmax(){

    return xmax;
}

double mnt::getymax(){

    return ymax;
}

double mnt::getzmax(){

    return zmax;
}

QVector<QVector3D>  mnt::getmontab(){
    return m_tabDonnees;
}
