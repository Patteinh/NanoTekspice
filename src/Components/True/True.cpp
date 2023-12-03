/*
** EPITECH PROJECT, 2023
** True.cpp
** File description:
** True
*/

#include "True.hpp"

True::True(const std::string &type) {
    this->_pinsMap.emplace(1, std::make_unique<Pin>(1));
    this->_pinsMap[1]->setTristate(TRUE);
    this->_type = type;
}

True::~True() {};

void True::simulate(std::size_t tick) {
    for (std::size_t i = 0; i < tick; i++)
        this->compute(1);
}

Tristate True::compute(std::size_t pin) {
    if (pin == 1)
        return (TRUE);
    throw Exception("Invalid pin");
};

void True::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    if (this->_pinsMap.find(pin) != this->_pinsMap.end() && other._pinsMap.find(otherPin) != other._pinsMap.end()) {
        this->_pinsMap[pin]->setPin(other._pinsMap[otherPin].get());
        other._pinsMap[otherPin]->setPin(this->_pinsMap[pin].get());
        other._pinsMap[otherPin]->setTristate(TRUE);
    }
}

void True::dump() const {};

std::string True::getType() const {
    return (this->_type);
}
