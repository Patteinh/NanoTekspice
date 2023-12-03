/*
** EPITECH PROJECT, 2023
** C4094.cpp
** File description:
** C4094
*/

#include "C4094.hpp"

C4094::C4094(const std::string &type) {
	this->_pinsMap.emplace(1, std::make_unique<Pin>(1));
	this->_pinsMap.emplace(2, std::make_unique<Pin>(2));
	this->_pinsMap.emplace(3, std::make_unique<Pin>(3));
	this->_pinsMap.emplace(4, std::make_unique<Pin>(4));
	this->_pinsMap.emplace(5, std::make_unique<Pin>(5));
	this->_pinsMap.emplace(6, std::make_unique<Pin>(6));
	this->_pinsMap.emplace(7, std::make_unique<Pin>(7));
	this->_pinsMap.emplace(9, std::make_unique<Pin>(9));
	this->_pinsMap.emplace(10, std::make_unique<Pin>(10));
	this->_pinsMap.emplace(11, std::make_unique<Pin>(11));
	this->_pinsMap.emplace(12, std::make_unique<Pin>(12));
	this->_pinsMap.emplace(13, std::make_unique<Pin>(13));
    this->_pinsMap.emplace(14, std::make_unique<Pin>(14));
    this->_pinsMap.emplace(15, std::make_unique<Pin>(15));
	this->_type = type;
}

void C4094::simulate(std::size_t tick) {
    for (std::size_t i = 0; i < tick; i++) {
        if (this->_enable) {
            if (this->_strobe) this->_shiftRegister = this->_savedValue;
            else {
                this->_shiftRegister >>= 1;
                this->_shiftRegister[7] = this->_pinsMap[2]->getTristate() == TRUE;
            }
            for (std::size_t i = 0; i < 8; i++) {
                this->_pinsMap[i + 4]->setTristate(this->_shiftRegister[i] ? TRUE : FALSE);
            }
        }
    }
}

Tristate C4094::compute(std::size_t pin) {
    if (pin == 9) return (gates::_not(this->_shiftRegister[7] ? TRUE : FALSE));
    else if (pin == 10) return (gates::_not(this->_shiftRegister[0] ? TRUE : FALSE));
    else if (pin == 2 || pin == 3 || pin == 15) return (_pinsMap[pin]->getTristate());
    else if (pin >= 4 && pin <= 11) return (_pinsMap[pin]->getTristate());
    else throw Exception("Error: Invalid pin in component");
}

void C4094::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    if (this->_pinsMap.find(pin) != this->_pinsMap.end() && other._pinsMap.find(otherPin) != other._pinsMap.end()) {
        this->_pinsMap[pin]->setPin(other._pinsMap[otherPin].get());
        other._pinsMap[otherPin]->setPin(this->_pinsMap[pin].get());
    } else throw Exception("Error: invalid links in component");
}

void C4094::dump() const {}

std::string C4094::getType() const {
    return _type;
}
