#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest/doctest.h"
#include "parser_changes_information.hpp"

TEST_SUITE("ParserChangesInformation")
{
    ParserChangesInformation pci;

    auto compareRegexes = [](auto r1, auto r2)
    {
        CHECK(r1.first == r2.first);
        CHECK(r1.second == r2.second);
    };

    TEST_CASE("Correct regex")
    {
        pci = {"%regex identifier [_[:alpha:]][_[:alnum:]]*"};
        auto regexes = pci.getRegexes();
        compareRegexes(pci.getRegexes()[0],
                       ParserChangesInformation::Regex{"identifier", "[_[:alpha:]][_[:alnum:]]*"});
    }

    TEST_CASE("Incorrect regex name")
    {
        CHECK_THROWS_AS(ParserChangesInformation{"%regex incorr3ct [_[:alpha:]][_[:alnum:]]*"},
                        ParserChangesInformation::BadRule);
    }

    TEST_CASE("Extra arguments")
    {
        CHECK_THROWS_AS(ParserChangesInformation{"%regex digit [0-9] extraArg"},
                        ParserChangesInformation::BadRule);
    }
}
