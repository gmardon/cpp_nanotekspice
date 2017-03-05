#include "Connection.hpp"

#include "Port.hpp"

#include <QGraphicsScene>

namespace nts {
    Connection::Connection(QGraphicsItem *parent) : QGraphicsPathItem(parent) {
        setPen(QPen(Qt::black, 2));
        setBrush(Qt::NoBrush);
        setZValue(-1);
        m_port1 = 0;
        m_port2 = 0;
    }

    Connection::~Connection() {
        if (m_port1)
            m_port1->connections().remove(m_port1->connections().indexOf(this));
        if (m_port2)
            m_port2->connections().remove(m_port2->connections().indexOf(this));
    }

    void Connection::setPos1(const QPointF &p) {
        pos1 = p;
    }

    void Connection::setPos2(const QPointF &p) {
        pos2 = p;
    }

    void Connection::setPort1(Port *p) {
        m_port1 = p;

        m_port1->connections().append(this);
    }

    void Connection::setPort2(Port *p) {
        m_port2 = p;

        m_port2->connections().append(this);
    }

    Port *Connection::getPort1() {
        return this->m_port1;
    }

    Port *Connection::getPort2() {
        return this->m_port2;
    }

    void Connection::updatePosFromPorts() {
        pos1 = m_port1->scenePos();
        pos2 = m_port2->scenePos();
    }

    void Connection::updatePath() {
        QPainterPath p;

        p.moveTo(pos1);

        qreal dx = pos2.x() - pos1.x();
        qreal dy = pos2.y() - pos1.y();

        QPointF ctr1(pos1.x() + dx * 0.25, pos1.y() + dy * 0.1);
        QPointF ctr2(pos1.x() + dx * 0.75, pos1.y() + dy * 0.9);

        p.cubicTo(ctr1, ctr2, pos2);

        setPath(p);
    }

    Port *Connection::port1() const {
        return m_port1;
    }

    Port *Connection::port2() const {
        return m_port2;
    }

    void Connection::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
        Q_UNUSED(option)
        Q_UNUSED(widget)

        if ((m_port2 == NULL)) {
            painter->setPen(QPen(Qt::black, 2));
            painter->setBrush(Qt::NoBrush);

            painter->drawPath(path());
            return;
        }

        if (m_port2->getPin()->getState() == TRUE) {
            painter->setPen(QPen(Qt::red, 2));
            painter->setBrush(Qt::NoBrush);
        } else {
            painter->setPen(QPen(Qt::black, 2));
            painter->setBrush(Qt::NoBrush);
        }

        painter->drawPath(path());
    }
}