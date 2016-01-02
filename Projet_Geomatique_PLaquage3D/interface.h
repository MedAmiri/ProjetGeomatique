#ifndef INTERFACE_H
#define INTERFACE_H
#include <QMainWindow>
#include <QWidget>



#include <viewer.h>
#include <objet.h>
#include <global.h>
#include <plaquage.h>
#include <mnt.h>

namespace Ui {
class interface;
}

class interface : public QMainWindow
{
    Q_OBJECT

public:
    explicit interface(QWidget *parent = 0);
    objet getobjet();
    ~interface();

private slots:
    void quitterApp();
    void DialogMNT();
    void DialogOBJ();
    void DialogTexture();
    void about();

private:
    Ui::interface *ui;
    void closeEvent(QCloseEvent*);
};

#endif // INTERFACE_H




