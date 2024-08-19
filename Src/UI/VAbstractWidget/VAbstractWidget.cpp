#include "VAbstractWidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

#include <QMouseEvent>
#include <QFile>

#include <Universal>

using namespace UNIVERSAL;

VAbstractWidget::VAbstractWidget(QWidget *parent)
    : QWidget{parent}
{
}


VAbstractWidget::~VAbstractWidget() {

}

void VAbstractWidget::Initialzation(int width, int height) {
    m_iFuncWidht = width;
    m_iFuncHeight = height;

    InitUi();
    InitObject();
    InitConnect();
    InitProperty();
}

void VAbstractWidget::setDoubleClickOutsideHide(bool b) {
    m_bDoubleClickHide = b;
}

bool VAbstractWidget::isDoubleClickHide() const {
    return m_bDoubleClickHide;
}



void VAbstractWidget::InitUi() {
    setObjectNameForDerived();

    parentWidget() ? resize(parentWidget()->width(), parentWidget()->height())
                   : resize(m_iWidth, m_iHeight);

    auto rootLayout = new QHBoxLayout(this);
    rootLayout->setContentsMargins(0, 0, 0, 0);
    rootLayout->setSpacing(0);

    m_pBackgroundWidget = new QWidget(this);
    m_pBackgroundWidget->setObjectName(objectName()+"BackgroundWidget");

    auto backgroundLayout = new QHBoxLayout(m_pBackgroundWidget);
    backgroundLayout->setContentsMargins(0, 0, 0, 0);
    backgroundLayout->setSpacing(0);

    m_pShadeWidget = new QWidget(m_pBackgroundWidget);
    m_pShadeWidget->setObjectName(objectName()+"ShadeWidget");

    auto shadeLayout = new QHBoxLayout(m_pShadeWidget);
    shadeLayout->setContentsMargins(0, 0, 0, 0);
    shadeLayout->setSpacing(0);


    rootLayout->addWidget(m_pBackgroundWidget);
    backgroundLayout->addWidget(m_pShadeWidget);

    m_pFuncWidget = new QWidget(m_pShadeWidget);
    m_pFuncWidget->setObjectName(objectName()+"FuncWidget");
    m_pFuncWidget->resize(m_iFuncWidht, m_iFuncHeight);


    if(parentWidget())
        m_pFuncWidget->move((parentWidget()->width() - m_pFuncWidget->width()) / 2,
                            (parentWidget()->height() - parentWidget()->height()) / 2);
    else
        m_pFuncWidget->resize(m_iWidth, m_iHeight);

}

void VAbstractWidget::InitObject() {

}

void VAbstractWidget::InitConnect() {
}

void VAbstractWidget::InitProperty() {
    QFile qss(QString(":/style/%1.css").arg(objectName()));
    if(qss.open(QFile::ReadOnly)) {
        setStyleSheet(qss.readAll());
        qss.close();
    }
    else WARNING() << "[WARNING] [UI] style load failed!";
}

void VAbstractWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event)
    m_iWidth = width();
    m_iHeight = height();

    if(parentWidget()) {
        resize(parentWidget()->width(), parentWidget()->height());
        m_pFuncWidget->move((parentWidget()->width() - m_pFuncWidget->width()) / 2,
                            (parentWidget()->height() - m_pFuncWidget->height()) / 2);
    } else {
        m_pFuncWidget->resize(m_iWidth, m_iHeight);
    }

}

void VAbstractWidget::mouseDoubleClickEvent(QMouseEvent *event) {
    if(Qt::LeftButton == event->button()) {
        if(!m_pFuncWidget->underMouse() && m_bDoubleClickHide){
            hide();
        }
    }
}




