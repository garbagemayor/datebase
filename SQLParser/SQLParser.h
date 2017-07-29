#ifndef SQLPARSER_H
#define SQLPARSER_H

#include <SQLParserResult.h>

class SQLParser {
public:
    bool tokenize(const std::string& sql, std::vector<int>* result);
    bool parse(const std::string& sql, SQLParserResult* result);
};

#endif /* SQLPARSER_H */
