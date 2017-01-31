//
// Created by gmardon on 31/01/17.
//

#ifndef CUSTOMQGRAPHICSSCENE_H
#define CUSTOMQGRAPHICSSCENE_H
#include <QGraphicsView>

class EditorView : public QGraphicsView
{
public:
    EditorView();

protected:
   void drawBackground(QPainter * painter, const QRectF & rect);
};

#endif // CUSTOMQGRAPHICSSCENE_H