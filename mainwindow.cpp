#include "mainwindow.h"
#include <QHBoxLayout>
#include <QSlider>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_progressIndicator = new ProgressIndicator(this);
    QSlider *slider = new QSlider(Qt::Horizontal, this);

    connect(slider, &QSlider::valueChanged, m_progressIndicator, &ProgressIndicator::setProgressValue);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(slider);
    layout->addWidget(m_progressIndicator);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
}
