#ifndef VABSTRACTWIDGET_H
#define VABSTRACTWIDGET_H

#include <QWidget>

#define ABSTRACT_CLASSNAME \
protected: \
    virtual void setObjectNameForDerived() override { \
        setObjectName(metaObject()->className()); \
    }


class VAbstractWidget : public QWidget
{
    Q_OBJECT
public:
    explicit VAbstractWidget(QWidget *parent);
    ~VAbstractWidget();

    void Initialzation(int width = 800,
                       int height = 480);

    void setDoubleClickOutsideHide(bool b = false);

    bool isDoubleClickHide() const;

private:
    void InitUi();
    void InitObject();
    void InitConnect();
    void InitProperty();

protected:
    virtual void setObjectNameForDerived() = 0;

    virtual void paintEvent(QPaintEvent *event) override;

    virtual void mouseDoubleClickEvent(QMouseEvent *event) override;

signals:

private:
    int m_iWidth = 800;
    int m_iHeight = 480;

    int m_iFuncWidht = 800;
    int m_iFuncHeight = 480;

    bool m_bDoubleClickHide = false;

protected:
    QWidget * m_pBackgroundWidget;
    QWidget * m_pShadeWidget;
    QWidget * m_pFuncWidget;

};



#endif // VABSTRACTWIDGET_H
