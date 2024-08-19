#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <VAbstractWidget>

class MainWidget : public VAbstractWidget
{
    Q_OBJECT
    ABSTRACT_CLASSNAME
public:
    explicit MainWidget(QWidget *p=nullptr);
    ~MainWidget();

private:
    void InitUi();
    void InitObject();
    void InitConnect();

public slots:


signals:



private:


};








#endif//MAINWIDGET.H