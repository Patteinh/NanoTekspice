/*
** EPITECH PROJECT, 2023
** NOT.cpp
** File description:
** NOT
*/

#include "NOT.hpp"

NOT::NOT(const std::string &type) {
	this->_pinsMap.emplace(1, std::make_unique<Pin>(1));
	this->_pinsMap.emplace(2, std::make_unique<Pin>(2));
	this->_type = type;
}

void NOT::simulate(std::size_t tick)  {
	for (std::size_t i = 0; i < tick; i++) {
		this->_pinsMap[2]->setTristate(this->compute(2));
	}
}

Tristate NOT::compute(std::size_t pin)  {
	if (pin == 2) return (gates::_not(this->compute(pin - 1)));
	else if (pin == 1) {
		Pin *link = this->_pinsMap[pin]->getPin();
		if (!link) return (UNDEFINED);
		this->_pinsMap[pin]->setTristate(link->getTristate());
		return (this->_pinsMap[pin]->getTristate());
	}
    throw Exception("Error: Invalid pin in component");
}

void NOT::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    if (this->_pinsMap.find(pin) != this->_pinsMap.end() && other._pinsMap.find(otherPin) != other._pinsMap.end()) {
        this->_pinsMap[pin]->setPin(other._pinsMap[otherPin].get());
        other._pinsMap[otherPin]->setPin(this->_pinsMap[pin].get());
    } else throw Exception("Error: invalid links in component");
}

void NOT::dump() const {};

std::string NOT::getType() const {
    return (this->_type);
}
