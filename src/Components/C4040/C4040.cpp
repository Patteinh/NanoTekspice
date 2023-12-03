/*
** EPITECH PROJECT, 2023
** C4040.cpp
** File description:
** C4040
*/

#include "C4040.hpp"

C4040::C4040(const std::string &type) {
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
	this->stop = false;
}

void C4040::simulate(std::size_t tick) {
	for (std::size_t i = 0; i < tick; i++) {
		this->stop = false;
		Tristate oldValue = this->_pinsMap[10]->getTristate();
		this->_pinsMap[10]->setTristate(this->_pinsMap[10]->getPin()->getTristate());
		this->_pinsMap[11]->setTristate(this->_pinsMap[11]->getPin()->getTristate());
		if (this->_pinsMap[11]->getTristate() == TRUE) this->reset();
		else if (oldValue == FALSE && this->_pinsMap[10]->getTristate() == TRUE) {
			this->compute(9);
			this->compute(7);
			this->compute(6);
			this->compute(5);
			this->compute(3);
			this->compute(2);
			this->compute(4);
			this->compute(13);
			this->compute(12);
			this->compute(14);
			this->compute(15);
			this->compute(1);
		}
	}
}

Tristate C4040::compute(std::size_t pin) {
	if (!this->stop) {
		std::size_t index = 0;
		for (; transposedArray[index] != pin; index++);
		bool beforeIsTrue = true;
		for (int i = index - 1; i >= 0; i--)
			if (this->_pinsMap[this->transposedArray[i]]->getTristate() != TRUE)
				beforeIsTrue = false;
		if (beforeIsTrue) {
			if (index == 11 && this->_pinsMap[pin]->getTristate() == TRUE) {
				this->_pinsMap[pin]->setTristate(FALSE);
				this->stop = true;
				for (size_t i = 0; i < 12; i++)
					this->_pinsMap[this->transposedArray[i]]->setTristate(FALSE);
			} else if (this->_pinsMap[pin]->getTristate() == UNDEFINED || this->_pinsMap[pin]->getTristate() == FALSE) {
				this->_pinsMap[pin]->setTristate(TRUE);
				this->stop = true;
				for (int i = index - 1; i >= 0; i--)
					this->_pinsMap[this->transposedArray[i]]->setTristate(FALSE);
			}
		}
	}
	return (this->_pinsMap[pin]->getTristate());
}

void C4040::setLink(std::size_t pin, IComponent &other, std::size_t otherPin) {
    if (this->_pinsMap.find(pin) != this->_pinsMap.end() && other._pinsMap.find(otherPin) != other._pinsMap.end()) {
        this->_pinsMap[pin]->setPin(other._pinsMap[otherPin].get());
        other._pinsMap[otherPin]->setPin(this->_pinsMap[pin].get());
    } else throw Exception("Error: invalid links in component");
}

void C4040::dump() const {};

std::string C4040::getType() const {
    return (this->_type);
}

void C4040::reset() {
	for (auto ite = this->_pinsMap.begin(); ite != this->_pinsMap.end(); ite++)
		(*ite).second->setTristate(FALSE);
	this->stop = false;
}
