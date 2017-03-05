#ifndef QNEMAINWINDOW_H
#define QNEMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <qmenubar.h>
#include "AComponent.hpp"
#include "IComponent.hpp"
#include "Pin.hpp"
#include "AComponent.hpp"
#include "Block.hpp"
#include "EditorView.hpp"


namespace nts {
    class Editor;

    class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);

        ~MainWindow();

        void setComponents(std::vector<AComponent*> components);

    private slots:

        void saveFile();

        void loadFile();

        void simulate();

        void addComponent(std::string name);

    private:
        Editor *nodesEditor;
        QMenu *fileMenu;
        EditorView *view;
        QGraphicsScene *scene;
        std::vector<Block*> *blocks;

        std::vector<Pin> getPorts(AComponent *component);
    };
}
#endif // QNEMAINWINDOW_H
