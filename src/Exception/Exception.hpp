/*
** EPITECH PROJECT, 2023
** Exception.hpp
** File description:
** Exception
*/

#pragma once

#include <iostream>

class Exception : public std::exception {
    public:
        Exception(const std::string &e) noexcept;
        ~Exception();
        virtual const char* what() const noexcept;
    private:
        std::string _e;
};
