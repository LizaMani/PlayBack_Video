#ifndef BACKGROUNDWDGT_H
#define BACKGROUNDWDGT_H

#include <QObject>
#include <QWidget>
#include <QQuickWindow>
#include <QApplication>
#include <QtMultimedia/QtMultimedia>
#include <QtMultimedia/QMediaPlayer>

#include <QtMultimediaWidgets/QVideoWidget>
#include <QFileDialog>
class QFileDialog;
class QVideoWidget;
class BackGroundWdgt : public QQuickWindow
{
    Q_OBJECT
     Q_PROPERTY(QWindow* windowActivate READ windowActivate WRITE setWindowForActivateRequesting NOTIFY windowActivateChanged)
     Q_PROPERTY(QString file_Name READ getfileName WRITE setFileName NOTIFY fileNameChanged)
public:
    explicit BackGroundWdgt(QWindow *parent = nullptr);
    ~BackGroundWdgt();
    QFileDialog *m_fileDialog;
    QVideoWidget *m_videoWidget;
    QMediaPlayer *player;
    QString fileName;
    QWindow *m_appWin;
    QWindow *windowActivate() const;
        void setWindowForActivateRequesting(QWindow* windowActivate);
        void setFileName(QString filename);
    QString getfileName() const;
        Q_INVOKABLE void open();
            Q_INVOKABLE void close();
public slots:
    QString fileSelectionDialog();
    void onPlayPressed();
    void onPausePressed();
    void onSliderDragged(int posn);
    int onProgressSlider();
protected slots:
    virtual void accept();
signals:
    void windowActivateChanged(QWindow*);
    void accepted();
    void fileNameChanged(QString filename);
};

#endif // BACKGROUNDWDGT_H
