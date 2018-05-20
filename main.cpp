#include "player.h"
#include <QApplication>
#include <plot.h>
#include "player.h"
#include "wid_win.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Player w;
    Plot pl;
    pl.set_player(&w);
    wid_win cx;
    cx.set_player(&w);

    w.showMaximized();
    return a.exec();
}
