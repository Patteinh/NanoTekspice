/*
** EPITECH PROJECT, 2023
** Tests_Parser.cpp
** File description:
** Tests_Parser
*/

#include <criterion/criterion.h>
#include "Parser.hpp"

Test(Parser, valid_file_simple) {
    Parser parser("testsNTS/valid_file_simple.nts");
    cr_assert(parser.GetChipsets().size() == 3);
    cr_assert(parser.GetLinks().size() == 2);
}

Test(Parser, valid_file_commentary) {
    Parser parser("testsNTS/valid_file_commentary.nts");
    cr_assert(parser.GetChipsets().size() == 3);
    cr_assert(parser.GetLinks().size() == 2);
}

Test(Parser, valid_file_long) {
    Parser parser("testsNTS/valid_file_long.nts");
    cr_assert(parser.GetChipsets().size() == 23);
    cr_assert(parser.GetLinks().size() == 22);
}

Test(Parser, valid_file_long_commentary) {
    Parser parser("testsNTS/valid_file_long_commentary.nts");
    cr_assert(parser.GetChipsets().size() == 23);
    cr_assert(parser.GetLinks().size() == 22);
}

Test(Parser, invalid_file_commentary) {
    cr_expect_throw(Parser("testsNTS/invalid_file_commentary.nts"), Exception);
}

Test(Parser, invalid_file_type) {
    cr_expect_throw(Parser("testsNTS/invalid_file.txt"), Exception);
}

Test(Parser, invalid_file_path) {
    cr_expect_throw(Parser("testsNTS/nonexistent_file.nts"), Exception);
}

Test(Parser, invalid_file_no_chipsets) {
    cr_expect_throw(Parser parser("testsNTS/invalid_file_no_chipsets.nts"), Exception);
}

Test(Parser, invalid_file_no_chipsets2) {
    cr_expect_throw(Parser parser("testsNTS/invalid_file_no_chipsets2.nts"), Exception);
}

Test(Parser, invalid_file_chipsets_type) {
    cr_expect_throw(Parser("testsNTS/invalid_file_chipsets_type.nts"), Exception);
}

Test(Parser, invalid_file_chipsets_format) {
    cr_expect_throw(Parser("testsNTS/invalid_file_chipsets_format.nts"), Exception);
}

Test(Parser, invalid_file_chipsets_name_already_exist) {
    cr_expect_throw(Parser parser("testsNTS/invalid_file_chipsets_name_already_exist.nts"), Exception);
}

Test(Parser, invalid_file_no_links) {
    cr_expect_throw(Parser parser("testsNTS/invalid_file_no_links.nts"), Exception);
}

Test(Parser, invalid_file_no_links2) {
    cr_expect_throw(Parser parser("testsNTS/invalid_file_no_links2.nts"), Exception);
}

Test(Parser, invalid_file_links_name) {
    cr_expect_throw(Parser parser("testsNTS/invalid_file_links_name.nts"), Exception);
}

Test(Parser, invalid_file_links_separator) {
    cr_expect_throw(Parser parser("testsNTS/invalid_file_links_separator.nts"), Exception);
}

Test(Parser, invalid_file_links_separator2) {
    cr_expect_throw(Parser parser("testsNTS/invalid_file_links_separator2.nts"), Exception);
}

Test(Parser, invalid_file_links_separator3) {
    cr_expect_throw(Parser parser("testsNTS/invalid_file_links_separator3.nts"), Exception);
}

Test(Parser, invalid_file_links_separator4) {
    cr_expect_throw(Parser parser("testsNTS/invalid_file_links_separator4.nts"), Exception);
}

Test(Parser, invalid_file_links_separator5) {
    cr_expect_throw(Parser parser("testsNTS/invalid_file_links_separator5.nts"), Exception);
}

Test(Parser, invalid_file_links_separator6) {
    cr_expect_throw(Parser parser("testsNTS/invalid_file_links_separator6.nts"), Exception);
}

Test(Parser, invalid_file_links_separator7) {
    cr_expect_throw(Parser parser("testsNTS/invalid_file_links_separator7.nts"), Exception);
}

Test(Parser, invalid_file_links_name_already_exist) {
    cr_expect_throw(Parser parser("testsNTS/invalid_file_links_name_already_exist.nts"), Exception);
}
