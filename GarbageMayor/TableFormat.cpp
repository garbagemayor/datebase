#include <cstdio>
#include <cstring>
#include <assert.h>

#include "Const.h"
#include "TableFormat.h"

namespace GarbageMayor
{
    TFcell::TFcell(DTenum type_, const char * name_, int nlen_)
        : type(type_)
    {
        assert(1 <= type && type <= 19);
        if(nlen_ == -1 || nlen_ > TFcell__max_length)
            nlen_ = TFcell__max_length;
        int i = 0;
        for(i = 0; i < nlen_&& name_[i] != 0; i++);
        nlen = i;
        name = new char [nlen + 1];
        memset(name, 0, sizeof(char) * (nlen + 1));
        for(i = 0; i < nlen; i++)
            name[i] = name_[i];
    }
    TFcell::TFcell(const TFcell & tf)
        : type(tf.type), nlen(tf.nlen)
    {
        type = tf.type;
        nlen = tf.nlen;
        name = new char [nlen + 1];
        memset(name, 0, sizeof(char) * (nlen + 1));
        for(int i = 0; i < nlen; i++)
            name[i] = tf.name[i];
    }
    
    void TFcell::write() const
    {
        printf("%s<%s>", name, get_typename());
    }
    /*
    void TFcell::read_fb(FILE * & file)
    {
        clear();
        fread(&type, 1, 1, file);
        fread(&nlen, 1, 1, file);
        name = new char [nlen + 1];
        memset(name, 0, sizeof(char) * (nlen + 1));
        fread(name, 1, nlen, file);
    }
    */
    void TFcell::write_fb(FILE * & file) const
    {
        fwrite(&type, 1, 1, file);
        fwrite(&nlen, 1, 1, file);
        fwrite(name, 1, nlen, file);
    }
    const char * const TFcell::get_typename() const
    {
        if(type == dt_int8)
            return "int8";
        if(type == dt_int16)
            return "int16";
        if(type == dt_int32)
            return "int32";
        if(type == dt_int64)
            return "int64";
        if(type == dt_inthp)
            return "inthp";
        
        if(type == dt_float32)
            return "float32";
        if(type == dt_float64)
            return "float64";
        if(type == dt_floathp)
            return "floathp";
        
        if(type == dt_timey)
            return "timey";
        if(type == dt_timed)
            return "timed";
        if(type == dt_times)
            return "times";
        if(type == dt_timeds)
            return "timeds";
        if(type == dt_timedsu)
            return "timedsu";
        
        if(type == dt_text2f)
            return "text2f";
        if(type == dt_text4f)
            return "text4f";
        if(type == dt_text8f)
            return "text8f";
        
        if(type == dt_binary2f)
            return "binary2f";
        if(type == dt_binary4f)
            return "binary4f";
        if(type == dt_binary8f)
            return "binary8f";
        
        return "error";
    }
    
}
