/*
** EPITECH PROJECT, 2023
** False.hpp
** File description:
** False
*/

#pragma once

#include "IComponent.hpp"

class False : public nts::IComponent {
	public:
		False(const std::string &type);
        ~False();
		void simulate(std::size_t tick) override;
        Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        void dump() const override;
        std::string getType() const override;
};
