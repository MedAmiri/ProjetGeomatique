#include "viewer.h"
#include <objet.h>
#include <mnt.h>

/***********************   Affichage du MNT  ********************************/

ViewerMNT::ViewerMNT(QWidget *parent) : QGLViewer(parent)
{
    restoreStateFromFile();
}

void ViewerMNT::init()
{
  //setSceneBoundingBox(qglviewer::Vec (900000,1900020,318.8), qglviewer::Vec(999975,1944980,3270));
  //showEntireScene();
    this->camera()->setUpVector(qglviewer::Vec(0,0,1));
    setSceneBoundingBox(qglviewer::Vec(900000-1000, 1944980-1000, 1073-1000), qglviewer::Vec(900000+1000,1944980+1000,1073+1000));
    showEntireScene();


}

void ViewerMNT::draw(){

    mntteste.drawMnt();
    objetteste.drawobjetfinal();

}


/***********************   Affichage de L'objet  ********************************/

ViewerObjet::ViewerObjet(QWidget *parent) : QGLViewer(parent)
{
    restoreStateFromFile();

}


void ViewerObjet::init()
{


}

void ViewerObjet::draw(){

    objetteste.drawobjet();
}

void ViewerObjet:: postDraw(){

    if(!((objetteste.getxMax() ==0 && objetteste.getyMax() == 0) && objetteste.getzMax() == 0)){

        setSceneBoundingBox(qglviewer::Vec(objetteste.getxMin()*2,objetteste.getyMin()*2,objetteste.getzMin()*2), qglviewer::Vec(objetteste.getxMax()*1.5,objetteste.getyMax()*1.5,objetteste.getzMax()*1.5));
        showEntireScene();
    }

 }

/***********************   Affichage de L'objet final ********************************/

ViewerObjetF::ViewerObjetF(QWidget *parent) : QGLViewer(parent)
{

}

void ViewerObjetF::init()
{
    setSceneBoundingBox(qglviewer::Vec(900000-1000, 1944980-1000, 1000), qglviewer::Vec(900000+1000,1944980+1000,1073+1000));
    showEntireScene();

}

void ViewerObjetF::draw(){
   objetteste.drawobjetfinal();
}

void ViewerObjetF:: postDraw(){


 }
