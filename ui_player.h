/********************************************************************************
** Form generated from reading UI file 'player.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYER_H
#define UI_PLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Player
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *local_tab;
    QGridLayout *gridLayout_8;
    QGridLayout *video_grid_layout;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *Play_Btn;
    QPushButton *Stop_Btn;
    QPushButton *Back_Btn;
    QPushButton *Forward_Btn;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *renderer_layout;
    QSpacerItem *horizontalSpacer;
    QGridLayout *chart_grid_layout;
    QVBoxLayout *date_time_vertical_layout;
    QHBoxLayout *horizontalLayout;
    QComboBox *drive_cbx;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *select_folder_btn;
    QPushButton *search_btn;
    QCalendarWidget *calendar;
    QSpacerItem *verticalSpacer_2;
    QWidget *remote_tab;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Player)
    {
        if (Player->objectName().isEmpty())
            Player->setObjectName(QStringLiteral("Player"));
        Player->resize(1162, 469);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Player->sizePolicy().hasHeightForWidth());
        Player->setSizePolicy(sizePolicy);
        Player->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
" border: 1px solid;\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"  background: 	SlateGray;\n"
"}\n"
""));
        Player->setTabShape(QTabWidget::Triangular);
        centralWidget = new QWidget(Player);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(200, 400));
        tabWidget->setSizeIncrement(QSize(0, 0));
        tabWidget->setMouseTracking(false);
        tabWidget->setFocusPolicy(Qt::NoFocus);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QLatin1String("font: 75 8pt \"Century Gothic\";\n"
""));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        local_tab = new QWidget();
        local_tab->setObjectName(QStringLiteral("local_tab"));
        gridLayout_8 = new QGridLayout(local_tab);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        video_grid_layout = new QGridLayout();
        video_grid_layout->setSpacing(6);
        video_grid_layout->setObjectName(QStringLiteral("video_grid_layout"));
        video_grid_layout->setSizeConstraint(QLayout::SetMinimumSize);
        video_grid_layout->setContentsMargins(-1, -1, 0, -1);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        Play_Btn = new QPushButton(local_tab);
        Play_Btn->setObjectName(QStringLiteral("Play_Btn"));
        Play_Btn->setMinimumSize(QSize(0, 30));

        horizontalLayout_5->addWidget(Play_Btn);

        Stop_Btn = new QPushButton(local_tab);
        Stop_Btn->setObjectName(QStringLiteral("Stop_Btn"));
        Stop_Btn->setMinimumSize(QSize(0, 30));

        horizontalLayout_5->addWidget(Stop_Btn);

        Back_Btn = new QPushButton(local_tab);
        Back_Btn->setObjectName(QStringLiteral("Back_Btn"));
        Back_Btn->setMinimumSize(QSize(0, 30));

        horizontalLayout_5->addWidget(Back_Btn);

        Forward_Btn = new QPushButton(local_tab);
        Forward_Btn->setObjectName(QStringLiteral("Forward_Btn"));
        Forward_Btn->setMinimumSize(QSize(0, 30));

        horizontalLayout_5->addWidget(Forward_Btn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        video_grid_layout->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        renderer_layout = new QGridLayout();
        renderer_layout->setSpacing(6);
        renderer_layout->setObjectName(QStringLiteral("renderer_layout"));
        renderer_layout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        renderer_layout->addItem(horizontalSpacer, 0, 0, 1, 1);


        video_grid_layout->addLayout(renderer_layout, 0, 0, 1, 1);


        gridLayout_8->addLayout(video_grid_layout, 0, 1, 1, 1);

        chart_grid_layout = new QGridLayout();
        chart_grid_layout->setSpacing(6);
        chart_grid_layout->setObjectName(QStringLiteral("chart_grid_layout"));
        chart_grid_layout->setSizeConstraint(QLayout::SetMinimumSize);

        gridLayout_8->addLayout(chart_grid_layout, 1, 0, 1, 2);

        date_time_vertical_layout = new QVBoxLayout();
        date_time_vertical_layout->setSpacing(6);
        date_time_vertical_layout->setObjectName(QStringLiteral("date_time_vertical_layout"));
        date_time_vertical_layout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        date_time_vertical_layout->addLayout(horizontalLayout);

        drive_cbx = new QComboBox(local_tab);
        drive_cbx->setObjectName(QStringLiteral("drive_cbx"));

        date_time_vertical_layout->addWidget(drive_cbx);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        select_folder_btn = new QPushButton(local_tab);
        select_folder_btn->setObjectName(QStringLiteral("select_folder_btn"));

        horizontalLayout_2->addWidget(select_folder_btn);

        search_btn = new QPushButton(local_tab);
        search_btn->setObjectName(QStringLiteral("search_btn"));

        horizontalLayout_2->addWidget(search_btn);


        date_time_vertical_layout->addLayout(horizontalLayout_2);

        calendar = new QCalendarWidget(local_tab);
        calendar->setObjectName(QStringLiteral("calendar"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(calendar->sizePolicy().hasHeightForWidth());
        calendar->setSizePolicy(sizePolicy1);
        calendar->setStyleSheet(QStringLiteral(""));
        calendar->setGridVisible(true);
        calendar->setHorizontalHeaderFormat(QCalendarWidget::SingleLetterDayNames);
        calendar->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        calendar->setNavigationBarVisible(true);
        calendar->setDateEditEnabled(true);

        date_time_vertical_layout->addWidget(calendar);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        date_time_vertical_layout->addItem(verticalSpacer_2);


        gridLayout_8->addLayout(date_time_vertical_layout, 0, 0, 1, 1);

        tabWidget->addTab(local_tab, QString());
        remote_tab = new QWidget();
        remote_tab->setObjectName(QStringLiteral("remote_tab"));
        tabWidget->addTab(remote_tab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        Player->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Player);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1162, 21));
        Player->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Player);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Player->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Player);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Player->setStatusBar(statusBar);

        retranslateUi(Player);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Player);
    } // setupUi

    void retranslateUi(QMainWindow *Player)
    {
        Player->setWindowTitle(QApplication::translate("Player", "Basket Player v0.1", nullptr));
        Play_Btn->setText(QApplication::translate("Player", "Play/Pause", nullptr));
        Stop_Btn->setText(QApplication::translate("Player", "Stop", nullptr));
        Back_Btn->setText(QApplication::translate("Player", "Back ", nullptr));
        Forward_Btn->setText(QApplication::translate("Player", "Forward", nullptr));
        drive_cbx->setCurrentText(QString());
        select_folder_btn->setText(QApplication::translate("Player", "Select Folder", nullptr));
        search_btn->setText(QApplication::translate("Player", "Search", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(local_tab), QApplication::translate("Player", "Local Disk", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(remote_tab), QApplication::translate("Player", "Remote", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Player: public Ui_Player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYER_H
