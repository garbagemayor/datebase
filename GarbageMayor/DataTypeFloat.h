#ifndef DATATYPEFLOAT_H_
#define DATATYPEFLOAT_H_

#include "DataTypeBase.h"

/*
各种浮点数。
*/
namespace GarbageMayor
{
    /*
    32位浮点数。
    */
    class DTfloat32
        : public DTbase
    {
    private:
        float value;
        
    public:
        DTfloat32();
        DTfloat32(float value_);
        DTfloat32(const DTfloat32 & dt);
        ~DTfloat32();
    
    public:
        void read();
        void write() const;
        void read_fb(FILE * & file);
        void write_fb(FILE * & file) const;
        int size() const;
        void clear();
        
    public:
        float get_value() const;
        void set_value(float value_);
        
    public:
        bool operator == (const DTfloat32 & dt) const;
        bool operator != (const DTfloat32 & dt) const;
        bool operator < (const DTfloat32 & dt) const;
        bool operator <= (const DTfloat32 & dt) const;
        bool operator > (const DTfloat32 & dt) const;
        bool operator >= (const DTfloat32 & dt) const;
    };
    
    /*
    64位浮点数。
    */
    class DTfloat64
        : public DTbase
    {
    private:
        double value;
        
    public:
        DTfloat64();
        DTfloat64(double value_);
        DTfloat64(const DTfloat64 & dt);
        ~DTfloat64();
    
    public:
        void read();
        void write() const;
        void read_fb(FILE * & file);
        void write_fb(FILE * & file) const;
        int size() const;
        void clear();
        
    public:
        double get_value() const;
        void set_value(double value_);
        
    public:
        bool operator == (const DTfloat64 & dt) const;
        bool operator != (const DTfloat64 & dt) const;
        bool operator < (const DTfloat64 & dt) const;
        bool operator <= (const DTfloat64 & dt) const;
        bool operator > (const DTfloat64 & dt) const;
        bool operator >= (const DTfloat64 & dt) const;
    };
    
    /*
    高精度浮点数。
    记录整数部分位数和小数部分位数，压位存储时整数部分向右对齐，小数部分向左对齐。
    读入时已删除整数部分前导零和小数部分后缀零。
    */
    class DTfloathp
        : public DTbase
    {
    private:
        int flag;       //符号位, +1, -1, 0
        int dlen;       //小数点前有多少位
        int plen;       //小数点后有多少位
        int alen;       //整数部分数组大小
        int blen;       //小数部分数组大小
        int * digit;    //每8个十进制位
        
    public:
        DTfloathp();
        DTfloathp(const char * vs, int slen_ = -1);
        DTfloathp(const DTfloathp & dt);
        ~DTfloathp();
    
    public:
        void read();
        void write() const;
        void read_fb(FILE * & file);
        void write_fb(FILE * & file) const;
        int size() const;
        void clear();
        
    public:
        bool operator == (const DTfloathp & dt) const;
        bool operator != (const DTfloathp & dt) const;
        bool operator < (const DTfloathp & dt) const;
        bool operator <= (const DTfloathp & dt) const;
        bool operator > (const DTfloathp & dt) const;
        bool operator >= (const DTfloathp & dt) const;
    };
}

#endif // DATATYPEFLOAT_H_
