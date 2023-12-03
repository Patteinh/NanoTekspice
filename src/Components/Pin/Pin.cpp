/*
** EPITECH PROJECT, 2023
** Pin.cpp
** File description:
** Pin
*/

#include "Pin.hpp"

namespace gates {
	Tristate _and(const Tristate &lhs, const Tristate &rhs) {
		if (lhs == FALSE || rhs == FALSE) return FALSE;
  		else if (lhs == TRUE && rhs == TRUE) return TRUE;
    	return UNDEFINED;
  	}
	Tristate _or(const Tristate &lhs, const Tristate &rhs) {
		if (lhs == TRUE || rhs == TRUE) return TRUE;
  		else if (lhs == FALSE && rhs == FALSE) return FALSE;
  		return UNDEFINED;
	}
	Tristate _not(const Tristate &lhs) {
		if (lhs == UNDEFINED) return UNDEFINED;
		else if (lhs == TRUE) return FALSE;
		else return TRUE;
	}
	Tristate _nor(const Tristate &lhs, const Tristate &rhs) {
		return _not(_or(lhs, rhs));
	}
	Tristate _nand(const Tristate &lhs, const Tristate &rhs) {
		return _not(_and(lhs, rhs));
	}
	Tristate _xor(const Tristate &lhs, const Tristate &rhs) {
		if (lhs == UNDEFINED || rhs == UNDEFINED) return UNDEFINED;
		else if (lhs != rhs) return TRUE;
		else return FALSE;
	}
}

Pin::Pin(std::size_t pin) {
    this->_id = pin;
    this->_tristate = UNDEFINED;
	this->_link = nullptr;
}

Pin::~Pin() {};

void Pin::setTristate(Tristate tristate) {
    this->_tristate = tristate;
}


void Pin::setId(std::size_t id) {
    this->_id = id;
}

void Pin::setPin(Pin *pin) {
	if (this->_link)
		throw Exception("Error: Pin already used");
    this->_link = pin;
}

Tristate Pin::getTristate() const {
    return (this->_tristate);
}

std::size_t Pin::getId() const {
    return (this->_id);
}

Pin *Pin::getPin() const {
    return (this->_link);
}
