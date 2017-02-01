#include "MainWindow.h"

#include "src/editor/elements/Block.h"
#include "Editor.h"

#include "src/editor/elements/Port.h"
#include <typeinfo>
#include <iostream>
#include <cxxabi.h>
#include <src/components/Pin.hpp>

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
        view->setScene(scene);

        view->setRenderHint(QPainter::Antialiasing, true);
        // in near-future, active this

        this->setCentralWidget(view);

        nodesEditor = new Editor(this);
        nodesEditor->install(scene);

       /* Block *b = new Block(0);
        scene->addItem(b);
        b->addPort("test", 0, Port::NamePort);
        b->addInputPort("in");
        b->addOutputPort("out");

        b = b->clone();
        b->setPos(150, 0);

        b = b->clone();
        b->setPos(150, 150);
*/
        this->setMinimumWidth(480);
        this->setMinimumHeight(640);
    }

    MainWindow::~MainWindow() {

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

    const char* MainWindow::getComponentName(nts::IComponent *component) {
        char   *realname;
        const std::type_info  &ti = typeid(*component);
        realname = abi::__cxa_demangle(ti.name(), 0, 0, new int);
        return (realname);
    }

    void MainWindow::setComponents(std::vector<IComponent*> components)
    {
        for (const auto& component : components)
        {
            const char *name = getComponentName(component);

            Block *b = new Block(0);
            scene->addItem(b);
            b->addPort(name, 0, Port::NamePort);
            b->addInputPort("in");
            b->addOutputPort("out");

            printf("NAME: %s\n", name);
        }

    }
}