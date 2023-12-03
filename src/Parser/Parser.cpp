/*
** EPITECH PROJECT, 2023
** Parser.cpp
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser(const std::string &filepath) {
    std::ifstream file(filepath);
    std::string line;
    bool isLinks = false;
    bool isChipsets = false;

    if (filepath.length() < 4 || filepath.substr(filepath.length() - 4, 4) != ".nts")
        throw Exception("Error: invalid file type: " + filepath);
    if (!file.is_open())
        throw Exception("Error: Failed to open file: " + filepath);
    while (std::getline(file, line))
        this->_fileContent.push_back(line);
    file.close();
    for (const auto& it : this->_fileContent) {
        std::string line = it.substr(0, it.find("#"));
        line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
        if (!line.find(".chipsets:") && line.back() == ':') { isChipsets = true; continue; }
        if (!line.find(".links:") && line.back() == ':') { isLinks = true; break; }
    }
    if (isLinks && !isChipsets) throw Exception("Error: no '.chipsets:' in file");
    if (!isLinks) throw Exception("Error: no '.links:' in file");
    this->SetChipsets(this->_fileContent);
    this->SetLinks(this->_fileContent);
    if (!GetChipsets().size() || !GetLinks().size())
        throw Exception("Error: Empty '.chipsets:' or '.links:' in file");
}

Parser::~Parser() {};

void Parser::SetChipsets(const std::vector<std::string> &fileContent) {
    bool isChipsets = false;
    std::string line;
    for (const auto& it : fileContent) {
        if (!it.find(".chipsets:")) { isChipsets = true; continue; }
        if (!it.find(".links:")) break;
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
        line.erase(std::remove(line.begin(), line.end(), '\t'), line.end());
        line = it.substr(0, it.find("#"));
        std::string line = it.substr(0, it.find("#"));
        if (!isChipsets || line.empty()) continue;
        std::istringstream iss(line);
        std::vector<std::string> tok(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{});
        if (tok.size() != 2) throw Exception("Error: invalid numbers of args of chipsets line in file");
        auto isNameValid = std::find(_validTypes.begin(), _validTypes.end(), tok[0]);
        if (isNameValid == _validTypes.end()) throw Exception("Error: invalid chipsets in file");
        if (ContainsKey(this->_chipsets, tok[1]) == true) throw Exception("Error: name already exist in '.chipsets:'");
        this->_chipsets.insert(std::make_pair(tok[0], tok[1]));
    }
}

template<typename Map, typename Key>
bool Parser::ContainsKey(const Map& map, const Key& key) const {
    auto pred = [&key](const typename Map::value_type& element) { return element.second == key; };
    return (std::find_if(map.begin(), map.end(), pred) != map.end());
}

void Parser::SetLinks(const std::vector<std::string> &fileContent) {
    bool isLinks = false;
    std::string line;
    for (const auto& it : fileContent) {
        if (it.find(".links:") != std::string::npos) { isLinks = true; continue; }
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
        line.erase(std::remove(line.begin(), line.end(), '\t'), line.end());
        line = it.substr(0, it.find("#"));
        if (!isLinks || line.empty()) continue;
        std::istringstream iss(line);
        std::vector<std::string> tok(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{});
        if (tok.size() != 2) throw Exception("Error: invalid numbers of args of links line in file");
        if (tok[0].find(":") == std::string::npos || tok[1].find(":") == std::string::npos ||
        tok[0].find(":") != tok[0].rfind(":") || tok[1].find(":") != tok[1].rfind(":") ||
        tok[0].substr(tok[0].find(":") + 1).empty() || tok[1].substr(tok[1].find(":") + 1).empty()) throw Exception("Error: invalid separator in '.links:'");
        if (ContainsKey(this->_chipsets, tok[0].substr(0, tok[0].find(":"))) != true || ContainsKey(this->_chipsets, tok[1].substr(0, tok[1].find(":"))) != true)
            throw Exception("Error: name in '.links:' not exist in '.chipsets:'");
        this->_links.insert(std::make_pair(std::make_pair(tok[0].substr(0, tok[0].find(":")), tok[0].substr(tok[0].find(":") + 1)),
        std::make_pair(tok[1].substr(0, tok[1].find(":")), tok[1].substr(tok[1].find(":") + 1))));
    }
}

chipsetsMap Parser::GetChipsets() const {
    return (this->_chipsets);
}

linksMap Parser::GetLinks() const {
    return (this->_links);
}
