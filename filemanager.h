#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "sourcedata.h"
#include <QFile>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QTableWidget>

class FileManager
{
public:
    QFile file;
    FileManager();
    SourceData LoadFile(QWidget* w,SourceData data);
    void SaveFile(QWidget* w,SourceData data);

};

#endif // FILEMANAGER_H
