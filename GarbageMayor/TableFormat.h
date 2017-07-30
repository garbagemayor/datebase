#ifndef TABLEFORMAT_H_
#define TABLEFORMAT_H_

#include "DataType.h"

namespace GarbageMayor
{
    /*
    单元格格式类。
    */
    class TFcell
    {
    private:
        DTenum type;        //列数据类型
        int nlen;           //列名称长度
        char * name;        //列名称
        
    public:
        TFcell(DTenum type_, const char * name_, int nlen_ = -1);
        TFcell(const TFcell & tf);
        ~TFcell();
        
    public:
        void write() const;
        //void read_fb(FILE * & file);
        void write_fb(FILE * & file) const;
        const char * const get_typename() const;
    };
    
    /*
    行格式。
    */
    class TFrow
    {
    private:
        int col;            //列数
        TFcell * format;    //格式
        
    public:
        
        
    };
}

#endif // TABLEFORMAT_H_
