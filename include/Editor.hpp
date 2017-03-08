#ifndef QNODESEDITOR_H
#define QNODESEDITOR_H

#include <QObject>
#include <QtWidgets/QGraphicsScene>
#include <include/Connection.hpp>


class QPointF;

class QGraphicsScene;

class QGraphicsItem;

class QObject;

namespace nts {

    class Block;

    class Editor : public QObject {
    Q_OBJECT
    public:
        explicit Editor(QObject *parent = 0);

        void install(QGraphicsScene *scene);

        bool eventFilter(QObject *, QEvent *);

        void clear();

    private:
        QGraphicsItem *itemAt(const QPointF &);

    private:
        QGraphicsScene *scene;
        Connection *conn;
    };
}

#endif // QNODESEDITOR_H
