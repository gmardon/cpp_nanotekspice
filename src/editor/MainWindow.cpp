#include "MainWindow.hpp"

#include "Editor.hpp"

#include "Port.hpp"
#include <typeinfo>
#include "Input.hpp"
#include "True.hpp"
#include "False.hpp"
#include "Clock.hpp"
#include "Output.hpp"

namespace nts {

    MainWindow::MainWindow(QWidget *parent) :
            QMainWindow(parent) {
        scene = new QGraphicsScene();

        QAction *quitAct = new QAction(tr("&Quit"), this);
        quitAct->setShortcuts(QKeySequence::Quit);
        quitAct->setStatusTip(tr("Quit the application"));
        connect(quitAct, SIGNAL(triggered()), qApp, SLOT(quit()));

        QAction *loadAct = new QAction(tr("&Load"), this);
        loadAct->setShortcuts(QKeySequence::Open);
        loadAct->setStatusTip(tr("Open a file"));
        connect(loadAct, SIGNAL(triggered()), this, SLOT(loadFile()));

        QAction *saveAct = new QAction(tr("&Save"), this);
        saveAct->setShortcuts(QKeySequence::Save);
        saveAct->setStatusTip(tr("Save a file"));
        connect(saveAct, SIGNAL(triggered()), this, SLOT(saveFile()));

        fileMenu = menuBar()->addMenu(tr("&File"));
        fileMenu->addAction(loadAct);
        fileMenu->addAction(saveAct);
        fileMenu->addSeparator();
        fileMenu->addAction(quitAct);

        setWindowTitle(tr("Nanotekspice"));

        view = new EditorView();
        connect(view, SIGNAL(addComponentEvent(std::string)), this, SLOT(addComponent(std::string)));
        view->setScene(scene);

        view->setRenderHint(QPainter::Antialiasing, true);
        // in near-future, active this

        this->setCentralWidget(view);

        nodesEditor = new Editor(this);
        nodesEditor->install(scene);

        blocks = new std::list<Block*>();

        this->setMinimumWidth(480);
        this->setMinimumHeight(640);

    }

    MainWindow::~MainWindow() {
        delete blocks;
    }

    void MainWindow::addComponent(std::string name) {
        nts::AComponent *component;
        if (name == "true") {
            component = new nts::True();
        } else if (name == "false") {
            component = new nts::False();
        } else if (name == "clock") {
            component = new nts::Clock();
        } else if (name == "output") {
            component = new nts::Output();
        } else {
            return;
        }

        Block *b = new Block(0);
        scene->addItem(b);
        blocks->push_front(b);
        b->setAComponent(component);
        b->addPort(QString::fromStdString(component->getName()), NULL, 0, Port::NamePort);

        QPointF pos = view->mapToScene(mapFromGlobal(QCursor::pos()));

        b->setPos(pos.x(), pos.y() - 10);

        for (const auto &pin : component->getPins()) {
            switch (pin.getMode()) {
                case Pin::Mode::U:
                    b->addInputPort("UNDEFINED", &pin);
                    break;

                case Pin::Mode::I:
                    b->addInputPort("IN " + pin.getTargetPin(), &pin);
                    break;

                case Pin::Mode::O:
                    b->addOutputPort("OUT " + pin.getTargetPin(), &pin);
                    break;

                case Pin::Mode::IO:
                    b->addOutputPort("IN/OUT" + pin.getTargetPin(), &pin);
                    break;

                case Pin::Mode::VSS:
                    b->addOutputPort("VSS " + pin.getTargetPin(), &pin);
                    break;

                case Pin::Mode::VDD:
                    b->addOutputPort("VDD " + pin.getTargetPin(), &pin);
                    break;
            }
        }
    }

    void MainWindow::saveFile() {
        QString fname = QFileDialog::getSaveFileName();
        if (fname.isEmpty())
            return;

        QFile f(fname);
        f.open(QFile::WriteOnly);
        QDataStream ds(&f);
    }

    void MainWindow::loadFile() {
        QString fname = QFileDialog::getOpenFileName();
        if (fname.isEmpty())
            return;

        QFile f(fname);
        f.open(QFile::ReadOnly);
        QDataStream ds(&f);
    }

    void MainWindow::setComponents(std::vector<AComponent*> components)
    {
        blocks = new std::list<Block*>();

        int index = 0;
        for (const auto& component : components)
        {
            index++;
            Block *b = new Block(0);
            b->setPos(120 * index, index / 3 * 120);
            scene->addItem(b);
            blocks->push_front(b);
            b->setAComponent(component);
            b->addPort(QString::fromStdString(component->getName()), NULL, 0, Port::NamePort);

            //printf("block: x(%d), y(%d)\n", (int) b->pos().x(), (int) b->pos().y());

            for (const auto& pin : component->getPins()) {
                switch(pin.getMode()) {
                    case Pin::Mode::U:
                        b->addInputPort("UNDEFINED", &pin);
                        break;

                    case Pin::Mode::I:
                        b->addInputPort("IN " + pin.getTargetPin(), &pin);
                        break;

                    case Pin::Mode::O:
                        b->addOutputPort("OUT " + pin.getTargetPin(), &pin);
                        break;

                    case Pin::Mode::IO:
                        b->addOutputPort("IN/OUT" + pin.getTargetPin(), &pin);
                        break;

                    case Pin::Mode::VSS:
                        b->addOutputPort("VSS " + pin.getTargetPin(), &pin);
                        break;

                    case Pin::Mode::VDD:
                        b->addOutputPort("VDD " + pin.getTargetPin(), &pin);
                        break;
                }
            }
        }

        for (const auto& block : *blocks) {
            const AComponent *component = block->getAComponent();
            for (const auto &pin : component->getPins()) {
                if (&pin.getComponent()) {
                    Connection *connection = new Connection(0);
                    connection->setPort1(block->getPortFromPin(&pin));
                    scene->addItem(connection);
                    Block *target;
                    for (const auto& ba : *blocks) {
                        if (ba->getAComponent() == &pin.getComponent()) {
                            target = ba;
                            break;
                        }
                    }
                    if (target != NULL) {
                        Port *port = target->getPortFromPinId(pin.getTargetPin());
                        if (!port) {
                            delete connection;
                            scene->removeItem(connection);
                            continue;
                        } else {
                            connection->setPort2(port);
                        }
                    }
                    connection->updatePosFromPorts();
                    connection->updatePath();
                }
            }
        }
    }
}