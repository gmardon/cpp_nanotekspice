#include <QtWidgets>
#include <src/components/IComponent.hpp>
#include <src/components/True.hpp>
#include <src/components/c4001.hpp>
#include <src/components/Output.hpp>
#include "src/editor/MainWindow.h"
#include <typeinfo>
#include <cxxabi.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    nts::MainWindow w;
    w.show();

    nts::IComponent *input1 = new nts::True();
    nts::IComponent *input2 = new nts::True();
    nts::IComponent *c4001 = new nts::c4001();
    nts::IComponent *output = new nts::Output();

    c4001->SetLink(1, *input1, 1);
    c4001->SetLink(2, *input2, 1);
    output->SetLink(1, *c4001, 3);

    std::vector<nts::IComponent*> *v = new std::vector<nts::IComponent*>();
    v->push_back(input1);
    v->push_back(input2);
    v->push_back(c4001);
    v->push_back(output);

    w.setComponents(*v);

    return a.exec();
}
