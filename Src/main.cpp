#include <QApplication>

#include "MainWidget.h"

#include <QFont>
#include <QFontDatabase>
#include <QDebug>
#include <QDateTime>

#include "SaveLog.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    qDebug() << "[" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz") << "] "
                << "[Application] [Start] \"Program\"";

    if((qApp->arguments().size() >= 1) && qApp->arguments().contains("--log")) {
#ifdef LOG_MODULE
        SaveLog::Instance()->setPath(QApplication::applicationDirPath()+"/log/");
        SaveLog::Instance()->setMaxSize(10240);

#ifdef DEBUG
        SaveLog::Instance()->setMsgType(MsgType_Debug);
#endif
        SaveLog::Instance()->setUseContext(true);
        SaveLog::Instance()->setListenPort(12345);
        SaveLog::Instance()->setToNet(true);
        SaveLog::Instance()->start();
#endif
    }
    
    int fontId = QFontDatabase::addApplicationFont(QApplication::applicationDirPath()+"/dependent/font/myfont.ttf");
    if(0 == fontId) {
        QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
        QFont font(fontName);
        QApplication::setFont(font);
    } else {
        qDebug() << "[" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz") << "] "
                    << "[Application] [Font] WARNING: font load failed!";
    }


    MainWidget w;
    w.show();

    return a.exec();
}