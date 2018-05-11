#ifndef PLAYER_H
#define PLAYER_H
#include <QMainWindow>
#include<QMessageBox>
#include<QBarSet>
#include<QChart>
#include<QChartView>
#include<QtAV>

class  Settings;
namespace Ui {
class Player;
}

class Plot;
class Player : public QMainWindow
{
    Q_OBJECT
public:
    explicit Player(QWidget *parent = 0);
    ~Player();

    // Structures and Defines
#define MINUTES_OF_DAY 1440
#define MAX_CHANNEL			8
#define ID_INDEX_HEADER	   0xF0000001
#define ID_INDEX_DATA	   0xF0000002
    enum _enumEventFlag
    {
        EVT_NONE=0,
        EVT_CONT=1,
        EVT_MOT,
        EVT_SENSOR,
        EVT_VLOSS
    } ;

    typedef struct _tBasketTimeStamp
    {
        unsigned int sec;	//seconds
        unsigned int usec;  //microseconds (1/1000000 seconds)
    }T_TIMESTAMP, T_TS;

    typedef struct _tBasketTime
    {
        T_TIMESTAMP t1[MAX_CHANNEL];			// fist timestamp in a BKT file
        T_TIMESTAMP t2[MAX_CHANNEL];			// last timestamp in a BKT file
    }T_BASKET_TIME;

    typedef struct _tBasketRdb
    {
        unsigned int bid; // basket & index file id;
        unsigned int  idx_pos; // index file pointer }T_BASKET_RDB; #define SIZEOF_RDB 8
    } T_BASKET_RDB;

    typedef struct _tRdbFile
    {
        unsigned char EventType[MINUTES_OF_DAY][MAX_CHANNEL];
        T_BASKET_RDB RdbFile[MINUTES_OF_DAY][MAX_CHANNEL];
    }T_RDBFILE;

    typedef struct _tIndexHeader
    {
        unsigned int   id;
        unsigned int   bid;
        unsigned int   count;
        T_BASKET_TIME ts;
        unsigned int   reserved;
    }T_INDEX_HDR;

    typedef struct _tIndexData{
        unsigned int  id;		// index data id
        T_TS      ts;		// time stamp..sec and usec
        unsigned int  fpos;		// file position
        unsigned int  ch;
        unsigned int  s_type;	// stream type audio, video, etc..
        unsigned int  event;
        short     width __attribute__ ((packed));	// video frame width
        short     height __attribute__ ((packed));	// video frame height
        unsigned int  capMode;
        unsigned int  reserved1 __attribute__ ((packed));
        unsigned int  reserved2 __attribute__ ((packed));
    }T_INDEX_DATA;


    //Functions
    void find_basket_id_and_pos(int  value);
    int pts_to_string_buf(int64_t pts, char *buf, int buf_len);
    int sec_to_string_buf(time_t t, char *buf, int buf_len);
    QDateTime convertdate(QDate date,int value);
    void search_file_and_directory(QString path);
    void read_RdbFile(QString file_path,QDate date);
    void read_Index_File(QString file_path,unsigned int fpos);
    void find_path(QDate date);
    void clik();


    // Values  and Widgets
    QByteArray blob;
    QString fileName ;
    QStringList drive_list;
    QMessageBox message_box;
    T_RDBFILE t1;
    QtAV::VideoOutput *m_renderer1;
    QtAV::VideoOutput *m_renderer2;
    QtAV::VideoOutput *m_renderer3;
    QtAV::VideoOutput *m_renderer4;
    QtAV::AVPlayer *m_player;
    int m_unit;

protected:
private slots:
    void on_select_folder_btn_clicked();
    void  check_drive();
    void on_calendar_clicked(const QDate &date);
    void on_search_btn_clicked();
//    void on_Play_Btn_clicked();
//    void on_Stop_Btn_clicked();

signals:
private:
    Ui::Player *ui;
    Plot *d_plot;
    Plot *d_plot1;
    Plot *d_plot2;
    Plot *d_plot3;
};

#endif // PLAYER_H
