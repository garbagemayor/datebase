#ifndef TABLEROW_H
#define TABLEROW_H

#include "DataType.h"

namespace GarbageMayor
{
    /*
    表头。
    记录列数、每列的类型。
    */
    class TableHeader
    {
        
    };
    
    class TableRow
    {
    private:
        int column_number;  //列数
        
        DataTypeBase * data;//数据内容
        
        
        
    public:
        TableRow();
        ~TableRow();

    private:
        
    };

    
    
    class Table
    {
        
        
        
    };
} 

#endif // GARBAGEMAYOR_TABLEROW_H
