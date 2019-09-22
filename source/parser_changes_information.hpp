#pragma once

#include <string>
#include <vector>

/// A builder class that gathers information in order to expand a grammar.
class ParserChangesInformation
{
public:
    /// Alias for regexes.
    using Regex = std::pair<std::string, std::string>;

    class BadRule;

    /// Creates a new empty object.
    ParserChangesInformation() = default;
    /// Create a new objects containing the rules given in changes.
    ParserChangesInformation(std::string changes);

    /// Include additional rules.
    void addChanges(std::string changes);

    /// Return the regexes rules.
    const std::vector<Regex>& getRegexes() const noexcept;

private:
    std::vector<Regex> regexes_;
};

/// Indicates as bad rule during parsing of new rules.
class ParserChangesInformation::BadRule : public std::runtime_error
{
public:
    using runtime_error::runtime_error;
    BadRule();
};
