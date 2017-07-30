# database过程记录
## 前期吐槽
- 可以统一用Makefile,不管你怎么生成的,你去下一个cbp2make试一试吧
- 这1000多行一个文件也太暴力了吧?真的要这样吗,可以找一个造好的轮子吗?
- 现在是什么接口?反正我先做解析后面再组合嘛

## sql-parser阅读
### top interface
1. parse: sqlString, scanner, result
2. tokenize: sqlString, scanner, tokens
3. result: statement, isValid

### sql statement
1. basic
    - enum StatementType: select, insert, delete etc.
    - struct SQLStatement: type_, type(), is(type)
    - struct TableRef: type, schema, name, alias, join
    - struct Expr: ExprType, OperatorType, 
2. derive
    - select: fromTable, selectDistinct, whereClause, groupBy
    - create: select, exist, filePath, tableName
    - import: filePath, tableName
    - insert: select, tableName, columns, values 
    - update: fromTable, updates, whereClause
    - delete: tableName, expr
    - drop: type, name

### parser
1. flex: write some rules(for each tokentype)
2. bison: write some grammar(for each statement)
