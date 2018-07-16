#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mnkcalculator.h"
#include "filemanager.h"
#include "deleg.h"
#include <QFile>
#include <QTextStream>
#include <QWidget>
#include <QTableWidget>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->tableWidget->setItemDelegate(new deleg); //loading delegate to tablewidget
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()  //calculating
{
SourceData data;
data=loadfromtable(data);
if (data.xy.size()!=0){
   ui->label->setText(MnkCalculator::Calculating(data));
}
}
void MainWindow::on_pushButton_2_clicked()
{
  ui->tableWidget->setRowCount(ui->tableWidget->rowCount()-1);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
}

void MainWindow::on_pushButton_3_clicked()   //writing data to tablewidget
{
    SourceData data1;
    FileManager File;
    data1=File.LoadFile(this,data1);
    int hs=data1.xy.size()/2;
    int i=0;
    ui->tableWidget->setRowCount(0);
    while (i<hs){
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,new QTableWidgetItem(QString::number(data1.xy[2*i])));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,new QTableWidgetItem(QString::number(data1.xy[2*i+1])));
    i++;
    }

}

void MainWindow::on_pushButton_5_clicked()   //writing data back to file
{
SourceData data;
data=loadfromtable(data);
if (data.xy.size()!=0){
    FileManager file;
    file.SaveFile(this,data);
}
}

SourceData MainWindow::loadfromtable(SourceData data1)  //reading data from tablewidget
{
    int i=0;
    bool clear=true;
        while (i<ui->tableWidget->rowCount()){
        if (!(ui->tableWidget->item(i,0)->text().toDouble()==0 && ui->tableWidget->item(i,0)->text()!="0"))  //checking for incorrect data
        {
             data1.xy.append(ui->tableWidget->item(i,0)->text().toDouble());
        }
        else
        {
             QMessageBox msgBox;
             msgBox.setText("HEKOPPEKTHOE X" +QString::number(i+1));
             msgBox.exec();
             clear=false;
             break;
        }
        if (!(ui->tableWidget->item(i,1)->text().toDouble()==0 && ui->tableWidget->item(i,1)->text()!="0"))  //same as above (lame yeah)
        {
             data1.xy.append(ui->tableWidget->item(i,1)->text().toDouble());
        }
        else
        {
             QMessageBox msgBox;
             msgBox.setText("HEKOPPEKTHOE Y" +QString::number(i+1));
             msgBox.exec();
             clear=false;
             break;
        }
       i++;
    }
  if (clear){
   return data1;
  }
  else{
      data1.xy.clear();
      return data1;
  }
}
