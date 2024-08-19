#include "MainWidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <Universal>

using namespace UNIVERSAL;

MainWidget::MainWidget(QWidget *p)
    :QWidget{p}
{
    InitUi();
    InitObject();
    InitConnect();
    InitProperty();
}

MainWidget::~MainWidget()
{
    //do something...
}

void MainWidget::InitUi()
{
    setObjectName("MainWidget");
    setWindowTitle(tr("QtGeneralTemplate"));
    resize(400,400);

    auto rootLayout = new QHBoxLayout(this);
    rootLayout->setContentsMargins(0, 0, 0, 0);
    rootLayout->setSpacing(0);

    auto backWidget = new QWidget(this);
    backWidget->setObjectName("MainWidgetBackgroundWidget");
    
    auto backLayout = new QHBoxLayout(backWidget);
    backLayout->setContentsMargins(0, 0, 0, 0);
    backLayout->setSpacing(0);

    auto shadeWidget = new QWidget(backWidget);
    shadeWidget->setObjectName("MainWidgetShadeWidget");
    
    auto shadeLayout = new QHBoxLayout(shadeWidget);
    shadeLayout->setContentsMargins(0, 0, 0, 0);
    shadeLayout->setSpacing(0);




    //Layout 
    rootLayout->addWidget(backWidget);
    backLayout->addWidget(shadeWidget);


}

void MainWidget::InitObject()
{

}

void MainWidget::InitConnect()
{

}

void MainWidget::InitProperty()
{
    QFile qss(":/style/MainWidget.css");
    if(qss.open(QFile::ReadOnly))
    {
        setStyleSheet(qss.readAll());
        qss.close();
    }
    else WARNING() << "[ERROR] style load failed!";
}

