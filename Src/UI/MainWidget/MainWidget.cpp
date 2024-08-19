#include "MainWidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <Universal>

using namespace UNIVERSAL;

MainWidget::MainWidget(QWidget *p)
    :VAbstractWidget{p}
{
    Initialzation(800, 480);
    InitUi();
    InitObject();
    InitConnect();
}

MainWidget::~MainWidget()
{
    //do something...
}

void MainWidget::InitUi() {
    setWindowTitle(tr("QtGeneralTemplate"));

}

void MainWidget::InitObject() {

}

void MainWidget::InitConnect() {

}
