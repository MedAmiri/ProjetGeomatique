#include <QWidget>
#include <QGLViewer/qglviewer.h>
#include <objet.h>
#include <global.h>
#ifndef VIEWER_H
#define VIEWER_H

class ViewerMNT : public QGLViewer
{
public:
    ViewerMNT(QWidget *parent=0);

protected :
    virtual void draw();
    virtual void init();
};

/*****************************************************************/
class ViewerObjet : public QGLViewer
{

public :
    ViewerObjet(QWidget *parent=0);

protected :

    virtual void draw();
    virtual void init();
    virtual void postDraw();

};
/*************************************************************/
class ViewerObjetF : public QGLViewer
{

public :
    ViewerObjetF(QWidget *parent=0);

protected :
    virtual void draw();
    virtual void init();
    virtual void postDraw();
};


#endif // VIEWER_H
