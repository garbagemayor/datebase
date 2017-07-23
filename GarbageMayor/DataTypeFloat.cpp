#include <cstdio>
#include <cstring>

#include "Const.h"
#include "DataTypeFloat.h"

namespace GarbageMayor
{
    /*
    32位浮点数。
    */
    DTfloat32::DTfloat32() : value(0) { type = dt_float32; }
    DTfloat32::DTfloat32(float value_) : value(value_) { type = dt_float32; }
    DTfloat32::DTfloat32(const DTfloat32 & dt) : value(dt.value) { type = dt_float32; }
    DTfloat32::~DTfloat32() {}
    
    void DTfloat32::read()
    {
        scanf("%f", &value);
    }
    void DTfloat32::write()
    {
        printf("%f", value);
    }
    int DTfloat32::get_size() const
    {
        return 4; 
    }
    
    /*
    64位浮点数。
    */
    DTfloat64::DTfloat64() : value(0) { type = dt_float64; }
    DTfloat64::DTfloat64(double value_) : value(value_) { type = dt_float64; }
    DTfloat64::DTfloat64(const DTfloat64 & dt) : value(dt.value) { type = dt_float64; }
    DTfloat64::~DTfloat64() {}
    
    void DTfloat64::read()
    {
        scanf("%lf", &value);
    }
    void DTfloat64::write()
    {
        printf("%lf", value);
    }
    int DTfloat64::get_size() const
    {
        return 8; 
    }
    
    /*
    高精度浮点数
    */
    DTfloathp::DTfloathp()
    {
        type = dt_floathp;
        flag = 0;
        dlen = 0;
        plen = 0;
        alen = 0;
        blen = 0;
        digit = NULL;
    }
    DTfloathp::DTfloathp(const char * vs, int slen_)
    {
        type = dt_floathp;
        flag = 0;
        dlen = 0;
        plen = 0;
        alen = 0;
        blen = 0;
        digit = NULL;
        
        if(slen_ == -1)
            slen_ = max_int;
        if(vs[0] == '-')
            flag = -1, vs++, slen_--;
        for(; vs[0] == '0'; vs++, slen_--);
        if((vs[0] < '0' || vs[0] > '9') && vs[0] != '.')
        {
            flag = 0;
            return;
        }
        if(slen_ > DTfloathp__max_slen)
            slen_ = DTfloathp__max_slen;
        
        int i = 0;
        for(; i < slen_ && '0' <= vs[i] && vs[i] <= '9'; i++);
        if(vs[i] != '.')
        {
            dlen = i;
            plen = 0;
            alen = (dlen + 7) >> 3;
            blen = (plen + 7) >> 3;
            digit = new int [alen + blen];
            memset(digit, 0, sizeof(int) * (alen + blen));
            for(i = 0; i < dlen; i++)
                digit[blen + (i >> 3)] += (vs[dlen - 1 - i] - '0') * DTintbig__power_10[i & 7];
        }
        else
        {
            int j = 0;
            for(; i + 1 + j < slen_ && '0' <= vs[i + 1 + j] && vs[i + 1 + j] <= '9'; j++);
            for(; j > 0 && vs[i + j] == '0'; j--);
            if(i == 0 && j == 0)
            {
                flag = 0;
                return;
            }
            dlen = i;
            plen = j;
            alen = (dlen + 7) >> 3;
            blen = (plen + 7) >> 3;
            digit = new int [alen + blen];
            memset(digit, 0, sizeof(int) * (alen + blen));
            for(j = 0; j < plen; j++)
                digit[blen - 1 - (j >> 3)] += (vs[dlen + 1 + j] - '0') * DTintbig__power_10[~j & 7];
            for(j = 0; j < dlen; j++)
                digit[blen + (j >> 3)] += (vs[dlen - 1 - j] - '0') * DTintbig__power_10[j & 7];
        }
    }
    DTfloathp::DTfloathp(const DTfloathp & dt)
    {
        type = dt_floathp;
        flag = dt.flag;
        dlen = dt.dlen;
        plen = dt.plen;
        alen = dt.alen;
        blen = dt.blen;
        digit = new int [alen + blen];
        memset(digit, 0, sizeof(int) * (alen + blen));
        for(int i = 0; i < alen + blen; i++)
            digit[i] = dt.digit[i];
    }
    DTfloathp::~DTfloathp()
    {
        if(digit != NULL)
        {
            delete [] digit;
            digit = NULL;
        }
    }
    
    void DTfloathp::read()
    {
        type = dt_floathp;
        flag = 0;
        dlen = 0;
        plen = 0;
        alen = 0;
        blen = 0;
        digit = NULL;
        
        static char buffer[DTfloathp__max_slen + 5];
        char * vs = buffer;
        scanf(DTfloathp__scan_mode, vs);
        int slen_ = DTfloathp__max_slen;
        if(vs[0] == '-')
            flag = -1, vs++, slen_--;
        for(; vs[0] == '0'; vs++, slen_--);
        if((vs[0] < '0' || vs[0] > '9') && vs[0] != '.')
        {
            flag = 0;
            return;
        }
        
        int i = 0;
        for(; i < slen_ && '0' <= vs[i] && vs[i] <= '9'; i++);
        if(vs[i] != '.')
        {
            dlen = i;
            plen = 0;
            alen = (dlen + 7) >> 3;
            blen = (plen + 7) >> 3;
            digit = new int [alen + blen];
            memset(digit, 0, sizeof(int) * (alen + blen));
            for(i = 0; i < dlen; i++)
                digit[blen + (i >> 3)] += (vs[dlen - 1 - i] - '0') * DTintbig__power_10[i & 7];
        }
        else
        {
            int j = 0;
            for(; i + 1 + j < slen_ && '0' <= vs[i + 1 + j] && vs[i + 1 + j] <= '9'; j++);
            for(; j > 0 && vs[i + j] == '0'; j--);
            if(i == 0 && j == 0)
            {
                flag = 0;
                return;
            }
            dlen = i;
            plen = j;
            alen = (dlen + 7) >> 3;
            blen = (plen + 7) >> 3;
            digit = new int [alen + blen];
            memset(digit, 0, sizeof(int) * (alen + blen));
            for(j = 0; j < plen; j++)
                digit[blen - 1 - (j >> 3)] += (vs[dlen + 1 + j] - '0') * DTintbig__power_10[~j & 7];
            for(j = 0; j < dlen; j++)
                digit[blen + (j >> 3)] += (vs[dlen - 1 - j] - '0') * DTintbig__power_10[j & 7];
        }
    }
    void DTfloathp::write()
    {
        if(flag == -1)
            printf("-");
        else if(flag == 0)
        {
            printf("0");
            return;
        }
        if(alen == 0)
            printf("0");
        int i = 0;
        for(i = alen + blen - 1; i >= blen; i--)
            printf("%d", digit[i]);
        printf(".");
        for(i = blen - 1; i > 0; i--)
            printf("%d", digit[i]);
        for(i = digit[0]; i % 10 == 0; i /= 10);
        printf("%d", i);
    }
    int DTfloathp::get_size() const
    {
        return 12 + (alen + blen) * 4;
    }
    
    bool DTfloathp::operator == (const DTfloathp & dt) const
    {
        if(flag != dt.flag)
            return false;
        if(dlen != dt.dlen)
            return false;
        if(plen != dt.plen)
            return false;
        for(int i = alen + blen - 1; i >= 0; i--)
            if(digit[i] != dt.digit[i])
                return false;
        return true;
    }
    bool DTfloathp::operator != (const DTfloathp & dt) const
    {
        if(flag != dt.flag)
            return true;
        if(dlen != dt.dlen)
            return true;
        if(plen != dt.plen)
            return true;
        for(int i = alen + blen - 1; i >= 0; i--)
            if(digit[i] != dt.digit[i])
                return true;
        return false;
    }
    bool DTfloathp::operator < (const DTfloathp & dt) const
    {
        if(flag != dt.flag)
            return flag < dt.flag;
        if(dlen != dt.dlen)
            return dlen < dt.dlen;
        int i = alen + blen - 1;
        int j = dt.alen + dt.blen - 1;
        for(; i >= 0 && j >= 0; i--, j--)
            if(digit[i] != dt.digit[j])
                return digit[i] < dt.digit[j];
        return j >= 0;
    }
    bool DTfloathp::operator <= (const DTfloathp & dt) const
    {
        if(flag != dt.flag)
            return flag < dt.flag;
        if(dlen != dt.dlen)
            return dlen < dt.dlen;
        int i = alen + blen - 1;
        int j = dt.alen + dt.blen - 1;
        for(; i >= 0 && j >= 0; i--, j--)
            if(digit[i] != dt.digit[j])
                return digit[i] < dt.digit[j];
        return i < 0;
    }
    bool DTfloathp::operator > (const DTfloathp & dt) const
    {
        if(flag != dt.flag)
            return flag > dt.flag;
        if(dlen != dt.dlen)
            return dlen > dt.dlen;
        int i = alen + blen - 1;
        int j = dt.alen + dt.blen - 1;
        for(; i >= 0 && j >= 0; i--, j--)
            if(digit[i] != dt.digit[j])
                return digit[i] > dt.digit[j];
        return i >= 0;
    }
    bool DTfloathp::operator >= (const DTfloathp & dt) const
    {
        if(flag != dt.flag)
            return flag > dt.flag;
        if(dlen != dt.dlen)
            return dlen > dt.dlen;
        int i = alen + blen - 1;
        int j = dt.alen + dt.blen - 1;
        for(; i >= 0 && j >= 0; i--, j--)
            if(digit[i] != dt.digit[j])
                return digit[i] > dt.digit[j];
        return j < 0;
    }
}
