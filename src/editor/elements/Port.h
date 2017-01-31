#ifndef QNEPORT_H
#define QNEPORT_H

#include <QGraphicsPathItem>


namespace nts {
    class Block;

    class Connection;

    class Port : public QGraphicsPathItem {
    public:
        enum {
            Type = QGraphicsItem::UserType + 1
        };
        enum {
            NamePort = 1, TypePort = 2
        };

        Port(QGraphicsItem *parent = 0);

        ~Port();

        void setNEBlock(Block *);

        void setName(const QString &n);

        void setIsOutput(bool o);

        int radius();

        bool isOutput();

        QVector<Connection *> &connections();

        void setPortFlags(int);

        const QString &portName() const { return name; }

        int portFlags() const { return m_portFlags; }

        int type() const { return Type; }

        Block *block() const;

        quint64 ptr();

        void setPtr(quint64);

        bool isConnected(Port *);

    protected:
        QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    private:
        Block *m_block;
        QString name;
        bool isOutput_;
        QGraphicsTextItem *label;
        int radius_;
        int margin;
        QVector<Connection *> m_connections;
        int m_portFlags;
        quint64 m_ptr;
    };
}
#endif // QNEPORT_H
