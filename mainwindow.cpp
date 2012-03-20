#include <QHBoxLayout>
#include "mainwindow.h"

MainWindow::MainWindow() {
    _serpinsiShapeRenderer = new SerpinskiShape(this);
    _serpinsiShapeRenderer->setGeometry(0, 0, 615, 550);
    _controlPanel = new ControlPanel(this);
    _controlPanel->setGeometry(615, 0, 70, 550);

//    QHBoxLayout *hLayout = new QHBoxLayout();
//    hLayout->addWidget(_serpinsiShapeRenderer);
//    hLayout->addWidget(_controlPanel);

//    setLayout(hLayout);

    setGeometry(0, 0, 680, 550);
    setWindowTitle("Serpinski shapes");
}

MainWindow::~MainWindow() {
    delete _controlPanel;
}

void MainWindow::changeCorners(int corners) {
//    qDebug("corners");
    _serpinsiShapeRenderer->setCorners(corners);
}

void MainWindow::changeRotate(int rotateAngle) {
//    qDebug("rotate");
    _serpinsiShapeRenderer->setRotate(rotateAngle);
}
