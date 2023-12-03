/*
** EPITECH PROJECT, 2023
** Tests_Circuit.cpp
** File description:
** Tests_Circuit
*/

#include <criterion/criterion.h>
#include "Parser.hpp"
#include "Circuit.hpp"

Test(Circuit, DisplayOutputsCorrectly) {
    chipsetsMap chipsets = {{"input", "in"}, {"output", "out"}, {"clock", "cl"}};
    linksMap links = {{{"in", "1"}, {"out", "1"}}};
    Circuit circuit(chipsets, links);
    std::stringstream ss;
    std::streambuf* oldCoutBuf = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    circuit.display();
    std::cout.rdbuf(oldCoutBuf);
    circuit.simulate(1);
    cr_assert_eq(ss.str().compare("tick: 0\ninput(s):\n  cl: U\n  in: U\noutput(s):\n  out: U\n"), 0);
}

Test(Circuit, ThrowInvalidInputInput) {
    chipsetsMap chipsets = {{"input", "in"}, {"output", "out"}};
    linksMap links = {{{"in", "1"}, {"in", "1"}}};
    cr_expect_throw(Circuit circuit(chipsets, links), Exception);
}

Test(Circuit, ThrowInvalidOutputOutput) {
    chipsetsMap chipsets = {{"output", "o1"}, {"output", "o2"}};
    linksMap links = {{{"o1", "1"}, {"o2", "1"}}};
    cr_expect_throw(Circuit circuit(chipsets, links), Exception);
}

Test(Circuit, ThrowInvalidLinkNotMadeWithInputOrOutput) {
    chipsetsMap chipsets = {{"input", "in"}, {"output", "out"}, {"4008", "in2"}, {"output", "out2"}};
    linksMap links = {{{"in", "1"}, {"out", "1"}}, {{"in2", "1"}, {"out2", "1"}}};
    cr_expect_throw(Circuit circuit(chipsets, links), Exception);
}

Test(Circuit, ThrowInvalidcomponentInputOrOutput) {
    chipsetsMap chipsets = {{"23567", "in"}, {"output", "out"}, {"4008", "in2"}, {"output", "out2"}};
    linksMap links = {{{"in", "1"}, {"out", "1"}}, {{"in2", "1"}, {"out2", "1"}}};
    cr_expect_throw(Circuit circuit(chipsets, links), Exception);
}

Test(Circuit, ThrowInvalidPin) {
    chipsetsMap chipsets = {{"input", "in"}, {"output", "out"}, {"input", "in2"}, {"output", "out2"}};
    linksMap links = {{{"in", "1"}, {"out", "1"}}, {{"in2", "1"}, {"out2", "1"}}};
    cr_expect_throw(Circuit circuit(chipsets, links), Exception);
}

Test(Circuit, ThrowInvalidComponent) {
    chipsetsMap chipsets = {{"input", "in"}, {"output", "out"}, {"input", "in2"}, {"output", "out2"}};
    linksMap links = {{{"in", "1"}, {"out", "1"}}, {{"i", "1"}, {"out2", "2"}}};
    cr_expect_throw(Circuit circuit(chipsets, links), Exception);
}

Test(Circuit, ValidSimulation4001) {
    Parser pars("testsNTS/4001_nor.nts");
    Circuit c(pars.GetChipsets(), pars.GetLinks());
    cr_assert_eq(0, 0);
}

Test(Circuit, ValidSimulation4008) {
    Parser pars("testsNTS/4008_adder.nts");
    Circuit c(pars.GetChipsets(), pars.GetLinks());
    cr_assert_eq(0, 0);
}

Test(Circuit, ValidSimulation4011) {
    Parser pars("testsNTS/4011_nand.nts");
    Circuit c(pars.GetChipsets(), pars.GetLinks());
    cr_assert_eq(0, 0);
}

Test(Circuit, ValidSimulation4013) {
    Parser pars("testsNTS/4013_flipflop.nts");
    Circuit c(pars.GetChipsets(), pars.GetLinks());
    cr_assert_eq(0, 0);
}

Test(Circuit, ValidSimulation4030) {
    Parser pars("testsNTS/4030_xor.nts");
    Circuit c(pars.GetChipsets(), pars.GetLinks());
    cr_assert_eq(0, 0);
}

Test(Circuit, ValidSimulation4040) {
    Parser pars("testsNTS/4040_counter.nts");
    Circuit c(pars.GetChipsets(), pars.GetLinks());
    cr_assert_eq(0, 0);
}

Test(Circuit, ValidSimulation4069) {
    Parser pars("testsNTS/4069_not.nts");
    Circuit c(pars.GetChipsets(), pars.GetLinks());
    cr_assert_eq(0, 0);
}

Test(Circuit, ValidSimulation4071) {
    Parser pars("testsNTS/4071_or.nts");
    Circuit c(pars.GetChipsets(), pars.GetLinks());
    cr_assert_eq(0, 0);
}

Test(Circuit, ValidSimulation4081) {
    Parser pars("testsNTS/4081_and.nts");
    Circuit c(pars.GetChipsets(), pars.GetLinks());
    cr_assert_eq(0, 0);
}

Test(Circuit, ValidSimulationTrue) {
    Parser pars("testsNTS/true.nts");
    Circuit c(pars.GetChipsets(), pars.GetLinks());
    cr_assert_eq(0, 0);
}

Test(Circuit, ValidSimulationFalse) {
    Parser pars("testsNTS/false.nts");
    Circuit c(pars.GetChipsets(), pars.GetLinks());
    cr_assert_eq(0, 0);
}

Test(Circuit, ValidSimulation4094) {
    Parser pars("testsNTS/4094_shift.nts");
    Circuit c(pars.GetChipsets(), pars.GetLinks());
    cr_assert_eq(0, 0);
}
