/*
** EPITECH PROJECT, 2023
** Tests_Gates.cpp
** File description:
** Tests_Gates
*/

#include <criterion/criterion.h>
#include "Pin.hpp"

Test(Gates, AndGateTest) {
    cr_assert_eq(gates::_and(TRUE, TRUE), TRUE);
    cr_assert_eq(gates::_and(TRUE, FALSE), FALSE);
    cr_assert_eq(gates::_and(FALSE, TRUE), FALSE);
    cr_assert_eq(gates::_and(FALSE, FALSE), FALSE);
    cr_assert_eq(gates::_and(TRUE, UNDEFINED), UNDEFINED);
    cr_assert_eq(gates::_and(FALSE, UNDEFINED), FALSE);
    cr_assert_eq(gates::_and(UNDEFINED, TRUE), UNDEFINED);
    cr_assert_eq(gates::_and(UNDEFINED, FALSE), FALSE);
    cr_assert_eq(gates::_and(UNDEFINED, UNDEFINED), UNDEFINED);
}

Test(GatesTest, OrGateTest) {
    cr_assert_eq(gates::_or(TRUE, TRUE), TRUE);
    cr_assert_eq(gates::_or(TRUE, FALSE), TRUE);
    cr_assert_eq(gates::_or(FALSE, TRUE), TRUE);
    cr_assert_eq(gates::_or(FALSE, FALSE), FALSE);
    cr_assert_eq(gates::_or(TRUE, UNDEFINED), TRUE);
    cr_assert_eq(gates::_or(FALSE, UNDEFINED), UNDEFINED);
    cr_assert_eq(gates::_or(UNDEFINED, TRUE), TRUE);
    cr_assert_eq(gates::_or(UNDEFINED, FALSE), UNDEFINED);
    cr_assert_eq(gates::_or(UNDEFINED, UNDEFINED), UNDEFINED);
}

Test(Gates, NotGateTest) {
    cr_assert_eq(gates::_not(TRUE), FALSE);
    cr_assert_eq(gates::_not(FALSE), TRUE);
    cr_assert_eq(gates::_not(UNDEFINED), UNDEFINED);
}

Test(Gates, NorGateTest) {
    cr_assert_eq(gates::_nor(TRUE, TRUE), FALSE);
    cr_assert_eq(gates::_nor(TRUE, FALSE), FALSE);
    cr_assert_eq(gates::_nor(FALSE, TRUE), FALSE);
    cr_assert_eq(gates::_nor(FALSE, FALSE), TRUE);
    cr_assert_eq(gates::_nor(TRUE, UNDEFINED), FALSE);
    cr_assert_eq(gates::_nor(FALSE, UNDEFINED), UNDEFINED);
    cr_assert_eq(gates::_nor(UNDEFINED, TRUE), FALSE);
    cr_assert_eq(gates::_nor(UNDEFINED, FALSE), UNDEFINED);
    cr_assert_eq(gates::_nor(UNDEFINED, UNDEFINED), UNDEFINED);
}

Test(Gates, NandGateTest) {
    cr_assert_eq(gates::_nand(TRUE, TRUE), FALSE);
    cr_assert_eq(gates::_nand(TRUE, FALSE), TRUE);
    cr_assert_eq(gates::_nand(FALSE, TRUE), TRUE);
    cr_assert_eq(gates::_nand(FALSE, FALSE), TRUE);
    cr_assert_eq(gates::_nand(TRUE, UNDEFINED), UNDEFINED);
    cr_assert_eq(gates::_nand(FALSE, UNDEFINED), TRUE);
    cr_assert_eq(gates::_nand(UNDEFINED, TRUE), UNDEFINED);
    cr_assert_eq(gates::_nand(UNDEFINED, FALSE), TRUE);
    cr_assert_eq(gates::_nand(UNDEFINED, UNDEFINED), UNDEFINED);
}

Test(Gates, XorGateTest) {
    cr_assert_eq(gates::_xor(TRUE, TRUE), FALSE);
    cr_assert_eq(gates::_xor(TRUE, FALSE), TRUE);
    cr_assert_eq(gates::_xor(FALSE, TRUE), TRUE);
    cr_assert_eq(gates::_xor(FALSE, FALSE), FALSE);
    cr_assert_eq(gates::_xor(TRUE, UNDEFINED), UNDEFINED);
    cr_assert_eq(gates::_xor(FALSE, UNDEFINED), UNDEFINED);
    cr_assert_eq(gates::_xor(UNDEFINED, TRUE), UNDEFINED);
    cr_assert_eq(gates::_xor(UNDEFINED, FALSE), UNDEFINED);
    cr_assert_eq(gates::_xor(UNDEFINED, UNDEFINED), UNDEFINED);
}
