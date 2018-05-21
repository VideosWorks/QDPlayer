#include "wid_win.h"
#include <player.h>
#include <QtAVWidgets>
using namespace QtAV;


wid_win::wid_win()
{
    m_unit = 1000;
    m_player = new AVPlayer();
    m_player->setSeekType(KeyFrameSeek);



    m_renderer1 = new VideoOutput(VideoRendererId_GLWidget2);
    m_renderer2 = new VideoOutput(VideoRendererId_GLWidget2);
    m_renderer3 = new VideoOutput(VideoRendererId_GLWidget2);
    m_renderer4 = new VideoOutput(VideoRendererId_GLWidget2);
    widgt = new QWidget();


    m_player->addVideoRenderer(m_renderer1, 0);
    m_player->addVideoRenderer(m_renderer2, 1);
    m_player->addVideoRenderer(m_renderer3, 2);
    m_player->addVideoRenderer(m_renderer4, 3);
    lay = new QGridLayout;

    lay->setSpacing(2);
    lay->setMargin(2);

    //  widgt->setLayout(lay);
    setLayout(lay);


    lay->addWidget(m_renderer1->widget(),0,1);
    lay->addWidget(m_renderer2->widget(),0,2);

    lay->addWidget(m_renderer3->widget(),1,1);
    lay->addWidget(m_renderer4->widget(),1,2);



}

void wid_win::mousePressEvent(QMouseEvent *event)
{
    int a =-1;
    QWidget * const widget = childAt(event->pos());
    if(widget)
    {
        const int index = lay->indexOf(widget);
        a=index;
        qDebug() << "layout index" << index;

    }
    if(clicked_state==0)
    {
        if(a==0)
        {
            m_renderer1->widget()->setVisible(true);
            m_renderer2->widget()->setVisible(false);
            m_renderer3->widget()->setVisible(false);
            m_renderer4->widget()->setVisible(false);
        }
        if(a==1)
        {
            m_renderer1->widget()->setVisible(false);
            m_renderer2->widget()->setVisible(true);
            m_renderer3->widget()->setVisible(false);
            m_renderer4->widget()->setVisible(false);
        }
        if(a==2)
        {
            m_renderer1->widget()->setVisible(false);
            m_renderer2->widget()->setVisible(false);
            m_renderer3->widget()->setVisible(true);
            m_renderer4->widget()->setVisible(false);
        }
        if(a==3)
        {
            m_renderer1->widget()->setVisible(false);
            m_renderer2->widget()->setVisible(false);
            m_renderer3->widget()->setVisible(false);
            m_renderer4->widget()->setVisible(true);
        }
        clicked_state=1;
    }
    else
    {

        if(screen_mode==1)
        {
            m_renderer1->widget()->setVisible(true);
            m_renderer2->widget()->setVisible(false);
            m_renderer3->widget()->setVisible(false);
            m_renderer4->widget()->setVisible(false);
        }
        if(screen_mode==2)
        {
            m_renderer1->widget()->setVisible(true);
            m_renderer2->widget()->setVisible(true);
            m_renderer3->widget()->setVisible(false);
            m_renderer4->widget()->setVisible(false);
        }
        if(screen_mode==4)
        {
            m_renderer1->widget()->setVisible(true);
            m_renderer2->widget()->setVisible(true);
            m_renderer3->widget()->setVisible(true);
            m_renderer4->widget()->setVisible(true);

        }
        clicked_state=0;
    }
    play->reSize();

}

void wid_win::keyPressEvent(QKeyEvent* event)
{


    if(event->key() == Qt::Key_Escape)
    {
        qDebug()<<"escape ";
        play->reSize();
        play->exitFullScreen();


    }

}

void  wid_win::set_player(Player *p)
{
    play = p;
}
