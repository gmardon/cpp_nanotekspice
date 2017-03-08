#include "Editor.hpp"

#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <QtWidgets/QGraphicsItem>

#include "include/Port.hpp"
#include "include/Connection.hpp"
#include "include/Block.hpp"

namespace nts {
    Editor::Editor(::QObject *parent) :
            QObject(parent) {
        conn = 0;
    }

    void Editor::install(::QGraphicsScene *s) {
        s->installEventFilter(this);
        scene = s;
    }

    ::QGraphicsItem *Editor::itemAt(const ::QPointF &pos) {
        ::QList<::QGraphicsItem *> items = scene->items(::QRectF(pos - ::QPointF(1, 1), ::QSize(3, 3)));

        foreach(::QGraphicsItem *item, items) if (item->type() > ::QGraphicsItem::UserType)
            return item;

        return 0;
    }

    bool Editor::eventFilter(::QObject *o, ::QEvent *e) {
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

                        if (/*!port1->getPin()->getTargetPin() && !port2->getPin()->getTargetPin()&&*/ port1->block() != port2->block() && port1->getPin()->getMode() != port2->getPin()->getMode() &&
                            !port1->isConnected(port2)) {
                            conn->setPos2(port2->scenePos());
                            conn->setPort2(port2);

                            if (conn->getPort1()->getPin()->getMode() == Pin::Mode::O && conn->getPort2()->getPin()->getMode() == Pin::Mode::I) {
                                conn->getPort2()->getPin()->setComponent(*conn->getPort1()->block()->getAComponent());
                                conn->getPort2()->getPin()->setTarget(conn->getPort1()->block()->getPinIdFromPin(conn->getPort1()->getPin()));
                                conn->getPort2()->getPin()->setState(conn->getPort2()->getPin()->compute());
                            } else if (conn->getPort1()->getPin()->getMode() == Pin::Mode::I && conn->getPort2()->getPin()->getMode() == Pin::Mode::O) {
                                conn->getPort1()->getPin()->setComponent(*conn->getPort2()->block()->getAComponent());
                                conn->getPort1()->getPin()->setTarget(conn->getPort2()->block()->getPinIdFromPin(conn->getPort2()->getPin()));
                                conn->getPort1()->getPin()->setState(conn->getPort1()->getPin()->compute());
                            }
// TODO need to support all
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
        this->scene->update();
        return QObject::eventFilter(o, e);
    }

    void Editor::clear() {
        this->scene->clear();
        this->conn = 0;
    }
}