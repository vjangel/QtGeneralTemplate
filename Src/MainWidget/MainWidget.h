#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QFile>
#include <QFrame>


class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *p=nullptr);
    ~MainWidget();

private:
    void InitUi();
    void InitObject();
    void InitConnect();
    void InitProperty();

public slots:


signals:



private:


};








#endif//MAINWIDGET.H