/*
** EPITECH PROJECT, 2023
** C4008.cpp
** File description:
** C4008
*/

#include "C4008.hpp"

C4008::C4008(const std::string &type) {
    this->_pinsMap.emplace(1, std::make_unique<Pin>(1));
    this->_pinsMap.emplace(2, std::make_unique<Pin>(2));
    this->_pinsMap.emplace(3, std::make_unique<Pin>(3));
    this->_pinsMap.emplace(4, std::make_unique<Pin>(4));
    this->_pinsMap.emplace(5, std::make_unique<Pin>(5));
    this->_pinsMap.emplace(6, std::make_unique<Pin>(6));
    this->_pinsMap.emplace(7, std::make_unique<Pin>(8));
    this->_pinsMap.emplace(9, std::make_unique<Pin>(9));
    this->_pinsMap.emplace(10, std::make_unique<Pin>(10));
    this->_pinsMap.emplace(11, std::make_unique<Pin>(11));
    this->_pinsMap.emplace(12, std::make_unique<Pin>(12));
    this->_pinsMap.emplace(13, std::make_unique<Pin>(13));
    this->_pinsMap.emplace(14, std::make_unique<Pin>(14));
    this->_pinsMap.emplace(15, std::make_unique<Pin>(15));
	this->_type = type;
}

void C4008::simulate(std::size_t tick) {
	(void)tick;
    Tristate a_bit, b_bit, carry_in;
    a_bit = this->compute(7);
    b_bit = this->compute(6);
    carry_in = this->compute(9);
    this->carry_out = gates::_or(gates::_and(a_bit, b_bit), gates::_and(carry_in, gates::_xor(a_bit, b_bit)));
    this->_pinsMap[10]->setTristate(gates::_xor(carry_in, gates::_xor(a_bit, b_bit)));

    a_bit = this->compute(5);
    b_bit = this->compute(4);
    carry_in = this->carry_out;
    this->carry_out = gates::_or(gates::_and(a_bit, b_bit), gates::_and(carry_in, gates::_xor(a_bit, b_bit)));
    this->_pinsMap[11]->setTristate(gates::_xor(carry_in, gates::_xor(a_bit, b_bit)));

    a_bit = this->compute(3);
    b_bit = this->compute(2);
    carry_in = this->carry_out;
    this->carry_out = gates::_or(gates::_and(a_bit, b_bit), gates::_and(carry_in, gates::_xor(a_bit, b_bit)));
    this->_pinsMap[12]->setTristate(gates::_xor(carry_in, gates::_xor(a_bit, b_bit)));

    a_bit = this->compute(1);
    b_bit = this->compute(15);
    carry_in = this->carry_out;
    this->carry_out = gates::_or(gates::_and(a_bit, b_bit), gates::_and(carry_in, gates::_xor(a_bit, b_bit)));
    this->_pinsMap[13]->setTristate(gates::_xor(carry_in, gates::_xor(a_bit, b_bit)));
    this->_pinsMap[14]->setTristate(this->carry_out);

}

Tristate C4008::compute(std::size_t pin) {
	Pin *link = this->_pinsMap[pin]->getPin();
	if (!link) return (UNDEFINED);
	this->_pinsMap[pin]->setTristate(link->getTristate());
	return (this->_pinsMap[pin]->getTristate());
}

void C4008::setLink(std::size_t pin, IComponent &other, std::size_t otherPin) {
    if (this->_pinsMap.find(pin) != this->_pinsMap.end() && other._pinsMap.find(otherPin) != other._pinsMap.end()) {
        this->_pinsMap[pin]->setPin(other._pinsMap[otherPin].get());
        other._pinsMap[otherPin]->setPin(this->_pinsMap[pin].get());
    } else throw Exception("Error: invalid links in component");
}

void C4008::dump() const {};

std::string C4008::getType() const {
    return (this->_type);
}
