#include <cstdio>
#include <cstring>
#include "assert.h"

#include "Const.h"
#include "DataTypeFloat.h"

namespace GarbageMayor
{
    /*
    32位浮点数。
    */
    DTfloat32::DTfloat32()
        : value(0)
    {
        type = dt_null;
    }
    DTfloat32::DTfloat32(float value_)
        : value(value_)
    {
        type = dt_float32;
    }
    DTfloat32::DTfloat32(const DTfloat32 & dt)
        : value(dt.value)
    {
        type = dt_float32;
    }
    DTfloat32::~DTfloat32() {}
    
    void DTfloat32::read()
    {
        type = dt_float32;
        
        scanf("%f", &value);
    }
    void DTfloat32::write() const
    {
        if(type == dt_null)
        {
            printf("NULL");
            return;
        }
        printf("%f", value);
    }
    void DTfloat32::read_fb(FILE * & file)
    {
        fread(&type, 1, 1, file);
        fread(&value, 4, 1, file);
        assert(type == dt_float32 || type == dt_null);
        if(type == dt_null)
            value = 0;
    }
    void DTfloat32::write_fb(FILE * & file) const
    {
        fwrite(&type, 1, 1, file);
        fwrite(&value, 4, 1, file);
    }
    int DTfloat32::size() const
    {
        return 1 + 4; 
    }
    void DTfloat32::clear()
    {
        type = dt_null;
        value = 0;
    }
    
    float DTfloat32::get_value() const
    {
        assert(type == dt_float32);
        return value;
    }
    void DTfloat32::set_value(float value_)
    {
        type = dt_float32;
        value = value_;
    }
    
    bool DTfloat32::operator == (const DTfloat32 & dt) const 
    {
        if(type != dt.type)
            return false;
        return value > dt.value - DTfloat32__eps && value < dt.value + DTfloat32__eps;
    }
    bool DTfloat32::operator != (const DTfloat32 & dt) const 
    {
        if(type != dt.type)
            return true;
        return value <= dt.value - DTfloat32__eps || value >= dt.value + DTfloat32__eps;
    }
    bool DTfloat32::operator < (const DTfloat32 & dt) const 
    {
        if(type != dt.type)
            return type < dt.type;
        return value <= dt.value - DTfloat32__eps;
    }
    bool DTfloat32::operator <= (const DTfloat32 & dt) const 
    {
        if(type != dt.type)
            return type < dt.type;
        return value < dt.value + DTfloat32__eps;
    }
    bool DTfloat32::operator > (const DTfloat32 & dt) const 
    {
        if(type != dt.type)
            return type > dt.type;
        return value >= dt.value + DTfloat32__eps;
    }
    bool DTfloat32::operator >= (const DTfloat32 & dt) const 
    {
        if(type != dt.type)
            return type > dt.type;
        return value > dt.value - DTfloat32__eps;
    }
    
    /*
    64位浮点数。
    */
    DTfloat64::DTfloat64()
        : value(0)
    {
        type = dt_null;
    }
    DTfloat64::DTfloat64(double value_)
        : value(value_)
    {
        type = dt_float64;
    }
    DTfloat64::DTfloat64(const DTfloat64 & dt)
        : value(dt.value)
    {
        type = dt_float64;
    }
    DTfloat64::~DTfloat64() {}
    
    void DTfloat64::read()
    {
        type = dt_float64;
        
        scanf("%lf", &value);
    }
    void DTfloat64::write() const
    {
        if(type == dt_null)
        {
            printf("NULL");
            return;
        }
        printf("%lf", value);
    }
    void DTfloat64::read_fb(FILE * & file)
    {
        fread(&type, 1, 1, file);
        fread(&value, 8, 1, file);
        assert(type == dt_float64 || type == dt_null);
        if(type == dt_null)
            value = 0;
    }
    void DTfloat64::write_fb(FILE * & file) const
    {
        fwrite(&type, 1, 1, file);
        fwrite(&value, 8, 1, file);
    }
    int DTfloat64::size() const
    {
        return 1 + 8; 
    }
    void DTfloat64::clear()
    {
        type = dt_null;
        value = 0;
    }
    
    double DTfloat64::get_value() const
    {
        assert(type == dt_float64);
        return value;
    }
    void DTfloat64::set_value(double value_)
    {
        type = dt_float64;
        value = value_;
    }
    
    bool DTfloat64::operator == (const DTfloat64 & dt) const 
    {
        if(type != dt.type)
            return false;
        return value > dt.value - DTfloat64__eps && value < dt.value + DTfloat64__eps;
    }
    bool DTfloat64::operator != (const DTfloat64 & dt) const 
    {
        if(type != dt.type)
            return true;
        return value <= dt.value - DTfloat64__eps || value >= dt.value + DTfloat64__eps;
    }
    bool DTfloat64::operator < (const DTfloat64 & dt) const 
    {
        if(type != dt.type)
            return type < dt.type;
        return value <= dt.value - DTfloat64__eps;
    }
    bool DTfloat64::operator <= (const DTfloat64 & dt) const 
    {
        if(type != dt.type)
            return type < dt.type;
        return value < dt.value + DTfloat64__eps;
    }
    bool DTfloat64::operator > (const DTfloat64 & dt) const 
    {
        if(type != dt.type)
            return type > dt.type;
        return value >= dt.value + DTfloat64__eps;
    }
    bool DTfloat64::operator >= (const DTfloat64 & dt) const 
    {
        if(type != dt.type)
            return type > dt.type;
        return value > dt.value - DTfloat64__eps;
    }
    
    /*
    高精度浮点数
    */
    DTfloathp::DTfloathp()
    {
        type = dt_null;
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
                digit[blen + (i >> 3)] += (vs[dlen - 1 - i] - '0') * DTinthp__power_10[i & 7];
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
                digit[blen - 1 - (j >> 3)] += (vs[dlen + 1 + j] - '0') * DTinthp__power_10[~j & 7];
            for(j = 0; j < dlen; j++)
                digit[blen + (j >> 3)] += (vs[dlen - 1 - j] - '0') * DTinthp__power_10[j & 7];
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
        clear();
        type = dt_floathp;
        
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
                digit[blen + (i >> 3)] += (vs[dlen - 1 - i] - '0') * DTinthp__power_10[i & 7];
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
                digit[blen - 1 - (j >> 3)] += (vs[dlen + 1 + j] - '0') * DTinthp__power_10[~j & 7];
            for(j = 0; j < dlen; j++)
                digit[blen + (j >> 3)] += (vs[dlen - 1 - j] - '0') * DTinthp__power_10[j & 7];
        }
    }
    void DTfloathp::write() const
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
        int i = 0;
        if(alen == 0)
            printf("0");
        else
        {
            printf("%d", digit[alen + blen - 1]);
            for(i = alen + blen - 2; i >= blen; i--)
                printf("%08d", digit[i]);
        }
        if(blen == 0)
            return;
        printf(".");
        for(i = blen - 1; i > 0; i--)
            printf("%08d", digit[i]);
        for(i = digit[0]; i % 10 == 0; i /= 10);
        printf("%d", i);
    }
    void DTfloathp::read_fb(FILE * & file)
    {
        clear();
        fread(&type, 1, 1, file);
        fread(&flag, 1, 1, file);
        flag -= 1;
        fread(&dlen, 2, 1, file);
        alen = (dlen + 7) >> 3;
        fread(&plen, 2, 1, file);
        blen = (plen + 7) >> 3;
        if(type != dt_null)
        {
            memset(digit, 0, sizeof(int) * (alen + blen));
            fread(digit, 4, alen + blen, file);
        }
        assert(type == dt_inthp || type == dt_null);
        if(type == dt_null)
            clear();
    }
    void DTfloathp::write_fb(FILE * & file) const
    {
        fwrite(&type, 1, 1, file);
        int tmp = flag + 1;
        fwrite(&tmp, 1, 1, file);
        fwrite(&dlen, 2, 1, file);
        fwrite(&plen, 2, 1, file);
        if(type != dt_null)
            fwrite(digit, 4, alen + blen, file);
    }
    int DTfloathp::size() const
    {
        return 1 + 1 + 2 + 2 + (alen + blen) * 4;
    }
    void DTfloathp::clear()
    {
        type = dt_null;
        flag = 0;
        dlen = 0;
        plen = 0;
        alen = 0;
        blen = 0;
        if(digit != NULL)
        {
            delete [] digit;
            digit = NULL;
        }
    }
    
    bool DTfloathp::operator == (const DTfloathp & dt) const
    {
        if(type != dt.type)
            return false;
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
        if(type != dt.type)
            return true;
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
        if(type != dt.type)
            return type < dt.type;
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
        if(type != dt.type)
            return type < dt.type;
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
        if(type != dt.type)
            return type > dt.type;
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
        if(type != dt.type)
            return type > dt.type;
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
