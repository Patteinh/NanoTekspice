/*
** EPITECH PROJECT, 2023
** OR.hpp
** File description:
** OR
*/

#pragma once

#include "IComponent.hpp"

class OR: public nts::IComponent {
	public:
		OR(const std::string &type);
		void simulate(std::size_t tick) override;
		Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
		void dump() const override;
        std::string getType() const override;
};
