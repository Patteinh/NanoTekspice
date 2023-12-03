/*
** EPITECH PROJECT, 2023
** Parser.hpp
** File description:
** Parser
*/

#pragma once

#include <algorithm>
#include <iterator>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include "Exception.hpp"

typedef std::multimap<std::pair<std::string, std::string>, std::pair<std::string, std::string>> linksMap;
typedef std::multimap<std::string, std::string> chipsetsMap;

class Parser {
    public:
        Parser(const std::string &filepath = "");
        ~Parser();
        void SetChipsets(const std::vector<std::string> &fileContent);
        void SetLinks(const std::vector<std::string> &fileContent);
        template<typename Map, typename Key>
        bool ContainsKey(const Map &map, const Key &key) const;
        chipsetsMap GetChipsets() const;
        linksMap GetLinks() const;
    private:
        std::vector<std::string> _fileContent;
        chipsetsMap _chipsets;
        linksMap  _links;
        std::vector<std::string> _validTypes = {"input", "clock", "true", "false", "output",
                                                "and", "or", "xor", "not","4001", "4011", "4030",
                                                "4071", "4081", "4069", "4008", "4013", "4017",
                                                "4040", "4094", "4512", "4514", "4801", "2716"};
};
