#include <cmath>
#include "serpinskishape.h"

SerpinskiShape::SerpinskiShape(QWidget *parent) : QWidget(parent), _corners(3), _rotateAngle(0) {
}

void SerpinskiShape::setCorners(int corners) {
    _corners = corners;
    update();
}

void SerpinskiShape::setRotate(int rotateAngle) {
    _rotateAngle = rotateAngle;
    update();
}

void SerpinskiShape::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QPen pen(QBrush(Qt::darkGreen), 2.3f);
    painter.setPen(pen);
    painter.setRenderHint(QPainter::Antialiasing, true);

    drawShape(painter, width() * 0.5, height() * 0.5, getMaxRadius());

    painter.setRenderHint(QPainter::Antialiasing, false);
}

int SerpinskiShape::getMaxRadius() const {
    int min = (width() < height()) ? width() : height();
    return min * 0.5 - 15;
}

void SerpinskiShape::drawShape(QPainter &painter, float cx, float cy, float radius) {
    if (radius < 3) return;

    float step = 2 * M_PI / _corners;
    float beginAngle = (-_rotateAngle - 90) * M_PI / 180;
    float endAngle = M_PI * ((float)(-_rotateAngle - 90) / 180 + 2);
    if (_corners == 4) {
        beginAngle += M_PI / 4;
        endAngle += M_PI / 4;
    }

    QVector<QPointF> vertices;
    for (float angle = beginAngle; angle < endAngle; angle += step) {
        vertices.push_back(QPointF(cos(angle) * radius, sin(angle) * radius));
    }
    vertices.push_back(vertices[0]);

    painter.save();
    painter.translate(cx, cy);
    painter.drawPolyline(QPolygonF(vertices));
    painter.restore();

    float nextRadius = 0;
    switch (_corners) {
    case 3:
        nextRadius = radius * 0.5;
        break;
    case 4:
    case 6:
        nextRadius = radius * 0.333;
        break;
    case 5:
        nextRadius = radius / 2.63;
        break;
    }

    float centerRaduis = radius - nextRadius;
    for (float angle = beginAngle; angle < endAngle; angle += step) {
        drawShape(painter,
                  cos(angle) * centerRaduis + cx,
                  sin(angle) * centerRaduis + cy,
                  nextRadius);
    }

    if (_corners != 4) return;

    float addRotate = M_PI / 4;
    beginAngle += addRotate;
    endAngle += addRotate;
    centerRaduis = radius * cos(addRotate) * 0.667;
    for (float angle = beginAngle; angle < endAngle; angle += step) {
        drawShape(painter,
                  cos(angle) * centerRaduis + cx,
                  sin(angle) * centerRaduis + cy,
                  nextRadius);
    }
}
