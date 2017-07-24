#ifndef DATATIMETEXT_H_
#define DATATIMETEXT_H_

#include "DataTypeBase.h"

/*
各种文本。
*/
namespace GarbageMayor
{
    /*
    短文本。
    长度不超过255字节。
    */
    class DTtext2f
        : public DTbase
    {
    public:
        int length;
        char * text;
        
        DTtext2f();
        DTtext2f(const char * text_, int length_ = -1);
        DTtext2f(const DTtext2f & dt);
        ~DTtext2f();
        
    public:
        void read();
        void write();
        int get_size() const;
        
    public:
        inline int get_length() const { return length; }
        inline char * get_c_str() const { return text; }
        
    public:
        bool operator == (const DTtext2f & dt) const;
        bool operator != (const DTtext2f & dt) const;
        bool operator < (const DTtext2f & dt) const;
        bool operator <= (const DTtext2f & dt) const;
        bool operator > (const DTtext2f & dt) const;
        bool operator >= (const DTtext2f & dt) const;
    };
    
    /*
    中文本。
    长度不超过65535字节。
    */
    class DTtext4f
        : public DTbase
    {
    public:
        int length;
        char * text;
        
        DTtext4f();
        DTtext4f(const char * text_, int length_ = -1);
        DTtext4f(const DTtext4f & dt);
        ~DTtext4f();
        
    public:
        void read();
        void write();
        int get_size() const;
        
    public:
        inline int get_length() const { return length; }
        inline char * get_c_str() const { return text; }
        
    public:
        bool operator == (const DTtext4f & dt) const;
        bool operator != (const DTtext4f & dt) const;
        bool operator < (const DTtext4f & dt) const;
        bool operator <= (const DTtext4f & dt) const;
        bool operator > (const DTtext4f & dt) const;
        bool operator >= (const DTtext4f & dt) const;
    };
    
    /*
    长文本。
    长度不超过1073741823字节。
    如果从stdin读取，长度不能超过1048575字节。
    */
    class DTtext8f
        : public DTbase
    {
    public:
        int length;
        char * text;
        
        DTtext8f();
        DTtext8f(const char * text_, int length_ = -1);
        DTtext8f(const DTtext8f & dt);
        ~DTtext8f();
        
    public:
        void read();
        void write();
        int get_size() const;
        
    public:
        inline int get_length() const { return length; }
        inline char * get_c_str() const { return text; }
        
    public:
        bool operator == (const DTtext8f & dt) const;
        bool operator != (const DTtext8f & dt) const;
        bool operator < (const DTtext8f & dt) const;
        bool operator <= (const DTtext8f & dt) const;
        bool operator > (const DTtext8f & dt) const;
        bool operator >= (const DTtext8f & dt) const;
    };
}

#endif // DATATIMETEXT_H_
