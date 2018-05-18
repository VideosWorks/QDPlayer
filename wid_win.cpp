#include "wid_win.h"
#include <QtAVWidgets>
using namespace QtAV;
wid_win::wid_win()
{

  m_player = new AVPlayer();

  m_renderer1 = new VideoOutput(VideoRendererId_GLWidget2);
  m_renderer2 = new VideoOutput(VideoRendererId_GLWidget2);
  m_renderer3 = new VideoOutput(VideoRendererId_GLWidget2);
  m_renderer4 = new VideoOutput(VideoRendererId_GLWidget2);
  widgt = new QWidget();
  QGridLayout *lay = new QGridLayout;
  widgt->setLayout(lay);
  lay->addWidget(m_renderer1->widget(),0,0);
  lay->addWidget(m_renderer2->widget(),0,1);
  lay->addWidget(m_renderer3->widget(),1,0);
  lay->addWidget(m_renderer4->widget(),1,1);




}
void wid_win::mousePressEvent(QMouseEvent *event)
{
  qDebug()<<"aaa";

}



