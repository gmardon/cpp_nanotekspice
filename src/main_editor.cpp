#include <QtWidgets>
#include "IComponent.hpp"
#include "True.hpp"
#include "c4001.hpp"
#include "Output.hpp"
#include "include/MainWindow.hpp"
#include <typeinfo>
#include <cxxabi.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    nts::MainWindow w;
    w.show();

    nts::AComponent *input1 = new nts::True();
    nts::AComponent *input2 = new nts::True();
    nts::AComponent *c4001 = new nts::c4001();
    nts::AComponent *output = new nts::Output();

    c4001->SetLink(1, *input1, 1);
    c4001->SetLink(2, *input2, 1);
    output->SetLink(1, *c4001, 3);

    std::vector<nts::AComponent*> *v = new std::vector<nts::AComponent*>();
    v->push_back(input1);
    v->push_back(input2);
    v->push_back(c4001);
    v->push_back(output);

    w.setComponents(*v);

    return a.exec();
}
