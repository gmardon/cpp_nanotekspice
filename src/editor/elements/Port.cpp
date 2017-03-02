#include "Port.hpp"

#include <QGraphicsScene>
#include <QFontMetrics>

#include "Connection.hpp"

namespace nts {
    Port::Port(QGraphicsItem *parent) :
            QGraphicsPathItem(parent) {
        label = new QGraphicsTextItem(this);

        radius_ = 5;
        margin = 2;

        QPainterPath p;
        p.addEllipse(-radius_, -radius_, 2 * radius_, 2 * radius_);
        setPath(p);

        setPen(QPen(Qt::black));
        setBrush(Qt::white);

        setFlag(QGraphicsItem::ItemSendsScenePositionChanges);

        m_portFlags = 0;
    }

    Port::~Port() {
                foreach(Connection *conn, m_connections) delete conn;
    }

    void Port::setNEBlock(Block *b) {
        m_block = b;
    }

    void Port::setName(const QString &n) {
        name = n;
        label->setPlainText(n);
    }

    void Port::setIsOutput(bool o) {
        isOutput_ = o;

        QFontMetrics fm(scene()->font());
        fm.boundingRect(name);

        if (isOutput_)
            label->setPos(-radius_ - margin - label->boundingRect().width(), -label->boundingRect().height() / 2);
        else
            label->setPos(radius_ + margin, -label->boundingRect().height() / 2);
    }

    int Port::radius() {
        return radius_;
    }

    bool Port::isOutput() {
        return isOutput_;
    }

    void Port::setPin(const Pin* pin) {
        this->pin = pin;
    }

    const Pin *Port::getPin() {
        return this->pin;
    }

    QVector<Connection *> &Port::connections() {
        return m_connections;
    }

    void Port::setPortFlags(int f) {
        m_portFlags = f;

        if (m_portFlags & TypePort) {
            QFont font(scene()->font());
            font.setItalic(true);
            label->setFont(font);
            setPath(QPainterPath());
        } else if (m_portFlags & NamePort) {
            QFont font(scene()->font());
            font.setBold(true);
            label->setFont(font);
            setPath(QPainterPath());
        }
    }

    Block *Port::block() const {
        return m_block;
    }

    quint64 Port::ptr() {
        return m_ptr;
    }

    void Port::setPtr(quint64 p) {
        m_ptr = p;
    }

    bool Port::isConnected(Port *other) {
                foreach(Connection *conn, m_connections) if (conn->port1() == other || conn->port2() == other)
                    return true;

        return false;
    }

    QVariant Port::itemChange(GraphicsItemChange change, const QVariant &value) {
        if (change == ItemScenePositionHasChanged) {
                    foreach(Connection *conn, m_connections) {
                    conn->updatePosFromPorts();
                    conn->updatePath();
                }
        }
        return value;
    }
}