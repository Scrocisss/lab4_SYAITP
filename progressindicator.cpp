#include "progressindicator.h"
#include <QPainter>
#include <QMouseEvent>

ProgressIndicator::ProgressIndicator(QWidget *parent) : QWidget(parent),
    m_progressValue(0),
    m_maximumValue(100),
    m_minimumValue(0)
{
    setFixedSize(150, 150);
}

int ProgressIndicator::progressValue() const
{
    return m_progressValue;
}

void ProgressIndicator::setProgressValue(int value)
{
    if (value >= m_minimumValue && value <= m_maximumValue) {
        m_progressValue = value;
        update();
    }
}

int ProgressIndicator::maximumValue() const
{
    return m_maximumValue;
}

void ProgressIndicator::setMaximumValue(int value)
{
    m_maximumValue = value;
}

int ProgressIndicator::minimumValue() const
{
    return m_minimumValue;
}

void ProgressIndicator::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    qreal percentage = qRound((qreal)(m_progressValue - m_minimumValue) / (m_maximumValue - m_minimumValue) * 100) / 100.0;
    qreal fillAngle = 360 * percentage;

    QRectF baseRect = rect().adjusted(10, 10, -10, -10);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawEllipse(baseRect);

    painter.setBrush(Qt::green);
    if (percentage <= 0.5) {
        painter.drawPie(baseRect, 90 * 16, -fillAngle * 16);
    } else {
        painter.drawPie(baseRect, 90 * 16 - fillAngle * 16, fillAngle * 16);
    }

    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 12));
    QString percentageText = QString::number(qRound(percentage * 100)) + "%";
    painter.drawText(rect(), Qt::AlignCenter, percentageText);
}

void ProgressIndicator::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        int diff = event->position().y() - height() / 2;
        int newValue = m_progressValue + diff / 2;
        if (newValue < 0) {
            newValue = 0;
        } else if (newValue > 100) {
            newValue = 100;
        }
        setProgressValue(newValue);
    }
}


void ProgressIndicator::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        int diff = event->position().y() - height() / 2;
        int newValue = m_progressValue + diff / 2;
        setProgressValue(newValue);
    }
}
