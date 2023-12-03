/*
** EPITECH PROJECT, 2023
** Pin.hpp
** File description:
** Pin
*/

#pragma once

#include <iostream>
#include "Exception.hpp"

enum Tristate { UNDEFINED = (-true), TRUE = true, FALSE = false };
namespace gates {
	Tristate _and(const Tristate &lhs, const Tristate &rhs);
	Tristate _or(const Tristate &lhs, const Tristate &rhs);
	Tristate _not(const Tristate &lhs);
	Tristate _nor(const Tristate &lhs, const Tristate &rhs);
	Tristate _nand(const Tristate &lhs, const Tristate &rhs);
	Tristate _xor(const Tristate &lhs, const Tristate &rhs);
}

class Pin {
    public:
        Pin(std::size_t pin);
        ~Pin();
        void setTristate(Tristate tristate);
        void setId(std::size_t id);
        void setPin(Pin *pin);
        Tristate getTristate() const;
        std::size_t getId() const;
        Pin *getPin() const;
    private:
        Tristate _tristate;
        std::size_t _id;
        Pin *_link;
};
