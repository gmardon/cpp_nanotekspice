//
// Created by gmardon on 31/01/17.
//
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QAction>
#include <QtWidgets/QMenu>
#include <QtWidgets/QPushButton>
#include "EditorView.h"

namespace nts {
    static const int GRID_STEP = 30;

    inline qreal round(qreal val, int step) {
        int tmp = int(val) + step / 2;
        tmp -= tmp % step;
        return qreal(tmp);
    }

    void EditorView::addComponent() {
        QAction *action = (QAction *) sender();
        if (action->text().toStdString() == "input") {
            printf("add input");
        }
    }
    void EditorView::showContextMenu(const QPoint &pos)
    {
        QMenu contextMenu("Context menu", this);
        QAction *actions[10];

        for (int i = 0; i < 10; ++i) {
            QString text = QString::number(i);
            //buttons[i] = new QPushButton(text, this);

            actions[i] = new QAction(text, this);
            connect(actions[i], SIGNAL(triggered()), this, SLOT(addComponent()));

            contextMenu.addAction(actions[i]);
        }

        //QAction action1("add input", this);
        //connect(&action1, SIGNAL(triggered()), this, SLOT(addComponent()));


        contextMenu.exec(mapToGlobal(pos));
    }

    EditorView::EditorView() : QGraphicsView() {
        this->setContextMenuPolicy(Qt::CustomContextMenu);
        connect(this, SIGNAL(customContextMenuRequested(const QPoint &)),
                this, SLOT(showContextMenu(const QPoint &)));
    }

    void EditorView::drawBackground(QPainter *painter, const QRectF &rect) {
        int step = GRID_STEP;

        painter->setBrush(QBrush("#353535"));
        painter->drawRect(rect);
        painter->setPen(QColor("#3C3C3C"));
        // draw horizontal grid
        qreal start = round(rect.top(), step);
        if (start > rect.top()) {
            start -= step;
        }
        for (qreal y = start - step; y < rect.bottom();) {
            y += step;
            painter->drawLine(rect.left(), y, rect.right(), y);
        }
        // now draw vertical grid
        start = round(rect.left(), step);
        if (start > rect.left()) {
            start -= step;
        }
        for (qreal x = start - step; x < rect.right();) {
            x += step;
            painter->drawLine(x, rect.top(), x, rect.bottom());
        }
    }
}