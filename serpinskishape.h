#ifndef SERPINSKISHAPE_H
#define SERPINSKISHAPE_H

#include <QtGui>

class SerpinskiShape : public QWidget
{
    Q_OBJECT
public:
    explicit SerpinskiShape(QWidget *parent = 0);

    void setCorners(int corners);
    void setRotate(int rotateAngle);
    
protected:
    void paintEvent(QPaintEvent *);

private:
    int getMaxRadius() const;
    void drawShape(QPainter &painter, float cx, float cy, float radius);

    int _corners, _rotateAngle;
};

#endif // SERPINSKISHAPE_H
