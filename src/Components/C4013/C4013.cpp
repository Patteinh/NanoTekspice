/*
** EPITECH PROJECT, 2023
** C4013.cpp
** File description:
** C4013
*/

#include "C4013.hpp"

C4013::C4013(const std::string &type) {
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

void C4013::simulate(std::size_t tick)  {
	for (std::size_t i = 0; i < tick; i++) {
		Tristate oldClk1 = this->_pinsMap[3]->getTristate();
		this->_pinsMap[3]->setTristate(this->compute(3));
		Tristate set1 = this->compute(6);
		Tristate reset1 = this->compute(4);
		if (set1 == TRUE) this->_pinsMap[1]->setTristate(TRUE);
		else if (reset1 == TRUE) this->_pinsMap[1]->setTristate(FALSE);
		else if (oldClk1 == FALSE && this->_pinsMap[3]->getTristate() == TRUE) this->_pinsMap[1]->setTristate(this->compute(1));
		this->_pinsMap[2]->setTristate(gates::_not(this->_pinsMap[1]->getTristate()));
		Tristate oldClk2 = this->_pinsMap[11]->getTristate();
		this->_pinsMap[11]->setTristate(this->compute(11));
		Tristate set2 = this->compute(8);
		Tristate reset2 = this->compute(10);
		if (set2 == TRUE) this->_pinsMap[13]->setTristate(TRUE);
		else if (reset2 == TRUE) this->_pinsMap[13]->setTristate(FALSE);
		else if (oldClk2 == FALSE && this->_pinsMap[11]->getTristate() == TRUE) this->_pinsMap[13]->setTristate(this->compute(1));
		this->_pinsMap[12]->setTristate(gates::_not(this->_pinsMap[13]->getTristate()));
	}
}

Tristate C4013::compute(std::size_t pin)  {
	if (pin == 1) return (this->compute(5));
	else if (pin == 13) return (this->compute(9));
	else if (pin == 3 || pin == 5 || pin == 6 || pin == 4 || pin == 9 || pin == 8 || pin == 10 || pin == 11) {
		Pin *link = this->_pinsMap[pin]->getPin();
		if (!link) return (UNDEFINED);
		this->_pinsMap[pin]->setTristate(link->getTristate());
		return (this->_pinsMap[pin]->getTristate());
	}
	throw Exception("Error: Invalid pin in component");
}

void C4013::setLink(std::size_t pin, IComponent &other, std::size_t otherPin) {
    if (this->_pinsMap.find(pin) != this->_pinsMap.end() && other._pinsMap.find(otherPin) != other._pinsMap.end()) {
        this->_pinsMap[pin]->setPin(other._pinsMap[otherPin].get());
        other._pinsMap[otherPin]->setPin(this->_pinsMap[pin].get());
    } else throw Exception("Error: invalid links in component");
}

void C4013::dump() const {};

std::string C4013::getType() const {
    return (this->_type);
}
