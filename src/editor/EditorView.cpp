//
// Created by gmardon on 31/01/17.
//
#include "EditorView.h"
#include <QPainter>

static const int GRID_STEP = 30;

inline qreal round(qreal val, int step) {
    int tmp = int(val) + step /2;
    tmp -= tmp % step;
    return qreal(tmp);
}

EditorView::EditorView() : QGraphicsView()
{}

void EditorView::drawBackground(QPainter *painter, const QRectF &rect)
{
    int step = GRID_STEP;
    painter->setBrush(QBrush("#3C3C3C"));
    // draw horizontal grid
    qreal start = round(rect.top(), step);
    if (start > rect.top()) {
        start -= step;
    }
    for (qreal y = start - step; y < rect.bottom(); ) {
        y += step;
        painter->drawLine(rect.left(), y, rect.right(), y);
    }
    // now draw vertical grid
    start = round(rect.left(), step);
    if (start > rect.left()) {
        start -= step;
    }
    for (qreal x = start - step; x < rect.right(); ) {
        x += step;
        painter->drawLine(x, rect.top(), x, rect.bottom());
    }
    painter->setBackgroundMode(Qt::OpaqueMode);
    painter->setBackground(QBrush("#353535"));
}