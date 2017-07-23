#include <cstdio>
#include <cstring>

#include "Const.h"
#include "DataTypeInt.h"

namespace GarbageMayor
{
    /*
    8位整数。
    */
    DTint8::DTint8() : value(0) { type = dt_int8; }
    DTint8::DTint8(char value_) : value(value_) { type = dt_int8; }
    DTint8::DTint8(const DTint8& dt) : value(dt.value) { type = dt_int8; }
    DTint8::~DTint8() {}
    
    void DTint8::read() 
    {
        int tmp;
        scanf("%d", &tmp);
        value = tmp;
    }
    void DTint8::write()
    {
        printf("%d", (int)value);
    }
    int DTint8::get_size() const
    {
        return 1;
    }
    
    
    /*
    16位整数。
    */
    DTint16::DTint16() : value(0) { type = dt_int16; }
    DTint16::DTint16(short value_) : value(value_) { type = dt_int16; }
    DTint16::DTint16(const DTint16& dt) : value(dt.value) { type = dt_int16; }
    DTint16::~DTint16() {}
    
    void DTint16::read() 
    {
        int tmp;
        scanf("%d", &tmp);
        value = tmp;
    }
    void DTint16::write()
    {
        printf("%d", (int)value);
    }
    int DTint16::get_size() const
    {
        return 2;
    }
    
    /*
    32位整数。
    */
    DTint32::DTint32() : value(0) { type = dt_int32; }
    DTint32::DTint32(int value_) : value(value_) { type = dt_int32; }
    DTint32::DTint32(const DTint32& dt) : value(dt.value) { type = dt_int32; }
    DTint32::~DTint32() {}
    
    void DTint32::read() 
    {
        scanf("%d", &value);
    }
    void DTint32::write()
    {
        printf("%d", value);
    }
    int DTint32::get_size() const
    {
        return 4;
    }
    
    /*
    64位整数。
    */
    DTint64::DTint64() : value(0) { type = dt_int64; }
    DTint64::DTint64(long long value_) : value(value_) { type = dt_int64; }
    DTint64::DTint64(const DTint64& dt) : value(dt.value) { type = dt_int64; }
    DTint64::~DTint64() {}
    
    void DTint64::read() 
    {
#if defined(_WIN32) && !defined(_WIN64)
        scanf("%I64d", &value);
#else
        scanf("%lld", &value);
#endif
    }
    void DTint64::write()
    {
#if defined(_WIN32) && !defined(_WIN64)
        printf("%I64d", value);
#else
        printf("%lld", value);
#endif
    }
    int DTint64::get_size() const
    {
        return 8;
    }
    
    /*
    高精度整数。
    */
    DTinthp::DTinthp()
    {
        type = dt_inthp;
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
        flag = 0;
        dlen = 0;
        alen = 0;
        if(digit != NULL)
        {
            delete [] digit;
            digit = NULL;
        }
        
        static char buffer[DTinthp__max_dlen + 5];
        char * vs = buffer;
        scanf(DTinthp__scan_mode, vs);
        int dlen_ = DTinthp__max_dlen;
        if(vs[0] == '-')
            flag = -1, vs++, dlen_--;
        for(; vs[0] == '0'; vs++, dlen_--);
        if(vs[0] < '0' || vs[0] > '9')
            return;
            
        int i = 0;
        for(; i < dlen_ && '0' <= vs[i] && vs[i] <= '9'; i++);
        dlen = i;
        alen = (dlen + 7) >> 3;
        digit = new int [alen];
        memset(digit, 0, sizeof(int) * alen);
        for(i = 0; i < dlen; i++)
            digit[i >> 3] += (vs[dlen - 1 - i] - '0') * DTinthp__power_10[i & 7];
    }
    void DTinthp::write()
    {
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
    int DTinthp::get_size() const
    {
        return 8 + alen * 4;
    }
    
    bool DTinthp::operator == (const DTinthp & dt) const
    {
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
