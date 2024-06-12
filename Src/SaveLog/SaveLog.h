#ifndef SAVELOG_H
#define SAVELOG_H
#include <QObject>

QT_BEGIN_NAMESPACE
class QFile;
class QTcpSocket;
class QTcpServer;
QT_END_NAMESPACE

enum MsgType {
    MsgType_Debug = 0x0001,
    MsgType_Info = 0x0002,
    MsgType_Warning = 0x0004,
    MsgType_Critical = 0x0008,
    MsgType_Fatal = 0x0010,
};

#ifdef quc
class Q_DECL_EXPORT SaveLog : public QObject
#else
class SaveLog : public QObject
#endif

{
    Q_OBJECT
public:
    static SaveLog *Instance();
    explicit SaveLog(QObject *parent = 0);
    ~SaveLog();

private:
    static QScopedPointer<SaveLog> self;

    bool isRun;
    //文件最大行数 0表示不启用
    int maxRow, currentRow;
    //文件最大大小 0表示不启用 单位kb
    int maxSize;
    //是否重定向到网络
    bool toNet;
    //是否输出日志上下文
    bool useContext;

    QFile *file;
    QString path;
    QString name;
    QString fileName;
    MsgType msgType;

private:
    void openFile(const QString &fileName);

public:
    bool getUseContext();
    MsgType getMsgType();

Q_SIGNALS:
    void send(const QString &content);

public Q_SLOTS:
    void start();
    void stop();

    void clear();
    void save(const QString &content);

    void setMaxRow(int maxRow);
    void setMaxSize(int maxSize);

    void setListenPort(int listenPort);
    void setToNet(bool toNet);
    //设置是否输出日志上下文
    void setUseContext(bool useContext);

    //设置日志文件存放路径
    void setPath(const QString &path);
    //设置日志文件名称
    void setName(const QString &name);
    //设置消息类型
    void setMsgType(const MsgType &msgType);
};

#ifdef quc
class Q_DECL_EXPORT SendLog : public QObject
#else
class SendLog : public QObject
#endif

{
    Q_OBJECT
public:
    static SendLog *Instance();
    explicit SendLog(QObject *parent = 0);
    ~SendLog();

private:
    static QScopedPointer<SendLog> self;

    int listenPort;
    QTcpSocket *socket;
    QTcpServer *server;

private slots:
    void newConnection();

public Q_SLOTS:
    void setListenPort(int listenPort);

    void start();
    void stop();

    void send(const QString &content);
};

#endif // SAVELOG_H

