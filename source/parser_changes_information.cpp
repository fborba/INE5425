#include <sstream>
#include <regex>

#include "parser_changes_information.hpp"

ParserChangesInformation::ParserChangesInformation(std::string changes)
{
    addChanges(std::move(changes));
}

void ParserChangesInformation::addChanges(std::string changes)
{
    std::istringstream input {std::move(changes)};
    std::regex rule {R"(\s*%regex\s+([[:alpha:]][_[:alpha:]]*)\s+(\S+)\s*)"};

    std::string line;
    while (std::getline(input, line))
    {
        std::smatch matches;
        if (!std::regex_match(line, matches, rule))
        {
            throw BadRule{std::move(line)};
        }
        regexes_.push_back({matches[1], matches[2]});
    }
}

const std::vector<ParserChangesInformation::Regex>& ParserChangesInformation::getRegexes() const noexcept
{
    return regexes_;
}

ParserChangesInformation::BadRule::BadRule()
:   std::runtime_error{""}
{
}
