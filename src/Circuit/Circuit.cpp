/*
** EPITECH PROJECT, 2023
** Circuit.cpp
** File description:
** Circuit
*/

#include "Circuit.hpp"

Circuit::Circuit(chipsetsMap chipsetsMap, linksMap linksMap) : _tick(0) {
    for (const auto &chipset : chipsetsMap)
        this->_listComponents.push_back(std::make_pair(chipset.second, _factory.createComponent(chipset.first)));
    for (const auto &link : linksMap) {
        if (std::find(_validInput.begin(), _validInput.end(), this->getComponent(link.first.first)->getType()) != _validInput.end() &&
            std::find(_validInput.begin(), _validInput.end(), this->getComponent(link.second.first)->getType()) != _validInput.end())
                throw Exception("Error: invalid link from input - input");
        if (this->getComponent(link.first.first)->getType() == "output" && this->getComponent(link.second.first)->getType() == "output")
            throw Exception("Error: invalid link from output - output");
        getComponent(link.first.first)->setLink(std::stoi(link.first.second), (*getComponent(link.second.first)), std::stoi(link.second.second));
    }
}

Circuit::~Circuit() {};

std::unique_ptr<nts::IComponent> &Circuit::getComponent(const std::string &name) {
    for (auto &component : _listComponents)
        if (component.first == name)
            return (component.second);
    throw Exception("Error: could not find name of component in '.links:");
}

void Circuit::display() const {
    std::vector<std::string> _validTypes = {"input", "clock"};
    std::cout << "tick: " << this->_tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (const auto &component : this->_listComponents) {
        if (std::find(_validTypes.begin(), _validTypes.end(), component.second->getType()) != _validTypes.end()) {
            if (component.second->_pinsMap[1]->getTristate() != UNDEFINED)
                std::cout << "  " << component.first << ": " << component.second->_pinsMap[1]->getTristate() << std::endl;
            else
                std::cout << "  " << component.first << ": " << "U" << std::endl;
        }
    }
    std::cout << "output(s):" << std::endl;
    for (const auto &component : this->_listComponents) {
        if (component.second->getType() == "output") {
            if (component.second->_pinsMap[1]->getTristate() != UNDEFINED)
                std::cout << "  " << component.first << ": " << component.second->_pinsMap[1]->getTristate() << std::endl;
            else
                std::cout << "  " << component.first << ": " << "U" << std::endl;
        }
    }
}

void Circuit::simulate(std::size_t tick) {
    for (std::size_t i = 0; i < tick; i++, this->_tick++) {
        for (const auto &component : this->_listComponents)
            if (component.second->getType() == "input")
                component.second->simulate(1);
        for (const auto &component : this->_listComponents)
            if (component.second->getType() != "output" && component.second->getType() != "clock")
                component.second->simulate(1);
        for (const auto &component : this->_listComponents)
            if (component.second->getType() == "clock")
                component.second->simulate(1);
        for (const auto &component : this->_listComponents)
            if (component.second->getType() == "output")
                component.second->simulate(1);
    }
}
