/*
** EPITECH PROJECT, 2023
** output.hpp
** File description:
** output
*/

#pragma once

#include "IComponent.hpp"

class Output : public nts::IComponent {
	public:
		Output(const std::string &type);
		void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
		void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        void dump() const override;
		std::string getType() const override;
};
