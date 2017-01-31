//
// Created by gmardon on 31/01/17.
//

#ifndef EDITORVIEW_H
#define EDITORVIEW_H

#include <QGraphicsView>

namespace nts {
    class EditorView : public QGraphicsView {
    public:
        EditorView();

    protected:
        void drawBackground(QPainter *painter, const QRectF &rect);
    };
}

#endif // EDITORVIEW_H