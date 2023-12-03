/*
** EPITECH PROJECT, 2023
** Clock.hpp
** File description:
** Clock
*/

#include "Clock.hpp"

Clock::Clock(const std::string &type) {
    this->_pinsMap.emplace(1, std::make_unique<Pin>(1));
    this->_type = type;
}

Clock::~Clock() {};

void Clock::simulate(std::size_t tick) {
    for (std::size_t i = 0; i < tick; i++)
        this->_pinsMap[1]->setTristate(this->compute(1));
}

Tristate Clock::compute(std::size_t pin) {
    if (pin == 1 && this->_nextState != nullptr) {
        Tristate tmp = (*this->_nextState);
        this->_nextState = nullptr;
        return (tmp);
    } else if (pin == 1) {
		Tristate oldValue = this->_pinsMap[pin]->getTristate();
		if (oldValue == FALSE) return (TRUE);
		else if (oldValue == TRUE) return(FALSE);
		return (oldValue);
	}
    throw Exception("Error: Invalid pin in component");
}

void Clock::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    if (this->_pinsMap.find(pin) != this->_pinsMap.end() && other._pinsMap.find(otherPin) != other._pinsMap.end()) {
        this->_pinsMap[pin]->setPin(other._pinsMap[otherPin].get());
        other._pinsMap[otherPin]->setPin(this->_pinsMap[pin].get());
    } else throw Exception("Error: invalid links in component");
}

void Clock::dump() const {};

std::string Clock::getType() const {
    return (this->_type);
}
