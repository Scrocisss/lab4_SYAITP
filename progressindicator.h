#ifndef PROGRESSINDICATOR_H
#define PROGRESSINDICATOR_H

#include <QWidget>

class ProgressIndicator : public QWidget
{
    Q_OBJECT

public:
    explicit ProgressIndicator(QWidget *parent = nullptr);

    int progressValue() const;
    void setProgressValue(int value);

    int maximumValue() const;
    void setMaximumValue(int value);

    int minimumValue() const;
    void setMinimumValue(int value);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    int m_progressValue;
    int m_maximumValue;
    int m_minimumValue;
};

#endif // PROGRESSINDICATOR_H
