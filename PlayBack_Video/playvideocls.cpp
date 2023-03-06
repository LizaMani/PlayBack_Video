#include "playvideocls.h"

#pragma comment(lib,"comdlg32.lib")
PlayVideoCls::PlayVideoCls(QObject *parent)
    : QObject{parent}
{

  //  wid=new BackGroundWdgt;

}
void PlayVideoCls::fileSelectionDialog()
{
  /*  char Filestring[MAX_PATH] = "\0";
    fileName={0};
    fileName.lStructSize = sizeof(OPENFILENAME);
    fileName.lpstrFile =(LPWSTR) Filestring;
    fileName.nMaxFile = MAX_PATH;
    GetOpenFileName(&fileName);*/
    //w->setModality(Qt::WindowModal);

   /* fileDlg=new QFileDialog(QFileDialogArgs());
    //fileDlg->
    fileDlg->setModal(true);

    //fileDlg->setModal(true);
    fileName=fileDlg->getOpenFileName();*/


}
void PlayVideoCls::onPlayPressed()
{
    QMediaPlayer *player=new QMediaPlayer;
  /*const char *temp;
   temp=(const char *)fileName.lpstrFile;*/
    player->setSource(QUrl(fileName));
    QVideoWidget *videoWidget = new QVideoWidget;
    player->setVideoOutput(videoWidget);

    videoWidget->show();

    player->play();
}
