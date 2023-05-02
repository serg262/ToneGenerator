#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QtMultimedia/QAudioDeviceInfo>
#include <QtMultimedia/QAudioOutput>

#include <QByteArray>
#include <QBuffer>

#include <QtCharts/QChartGlobal>

#include "ringbuffer.h"

QT_CHARTS_BEGIN_NAMESPACE
class QLineSeries;
class QChart;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE



namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:


private slots:
    void on_pushButton_clicked();
    void onClicked(QPointF point);

private:
    Ui::Widget *ui;
    QByteArray buffer;
    QAudioOutput * m_audioOutput;
    QBuffer *buf;

    QList<int> list;

    RingBuffer *r_buffer;
};

#endif // WIDGET_H
