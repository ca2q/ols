#include "filemanager.h"
#include "mainwindow.h"
#include <QFile>
#include "ui_mainwindow.h"
#include <QTextStream>


FileManager::FileManager()
{

}
SourceData FileManager::LoadFile(QWidget* w,SourceData data)
{
    file.setFileName(QFileDialog::getOpenFileName(w,"Open File", "/", "Text Files (*.txt)"));      //creating dialog to open file
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))                                         //opening text file in read only mode
             return data;
    QString line,x,y;
    QTextStream in(&file);
    bool clear=true;
    while (!in.atEnd()) {
         line = in.readLine();
         x=line.midRef(0,line.indexOf(" ") ).toString();                                          //diving line to 2 separate numbers
         y=line.midRef(line.indexOf(" ")+1,line.size()-line.indexOf(" ")-1).toString();

         if (!(x.toDouble()==0 && x!="0"))
         {
              data.xy.append( x.toDouble()  );                                                    //and writing it to sourcedata if its сorrect
         }
         else
         {
              clear=false;
         }

         if (!(y.toDouble()==0 && y!="0"))
         {
              data.xy.append( y.toDouble()  );                                                    //same yeah
         }
         else
         {
              clear=false;
         }
         if(!clear){
             QMessageBox msgBox;
             msgBox.setText("incorrect data in file");                                           //an ERROR message
             msgBox.exec();
             clear=false;
             break;
         }
    }
    file.close();

    if (clear){
     return data;
    }
    else{
        data.xy.clear();
        return data;
    }
}



void FileManager::SaveFile(QWidget* w,SourceData data)
{
    file.setFileName(QFileDialog::getSaveFileName(w,"Save File", "/", "Text Files (*.txt)"));
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
             return;
    QTextStream out(&file);
    int hs=data.xy.size()/2; //setting Loop count
    int i=0;
    while (i<hs){
          out << data.xy[2*i] << " " <<  data.xy[2*i+1] << "\n";;
          i++;
    }
    file.close();
}
