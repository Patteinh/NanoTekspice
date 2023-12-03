/*
** EPITECH PROJECT, 2023
** C4071.hpp
** File description:
** C4071
*/

#pragma once

#include "IComponent.hpp"

class C4071: public nts::IComponent {
	public:
		C4071(const std::string &type);
		void simulate(std::size_t tick) override;
		Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
		void dump() const override;
        std::string getType() const override;
};