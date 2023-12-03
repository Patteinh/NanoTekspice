/*
** EPITECH PROJECT, 2023
** Circuit.hpp
** File description:
** Circuit
*/

#pragma once

#include <vector>
#include <algorithm>
#include "ComponentFactory.hpp"

typedef std::multimap<std::pair<std::string, std::string>, std::pair<std::string, std::string>> linksMap;
typedef std::multimap<std::string, std::string> chipsetsMap;
typedef std::vector<std::pair<std::string, std::unique_ptr<nts::IComponent>>> VectorComponent;

class Circuit {
    public:
        VectorComponent _listComponents;
        Circuit(chipsetsMap chipsetsMap, linksMap linksMap);
        ~Circuit();
        std::unique_ptr<nts::IComponent> &getComponent(const std::string &name);
        void display() const;
        void simulate(std::size_t tick);
    private:
        std::vector<std::string> _validInput = {"input", "clock", "true", "false"};
        ComponentFactory _factory;
        std::size_t _tick;
};
