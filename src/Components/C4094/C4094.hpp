/*
** EPITECH PROJECT, 2023
** C4094.hpp
** File description:
** C4094
*/

#pragma once

#include <bitset>
#include "IComponent.hpp"

class C4094 : public nts::IComponent {
    public:
        C4094(const std::string &type);
        void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        void dump() const override;
        std::string getType() const override;
    private:
        std::string _type;
        bool _enable;
        bool _strobe;
        std::bitset<8> _savedValue;
        std::bitset<8> _shiftRegister;
};
