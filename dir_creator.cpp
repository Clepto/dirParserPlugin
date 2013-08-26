#include "dir_creator.h"
#include <QDir>
#include <QDebug>

DirParser::DirParser(QQuickItem *parent)
    : QQuickItem(parent)
{
}

bool DirParser::createDirectory(const QString &name)
{
    QDir dir;
    return dir.mkpath(name);
}

QStringList DirParser::fetchAllFiles(const QString &name){
    QDir dir(name);
    if(!dir.exists())
        return QStringList("");
    dir.setFilter(QDir::NoDotAndDotDot | QDir::Files);

    return dir.entryList();
}

bool DirParser::dirExists(const QString &name){
    return QDir(name).exists();
}
