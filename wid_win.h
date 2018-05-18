#ifndef WID_WIN_H
#define WID_WIN_H

#include <QWidget>
#include <QGridLayout>
#include <QWidget>
#include <QPushButton>
#include<QtAV>
class wid_win:public QWidget
{

public:
  wid_win();

   QGridLayout *lay;
   QWidget *widgt;
   QPushButton *btn;
   QtAV::VideoOutput *m_renderer1;
   QtAV::VideoOutput *m_renderer2;
   QtAV::VideoOutput *m_renderer3;
   QtAV::VideoOutput *m_renderer4;
   QtAV::AVPlayer *m_player;



   public Q_SLOTS:
   void mousePressEvent(QMouseEvent* event);

};

#endif // WID_WIN_H
