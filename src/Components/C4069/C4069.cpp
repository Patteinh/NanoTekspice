/*
** EPITECH PROJECT, 2023
** C4069.cpp
** File description:
** C4069
*/

#include "C4069.hpp"

C4069::C4069(const std::string &type) {
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

void C4069::simulate(std::size_t tick)  {
	for (std::size_t i = 0; i < tick; i++) {
		this->_pinsMap[2]->setTristate(this->compute(2));
		this->_pinsMap[4]->setTristate(this->compute(4));
		this->_pinsMap[6]->setTristate(this->compute(6));
		this->_pinsMap[8]->setTristate(this->compute(8));
		this->_pinsMap[10]->setTristate(this->compute(10));
		this->_pinsMap[12]->setTristate(this->compute(12));
	}
}

Tristate C4069::compute(std::size_t pin)  {
	if (pin == 2 || pin == 4 || pin == 6) return (gates::_not(this->compute(pin - 1)));
	else if (pin == 8 || pin == 10 || pin == 12) return (gates::_not(this->compute(pin + 1)));
	else if (pin == 1 || pin == 3 || pin == 5 || pin == 7 || pin == 9 || pin == 11 || pin == 13) {
		Pin *link = this->_pinsMap[pin]->getPin();
		if (!link) return (UNDEFINED);
		this->_pinsMap[pin]->setTristate(link->getTristate());
		return (this->_pinsMap[pin]->getTristate());
	}
	throw Exception("Error: Invalid pin in component");
}

void C4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    if (this->_pinsMap.find(pin) != this->_pinsMap.end() && other._pinsMap.find(otherPin) != other._pinsMap.end()) {
        this->_pinsMap[pin]->setPin(other._pinsMap[otherPin].get());
        other._pinsMap[otherPin]->setPin(this->_pinsMap[pin].get());
    } else throw Exception("Error: invalid links in component");
}

void C4069::dump() const {};

std::string C4069::getType() const {
    return (this->_type);
}
