/*
** EPITECH PROJECT, 2023
** IComponent.hpp
** File description:
** IComponent
*/

#pragma once

#include <map>
#include <memory>
#include "Exception.hpp"
#include "Pin.hpp"

namespace nts {
    class IComponent {
        public:
            std::map<std::size_t,std::unique_ptr<Pin>> _pinsMap;
            virtual ~IComponent() = default;
            virtual void simulate(std::size_t tick) = 0;
            virtual Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;
            virtual std::string getType() const = 0;
            void setNextState(Tristate tristate) {
                _nextState = std::make_unique<Tristate>(tristate);
            }
        protected:
            std::string _type;
            std::unique_ptr<Tristate> _nextState;
    };

}
