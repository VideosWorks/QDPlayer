#include "player.h"
#include "ui_player.h"
#include<QFileInfo>
#include<QDir>
#include<QDebug>
#include <QFileDialog>
#include <QDirIterator>
#include<QMessageBox>
#include <QPainter>
#include<QPen>
#include<QBrush>
#include <QTextCharFormat>
#include<QPixmap>
#include<QLabel>
#include <QColor>
#include<QRect>
#include <qmainwindow.h>
#include "plot.h"
#include <qwt_date.h>
#include <qwt_scale_widget.h>
#include <qlayout.h>
#include <qsettings.h>
#include<qtimer.h>
#include <cstdio>
#include <cstring>
using namespace QtAV;
using namespace std;

Player::Player(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Player)
{
  ui->setupUi(this);
  this->setStyleSheet("background-color: qlineargradient(spread:reflect, x1:0.5, y1:0, x2:0, y2:0, stop:0 rgba(91, 204, 233, 100), stop:1 rgba(32, 80, 96,100)); ");
  QString tabStyle = "QTabBar {width:500;height:20;margin : 1;radius:5; color:white;font:bold;}"
                     "QTabBar::tab:!selected {width:500;height:20;margin : 1;radius:15; color:white;font:bold;font-size:10pt;}"
                     "QTabBar::tab:selected {width:500;height:20;margin : 1;radius:15; color:white;font:bold;font-size:8pt;background-color:gray}";
  ui->tabWidget->setStyleSheet(tabStyle);
  ui->calendar->setStyleSheet("selection-background-color: blue;   selection-color: white ");
  ui->pushButton->setStyleSheet("background-image:url(video_bk.jpg)");
  ui->pushButton_2->setStyleSheet("background-image:url(video_bk.jpg)");
  ui->pushButton_3->setStyleSheet("background-image:url(video_bk.jpg)");
  ui->pushButton_4->setStyleSheet("background-image:url(video_bk.jpg)");
  //Kullanılacak nesneler oluşturuluyor
  d_plot = new Plot();
  d_plot1 = new Plot();
  d_plot2 = new Plot();
  d_plot3= new Plot();
  d_plot->setMaximumHeight(120);
  ui->chart_grid_layout->addWidget(d_plot);
  /* searh computer drive directory */
  check_drive();
  QTimer *timer = new QTimer( this );
  connect( timer, SIGNAL(timeout()), this, SLOT(check_drive()) );
  timer->start( 10000 ); // 2 seconds single-shot timer
  m_unit = 1000;
  m_player = new AVPlayer(this);
  m_player->setSeekType(KeyFrameSeek);
  m_vo1 = new VideoOutput(this);
  if (!m_vo1->widget()) {
      QMessageBox::warning(0, QString::fromLatin1("QtAV error"), tr("Can not create video renderer 1"));
      return;
    }
  m_vo2 = new VideoOutput(this);
  if (!m_vo2->widget()) {
      QMessageBox::warning(0, QString::fromLatin1("QtAV error"), tr("Can not create video renderer 2"));
      return;
    }
  m_vo3 = new VideoOutput(this);
  if (!m_vo3->widget()) {
      QMessageBox::warning(0, QString::fromLatin1("QtAV error"), tr("Can not create video renderer 3"));
      return;
    }
  m_vo4 = new VideoOutput(this);
  if (!m_vo4->widget()) {
      QMessageBox::warning(0, QString::fromLatin1("QtAV error"), tr("Can not create video renderer 4"));
      return;
    }
  m_player->addVideoRenderer(m_vo1, 0);
  m_player->addVideoRenderer(m_vo2, 1);
  m_player->addVideoRenderer(m_vo3, 2);
  m_player->addVideoRenderer(m_vo4, 3);
  m_player->setFrameRate(12);

  ui->video_grid_layout->addWidget(m_vo1->widget(), 0, 0);
  ui->video_grid_layout->addWidget(m_vo2->widget(), 0, 1);
  ui->video_grid_layout->addWidget(m_vo3->widget(), 1, 0);
  ui->video_grid_layout->addWidget(m_vo4->widget(), 1, 1);
}


Player::~Player()
{
  delete ui;
}

void Player::check_drive()
{
  drive_list.clear();
  foreach( QFileInfo drive, QDir::drives())
    {
      drive_list<<drive.absolutePath();
    }
  if(ui->drive_cbx->count() != drive_list.count())
    {
      ui->drive_cbx->clear();
      for(int i=0;i<drive_list.count();i++)
        {
          ui->drive_cbx->addItem(drive_list[i]);
        }
    }
}


void Player::on_select_folder_btn_clicked()
{
  fileName.clear();
  fileName = QFileDialog::getExistingDirectory(this,"Select");
  if(fileName.isEmpty())
    {
      message_box.setText("Please select folder ");
      message_box.show();
      return;
    }
  else
    {
      search_file_and_directory(fileName);
    }
}


QList<QDate>date_list;
QStringList date_path_list;
QString new_path;
QString rdb_file;
QString basket_file;
void Player::search_file_and_directory(QString path)
{
  d_plot->set_player(this);
  QString rmdb;

  QDirIterator it(path, QDirIterator::Subdirectories);
  while (it.hasNext())
    {
      rmdb=it.next();
      if(rmdb.contains("rdb"))
        {
          qDebug()<<"found  : "<<rmdb;
          new_path=rmdb;
          break;
        }
    }
  QString rmd_member;
  QDate date;
  QDate max_date;
  bool ok(false);
  if(new_path !=0)
    {
      QDirIterator it(new_path, QDirIterator::Subdirectories);
      while (it.hasNext())
        {
          rmd_member=it.next();
          rmd_member=it.fileName();
          date_path_list.append(it.filePath());
          date.setDate(rmd_member.mid(0,4).toInt(&ok),rmd_member.mid(4,2).toInt(&ok),rmd_member.mid(6,2).toInt(&ok));
          date_list.append(date);
        }
      QTextCharFormat day_light;
      if(date_list.size()>2)
        {
          max_date=date_list[2];
          for(int i=2;i<date_list.size();i++)
            {
              //day_light.setBackground(Qt::cyan);
              QFont serifFont("Times", 10, QFont::Bold);
              day_light.setFont(serifFont);
              day_light.setForeground(QColor(Qt::blue));
              ui->calendar->setDateTextFormat(date_list[i],day_light);
              if(max_date<date_list[i])
                {
                  max_date=date_list[i];
                }
            }
          d_plot->applySettings(max_date);
          find_path(max_date);

          day_light.setBackground(QColor(Qt::blue));
          ui->calendar->setSelectedDate(max_date);
        }
      else
        {
          message_box.setText("Not found record at  " +new_path );
          message_box.show();
        }
    }
  else
    {
      message_box.setText("Not found RMDB folder ");
      message_box.show();
    }
}


QString select_date_string;
void Player::on_calendar_clicked(const QDate &date)
{
  if(date_list.contains(date))
    {
      d_plot->applySettings(date);
      find_path(date);
    }
  else
    {
      qDebug()<<"not found selected date ";
    }
}
void Player::find_path(QDate date)
{
  QString find_date=date.toString("yyyyMMdd");
  for(int i=0;i<date_path_list.size();i++)
    {
      if(date_path_list[i].contains(find_date))
        {
          read_RdbFile(date_path_list[i], date);
          break;
        }
    }
}


void Player::read_RdbFile(QString file_path,QDate date)
{
  qDebug()<<"path: "<< file_path;
  qDebug() << "*n\n\n Start read rdb file ";
  d_plot->first_paint(convertdate(date,0),convertdate(date,1439),1);
  d_plot->first_paint(convertdate(date,0),convertdate(date,1439),2);
  d_plot->first_paint(convertdate(date,0),convertdate(date,1439),3);
  d_plot->first_paint(convertdate(date,0),convertdate(date,1439),4);
  QFile file(file_path);
  if(!file.open(QIODevice::ReadOnly))
    {
      return;
    }
  qDebug()<< "size t1 :"<< sizeof(t1);
  blob = file.readAll();
  QString blob_str = blob.toHex();
  qDebug()<<"reading file   :"<<  file_path;
  qDebug()<<file.size();
  int current_value=0;
  int index ;
  bool ok(false);
  QString bid_str;
  QString idx_str;
  for(int i=0;i<MAX_CHANNEL;i++)
    {
      int start_value=0;
      bool control=false;
      int   last_vaule=0;
      for(int j=0;j<MINUTES_OF_DAY;j++)
        {
          index = 1440*2*8 + 1440*16*i+16*(j);
          current_value=blob[i*1440+j];
          bid_str=blob_str.mid(index+6,2)+blob_str.mid(index+4,2)+blob_str.mid(index+2,2)+blob_str.mid(index+0,2);
          idx_str=blob_str.mid(index+14,2)+blob_str.mid(index+12,2)+blob_str.mid(index+10,2)+blob_str.mid(index+8,2);
          int bid_int =bid_str.toInt(&ok,16);
          int idx_int=idx_str.toInt(&ok,16);
          t1.RdbFile[j][i].bid=bid_int;
          t1.RdbFile[j][i].idx_pos=idx_int;
          //    qDebug()<< "index :" <<   index << "camera       :  "<<i <<   "minutes    :  "<< j    <<   "basket_id : "<<t1.RdbFile[j][i].bid<<     "idx_pos  : "<< t1.RdbFile[j][i].idx_pos;
          if(current_value==last_vaule)
            {
              if(control==false)
                {
                  qDebug()<<"---------------------üst---------------------------";
                  qDebug() <<"last value    :   "<< last_vaule  << "current value : "     <<current_value;
                  qDebug()<< "i   :      "<< i << "      j:    "<< j;
                  qDebug()<<"---------------------üst---------------------------";
                  start_value=j;
                  control=true;
                }
            }
          else
            {
              if(control==true)
                {
                  if(last_vaule==0)
                    {
                      qDebug()<<"---------------------0 icin---------------------------";
                      qDebug() <<"last value    :   "<< last_vaule  << "current value : "     <<current_value;
                      qDebug()<< "i   :      "<< i << "      j:    "<< j;
                      qDebug()<<"---------------------0 icin---------------------------";
                    }
                  if(last_vaule==1)
                    {
                      qDebug()<<"--------------------1 icin---------------------------";
                      qDebug() <<"last value    :   "<< last_vaule  << "current value : "     <<current_value;
                      qDebug()<< "i   :      "<< i << "      j:    "<< j;
                      qDebug()<<"---------------------1 icin---------------------------";
                      d_plot->paint(convertdate(date,start_value),convertdate(date,j),1,i+1);
                    }
                  if(last_vaule==2)
                    {
                      qDebug()<<current_value;
                      qDebug()<< "i   :      "<< i << "     j:    "<< j;
                      d_plot->paint(convertdate(date,start_value),convertdate(date,j),2,i+1);
                    }
                  if(last_vaule==3)
                    {
                      d_plot->paint(convertdate(date,start_value),convertdate(date,j),3,i+1);
                      qDebug()<<current_value;
                    }
                  last_vaule=current_value;
                  control=false;
                  start_value=0;
                }
              else
                {
                  last_vaule=current_value;
                }
            }

        }
    }
  if(date !=QDate::currentDate())
    {
      d_plot->Stick1(convertdate(date,1439));
    }
  file.close();
}

void Player::on_search_btn_clicked()
{
  search_file_and_directory(ui->drive_cbx->currentText());
}


QDateTime Player::convertdate(QDate date,int value)
{
  QString time_str = QDateTime::fromTime_t(value*60).toUTC().toString("hh:mm");
  QTime time = QTime::fromString(time_str,"hh:mm");
  QDateTime return_date=QDateTime(date,time,Qt::UTC);
  return return_date;
}

void Player::find_basket_id_and_pos(int  value)
{
  //    for(int i=0;i<4 ;i++)
  //    {
  //        for(int j=0;j<1440;j++)
  //        {
  //            qDebug() << "camera       :  "<<i+1 <<   "minutes    :  "<< j    <<   "basket_id : "<<t1.RdbFile[j][i].bid<<     "idx_pos  : "<< t1.RdbFile[j][i].idx_pos;
  //        }
  //    }
  //    qDebug()<< "Size of  Rdb Header :"<< sizeof(t1.EventType);
  //    qDebug()<<"Size of Rdbs :" << sizeof(t1.RdbFile);
  //    qDebug()<< "Total  Size : "<< sizeof(t1);
  //    qDebug() <<  "\n\n\n ---rdb  read  finished ---";
  int find_bkt=0;
  for(int ch=0;ch<MAX_CHANNEL;ch++)
    {
      if(t1.RdbFile[value][ch].bid !=0  && t1.RdbFile[value][ch].idx_pos!=0)
        {
          find_bkt=1;
          QString index_file_name ;
          int path_ind=new_path.indexOf("rdb");
          index_file_name=QString::number( t1.RdbFile[value][ch].bid);
          while(index_file_name.size()<8)
            {
              index_file_name="0"+index_file_name;
            }
          rdb_file=new_path.mid(0, path_ind)+index_file_name+".idx";
          basket_file=new_path.mid(0, path_ind)+index_file_name+".bkt";
          m_player->play(basket_file);
          read_Index_File(new_path.mid(0, path_ind)+index_file_name+".idx",t1.RdbFile[value][ch].idx_pos);
        }
    }
  if(find_bkt==0)
    {
      m_player->stop();
    }
}


int Player::sec_to_string_buf(time_t t, char *buf, int buf_len)
{
  struct tm *p;
  if (!(p = localtime(&t)))
    {
      qDebug()<<" date conversion error ";
    }
  if (!strftime(buf, buf_len, "%Y-%m-%d %H:%M:%S", p))
    {
      qDebug()<< " date conversion error 2 ";
    }
  return 0;
}

int Player::pts_to_string_buf(int64_t pts, char *buf, int buf_len)
{
  time_t t = pts/1000000;
  return sec_to_string_buf(t, buf, buf_len);
}
int first_seek=0;
void Player::read_Index_File(QString file_path,unsigned int fpos )
{

  qDebug()<< " read index "<< file_path;
  FILE *idx;
  char* cstr;
  string fname = file_path.toStdString();
  cstr = new char [fname.size()+1];
  strcpy( cstr, fname.c_str() );
  idx = fopen(cstr,"rb");
  if(!idx)
    {
      qDebug()<<"not open idx file ";
    }
  else
    {

      T_INDEX_HDR ihd;
      if(fread((unsigned char *)&ihd, 1, sizeof(T_INDEX_HDR), idx) < sizeof(T_INDEX_HDR))
        {
          qDebug()<<"failed index header file ";
        }
      else
        {

          if(QString::number(ihd.id, 16) =="f0000001")
            {
              int index_count=0;
              T_INDEX_DATA idd;
              int64_t t1[MAX_CHANNEL],t2[MAX_CHANNEL];
              for(int ch=0;ch<MAX_CHANNEL;ch++)
                {
                  t1[ch] = 0;
                  t2[ch] = 0;
                }
              fseek(idx,fpos,SEEK_SET);
              if(fread((unsigned char *)&idd, 1, sizeof(T_INDEX_DATA), idx) && index_count<=ihd.count )
                {
                  if(QString::number(idd.id, 16) =="f0000002")
                    {
                      int64_t pos, pts;
                      pts = idd.ts.sec * (int64_t)1000000 + idd.ts.usec;
                      pos = idd.fpos;
                      char t1_buf[32];
                      pts_to_string_buf(pts, t1_buf, sizeof(t1_buf));

                    if(first_seek==0)
                      {
                        qDebug()<< QString::number(idd.id, 16) << "T_TS :  " << t1_buf << " idd fpos :"<<idd.fpos << " idd ch :"<< idd.ch<< " s_type : "<< idd.s_type<< "event :"<< idd.event  << " width :   "<< idd.width << " height : "<< idd.height << " cap mode :"<< idd.capMode;
                        qint64 a= idd.fpos;
                        qDebug() <<"seek value :"<<a;
                         m_player->seek(a);
                      }


                    }
                  else
                    {
                      qDebug() << "header id  is not correct :" << idd.id;
                    }
                }
                             //          while(fread((unsigned char *)&idd, 1, sizeof(T_INDEX_DATA), idx) && index_count<=ihd.count )
                             //            {
                             //              int64_t pos, pts;
                             //              pts = idd.ts.sec * (int64_t)1000000 + idd.ts.usec;
                             //              pos = idd.fpos;
                             //              char t1_buf[32];
                             //              pts_to_string_buf(pts, t1_buf, sizeof(t1_buf));
                             //              qDebug()<< QString::number(idd.id, 16) << "T_TS :  " << t1_buf << " idd fpos :"<<idd.fpos << " idd ch :"<< idd.ch<< " s_type : "<< idd.s_type<< "event :"<< idd.event  << " width :   "<< idd.width << " height : "<< idd.height << " cap mode :"<< idd.capMode;
                             //              index_count++;
                             //            }
            }
          else
            {
              qDebug()<< " index heard id is not correct ";
            }
        }

    }
}

void Player::on_Play_Btn_clicked()
{
  qint64 x=26368;
  qDebug()<< x;
  if (!m_player->isPlaying()) {
      m_player->play();
      return;
    }
  m_player->pause(!m_player->isPaused());
  //  m_player->seek(x);

}

void Player::on_Stop_Btn_clicked()
{
  m_player->stop();
  //   qDebug()<<"stopp";
  //  qint64 x=1136722;
  //  m_player->seek(x);

}

