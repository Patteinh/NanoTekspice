/*
** EPITECH PROJECT, 2023
** C4040.hpp
** File description:
** C4040
*/

#pragma once

#include "IComponent.hpp"

class C4040: public nts::IComponent {
	public:
		C4040(const std::string &type);
		void simulate(std::size_t tick) override;
		Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
		void dump() const override;
        std::string getType() const override;
		void reset();
	private:
		bool stop;
		std::size_t transposedArray[12] = {9, 7, 6, 5, 3, 2, 4, 13, 12, 14, 15, 1}; //nb dabs l'ordre du compteur bit
};
