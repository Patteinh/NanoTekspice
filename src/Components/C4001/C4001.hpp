/*
** EPITECH PROJECT, 2023
** C4001.hpp
** File description:
** C4001
*/

#pragma once

#include "IComponent.hpp"

class C4001: public nts::IComponent {
	public:
		C4001(const std::string &type);
		void simulate(std::size_t tick) override;
		Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
		void dump() const override;
        std::string getType() const override;
};
