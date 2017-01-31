#include "Editor.h"

#include <QGraphicsScene>
#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <QtWidgets/QGraphicsItem>

#include "Port.h"
#include "Connection.h"
#include "Block.h"

Editor::Editor(QObject *parent) :
        QObject(parent) {
    conn = 0;
}

void Editor::install(QGraphicsScene *s) {
    s->installEventFilter(this);
    scene = s;
}

QGraphicsItem *Editor::itemAt(const QPointF &pos) {
    QList<QGraphicsItem *> items = scene->items(QRectF(pos - QPointF(1, 1), QSize(3, 3)));

            foreach(QGraphicsItem *item, items) if (item->type() > QGraphicsItem::UserType)
                return item;

    return 0;
}

bool Editor::eventFilter(QObject *o, QEvent *e) {
    QGraphicsSceneMouseEvent *me = (QGraphicsSceneMouseEvent *) e;

    switch ((int) e->type()) {
        case QEvent::GraphicsSceneMousePress: {

            switch ((int) me->button()) {
                case Qt::LeftButton: {
                    QGraphicsItem *item = itemAt(me->scenePos());
                    if (item && item->type() == Port::Type) {
                        conn = new Connection(0);
                        scene->addItem(conn);
                        conn->setPort1((Port *) item);
                        conn->setPos1(item->scenePos());
                        conn->setPos2(me->scenePos());
                        conn->updatePath();

                        return true;
                    } else if (item && item->type() == Block::Type) {
                        /* if (selBlock)
                            selBlock->setSelected(); */
                        // selBlock = (QNEBlock*) item;
                    }
                    break;
                }
                case Qt::RightButton: {
                    QGraphicsItem *item = itemAt(me->scenePos());
                    if (item && (item->type() == Connection::Type || item->type() == Block::Type))
                        delete item;
                    // if (selBlock == (QNEBlock*) item)
                    // selBlock = 0;
                    break;
                }
            }
        }
        case QEvent::GraphicsSceneMouseMove: {
            if (conn) {
                conn->setPos2(me->scenePos());
                conn->updatePath();
                return true;
            }
            break;
        }
        case QEvent::GraphicsSceneMouseRelease: {
            if (conn && me->button() == Qt::LeftButton) {
                QGraphicsItem *item = itemAt(me->scenePos());
                if (item && item->type() == Port::Type) {
                    Port *port1 = conn->port1();
                    Port *port2 = (Port *) item;

                    if (port1->block() != port2->block() && port1->isOutput() != port2->isOutput() &&
                        !port1->isConnected(port2)) {
                        conn->setPos2(port2->scenePos());
                        conn->setPort2(port2);
                        conn->updatePath();
                        conn = 0;
                        return true;
                    }
                }

                delete conn;
                conn = 0;
                return true;
            }
            break;
        }
    }
    return QObject::eventFilter(o, e);
}

void Editor::save(QDataStream &ds) {
            foreach(QGraphicsItem *item, scene->items()) if (item->type() == Block::Type) {
                ds << item->type();
                ((Block *) item)->save(ds);
            }

            foreach(QGraphicsItem *item, scene->items()) if (item->type() == Connection::Type) {
                ds << item->type();
                ((Connection *) item)->save(ds);
            }
}

void Editor::load(QDataStream &ds) {
    scene->clear();

    QMap<quint64, Port *> portMap;

    while (!ds.atEnd()) {
        int type;
        ds >> type;
        if (type == Block::Type) {
            Block *block = new Block(0);
            scene->addItem(block);
            block->load(ds, portMap);
        } else if (type == Connection::Type) {
            Connection *conn = new Connection(0);
            scene->addItem(conn);
            conn->load(ds, portMap);
        }
    }
}
