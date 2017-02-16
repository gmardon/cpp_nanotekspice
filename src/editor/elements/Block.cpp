#include "Block.h"

#include <QPen>
#include <QGraphicsScene>
#include <QFontMetrics>
#include <QPainter>

#include <QStyleOptionGraphicsItem>
#include <src/components/Pin.hpp>

#include "Port.h"

namespace nts {
    Block::Block(QGraphicsItem *parent) : QGraphicsPathItem(parent) {
        QPainterPath p;
        p.addRoundedRect(-50, -15, 100, 30, 5, 5);
        setPath(p);
        setPen(QPen(Qt::white));
        setBrush(Qt::green);
        setFlag(QGraphicsItem::ItemIsMovable);
        setFlag(QGraphicsItem::ItemIsSelectable);
        horzMargin = 40;
        vertMargin = 5;
        width = horzMargin;
        height = vertMargin;
    }

    Port *Block::addPort(const QString &name, const Pin* pin, bool isOutput, int flags, int ptr) {
        Port *port = new Port(this);
        port->setName(name);
        port->setIsOutput(isOutput);
        port->setNEBlock(this);
        port->setPortFlags(flags);
        port->setPtr(ptr);
        port->setPin(pin);

        QFontMetrics fm(scene()->font());
        int w = fm.width(name);
        int h = fm.height();
        // port->setPos(0, height + h/2);
        if (w > width - horzMargin)
            width = w + horzMargin;
        height += h;

        QPainterPath p;
        p.addRoundedRect(-width / 2, -height / 2, width, height, 5, 5);
        setPath(p);

        int y = -height / 2 + vertMargin + port->radius();
                foreach(QGraphicsItem *port_, childItems()) {
                if (port_->type() != Port::Type)
                    continue;

                Port *port = (Port *) port_;
                if (port->isOutput())
                    port->setPos(5 + width / 2 + port->radius(), y);
                else
                    port->setPos(-3 + -width / 2 - port->radius(), y);
                y += h;
            }

        return port;
    }

    void Block::addInputPort(const QString &name, const Pin *pin) {
        addPort(name, pin, false);
    }

    void Block::addOutputPort(const QString &name, const Pin *pin) {
        addPort(name, pin, true);
    }

    Port *Block::getPortFromPin(const Pin *pin) {
        for (const auto &port : ports()) {
            if (port->getPin() == pin)
                return port;
        }
        return NULL;
    }

    Port *Block::getPortFromPinId(size_t index) {
        if (&(this->getAComponent()->getPins()[index - 1]) == NULL)
            return NULL;
        return getPortFromPin(&(this->getAComponent()->getPins()[index - 1]));
    }

    void Block::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
        Q_UNUSED(option)
        Q_UNUSED(widget)

        if (isSelected()) {
            painter->setPen(QPen(Qt::darkYellow));
            painter->setBrush(Qt::yellow);
        } else {
            painter->setPen(QPen(Qt::black));
            painter->setBrush(Qt::white);
        }

        painter->drawPath(path());
    }

    Block *Block::clone() {
        Block *b = new Block(0);
        this->scene()->addItem(b);

                foreach(QGraphicsItem *port_, childItems()) {
                if (port_->type() == Port::Type) {
                    Port *port = (Port *) port_;
                    b->addPort(port->portName(), port->getPin(), port->isOutput(), port->portFlags(), port->ptr());
                }
            }

        return b;
    }

    QVector<Port *> Block::ports() {
        QVector<Port *> res;
                foreach(QGraphicsItem *port_, childItems()) {
                if (port_->type() == Port::Type)
                    res.append((Port *) port_);
            }
        return res;
    }

    QVariant Block::itemChange(GraphicsItemChange change, const QVariant &value) {
        Q_UNUSED(change);

        return value;
    }

    void Block::setAComponent(const AComponent *component) {
        this->aComponent = component;
    }

    const AComponent *Block::getAComponent() {
        return this->aComponent;
    }
}