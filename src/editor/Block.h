#ifndef QNEBLOCK_H
#define QNEBLOCK_H

#include <QGraphicsPathItem>

class Port;

class Block : public QGraphicsPathItem {
public:
    enum {
        Type = QGraphicsItem::UserType + 3
    };

    Block(QGraphicsItem *parent = 0);

    Port *addPort(const QString &name, bool isOutput, int flags = 0, int ptr = 0);

    void addInputPort(const QString &name);

    void addOutputPort(const QString &name);

    void addInputPorts(const QStringList &names);

    void addOutputPorts(const QStringList &names);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    Block *clone();

    QVector<Port *> ports();

    int type() const { return Type; }

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

private:
    int horzMargin;
    int vertMargin;
    int width;
    int height;
};

#endif // QNEBLOCK_H
