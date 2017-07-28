#include <cstdio>
#include <cstring>
#include <assert.h>

#include "Const.h"
#include "DataTypeInt.h"

namespace GarbageMayor
{
    /*
    8位整数。
    */
    DTint8::DTint8()
        : value(0)
    {
        type = dt_null;
    }
    DTint8::DTint8(char value_)
        : value(value_)
    {
        type = dt_int8;
    }
    DTint8::DTint8(const DTint8 & dt)
        : value(dt.value)
    {
        type = dt_int8;
    }
    DTint8::~DTint8() {}
    
    void DTint8::read() 
    {
        type = dt_int8;
        
        int tmp;
        scanf("%d", &tmp);
        value = tmp;
    }
    void DTint8::write() const
    {
        if(type == dt_null)
        {
            printf("NULL");
            return;
        }
        printf("%d", (int)value);
    }
    void DTint8::read_fb(FILE * & file)
    {
        fread(&type, 1, 1, file);
        fread(&value, 1, 1, file);
        assert(type == dt_int8 || type == dt_null);
        if(type == dt_null)
            value = 0;
    }
    void DTint8::write_fb(FILE * & file) const
    {
        fwrite(&type, 1, 1, file);
        fwrite(&value, 1, 1, file);
    }
    int DTint8::size() const
    {
        return 1 + 1;
    }
    void DTint8::clear()
    {
        type = dt_null;
        value = 0;
    }
    
    char DTint8::get_value() const
    {
        assert(type == dt_int8);
        return value;
    }
    void DTint8::set_value(char value_)
    {
        type = dt_int8;
        value = value_;
    }
    
    bool DTint8::operator == (const DTint8 & dt) const 
    {
        if(type != dt.type)
            return false;
        return value == dt.value; 
    }
    bool DTint8::operator != (const DTint8 & dt) const 
    {
        if(type != dt.type)
            return true;
        return value != dt.value; 
    }
    bool DTint8::operator < (const DTint8 & dt) const 
    {
        if(type != dt.type)
            return type < dt.type;
        return value < dt.value; 
    }
    bool DTint8::operator <= (const DTint8 & dt) const 
    {
        if(type != dt.type)
            return type < dt.type;
        return value <= dt.value; 
    }
    bool DTint8::operator > (const DTint8 & dt) const 
    {
        if(type != dt.type)
            return type > dt.type;
        return value > dt.value; 
    }
    bool DTint8::operator >= (const DTint8 & dt) const 
    {
        if(type != dt.type)
            return type > dt.type;
        return value >= dt.value; 
    }
    
    
    /*
    16位整数。
    */
    DTint16::DTint16()
        : value(0)
    {
        type = dt_null;
    }
    DTint16::DTint16(short value_)
        : value(value_)
    {
        type = dt_int16;
    }
    DTint16::DTint16(const DTint16 & dt)
        : value(dt.value)
    {
        type = dt_int16;
    }
    DTint16::~DTint16() {}
    
    void DTint16::read() 
    {
        type = dt_int16;
        
        int tmp;
        scanf("%d", &tmp);
        value = tmp;
    }
    void DTint16::write() const
    {
        if(type == dt_null)
        {
            printf("NULL");
            return;
        }
        printf("%d", (int)value);
    }
    void DTint16::read_fb(FILE * & file)
    {
        fread(&type, 1, 1, file);
        fread(&value, 2, 1, file);
        assert(type == dt_int16 || type == dt_null);
        if(type == dt_null)
            value = 0;
    }
    void DTint16::write_fb(FILE * & file) const
    {
        fwrite(&type, 1, 1, file);
        fwrite(&value, 2, 1, file);
    }
    int DTint16::size() const
    {
        return 1 + 2;
    }
    void DTint16::clear()
    {
        type = dt_null;
        value = 0;
    }
    
    short DTint16::get_value() const
    {
        assert(type == dt_int16);
        return value;
    }
    void DTint16::set_value(short value_)
    {
        type = dt_int16;
        value = value_;
    }
    
    bool DTint16::operator == (const DTint16 & dt) const 
    {
        if(type != dt.type)
            return false;
        return value == dt.value;
    }
    bool DTint16::operator != (const DTint16 & dt) const 
    {
        if(type != dt.type)
            return true;
        return value != dt.value;
    }
    bool DTint16::operator < (const DTint16 & dt) const 
    {
        if(type != dt.type)
            return type < dt.type;
        return value < dt.value;
    }
    bool DTint16::operator <= (const DTint16 & dt) const 
    {
        if(type != dt.type)
            return type < dt.type;
        return value <= dt.value;
    }
    bool DTint16::operator > (const DTint16 & dt) const 
    {
        if(type != dt.type)
            return type > dt.type;
        return value > dt.value;
    }
    bool DTint16::operator >= (const DTint16 & dt) const 
    {
        if(type != dt.type)
            return type > dt.type;
        return value >= dt.value;
    }
    
    /*
    32位整数。
    */
    DTint32::DTint32()
        : value(0)
    {
        type = dt_null;
    }
    DTint32::DTint32(int value_)
        : value(value_)
    {
        type = dt_int32;
    }
    DTint32::DTint32(const DTint32& dt)
        : value(dt.value)
    {
        type = dt_int32;
    }
    DTint32::~DTint32() {}
    
    void DTint32::read() 
    {
        type = dt_int32;
        
        scanf("%d", &value);
    }
    void DTint32::write() const
    {
        if(type == dt_null)
        {
            printf("NULL");
            return;
        }
        printf("%d", value);
    }
    void DTint32::read_fb(FILE * & file)
    {
        fread(&type, 1, 1, file);
        fread(&value, 4, 1, file);
        assert(type == dt_int32 || type == dt_null);
        if(type == dt_null)
            value = 0;
    }
    void DTint32::write_fb(FILE * & file) const
    {
        fwrite(&type, 1, 1, file);
        fwrite(&value, 4, 1, file);
    }
    int DTint32::size() const
    {
        return 1 + 4;
    }
    void DTint32::clear()
    {
        type = dt_null;
        value = 0;
    }
    
    int DTint32::get_value() const
    {
        assert(type == dt_int32);
        return value;
    }
    void DTint32::set_value(int value_)
    {
        type = dt_int32;
        value = value_;
    }
    
    bool DTint32::operator == (const DTint32 & dt) const 
    {
        if(type != dt.type)
            return false;
        return value == dt.value;
    }
    bool DTint32::operator != (const DTint32 & dt) const 
    {
        if(type != dt.type)
            return true;
        return value != dt.value;
    }
    bool DTint32::operator < (const DTint32 & dt) const 
    {
        if(type != dt.type)
            return type < dt.type;
        return value < dt.value;
    }
    bool DTint32::operator <= (const DTint32 & dt) const 
    {
        if(type != dt.type)
            return type < dt.type;
        return value <= dt.value;
    }
    bool DTint32::operator > (const DTint32 & dt) const 
    {
        if(type != dt.type)
            return type > dt.type;
        return value > dt.value;
    }
    bool DTint32::operator >= (const DTint32 & dt) const 
    {
        if(type != dt.type)
            return type > dt.type;
        return value >= dt.value;
    }
    
    /*
    64位整数。
    */
    DTint64::DTint64()
        : value(0)
    {
        type = dt_null;
    }
    DTint64::DTint64(long long value_)
        : value(value_)
    {
        type = dt_int64;
    }
    DTint64::DTint64(const DTint64& dt)
        : value(dt.value)
    {
        type = dt_int64;
    }
    DTint64::~DTint64() {}
    
    void DTint64::read() 
    {
        type = dt_int64;
        
#if defined(_WIN32) && !defined(_WIN64)
        scanf("%I64d", &value);
#else
        scanf("%lld", &value);
#endif
    }
    void DTint64::write() const
    {
        if(type == dt_null)
        {
            printf("NULL");
            return;
        }
#if defined(_WIN32) && !defined(_WIN64)
        printf("%I64d", value);
#else
        printf("%lld", value);
#endif
    }
    void DTint64::read_fb(FILE * & file)
    {
        fread(&type, 1, 1, file);
        fread(&value, 8, 1, file);
        assert(type == dt_int64 || type == dt_null);
        if(type == dt_null)
            value = 0;
    }
    void DTint64::write_fb(FILE * & file) const
    {
        fwrite(&type, 1, 1, file);
        fwrite(&value, 8, 1, file);
    }
    int DTint64::size() const
    {
        return 1 + 8;
    }
    void DTint64::clear()
    {
        type = dt_null;
        value = 0;
    }
    
    long long DTint64::get_value() const
    {
        assert(type == dt_int64);
        return value;
    }
    void DTint64::set_value(long long value_)
    {
        type = dt_int64;
        value = value_;
    }
    
    bool DTint64::operator == (const DTint64 & dt) const 
    {
        if(type != dt.type)
            return false;
        return value == dt.value;
    }
    bool DTint64::operator != (const DTint64 & dt) const 
    {
        if(type != dt.type)
            return true;
        return value != dt.value;
    }
    bool DTint64::operator < (const DTint64 & dt) const 
    {
        if(type != dt.type)
            return type < dt.type;
        return value < dt.value;
    }
    bool DTint64::operator <= (const DTint64 & dt) const 
    {
        if(type != dt.type)
            return type < dt.type;
        return value <= dt.value;
    }
    bool DTint64::operator > (const DTint64 & dt) const 
    {
        if(type != dt.type)
            return type > dt.type;
        return value > dt.value;
    }
    bool DTint64::operator >= (const DTint64 & dt) const 
    {
        if(type != dt.type)
            return type > dt.type;
        return value >= dt.value;
    }
    
    /*
    高精度整数。
    */
    DTinthp::DTinthp()
    {
        type = dt_null;
        flag = 0;
        dlen = 0;
        alen = 0;
        digit = NULL;
    }
    DTinthp::DTinthp(const char * vs, int dlen_)
    {
        type = dt_inthp;
        flag = 0;
        dlen = 0;
        alen = 0;
        digit = NULL;
        
        if(dlen_ == -1)
            dlen_ = max_int;
        if(vs[0] == '-')
            flag = -1, vs++, dlen_--;
        for(; vs[0] == '0'; vs++, dlen_--);
        if(vs[0] < '0' || vs[0] > '9')
            return;
        if(dlen_ > DTinthp__max_dlen)
            dlen_ = DTinthp__max_dlen;
        
        int i = 0;
        for(; i < dlen_ && '0' <= vs[i] && vs[i] <= '9'; i++);
        dlen = i;
        alen = (dlen + 7) >> 3;
        digit = new int [alen];
        memset(digit, 0, sizeof(int) * alen);
        for(i = 0; i < dlen; i++)
            digit[i >> 3] += (vs[dlen - 1 - i] - '0') * DTinthp__power_10[i & 7];
    }
    DTinthp::DTinthp(const DTinthp & dt)
    {
        type = dt_inthp;
        flag = dt.flag;
        dlen = dt.dlen;
        alen = dt.alen;
        digit = new int [alen];
        for(int i = 0; i < alen; i++)
            digit[i] = dt.digit[i];
    }
    DTinthp::~DTinthp()
    {
        if(digit != NULL)
        {
            delete [] digit;
            digit = NULL;
        }
    }
    
    void DTinthp::read()
    {
        clear();
        type = dt_inthp;
        
        static char buffer[DTinthp__max_dlen + 5];
        char * vs = buffer;
        scanf(DTinthp__scan_mode, vs);
        int dlen_ = DTinthp__max_dlen;
        if(vs[0] == '-')
            flag = -1, vs++, dlen_--;
        for(; vs[0] == '0'; vs++, dlen_--);
        if(vs[0] < '0' || vs[0] > '9')
        {
            flag = 0;
            return;
        }
            
        int i = 0;
        for(; i < dlen_ && '0' <= vs[i] && vs[i] <= '9'; i++);
        dlen = i;
        alen = (dlen + 7) >> 3;
        digit = new int [alen];
        memset(digit, 0, sizeof(int) * alen);
        for(i = 0; i < dlen; i++)
            digit[i >> 3] += (vs[dlen - 1 - i] - '0') * DTinthp__power_10[i & 7];
    }
    void DTinthp::write() const
    {
        if(type == dt_null)
        {
            printf("NULL");
            return;
        }
        if(flag == -1)
            printf("-");
        else if(flag == 0)
        {
            printf("0");
            return;
        }
        printf("%d", digit[alen - 1]);
        for(int i = alen - 2; i >= 0; i--)
            printf("%08d", digit[i]);
    }
    void DTinthp::read_fb(FILE * & file)
    {
        clear();
        fread(&type, 1, 1, file);
        fread(&flag, 1, 1, file);
        flag -= 1;
        fread(&dlen, 2, 1, file);
        alen = (dlen + 7) >> 3;
        digit = new int [alen];
        if(type != dt_null)
        {
            memset(digit, 0, sizeof(int) * alen);
            fread(digit, 4, alen, file);
        }
        assert(type == dt_inthp || type == dt_null);
        if(type == dt_null)
            clear();
    }
    void DTinthp::write_fb(FILE * & file) const
    {
        fwrite(&type, 1, 1, file);
        int tmp = flag + 1;
        fwrite(&tmp, 1, 1, file);
        fwrite(&dlen, 2, 1, file);
        if(type != dt_null)
            fwrite(digit, 4, alen, file);
    }
    int DTinthp::size() const
    {
        return 1 + 1 + 2 + alen * 4;
    }
    void DTinthp::clear()
    {
        type = dt_null;
        flag = 0;
        dlen = 0;
        alen = 0;
        if(digit != NULL)
        {
            delete [] digit;
            digit = NULL;
        }
    }
    
    bool DTinthp::operator == (const DTinthp & dt) const
    {
        if(type != dt.type)
            return false;
        if(flag != dt.flag)
            return false;
        if(dlen != dt.dlen)
            return false;
        for(int i = alen - 1; i >= 0; i--)
            if(digit[i] != dt.digit[i])
                return false;
        return true;
    }
    bool DTinthp::operator != (const DTinthp & dt) const
    {
        if(type != dt.type)
            return true;
        if(flag != dt.flag)
            return true;
        if(dlen != dt.dlen)
            return true;
        for(int i = alen - 1; i >= 0; i--)
            if(digit[i] != dt.digit[i])
                return true;
        return false;
    }
    bool DTinthp::operator < (const DTinthp & dt) const
    {
        if(type != dt.type)
            return type < dt.type;
        if(flag != dt.flag)
            return flag < dt.flag;
        if(dlen != dt.dlen)
            return dlen < dt.dlen;
        for(int i = alen - 1; i >= 0; i--)
            if(digit[i] != dt.digit[i])
                return digit[i] < dt.digit[i];
        return false;
    }
    bool DTinthp::operator <= (const DTinthp & dt) const
    {
        if(type != dt.type)
            return type < dt.type;
        if(flag != dt.flag)
            return flag < dt.flag;
        if(dlen != dt.dlen)
            return dlen < dt.dlen;
        for(int i = alen - 1; i >= 0; i--)
            if(digit[i] != dt.digit[i])
                return digit[i] < dt.digit[i];
        return true;
    }
    bool DTinthp::operator > (const DTinthp & dt) const
    {
        if(type != dt.type)
            return type > dt.type;
        if(flag != dt.flag)
            return flag > dt.flag;
        if(dlen != dt.dlen)
            return dlen > dt.dlen;
        for(int i = alen - 1; i >= 0; i--)
            if(digit[i] != dt.digit[i])
                return digit[i] > dt.digit[i];
        return false;
    }
    bool DTinthp::operator >= (const DTinthp & dt) const
    {
        if(type != dt.type)
            return type > dt.type;
        if(flag != dt.flag)
            return flag > dt.flag;
        if(dlen != dt.dlen)
            return dlen > dt.dlen;
        for(int i = alen - 1; i >= 0; i--)
            if(digit[i] != dt.digit[i])
                return digit[i] > dt.digit[i];
        return true;
    }
}
