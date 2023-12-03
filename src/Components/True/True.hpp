/*
** EPITECH PROJECT, 2023
** True.hpp
** File description:
** True
*/

#pragma once

#include "IComponent.hpp"

class True : public nts::IComponent {
	public:
		True(const std::string &type);
        ~True();
		void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        void dump() const override;
        std::string getType() const override;
};
