#ifndef QNEBLOCK_H
#define QNEBLOCK_H

#include <QGraphicsPathItem>
#include "Pin.hpp"
#include "AComponent.hpp"

namespace nts {

    class Port;

    class Block : public QGraphicsPathItem {
    public:
        enum {
            Type = QGraphicsItem::UserType + 3
        };

        Block(QGraphicsItem *parent = 0);

        Port *addPort(const QString &name, const Pin* pin, bool isOutput, int flags = 0, int ptr = 0);

        void addInputPort(const QString &name, const Pin *pin);

        void addOutputPort(const QString &name, const Pin *pin);

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

        Port *getPortFromPin(const Pin *pin);

        Port *getPortFromPinId(size_t index);

        Block *clone();

        QVector<Port *> ports();

        int type() const { return Type; }

        const AComponent *getAComponent();

        void setAComponent(const AComponent *component);

    protected:
        QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    private:
        int horzMargin;
        int vertMargin;
        int width;
        int height;
        const AComponent *aComponent;
    };
}
#endif // QNEBLOCK_H
