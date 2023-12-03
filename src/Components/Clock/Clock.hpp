/*
** EPITECH PROJECT, 2023
** Clock.hpp
** File description:
** Clock
*/

#pragma once

#include "IComponent.hpp"

class Clock : public nts::IComponent {
	public:
		Clock(const std::string &type);
        ~Clock();
		void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        void dump() const override;
        std::string getType() const override;
};
