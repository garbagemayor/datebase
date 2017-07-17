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
        DTint8(const DTint8& dt);
        ~DTint8();
    
    public:
        void read();
        void write();
        int get_size() const;
        
    public:
        inline char get_value() { return value; }
        inline void set_value(char value_) { value = value_; }
        
    public:
        inline bool operator == (const DTint8 & dt) const { return value == dt.value; }
        inline bool operator != (const DTint8 & dt) const { return value != dt.value; }
        inline bool operator < (const DTint8 & dt) const { return value < dt.value; }
        inline bool operator <= (const DTint8 & dt) const { return value <= dt.value; }
        inline bool operator > (const DTint8 & dt) const { return value > dt.value; }
        inline bool operator >= (const DTint8 & dt) const { return value >= dt.value; }
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
        void write();
        int get_size() const;
        
    public:
        inline short get_value() { return value; }
        inline void set_value(short value_) { value = value_; }
        
    public:
        inline bool operator == (const DTint16 & dt) const { return value == dt.value; }
        inline bool operator != (const DTint16 & dt) const { return value != dt.value; }
        inline bool operator < (const DTint16 & dt) const { return value < dt.value; }
        inline bool operator <= (const DTint16 & dt) const { return value <= dt.value; }
        inline bool operator > (const DTint16 & dt) const { return value > dt.value; }
        inline bool operator >= (const DTint16 & dt) const { return value >= dt.value; }
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
        void write();
        int get_size() const;
        
    public:
        inline int get_value() { return value; }
        inline void set_value(int value_) { value = value_; }
        
    public:
        inline bool operator == (const DTint32 & dt) const { return value == dt.value; }
        inline bool operator != (const DTint32 & dt) const { return value != dt.value; }
        inline bool operator < (const DTint32 & dt) const { return value < dt.value; }
        inline bool operator <= (const DTint32 & dt) const { return value <= dt.value; }
        inline bool operator > (const DTint32 & dt) const { return value > dt.value; }
        inline bool operator >= (const DTint32 & dt) const { return value >= dt.value; }
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
        void write();
        int get_size() const;
        
    public:
        inline long long get_value() { return value; }
        inline void set_value(long long value_) { value = value_; }
        
    public:
        inline bool operator == (const DTint64 & dt) const { return value == dt.value; }
        inline bool operator != (const DTint64 & dt) const { return value != dt.value; }
        inline bool operator < (const DTint64 & dt) const { return value < dt.value; }
        inline bool operator <= (const DTint64 & dt) const { return value <= dt.value; }
        inline bool operator > (const DTint64 & dt) const { return value > dt.value; }
        inline bool operator >= (const DTint64 & dt) const { return value >= dt.value; }
    };
    
    /*
    高精度整数。
    每8位压缩在一个int里面。
    最多256*8=2048位。
    */
    class DTintbig
        : public DTbase
    {
    private:
        int flag;       //符号位，+1,-1,0
        int dlen;       //十进制位的个数
        int alen;       //数组的范围
        int * digit;    //每8个十进制位
        
    public:
        DTintbig();
        DTintbig(const char * vs);
        DTintbig(const DTintbig & dt);
        ~DTintbig();
    
    public:
        void read();
        void write();
        int get_size() const;
        
    public:
        bool operator == (const DTintbig & dt) const;
        bool operator != (const DTintbig & dt) const;
        bool operator < (const DTintbig & dt) const;
        bool operator <= (const DTintbig & dt) const;
        bool operator > (const DTintbig & dt) const;
        bool operator >= (const DTintbig & dt) const;
    };
}

#endif // DATATYPEINT_H_
