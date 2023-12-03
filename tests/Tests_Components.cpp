/*
** EPITECH PROJECT, 2023
** Tests_Components.cpp$
** File description:
** Tests_Components
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"
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

//Input
Test(Input, constructor) {
    Input input("type");
    cr_assert(true);
}

Test(Input, simulate) {
    Input input("type");
    input._pinsMap.emplace(2, std::make_unique<Pin>(2));
    input._pinsMap[2]->setTristate(FALSE);
    input.setLink(1, input, 2);
    input.simulate(1);
    cr_assert(input._pinsMap[1]->getPin()->getTristate() == FALSE);
}

Test(Input, compute) {
    Input input("type");
    Input input2("type");
    input2.setNextState(TRUE);
    cr_assert_eq(input2.compute(1), TRUE);
    cr_assert_throw(input.compute(2), Exception);
}

Test(Input, setLink) {
    Input input1("type1");
    Input input2("type2");
    input1._pinsMap.emplace(2, std::make_unique<Pin>(2));
    input2._pinsMap.emplace(2, std::make_unique<Pin>(2));
    input1.setLink(1, input2, 2);
    cr_assert_throw(input1.setLink(3, input2, 2), Exception);
    cr_assert_throw(input1.setLink(1, input2, 3), Exception);
}

Test(Input, dump) {
    Input input("type");
    input.dump();
}

// Output
Test(output, constructor) {
    Output output("type");
    cr_assert(true);
}

Test(output, simulate) {
    Output output("type");
    output._pinsMap.emplace(2, std::make_unique<Pin>(2));
    output._pinsMap[2]->setTristate(FALSE);
    output.setLink(1, output, 2);
    output.simulate(1);
    cr_assert(output._pinsMap[1]->getPin()->getTristate() == FALSE);
}

Test(output, compute) {
    Output output("type");
    cr_assert_throw(output.compute(2), Exception);
}

Test(output, setLink) {
    Output output1("type1");
    Output output2("type2");
    output1._pinsMap.emplace(2, std::make_unique<Pin>(2));
    output2._pinsMap.emplace(2, std::make_unique<Pin>(2));
    output1.setLink(1, output2, 2);
    cr_assert_throw(output1.setLink(3, output2, 2), Exception);
    cr_assert_throw(output1.setLink(1, output2, 3), Exception);
}

Test(output, dump) {
    Output output("type");
    output.dump();
}

//False
Test(False, Constructor) {
    False f("test");
    cr_assert_eq(f.getType(), "test");
    cr_assert_eq(f.compute(1), FALSE);
}

Test(False, Simulate) {
    False f("test");
    f.simulate(10);
    cr_assert_eq(f.compute(1), FALSE);
}

Test(False, Compute) {
    False f("test");
    cr_assert_eq(f.compute(1), FALSE);
    cr_assert_throw(f.compute(2), Exception);
}

Test(False, SetLink) {
    False f1("t1");
    False f2("t2");

    cr_assert_eq(f1.compute(1), FALSE);
    cr_assert_eq(f2.compute(1), FALSE);
    cr_assert_throw(f1.setLink(2, f2, 1), Exception);
    cr_assert_throw(f1.setLink(1, f2, 2), Exception);
}

Test(False, setLink_valid) {
    False f("false");
    Input i("input");
    cr_assert_throw(f.setLink(2, i, 1), Exception);
    f.setLink(1, i, 1);
    cr_assert_eq(f.compute(1), FALSE);
    cr_assert_eq(i.compute(1), FALSE);
}

Test(False, dump) {
    False _true("false");
    _true.dump();
    cr_assert(true);
}

//True
Test(True, Constructor) {
    True t("test");
    cr_assert_eq(t.getType(), "test");
    cr_assert_eq(t.compute(1), TRUE);
}

Test(True, Simulate) {
    True t("test");
    t.simulate(10);
    cr_assert_eq(t.compute(1), TRUE);
}

Test(True, Compute) {
    True t("test");
    cr_assert_eq(t.compute(1), TRUE);
    cr_assert_throw(t.compute(2), Exception);
}

Test(True, SetLink) {
    True t1("t1");
    True t2("t2");

    cr_assert_eq(t1.compute(1), TRUE);
    cr_assert_eq(t2.compute(1), TRUE);
    cr_assert_throw(t1.setLink(2, t2, 1), Exception);
    cr_assert_throw(t1.setLink(1, t2, 2), Exception);
}

Test(True, setLink_valid) {
    True t("true");
    Input i("input");
    cr_assert_throw(t.setLink(2, i, 1), Exception);
    t.setLink(1, i, 1);
    cr_assert_eq(t.compute(1), TRUE);
    cr_assert_eq(i.compute(1), TRUE);
}

Test(True, dump) {
    True _true("true");
    _true.dump();
    cr_assert(true);
}

//Clock
Test(Clock, Constructor) {
    Clock c("test");
    cr_assert_eq(c.getType(), "test");
    cr_assert_eq(c.compute(1), UNDEFINED);
}

Test(Clock, Simulate) {
    Clock c("test");
    c.simulate(1);
    cr_assert_eq(c.compute(1), UNDEFINED);
}

Test(Clock, Compute) {
    Clock c("test");
    cr_assert_eq(c.compute(1), UNDEFINED);
    cr_assert_throw(c.compute(2), Exception);
}

Test(Clock, Compute2) {
    Clock clock("clock");
    clock.setNextState(TRUE);
    cr_assert_eq(clock.compute(1), TRUE);
}

Test(Clock, SetLink) {
    Clock c1("c1");
    Clock c2("c2");
    cr_assert_eq(c1.compute(1), UNDEFINED);
    cr_assert_eq(c2.compute(1), UNDEFINED);
    cr_assert_throw(c1.setLink(2, c2, 1), Exception);
    cr_assert_throw(c1.setLink(1, c2, 2), Exception);
}

Test(Clock, setLink_valid) {
    Clock c("clock");
    Input i("input");
    cr_assert_throw(c.setLink(2, i, 1), Exception);
    c.setLink(1, i, 1);
    cr_assert_eq(c.compute(1), UNDEFINED);
    cr_assert_eq(i.compute(1), UNDEFINED);
    c.simulate(1);
    cr_assert_eq(c.compute(1), UNDEFINED);
    cr_assert_eq(i.compute(1), UNDEFINED);
}


Test(Clock, dump) {
    Clock c("clock");
    c.dump();
    cr_assert(true);
}

//C4001
Test(C4001, constructor) {
    C4001 c4001("c4001");
    cr_assert(true);
}

Test(C4001, simulate) {
    C4001 c4001("c4001");
    c4001.simulate(1);
}

Test(C4001, compute) {
    C4001 c4001("c4001");
    Input input("i");
    cr_expect_throw(c4001.compute(7), Exception);
    cr_expect_throw(c4001.setLink(277, input, 345), Exception);
    c4001.setLink(1, input, 1);
}

Test(C4001, dump) {
    C4001 c("C4001");
    c.dump();
    cr_assert(true);
}

//4008
Test(C4008, constructor) {
    C4008 c4008("c4008");
    cr_assert(true);
}

Test(C4008, simulate) {
    C4008 c4008("c4008");
    c4008.simulate(1);
}

Test(C4008, dump) {
    C4008 c("C4008");
    c.dump();
    cr_assert(true);
}

//4011
Test(C4011, constructor) {
    C4011 c4011("c4011");
    cr_assert(true);
}

Test(C4011, simulate) {
    C4011 c4011("c4011");
    c4011.simulate(1);
}

Test(C4011, compute) {
    C4011 c4011("c4011");
    Input input("i");
    cr_expect_throw(c4011.compute(20), Exception);
    cr_expect_throw(c4011.setLink(277, input, 345), Exception);
    c4011.setLink(1, input, 1);
}

Test(C4011, dump) {
    C4011 c("C4011");
    c.dump();
    cr_assert(true);
}

//4013
Test(C4013, constructor) {
    C4013 c4013("c4013");
    cr_assert(true);
}

Test(C4013, simulate) {
    C4013 c4013("c4013");
    c4013.simulate(1);
}

Test(C4013, compute) {
    C4013 c4013("c4013");
    Input input("i");
    cr_expect_throw(c4013.compute(20), Exception);
    cr_expect_throw(c4013.setLink(277, input, 345), Exception);
    c4013.setLink(1, input, 1);
}

Test(C4013, dump) {
    C4013 c("C4013");
    c.dump();
    cr_assert(true);
}

//4030
Test(C4030, constructor) {
    C4030 c4030("c4030");
    cr_assert(true);
}

Test(C4030, simulate) {
    C4030 c4030("c4030");
    c4030.simulate(1);
}

Test(C4030, compute) {
    C4030 c4030("c4030");
    Input input("i");
    cr_expect_throw(c4030.compute(20), Exception);
    cr_expect_throw(c4030.setLink(277, input, 345), Exception);
    c4030.setLink(1, input, 1);
}

Test(C4030, dump) {
    C4030 c("C4030");
    c.dump();
    cr_assert(true);
}

//4040
Test(C4040, constructor) {
    C4040 c4040("c4040");
    cr_assert(true);
}

// Test(C4040, simulate)
// {
//     C4040 c4040("c4040");
//     c4040.simulate(1);
// }

Test(C4040, compute)
{
    C4040 c4040("c4040");
    Input input("i");
    cr_expect_throw(c4040.setLink(277, input, 345), Exception);
}

Test(C4040, dump) {
    C4040 c("C4040");
    c.dump();
    cr_assert(true);
}

//4069
Test(C4069, constructor) {
    C4069 c4069("c4069");
    cr_assert(true);
}

Test(C4069, simulate) {
    C4069 c4069("c4069");
    c4069.simulate(1);
}

Test(C4069, compute) {
    C4069 c4069("c4069");
    Input input("i");
    cr_expect_throw(c4069.compute(20), Exception);
    cr_expect_throw(c4069.setLink(277, input, 345), Exception);
    c4069.setLink(1, input, 1);
}

Test(C4069, dump) {
    C4069 c("C4069");
    c.dump();
    cr_assert(true);
}

//4071
Test(C4071, constructor) {
    C4071 c4071("c4071");
    cr_assert(true);
}

Test(C4071, simulate) {
    C4071 c4071("c4071");
    c4071.simulate(1);
}

Test(C4071, compute) {
    C4071 c4071("c4071");
    Input input("i");
    cr_expect_throw(c4071.compute(20), Exception);
    cr_expect_throw(c4071.setLink(277, input, 345), Exception);
    c4071.setLink(1, input, 1);
}

Test(C4071, dump) {
    C4071 c("C4071");
    c.dump();
    cr_assert(true);
}

//4081
Test(C4081, constructor) {
    C4081 c4081("c4081");
    cr_assert(true);
}

Test(C4081, simulate) {
    C4081 c4081("c4081");
    c4081.simulate(1);
}

Test(C4081, compute) {
    C4081 c4081("c4081");
    True __true("i");
    cr_expect_throw(c4081.compute(20), Exception);
    cr_expect_throw(c4081.setLink(277, __true, 345), Exception);
    c4081.setLink(1, __true, 1);
}

Test(C4081, dump) {
    C4081 c("C4081");
    c.dump();
    cr_assert(true);
}

//4094
Test(C4094, constructor) {
    C4094 c4081("c4081");
    cr_assert(true);
}

// Test(C4094, simulate) {
//     C4094 c4094("c4094");
//     c4094.simulate(1);
// }

Test(C4094, compute) {
    C4094 c4094("c4094");
    True __true("i");
    cr_expect_throw(c4094.compute(20), Exception);
    cr_expect_throw(c4094.setLink(277, __true, 345), Exception);
    c4094.setLink(1, __true, 1);
}

Test(C4094, dump) {
    C4094 c("C4094");
    c.dump();
    cr_assert(true);
}

//Pin
Test(Pin, SetId) {
    Pin p(1);
    p.setId(2);
    cr_assert(true);
}

Test(Pin, SetPin) {
    Pin p(1);
    Pin p2(1);
    p.setPin(&p2);
    cr_expect_throw(p.setPin(&p), Exception);
}

Test(Pin, GetId) {
    Pin p(2);
    cr_assert_eq(p.getId(), 2);
}

//and
Test(AND, constructor) {
    AND _and("_and");
    cr_assert(true);
}

Test(AND, simulate) {
    AND _and("_and");
    _and.simulate(1);
}

Test(AND, compute) {
    AND _and("_and");
    True __true("i");
    cr_expect_throw(_and.compute(20), Exception);
    cr_expect_throw(_and.setLink(277, __true, 345), Exception);
    _and.setLink(1, __true, 1);
}

Test(AND, dump) {
    AND c("AND");
    c.dump();
    cr_assert(true);
}

Test(AND, getType) {
    AND c("AND");
    cr_assert_eq(c.getType(), "AND");
}

//or
Test(OR, constructor) {
    OR _or("_or");
    cr_assert(true);
}

Test(OR, simulate) {
    OR _or("_or");
    _or.simulate(1);
}

Test(OR, compute) {
    OR _or("_or");
    True __true("i");
    cr_expect_throw(_or.compute(20), Exception);
    cr_expect_throw(_or.setLink(277, __true, 345), Exception);
    _or.setLink(1, __true, 1);
}

Test(OR, dump) {
    OR c("OR");
    c.dump();
    cr_assert(true);
}

Test(OR, getType) {
    OR c("OR");
    cr_assert_eq(c.getType(), "OR");
}

//xor
Test(XOR, constructor) {
    XOR _xor("_xor");
    cr_assert(true);
}

Test(XOR, simulate) {
    XOR _xor("_xor");
    _xor.simulate(1);
}

Test(XOR, compute) {
    XOR _xor("_xor");
    True __true("i");
    cr_expect_throw(_xor.compute(20), Exception);
    cr_expect_throw(_xor.setLink(277, __true, 345), Exception);
    _xor.setLink(1, __true, 1);
}

Test(XOR, dump) {
    XOR c("XOR");
    c.dump();
    cr_assert(true);
}

Test(XOR, getType) {
    XOR c("XOR");
    cr_assert_eq(c.getType(), "XOR");
}

//not
Test(NOT, constructor) {
    NOT _not("_not");
    cr_assert(true);
}

Test(NOT, simulate) {
    NOT _not("_not");
    _not.simulate(1);
}

Test(NOT, compute) {
    NOT _not("_not");
    True __true("i");
    cr_expect_throw(_not.compute(20), Exception);
    cr_expect_throw(_not.setLink(277, __true, 345), Exception);
    _not.setLink(1, __true, 1);
}

Test(NOT, dump) {
    NOT c("NOT");
    c.dump();
    cr_assert(true);
}

Test(NOT, getType) {
    NOT c("NOT");
    cr_assert_eq(c.getType(), "NOT");
}