/*
** EPITECH PROJECT, 2023
** Input.cpp
** File description:
** Input
*/

#include "Input.hpp"

Input::Input(const std::string &type) {
    this->_pinsMap.emplace(1, std::make_unique<Pin>(1));
    this->_pinsMap[1]->setTristate(UNDEFINED);
    this->_type = type;
}

void Input::simulate(std::size_t tick) {
    for (std::size_t i = 0; i < tick; i++)
        this->_pinsMap[1]->setTristate(this->compute(1));
}

Tristate Input::compute(std::size_t pin) {
    if (pin == 1 && this->_nextState != nullptr)
        return (*this->_nextState);
    else if (pin == 1)
        return (this->_pinsMap[pin]->getTristate());
    throw Exception("Error: Invalid pin in component");
}

void Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    if (this->_pinsMap.find(pin) != this->_pinsMap.end() && other._pinsMap.find(otherPin) != other._pinsMap.end()) {
        this->_pinsMap[pin]->setPin(other._pinsMap[otherPin].get());
        other._pinsMap[otherPin]->setPin(this->_pinsMap[pin].get());
    } else throw Exception("Error: invalid links in component");
}

void Input::dump() const {};

std::string Input::getType() const {
    return (this->_type);
}
