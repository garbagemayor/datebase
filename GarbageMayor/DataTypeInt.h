#ifndef DATATYPEINT_H_
#define DATATYPEINT_H_

#include "DataTypeBase.h"

/*
各种整数。
*/
namespace GarbageMayor
{
    /*
    8位整数。
    */
    class DTint8
        : public DTbase
    {
    private:
        char value;
        
    public:
        DTint8();
        DTint8(char value_);
        DTint8(const DTint8 & dt);
        ~DTint8();
    
    public:
        void read();
        void write() const;
        void read_fb(FILE * & file);
        void write_fb(FILE * & file) const;
        int size() const;
        void clear();
        
    public:
        char get_value() const;
        void set_value(char value_);
        
    public:
        bool operator == (const DTint8 & dt) const;
        bool operator != (const DTint8 & dt) const;
        bool operator < (const DTint8 & dt) const;
        bool operator <= (const DTint8 & dt) const;
        bool operator > (const DTint8 & dt) const;
        bool operator >= (const DTint8 & dt) const;
    };
    
    /*
    16位整数。
    */
    class DTint16
        : public DTbase
    {
    private:
        short value;
        
    public:
        DTint16();
        DTint16(short value_);
        DTint16(const DTint16 & dt);
        ~DTint16();
    
    public:
        void read();
        void write() const;
        void read_fb(FILE * & file);
        void write_fb(FILE * & file) const;
        int size() const;
        void clear();
        
    public:
        short get_value() const;
        void set_value(short value_);
        
    public:
        bool operator == (const DTint16 & dt) const;
        bool operator != (const DTint16 & dt) const;
        bool operator < (const DTint16 & dt) const;
        bool operator <= (const DTint16 & dt) const;
        bool operator > (const DTint16 & dt) const;
        bool operator >= (const DTint16 & dt) const;
    };
    
    /*
    32位整数。
    */
    class DTint32
        : public DTbase
    {
    private:
        int value;
        
    public:
        DTint32();
        DTint32(int value_);
        DTint32(const DTint32 & dt);
        ~DTint32();
    
    public:
        void read();
        void write() const;
        void read_fb(FILE * & file);
        void write_fb(FILE * & file) const;
        int size() const;
        void clear();
        
    public:
        int get_value() const;
        void set_value(int value_);
        
    public:
        bool operator == (const DTint32 & dt) const;
        bool operator != (const DTint32 & dt) const;
        bool operator < (const DTint32 & dt) const;
        bool operator <= (const DTint32 & dt) const;
        bool operator > (const DTint32 & dt) const;
        bool operator >= (const DTint32 & dt) const;
    };
    
    /*
    64位整数。
    */
    class DTint64
        : public DTbase
    {
    private:
        long long value;
        
    public:
        DTint64();
        DTint64(long long value_);
        DTint64(const DTint64 & dt);
        ~DTint64();
    
    public:
        void read();
        void write() const;
        void read_fb(FILE * & file);
        void write_fb(FILE * & file) const;
        int size() const;
        void clear();
        
    public:
        long long get_value() const;
        void set_value(long long value_);
        
    public:
        bool operator == (const DTint64 & dt) const;
        bool operator != (const DTint64 & dt) const;
        bool operator < (const DTint64 & dt) const;
        bool operator <= (const DTint64 & dt) const;
        bool operator > (const DTint64 & dt) const;
        bool operator >= (const DTint64 & dt) const;
    };
    
    /*
    高精度整数。
    每8位压缩在一个int里面。
    最多256*8=2048位。
    */
    class DTinthp
        : public DTbase
    {
    private:
        int flag;       //符号位，+1,-1,0
        int dlen;       //十进制位的个数
        int alen;       //数组的范围
        int * digit;    //每8个十进制位
        
    public:
        DTinthp();
        DTinthp(const char * vs, int dlen_ = -1);
        DTinthp(const DTinthp & dt);
        ~DTinthp();
    
    public:
        void read();
        void write() const;
        void read_fb(FILE * & file);
        void write_fb(FILE * & file) const;
        int size() const;
        void clear();
        
    public:
        bool operator == (const DTinthp & dt) const;
        bool operator != (const DTinthp & dt) const;
        bool operator < (const DTinthp & dt) const;
        bool operator <= (const DTinthp & dt) const;
        bool operator > (const DTinthp & dt) const;
        bool operator >= (const DTinthp & dt) const;
    };
}

#endif // DATATYPEINT_H_
