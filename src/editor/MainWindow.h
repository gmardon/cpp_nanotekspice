#ifndef QNEMAINWINDOW_H
#define QNEMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "EditorView.h"

class Editor;

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:

    void saveFile();

    void loadFile();

private:
    Editor *nodesEditor;
    QMenu *fileMenu;
    EditorView *view;
    QGraphicsScene *scene;
};

#endif // QNEMAINWINDOW_H
