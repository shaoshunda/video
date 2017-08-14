#include "videobottomwidgets.h"

#ifdef DEVICE_EVB
int video_bottom_height  = 160;
int video_playButton_size = 100;
int openFile_size = 80;
#else
int video_bottom_height  = 70;
int video_playButton_size = 50;
int openFile_size = 30;
#endif

VideoBottomWidgets::VideoBottomWidgets(QWidget *parent,bool fullScreenStyle):BaseWidget(parent)
{
    isFullScreenStyle = fullScreenStyle;
    if(isFullScreenStyle){
        m_parent = (FullScreenControlWidgets*)parent;
    }

    // Set background color and bottom widget height.
    setObjectName("VideoBottomWidgets");
    setStyleSheet("#VideoBottomWidgets{background:rgb(89,92,102)}");
    setFixedHeight(video_bottom_height);

    initLayout();
}

void VideoBottomWidgets::initLayout()
{
    QHBoxLayout *hmainlyout = new QHBoxLayout;

    m_btnPlayPause = new FlatButton(this);
    m_btnNext = new FlatButton(this);
    m_btnLast = new FlatButton(this);
    m_btnOpenFile = new FlatButton(this);
    m_VolWidget = new VolWidget(this);
    m_btnChangeSize = new FlatButton(this);
    m_btnRefresh = new FlatButton(this);

    m_btnPlayPause->setFixedSize(video_playButton_size,video_playButton_size);
    m_btnNext->setFixedSize(video_playButton_size,video_playButton_size);
    m_btnLast->setFixedSize(video_playButton_size,video_playButton_size);
    m_btnOpenFile->setFixedSize(video_playButton_size,video_playButton_size);
    m_btnChangeSize->setFixedSize(video_playButton_size,video_playButton_size);
    m_btnRefresh->setFixedSize(video_playButton_size,video_playButton_size);

    m_btnNext->setStyleSheet("QPushButton{border-image:url(:/image/video/btn_next (1).png);}"
                             "QPushButton::hover{border-image:url(:/image/video/btn_next (2).png);}"
                             "QPushButton::pressed{border-image:url(:/image/video/btn_next (3).png);}");
    m_btnLast->setStyleSheet("QPushButton{border-image:url(:/image/video/btn_previous (1).png);}"
                             "QPushButton::hover{border-image:url(:/image/video/btn_previous (2).png);}"
                             "QPushButton::pressed{border-image:url(:/image/video/btn_previous (3).png);}");
    m_btnPlayPause->setStyleSheet("QPushButton{border-image:url(:/image/video/btn_play (1).png);}"
                                  "QPushButton::hover{border-image:url(:/image/video/btn_play (2).png);}"
                                  "QPushButton::pressed{border-image:url(:/image/video/btn_play (3).png);}");

    m_btnOpenFile->setStyleSheet("QPushButton{border-image:url(:/image/video/video_open_file.png);}");
    m_btnChangeSize->setStyleSheet("QPushButton{border-image:url(:/image/video/btn_fullscreen.png);}");
    m_btnRefresh->setStyleSheet("QPushButton{border-image:url(:/image/video/video_refresh.png);}");

    QHBoxLayout *hlyout1 = new QHBoxLayout;
    hlyout1->addSpacing(80);
    hlyout1->addWidget(m_btnOpenFile);
    hlyout1->addSpacing(40);
    hlyout1->addWidget(m_VolWidget);
    hlyout1->addStretch(0);

    QHBoxLayout *hlyout2 = new QHBoxLayout;
    hlyout2->addWidget(m_btnLast);
    hlyout2->addSpacing(20);
    hlyout2->addWidget(m_btnPlayPause);
    hlyout2->addSpacing(20);
    hlyout2->addWidget(m_btnNext);

    QHBoxLayout *hlyout3 = new QHBoxLayout;
    hlyout3->addStretch(0);
    hlyout3->addWidget(m_btnChangeSize);
    hlyout3->addSpacing(30);
    hlyout3->addWidget(m_btnRefresh);
    hlyout3->addStretch(0);

    hmainlyout->addLayout(hlyout1,1);
    hmainlyout->addLayout(hlyout2,1);
    hmainlyout->addLayout(hlyout3,1);
    hmainlyout->setContentsMargins(0,0,0,0);
    hmainlyout->setSpacing(0);

    if(isFullScreenStyle){
        m_btnChangeSize->setStyleSheet("QPushButton{border-image:url(:/image/video/btn_normalSize.png);}");
        m_btnOpenFile->setVisible(false);
        m_btnRefresh->setVisible(false);
    }

    setLayout(hmainlyout);
}

void VideoBottomWidgets::setPlayingStyle()
{
    m_btnPlayPause->setStyleSheet("QPushButton{border-image:url(:/image/video/btn_pause (1).png);}"
                                  "QPushButton::hover{border-image:url(:/image/video/btn_pause (2).png);}"
                                  "QPushButton::pressed{border-image:url(:/image/video/btn_pause (3).png);}");

}

void VideoBottomWidgets::setPauseStyle()
{
    m_btnPlayPause->setStyleSheet("QPushButton{border-image:url(:/image/video/btn_play (1).png);}"
                                  "QPushButton::hover{border-image:url(:/image/video/btn_play (2).png);}"
                                  "QPushButton::pressed{border-image:url(:/image/video/btn_play (3).png);}");
}

void VideoBottomWidgets::mousePressEvent(QMouseEvent *)
{
    if(isFullScreenStyle){
        m_parent->slot_showControlView();
    }
}

VideoBottomWidgets::~VideoBottomWidgets()
{
}