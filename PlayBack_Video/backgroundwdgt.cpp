#include "backgroundwdgt.h"

BackGroundWdgt::BackGroundWdgt(QWindow *parent) :
    QQuickWindow(parent),
    m_fileDialog(new QFileDialog)//,m_videoWidget(new QVideoWidget)

{
    //m_appWin=parent;
    setModality(Qt::ApplicationModal);
    m_fileDialog->setAcceptMode(QFileDialog::AcceptOpen);
     m_fileDialog->setModal(true);
      player=new QMediaPlayer(parent);
      m_videoWidget=new QVideoWidget;
       // m_videoWidget->setParent();
    connect(m_fileDialog,&QFileDialog::accepted,this,&BackGroundWdgt::accept);
    connect(this, &BackGroundWdgt::fileNameChanged, m_fileDialog, &QFileDialog::selectFile);
}
QString BackGroundWdgt::fileSelectionDialog()
{
  /*  char Filestring[MAX_PATH] = "\0";
    fileName={0};
    fileName.lStructSize = sizeof(OPENFILENAME);
    fileName.lpstrFile =(LPWSTR) Filestring;
    fileName.nMaxFile = MAX_PATH;
    GetOpenFileName(&fileName);*/
    //w->setModality(Qt::WindowModal);

   // m_fileDialog=new QFileDialog(QFileDialogArgs());



    //fileDlg->setModal(true);
    //m_fileDialog->show();

   // fileName=this->fileName;
    qDebug()<<fileName;
    return fileName;
}
void BackGroundWdgt::onPlayPressed()
{
    if(player->position()>0)
    {
     player->play();
    }else
    {

    player->setSource(QUrl(fileName));

    player->setVideoOutput(m_videoWidget);


    m_videoWidget->show();
//player->setActiveVideoTrack(player->activeVideoTrack());
    player->play();
    }
}
void BackGroundWdgt::onPausePressed()
{
    player->pause();

}
void BackGroundWdgt::onSliderDragged(int posn)
{
    int durn=player->duration();
    int perc=(posn/300)*100;
    int playPosn=posn*durn/100;
    player->setPosition(playPosn);
    player->play();
}
int BackGroundWdgt::onProgressSlider()
{
    return (player->position()*100)/player->duration();
}
QWindow* BackGroundWdgt::windowActivate() const
{
    return m_appWin;
}
void BackGroundWdgt::setWindowForActivateRequesting(QWindow *windowActivate)
{
    if (m_appWin == windowActivate)
        return;

   m_appWin = windowActivate;
    emit windowActivateChanged(windowActivate);
}
void BackGroundWdgt::open()
{
    m_fileDialog->show();
}

void BackGroundWdgt::close()
{
    m_fileDialog->close();
    windowActivate()->requestActivate();
}
void BackGroundWdgt::accept()
{
    setFileName(m_fileDialog->selectedFiles().at(0));

    close();
    emit accepted();
}
void BackGroundWdgt::setFileName(QString filename)
{
    if (fileName == filename)
        return;

    fileName = filename;
    emit fileNameChanged(filename);
}
QString BackGroundWdgt::getfileName() const
{
    return fileName;
}
BackGroundWdgt::~BackGroundWdgt()
{
delete m_fileDialog;
    delete player;
    delete m_videoWidget;
}
