#ifndef SQLPARSER_H
#define SQLPARSER_H

#include <cstdio>
#include <string>
#include <vector>
#include "SQLParserResult.h"

class SQLParser {
public:
    bool parse(const std::string& sql, SQLParserResult* result);
    bool tokenize(const std::string& sql, std::vector<int>* result);
};

#endif /* SQLPARSER_H */
