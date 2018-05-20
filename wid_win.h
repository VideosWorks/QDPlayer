#ifndef WID_WIN_H
#define WID_WIN_H

#include <QWidget>
#include <QGridLayout>
#include <QWidget>
#include <QPushButton>
#include "player.h"
#include<QtAV>
class Player;
class wid_win:public QWidget
{
     Q_OBJECT

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
    QPushButton *button;
    int m_unit;
    int clicked_state=0;
    int screen_mode =4;
    int full_btn_state=0;
    void  keyPressEvent(QKeyEvent* event);
    void  set_player(Player *p);
public Q_SLOTS:
    void mousePressEvent(QMouseEvent* event);

private :
    Player *play;



};

#endif // WID_WIN_H
