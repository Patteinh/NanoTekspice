/*
** EPITECH PROJECT, 2023
** False.cpp
** File description:
** False
*/

#include "False.hpp"

False::False(const std::string &type) {
    this->_pinsMap.emplace(1, std::make_unique<Pin>(1));
    this->_pinsMap[1]->setTristate(FALSE);
    this->_type = type;
}

False::~False() {};

void False::simulate(std::size_t tick) {
    for (std::size_t i = 0; i < tick; i++)
        this->compute(1);
}

Tristate False::compute(std::size_t pin) {
    if (pin == 1)
        return (FALSE);
    throw Exception("Error: Invalid pin in component");
};

void False::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    if (this->_pinsMap.find(pin) != this->_pinsMap.end() && other._pinsMap.find(otherPin) != other._pinsMap.end()) {
        this->_pinsMap[pin]->setPin(other._pinsMap[otherPin].get());
        other._pinsMap[otherPin]->setPin(this->_pinsMap[pin].get());
        other._pinsMap[otherPin]->setTristate(FALSE);
    } else throw Exception("Error: invalid links in component");
}

void False::dump() const {};

std::string False::getType() const {
    return (this->_type);
}
