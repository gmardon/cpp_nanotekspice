#include "Block.h"

#include <QPen>
#include <QGraphicsScene>
#include <QFontMetrics>
#include <QPainter>

#include "Port.h"

Block::Block(QGraphicsItem *parent) : QGraphicsPathItem(parent)
{
	QPainterPath p;
	p.addRoundedRect(-50, -15, 100, 30, 5, 5);
	setPath(p);
	setPen(QPen(Qt::darkGreen));
	setBrush(Qt::green);
	setFlag(QGraphicsItem::ItemIsMovable);
	setFlag(QGraphicsItem::ItemIsSelectable);
	horzMargin = 20;
	vertMargin = 5;
	width = horzMargin;
	height = vertMargin;
}

Port* Block::addPort(const QString &name, bool isOutput, int flags, int ptr)
{
	Port *port = new Port(this);
	port->setName(name);
	port->setIsOutput(isOutput);
	port->setNEBlock(this);
	port->setPortFlags(flags);
	port->setPtr(ptr);

	QFontMetrics fm(scene()->font());
	int w = fm.width(name);
	int h = fm.height();
	// port->setPos(0, height + h/2);
	if (w > width - horzMargin)
		width = w + horzMargin;
	height += h;

	QPainterPath p;
	p.addRoundedRect(-width/2, -height/2, width, height, 5, 5);
	setPath(p);

	int y = -height / 2 + vertMargin + port->radius();
    foreach(QGraphicsItem *port_, childItems()) {
		if (port_->type() != Port::Type)
			continue;

		Port *port = (Port*) port_;
		if (port->isOutput())
			port->setPos(width/2 + port->radius(), y);
		else
			port->setPos(-width/2 - port->radius(), y);
		y += h;
	}

	return port;
}

void Block::addInputPort(const QString &name)
{
	addPort(name, false);
}

void Block::addOutputPort(const QString &name)
{
	addPort(name, true);
}

void Block::addInputPorts(const QStringList &names)
{
	foreach(QString n, names)
		addInputPort(n);
}

void Block::addOutputPorts(const QStringList &names)
{
	foreach(QString n, names)
		addOutputPort(n);
}

void Block::save(QDataStream &ds)
{
	ds << pos();

	int count(0);

    foreach(QGraphicsItem *port_, childItems())
	{
		if (port_->type() != Port::Type)
			continue;

		count++;
	}

	ds << count;

    foreach(QGraphicsItem *port_, childItems())
	{
		if (port_->type() != Port::Type)
			continue;

        Port *port = (Port*) port_;
		ds << (quint64) port;
		ds << port->portName();
		ds << port->isOutput();
		ds << port->portFlags();
	}
}

void Block::load(QDataStream &ds, QMap<quint64, Port*> &portMap)
{
	QPointF p;
	ds >> p;
	setPos(p);
	int count;
	ds >> count;
	for (int i = 0; i < count; i++)
	{
		QString name;
		bool output;
		int flags;
		quint64 ptr;

		ds >> ptr;
		ds >> name;
		ds >> output;
		ds >> flags;
		portMap[ptr] = addPort(name, output, flags, ptr);
	}
}

#include <QStyleOptionGraphicsItem>

void Block::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option)
	Q_UNUSED(widget)

	if (isSelected()) {
		painter->setPen(QPen(Qt::darkYellow));
		painter->setBrush(Qt::yellow);
	} else {
		painter->setPen(QPen(Qt::darkGreen));
		painter->setBrush(Qt::green);
	}

	painter->drawPath(path());
}

Block* Block::clone()
{
    Block *b = new Block(0);
    this->scene()->addItem(b);

	foreach(QGraphicsItem *port_, childItems())
	{
		if (port_->type() == Port::Type)
		{
            Port *port = (Port*) port_;
			b->addPort(port->portName(), port->isOutput(), port->portFlags(), port->ptr());
		}
	}

	return b;
}

QVector<Port*> Block::ports()
{
	QVector<Port*> res;
	foreach(QGraphicsItem *port_, childItems())
	{
		if (port_->type() == Port::Type)
			res.append((Port*) port_);
	}
	return res;
}

QVariant Block::itemChange(GraphicsItemChange change, const QVariant &value)
{

    Q_UNUSED(change);

	return value;
}

