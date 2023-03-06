#ifndef PLAYVIDEOCLS_H
#define PLAYVIDEOCLS_H
#include <windows.h>
#include <QObject>
#include <commdlg.h>
#include <QtMultimedia/QtMultimedia>
#include <QtMultimedia/QMediaPlayer>

#include <QtMultimediaWidgets/QVideoWidget>
#include <QFileDialog>
#include <QQuickWindow>
//#include "backgroundwdgt.h"
class PlayVideoCls : public QObject
{
    Q_OBJECT

public:
    explicit PlayVideoCls(QObject *parent = nullptr);

    //OPENFILENAME fileName;
   // QMediaPlayer *player;
   // QVideoWidget *videoWidget;
    QFileDialog *fileDlg;
    QString fileName;
    //BackGroundWdgt *wid;
public slots:
    void fileSelectionDialog();
    void onPlayPressed();

};

#endif // PLAYVIDEOCLS_H
