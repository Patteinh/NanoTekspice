/*
** EPITECH PROJECT, 2023
** XOR.cpp
** File description:
** XOR
*/

#include "XOR.hpp"

XOR::XOR(const std::string &type) {
	this->_pinsMap.emplace(1, std::make_unique<Pin>(1));
	this->_pinsMap.emplace(2, std::make_unique<Pin>(2));
	this->_pinsMap.emplace(3, std::make_unique<Pin>(3));
	this->_type = type;
}

void XOR::simulate(std::size_t tick)  {
	for (std::size_t i = 0; i < tick; i++) {
		this->_pinsMap[3]->setTristate(this->compute(3));
	}
}

Tristate XOR::compute(std::size_t pin)  {
	if (pin == 3) return (gates::_xor(this->compute(1), this->compute(2)));
	else if (pin == 1 || pin == 2) {
		Pin *link = this->_pinsMap[pin]->getPin();
		if (!link) return (UNDEFINED);
		this->_pinsMap[pin]->setTristate(link->getTristate());
		return (this->_pinsMap[pin]->getTristate());
	}
    throw Exception("Error: Invalid pin in component");
}

void XOR::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    if (this->_pinsMap.find(pin) != this->_pinsMap.end() && other._pinsMap.find(otherPin) != other._pinsMap.end()) {
        this->_pinsMap[pin]->setPin(other._pinsMap[otherPin].get());
        other._pinsMap[otherPin]->setPin(this->_pinsMap[pin].get());
    } else throw Exception("Error: invalid links in component");
}

void XOR::dump() const {};

std::string XOR::getType() const {
    return (this->_type);
}
