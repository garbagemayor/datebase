#ifndef DATATYPEBINARY_H_
#define DATATYPEBINARY_H_

#include "DataTypeBase.h"

/*
各种二进制串。
*/
namespace GarbageMayor
{
    /*
    短二进制串。
    长度不超过255字节。
    如果从stdin读取，则和文本一样读到\0就结束。
    */
    class DTbinary2f
        : public DTbase
    {
    public:
        int length;
        unsigned char * data;
        
        DTbinary2f();
        DTbinary2f(const unsigned char * data_, int length_);
        DTbinary2f(const DTbinary2f & dt);
        ~DTbinary2f();
        
    public:
        void read();
        void write();
        int get_size() const;
        
    public:
        inline int get_length() const { return length; }
        inline unsigned char * get_data_pointer() const { return data; }
        
    public:
        bool operator == (const DTbinary2f & dt) const;
        bool operator != (const DTbinary2f & dt) const;
        bool operator < (const DTbinary2f & dt) const;
        bool operator <= (const DTbinary2f & dt) const;
        bool operator > (const DTbinary2f & dt) const;
        bool operator >= (const DTbinary2f & dt) const;
    };
    
    /*
    中二进制串。
    长度不超过65535字节。
    如果从stdin读取，则和文本一样读到\0就结束。
    */
    class DTbinary4f
        : public DTbase
    {
    public:
        int length;
        unsigned char * data;
        
        DTbinary4f();
        DTbinary4f(const unsigned char * data_, int length_);
        DTbinary4f(const DTbinary4f & dt);
        ~DTbinary4f();
        
    public:
        void read();
        void write();
        int get_size() const;
        
    public:
        inline int get_length() const { return length; }
        inline unsigned char * get_data_pointer() const { return data; }
        
    public:
        bool operator == (const DTbinary4f & dt) const;
        bool operator != (const DTbinary4f & dt) const;
        bool operator < (const DTbinary4f & dt) const;
        bool operator <= (const DTbinary4f & dt) const;
        bool operator > (const DTbinary4f & dt) const;
        bool operator >= (const DTbinary4f & dt) const;
    };
    
    /*
    长二进制串。
    长度不超过1073741823字节。
    如果从stdin读取，则和文本一样读到\0就结束，长度不能超过1048575字节。
    */
    class DTbinary8f
        : public DTbase
    {
    public:
        int length;
        unsigned char * data;
        
        DTbinary8f();
        DTbinary8f(const unsigned char * data_, int length_);
        DTbinary8f(const DTbinary8f & dt);
        ~DTbinary8f();
        
    public:
        void read();
        void write();
        int get_size() const;
        
    public:
        inline int get_length() const { return length; }
        inline unsigned char * get_data_pointer() const { return data; }
        
    public:
        bool operator == (const DTbinary8f & dt) const;
        bool operator != (const DTbinary8f & dt) const;
        bool operator < (const DTbinary8f & dt) const;
        bool operator <= (const DTbinary8f & dt) const;
        bool operator > (const DTbinary8f & dt) const;
        bool operator >= (const DTbinary8f & dt) const;
    };
}

#endif // DATATYPEBINARY_H_
