#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "serpinskishape.h"
#include "controlpanel.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow();
    ~MainWindow();
    
signals:
    
public slots:
    void changeCorners(int corners);
    void changeRotate(int rotateAngle);

private:
    SerpinskiShape *_serpinsiShapeRenderer;
    ControlPanel *_controlPanel;
    
};

#endif // MAINWINDOW_H
