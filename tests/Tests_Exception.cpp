/*
** EPITECH PROJECT, 2023
** Tests_Exception.cpp
** File description:
** Tests_Exception
*/

#include <criterion/criterion.h>
#include "Exception.hpp"

Test(Exception, WhatReturnsCorrectMessage) {
    Exception ex("Test Exception");
    cr_assert_str_eq(ex.what(), "Test Exception");
}

Test(Exception, WhatReturnsEmptyStringIfNoMessage) {
    Exception ex("");
    cr_assert_str_empty(ex.what());
}

Test(Exception, WhatReturnsCorrectMessageAfterCopy) {
    Exception ex("Test Exception");
    Exception ex2 = ex;
    cr_assert_str_eq(ex2.what(), "Test Exception");
}

Test(Exception, WhatReturnsCorrectMessageAfterMove) {
    Exception ex("Test Exception");
    Exception ex2 = std::move(ex);
    cr_assert_str_eq(ex2.what(), "Test Exception");
}

Test(Exception, WhatReturnsCorrectMessageAfterAssignment) {
    Exception ex("Test Exception");
    Exception ex2("");
    ex2 = ex;
    cr_assert_str_eq(ex2.what(), "Test Exception");
}
