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
    DTintbig::DTintbig()
    {
        type = dt_intbig;
        flag = 0;
        dlen = 0;
        alen = 0;
        digit = NULL;
    }
    DTintbig::DTintbig(const char * vs)
    {
        type = dt_intbig;
        flag = 0;
        dlen = 0;
        alen = 0;
        digit = NULL;
        
        if(vs[0] == '-')
            flag = -1, vs++;
        for(; vs[0] == '0'; vs++);
        if(vs[0] < '0' || vs[0] > '9')
            return;
        
        int i = 0;
        for(; i < DTintbig__max_dlen && '0' <= vs[i] && vs[i] <= '9'; i++);
        dlen = i;
        alen = (dlen + 7) >> 3;
        digit = new int [alen];
        memset(digit, 0, sizeof(int) * alen);
        for(i = 0; i < dlen; i++)
            digit[i >> 3] += (vs[dlen - 1 - i] - '0') * DTintbig__power_10[i & 7];
    }
    DTintbig::DTintbig(const DTintbig & dt)
    {
        type = dt_intbig;
        flag = dt.flag;
        dlen = dt.dlen;
        alen = dt.alen;
        digit = new int [alen];
        for(int i = 0; i < alen; i++)
            digit[i] = dt.digit[i];
    }
    DTintbig::~DTintbig()
    {
        if(digit != NULL)
        {
            delete [] digit;
            digit = NULL;
        }
    }
    
    void DTintbig::read()
    {
        flag = 0;
        dlen = 0;
        alen = 0;
        if(digit != NULL)
        {
            delete [] digit;
            digit = NULL;
        }
        
        static char buff[DTintbig__max_dlen + 5];
        char * vs = buff;
        scanf("%s", vs);
        if(vs[0] == '-')
            flag = -1, vs++;
        for(; vs[0] == '0'; vs++);
        if(vs[0] < '0' || vs[0] > '9')
            return;
            
        int i = 0;
        for(; i < DTintbig__max_dlen && '0' <= vs[i] && vs[i] <= '9'; i++);
        dlen = i;
        alen = (dlen + 7) >> 3;
        digit = new int [alen];
        memset(digit, 0, sizeof(int) * alen);
        for(i = 0; i < dlen; i++)
            digit[i >> 3] += (vs[dlen - 1 - i] - '0') * DTintbig__power_10[i & 7];
    }
    void DTintbig::write()
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
    int DTintbig::get_size() const
    {
        return 8 + alen * 4;
    }
    
    bool DTintbig::operator == (const DTintbig & dt) const
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
    bool DTintbig::operator != (const DTintbig & dt) const
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
    bool DTintbig::operator < (const DTintbig & dt) const
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
    bool DTintbig::operator <= (const DTintbig & dt) const
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
    bool DTintbig::operator > (const DTintbig & dt) const
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
    bool DTintbig::operator >= (const DTintbig & dt) const
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
