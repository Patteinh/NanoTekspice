/*
** EPITECH PROJECT, 2023
** C4071.cpp
** File description:
** C4071
*/

#include "C4071.hpp"

C4071::C4071(const std::string &type) {
	this->_pinsMap.emplace(1, std::make_unique<Pin>(1));
	this->_pinsMap.emplace(2, std::make_unique<Pin>(2));
	this->_pinsMap.emplace(3, std::make_unique<Pin>(3));
	this->_pinsMap.emplace(4, std::make_unique<Pin>(4));
	this->_pinsMap.emplace(5, std::make_unique<Pin>(5));
	this->_pinsMap.emplace(6, std::make_unique<Pin>(6));
	this->_pinsMap.emplace(8, std::make_unique<Pin>(8));
	this->_pinsMap.emplace(9, std::make_unique<Pin>(9));
	this->_pinsMap.emplace(10, std::make_unique<Pin>(10));
	this->_pinsMap.emplace(11, std::make_unique<Pin>(11));
	this->_pinsMap.emplace(12, std::make_unique<Pin>(12));
	this->_pinsMap.emplace(13, std::make_unique<Pin>(13));
	this->_type = type;
}

void C4071::simulate(std::size_t tick)  {
	for (std::size_t i = 0; i < tick; i++) {
		this->_pinsMap[3]->setTristate(this->compute(3));
		this->_pinsMap[4]->setTristate(this->compute(4));
		this->_pinsMap[10]->setTristate(this->compute(10));
		this->_pinsMap[11]->setTristate(this->compute(11));
	}
}

Tristate C4071::compute(std::size_t pin)  {
	if (pin == 3) return (gates::_or(this->compute(1), this->compute(2)));
	else if (pin == 4) return (gates::_or(this->compute(5), this->compute(6)));
	else if (pin == 10) return (gates::_or(this->compute(8), this->compute(9)));
	else if (pin == 11) return (gates::_or(this->compute(12), this->compute(13)));
	else if (pin == 1 || pin == 2 || pin == 5 || pin == 6 || pin == 13 || pin == 12 || pin == 9 || pin == 8) {
		Pin *link = this->_pinsMap[pin]->getPin();
		if (!link) return (UNDEFINED);
		this->_pinsMap[pin]->setTristate(link->getTristate());
		return (this->_pinsMap[pin]->getTristate());
	}
    throw Exception("Error: Invalid pin in component");
}

void C4071::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    if (this->_pinsMap.find(pin) != this->_pinsMap.end() && other._pinsMap.find(otherPin) != other._pinsMap.end()) {
        this->_pinsMap[pin]->setPin(other._pinsMap[otherPin].get());
        other._pinsMap[otherPin]->setPin(this->_pinsMap[pin].get());
    } else throw Exception("Error: invalid links in component");
}

void C4071::dump() const {};

std::string C4071::getType() const {
    return (this->_type);
}
