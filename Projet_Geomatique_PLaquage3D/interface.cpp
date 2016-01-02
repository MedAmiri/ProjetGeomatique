#include <QMessageBox>
#include <QCloseEvent>
#include <QFileDialog>
#include <QString>
#include <QProgressDialog>
#include <string>

#include "interface.h"
#include "ui_interface.h"
using namespace std;


interface::interface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::interface)
{
    ui->setupUi(this);
    connect(ui->Ouvrir, SIGNAL(triggered()), this, SLOT(DialogMNT()));
    connect(ui->Plaquage, SIGNAL(triggered()), this, SLOT(DialogOBJ()));
    connect(ui->Texture, SIGNAL(triggered()), this, SLOT(DialogTexture()));
    connect(ui->Aide, SIGNAL(aboutToShow()), this, SLOT(about()));

}

interface::~interface()
{
    delete ui;
}


void interface::closeEvent(QCloseEvent *e) {

  e->ignore();
  quitterApp();
}

void interface::quitterApp() {

  int ret = QMessageBox::critical(this,tr("Quitter l'Application"),tr("Voulez-vous quitter?"),QMessageBox::Yes | QMessageBox::No);
  if (ret == QMessageBox::Yes) QApplication::quit();
}

void interface::DialogMNT()
{
    QString file;


    {   QFileDialog dialog;
        dialog.setFileMode(QFileDialog::ExistingFile);
        dialog.setNameFilter(tr("Text files(*.xyz)"));
        dialog.setWindowTitle("Selectionner le fichier XYZ");

        if(dialog.exec()) {
            QStringList selectedFiles;
            selectedFiles = dialog.selectedFiles();
            if(selectedFiles.length() == 1)
                file = selectedFiles.first();
        }
    }

    if(!file.isEmpty())
    {

        int filesize = file.size();
        QProgressDialog progressDialog(this);
        progressDialog.setCancelButtonText(tr("&Cancel"));
        progressDialog.setRange(0, filesize);

        progressDialog.setWindowTitle(tr("Chargement MNT"));
        progressDialog.resize(250,250);

        for (int i = 0; i < 1; ++i) {
            progressDialog.setValue(i);
            progressDialog.setLabelText(tr("Chargement..........."));//.arg(i).arg(filesize));
            qApp->processEvents();

            mntteste.loadXYZ(file);
            plaquageteste.setmontab(mntteste.getmontab());
            if (progressDialog.wasCanceled())
                break;
        }
        //--------------
       // mntteste.loadXYZ(file);
        //--------------


    }
}

void interface::DialogOBJ()
{
    QString filetemporaire;

    {   QFileDialog dialog;
        dialog.setFileMode(QFileDialog::ExistingFile);
        //dialog.setNameFilter(tr("Text files(*.obj)"));
        dialog.setWindowTitle("Selectionner le fichier OBJ");


        if(dialog.exec()) {
            QStringList selectedFiles;
            selectedFiles = dialog.selectedFiles();
            if(selectedFiles.length() == 1)
                filetemporaire = selectedFiles.first();
        }
    }

    if(!filetemporaire.isEmpty())
    {
        string file;
        file = filetemporaire.toStdString();
        objetteste.loadobjet(file);
    }
}


void interface::DialogTexture()
{
    QString file;


    {   QFileDialog dialog;
        dialog.setFileMode(QFileDialog::ExistingFile);
        dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
        dialog.setWindowTitle("Selectionner une Image png");

        if(dialog.exec()) {
            QStringList selectedFiles;
            selectedFiles = dialog.selectedFiles();
            if(selectedFiles.length() == 1)
                file = selectedFiles.first();
        }
    }

    if(!file.isEmpty())
    {
        mntteste.loadTexture(file);
    }
}
void interface::about(){

    QMessageBox::about(this, "Projet Plaquage 3D",
                "Mohammed AMIRI\n" \
                "Hatim LAMGHARI\n" \
                "Zakaria AIT-OMAR\n");
}
