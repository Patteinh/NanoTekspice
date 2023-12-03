/*
** EPITECH PROJECT, 2023
** ComponentFactory.hpp
** File description:
** ComponentFactory
*/

#pragma once

#include "Input.hpp"
#include "Output.hpp"
#include "True.hpp"
#include "False.hpp"
#include "Clock.hpp"
#include "C4001.hpp"
#include "C4008.hpp"
#include "C4011.hpp"
#include "C4013.hpp"
#include "C4030.hpp"
#include "C4040.hpp"
#include "C4069.hpp"
#include "C4071.hpp"
#include "C4081.hpp"
#include "C4094.hpp"
#include "AND.hpp"
#include "OR.hpp"
#include "XOR.hpp"
#include "NOT.hpp"

typedef std::unique_ptr<nts::IComponent> component;

class ComponentFactory {
    public:
        component createComponent(const std::string &type) const {
            if (type == "input") return (createInput());
            else if (type == "output") return (createOutput());
            else if (type == "true") return (createTrue());
            else if (type == "false") return (createFalse());
            else if (type == "clock") return (createClock());
            else if (type == "and") return (createAnd());
            else if (type == "or") return (createOr());
            else if (type == "xor") return (createXor());
            else if (type == "not") return (createNot());
            else if (type == "4001") return (create4001());
            else if (type == "4008") return (create4008());
            else if (type == "4011") return (create4011());
            else if (type == "4013") return (create4013());
            else if (type == "4030") return (create4030());
            else if (type == "4040") return (create4040());
            else if (type == "4069") return (create4069());
            else if (type == "4071") return (create4071());
            else if (type == "4081") return (create4081());
            else if (type == "4094") return (create4094());
            else throw Exception("Error: invalid component call");
        }
    private:
        component createInput() const noexcept { return (std::make_unique<Input>("input")); }
        component createOutput() const noexcept { return (std::make_unique<Output>("output")); }
        component createTrue() const noexcept { return (std::make_unique<True>("true")); }
        component createFalse() const noexcept { return (std::make_unique<False>("false")); }
        component createClock() const noexcept { return (std::make_unique<Clock>("clock")); }
        component createAnd() const noexcept { return (std::make_unique<AND>("and")); }
        component createOr() const noexcept { return (std::make_unique<OR>("or")); }
        component createXor() const noexcept { return (std::make_unique<XOR>("xor")); }
        component createNot() const noexcept { return (std::make_unique<NOT>("not")); }
        component create4001() const noexcept { return (std::make_unique<C4001>("4001")); }
        component create4008() const noexcept { return (std::make_unique<C4008>("4008")); }
        component create4011() const noexcept { return (std::make_unique<C4011>("4011")); }
        component create4013() const noexcept { return (std::make_unique<C4013>("4013")); }
        component create4030() const noexcept { return (std::make_unique<C4030>("4030")); }
        component create4040() const noexcept { return (std::make_unique<C4040>("4040")); }
        component create4069() const noexcept { return (std::make_unique<C4069>("4069")); }
        component create4071() const noexcept { return (std::make_unique<C4071>("4071")); }
        component create4081() const noexcept { return (std::make_unique<C4081>("4081")); }
        component create4094() const noexcept { return (std::make_unique<C4094>("4094")); }
};
