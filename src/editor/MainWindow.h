#ifndef QNEMAINWINDOW_H
#define QNEMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <src/components/IComponent.hpp>
#include "EditorView.h"


namespace nts {
    class Editor;

    class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);

        ~MainWindow();

        void setComponents(std::vector<IComponent*> components);

    private slots:

        void saveFile();

        void loadFile();

    private:
        Editor *nodesEditor;
        QMenu *fileMenu;
        EditorView *view;
        QGraphicsScene *scene;

        const char* getComponentName(nts::IComponent *component);
    };
}
#endif // QNEMAINWINDOW_H
