#ifndef UNIVERSAL_HPP
#define UNIVERSAL_HPP

#include <QObject>
#include <QDateTime>
#include <QTime>
#include <QTimer>
#include <QVector>
#include <QAbstractButton>
#include <QList>
#include <QCoreApplication>
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
#include <QRandomGenerator>
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(6, 2, 0))
#include <QRegularExpression>
#endif
#include <QStringList>
#include <QDateTime>
#include <QDebug>


namespace UNIVERSAL {

#define CURR_DATE_TIME QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz")

const QString m_none_SheetStyle = "min-width: %2px; \
                                   min-height: %2px; \
                                   max-width: %2px; \
                                   max-height: %2px;\
                                   border-radius: %3px; \
                                   border:1px solid %4; \
                                   background:%1";

inline const QString setCircleStyle(const QString& color, int dia, int border=1) {
    return m_none_SheetStyle.arg(color).arg(dia).arg(dia/2).arg(border);
}

enum ENDIAN {
    BIG         ,   //大端
    LITTLE      ,   //小端
    BIG_SWAP    ,   //大端-交换
    LITTLE_SWAP ,   //小端-交换
};

inline const QString redSheetStyle(uint a, uint b) {
    return m_none_SheetStyle.arg("red").arg(a).arg(b);
}

inline const QString greenSheetstyle(uint a, uint b) {
    return m_none_SheetStyle.arg("#06b025").arg(a).arg(b);
}

inline const QString whiteSheetstyle(uint a, uint b) {
    return m_none_SheetStyle.arg("white").arg(a).arg(b);
}

inline void MSleep(int msec) {
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < dieTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}


//小端 DCBA 4321
inline float getFloat(quint16 l16, quint16 h16, uint pos1, uint pos2, uint pos3, uint pos4) {
    // chTemp 0  1  2  3
    //    0x  12 34 56 78
    //        A  B  C  D
    float a = 0.f;
    unsigned char * r = (unsigned char *)&a;
    unsigned char chTemp[4]; // 4*8=32bit

    //L：0   H:3
    chTemp[0] = l16 & 0xFF;
    chTemp[1] = (l16 >> 8) & 0xFF;
    chTemp[2] = h16 & 0xFF;
    chTemp[3] = (h16 >> 8) & 0xFF;

    *r++ = chTemp[pos1];
    *r++ = chTemp[pos2];
    *r++ = chTemp[pos3];
    *r++ = chTemp[pos4];

    return a;
}

inline float getLittleFloat(quint16 h16, quint16 l16) {
    return getFloat(h16, l16, 3,2,1,0);
}
inline float getLittleFloat(quint32 u32) {
    quint16 h16 = u32 & 0xFFFF;
    quint16 l16 = u32 >> 0x10;
    return getLittleFloat(h16, l16);
}
inline float getLittleSwapFloat(quint16 h16, quint16 l16) {
    return getFloat(h16, l16, 2,3,0,1);
}
inline float getLittleSwapFloat(quint32 u32) {
    quint16 h16 = u32 >> 0x10;
    quint16 l16 = u32 & 0xFFFF;
    return getLittleSwapFloat(h16, l16);
}

//大端 ABCD
inline float getBigFloat(quint16 h16, quint16 l16) {
    return getFloat(h16, l16, 0,1,2,3);
}
inline float getBigFloat(quint32 u32) {
    quint16 h16 = u32 >> 0x10;
    quint16 l16 = u32 & 0xFFFF;
    return getBigFloat(h16, l16);
}
inline float getBigSwapFloat(quint16 h16, quint16 l16) {
    return getFloat(h16, l16, 1,0,3,2);
}
inline float getBigSwapFloat(quint32 u32) {
    quint16 h16 = u32 & 0xFFFF;
    quint16 l16 = u32 >> 0x10;
    return getBigSwapFloat(h16, l16);
}


//转32位浮点数  Big Big-Swap Littel  Littel-S
//             0     1        2       3
inline const QList<float> toFloatDatas(QVector<quint16> datas, ENDIAN model) {
    QList<float> fList;

    if(0 != datas.size() % 2) return fList;
    for(int i = 0; i < datas.size(); i+=2)
    {
        float f;
        if(ENDIAN::BIG == model)            f = UNIVERSAL::getBigFloat(         datas.at(i), datas.at(i+1));
        else if(ENDIAN::BIG_SWAP == model)  f = UNIVERSAL::getBigSwapFloat(     datas.at(i), datas.at(i+1));
        else if(ENDIAN::LITTLE == model)    f = UNIVERSAL::getLittleFloat(      datas.at(i), datas.at(i+1));
        else                                f = UNIVERSAL::getLittleSwapFloat(  datas.at(i), datas.at(i+1));

        fList << f;
    }
    return fList;
}

inline  bool isLittelEndian() {
    return ((uchar)0x1234 == 0x34);
}


inline bool oneButton(QAbstractButton *btn, const int msec, const QString& tipText=nullptr, bool recover=true) {
    if(nullptr == btn) return false;
    if(msec <= 0) return false;

    btn->setEnabled(false);
    auto oldStr = btn->text();
    if(!tipText.isNull()) btn->setText(tipText);
    QTimer::singleShot(msec, [=](){ btn->setEnabled(true);  if(recover) btn->setText(oldStr);});
    return true;
}

inline const QString generateRandomString(const uint length) {
    QString str;
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
    auto randomGenerator = QRandomGenerator::system();
#else
    qsrand(QDateTime::currentMSecsSinceEpoch());
#endif

    for (uint i = 0; i < length; i++) {
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
        int value = randomGenerator->bounded(62);
#else
        int value = qrand() % 62;
#endif
        char nextChar;

        if(value < 10)      nextChar = '0' + value;
        else if(value < 36) nextChar = 'A' + value  - 10;
        else                nextChar = 'a' + value  - 36;
        str.append(nextChar);
    }
    return str;
}

inline bool setRetainSizeHide(QWidget* w, bool b) {
    if(!w) return false;
    auto p = w->sizePolicy();
    p.setRetainSizeWhenHidden(b);
    w->setSizePolicy(p);
    return true;
}

inline QString simplityNumStr(const QString& str, bool *ok = nullptr) {
    QString s;
    bool b;
    if(str.isEmpty() || str.isNull()) {
        if(ok) *ok = false;
        return s;
    }

    auto d = str.toDouble(&b);
    if(!b) {
        if(ok) *ok = false;
        return s;
    }

#if (QT_VERSION >= QT_VERSION_CHECK(6, 2, 0))
    QRegularExpression rx("(\\.){0,1}0+$");
#else
    QRegExp rx;
    rx.setPattern("(\\.){0,1}0+$");
#endif
    s = QString("%1").arg(d,0,'f',-1).replace(rx,"");
    return s;
}

inline QDebug DEBUG(const QString &format = "yyyy-MM-dd hh:mm:ss:zzz") {
    return qDebug() << "[" << QDateTime::currentDateTime().toString(format) << "] ";
}

inline QDebug INFO(const QString &format = "yyyy-MM-dd hh:mm:ss:zzz") {
    return qInfo() << "[" << QDateTime::currentDateTime().toString(format) << "] ";
}

inline QDebug WARNING(const QString &format = "yyyy-MM-dd hh:mm:ss:zzz") {
    return qWarning() << "[" << QDateTime::currentDateTime().toString(format) << "] ";
}

inline QDebug CRITICAL(const QString &format = "yyyy-MM-dd hh:mm:ss:zzz") {
    return qCritical() << "[" << QDateTime::currentDateTime().toString(format) << "] ";
}


}   //namespcae UNIVERSAL


#endif // UNIVERSAL_HPP
