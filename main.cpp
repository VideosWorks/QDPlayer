#include "player.h"
#include <QApplication>
#include <plot.h>
#include "player.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Player w;
    Plot pl;
    pl.set_player(&w);
    w.resize(1100,800);
    w.show();
    return a.exec();
}
