#include <cstdio>
#include <cstring>

#include "Const.h"
#include "DataTypeBinary.h"

namespace GarbageMayor
{
    /*
    短二进制串。
    */
    DTbinary2f::DTbinary2f()
        : length(0), data(NULL)
    {
        type = dt_binary2f;
    }
    DTbinary2f::DTbinary2f(const unsigned char * data_, int length_)
        : length(0), data(NULL)
    {
        type = dt_binary2f;
        
        if(length_ > DTtext2f__max_length)
            length_ = DTtext2f__max_length;
        length = length_;
        data = new unsigned char [length + 1];
        memset(data, 0, sizeof(unsigned char) * (length + 1));
        for(int i = 0; i < length; i++)
            data[i] = data_[i];
    }
    DTbinary2f::DTbinary2f(const DTbinary2f & dt)
        : length(0), data(NULL)
    {
        type = dt_binary2f;
        
        length = dt.length;
        data = new unsigned char [length + 1];
        memset(data, 0, sizeof(unsigned char) * (length + 1));
        for(int i = 0; i < length; i++)
            data[i] = dt.data[i];
    }
    DTbinary2f::~DTbinary2f()
    {
        if(data != NULL)
        {
            delete [] data;
            data = NULL;
            length = 0;
        }
    }
    
    void DTbinary2f::read()
    {
        if(data != NULL)
        {
            delete [] data;
            data = NULL;
            length = 0;
        }
        
        static unsigned char buffer[DTtext2f__max_length + 1];
        int i = 0;
        
        scanf(DTtext2f__scan_mode, buffer);
        for(i = 0; i < DTtext2f__max_length && buffer[i] != 0; i++);
        length = i;
        data = new unsigned char [length + 1];
        memset(data, 0, sizeof(char) * (length + 1));
        for(i = 0; i < length; i++)
            data[i] = buffer[i];
    }
    void DTbinary2f::write()
    {
        printf("%s", data);
    }
    int DTbinary2f::get_size() const 
    {
        return length + 4;
    }
    
    bool DTbinary2f::operator == (const DTbinary2f & dt) const
    {
        if(length != dt.length)
            return false;
        for(int i = 0; i <= length; i++)
            if(data[i] != dt.data[i])
                return false;
        return true;
    }
    bool DTbinary2f::operator != (const DTbinary2f & dt) const
    {
        if(length != dt.length)
            return true;
        for(int i = 0; i <= length; i++)
            if(data[i] != dt.data[i])
                return true;
        return false;
    }
    bool DTbinary2f::operator < (const DTbinary2f & dt) const
    {
        for(int i = 0; i <= length; i++)
            if(data[i] != dt.data[i])
                return data[i] < dt.data[i];
        return length < dt.length;
    }
    bool DTbinary2f::operator <= (const DTbinary2f & dt) const
    {
        for(int i = 0; i <= length; i++)
            if(data[i] != dt.data[i])
                return data[i] < dt.data[i];
        return length <= dt.length;
    }
    bool DTbinary2f::operator > (const DTbinary2f & dt) const
    {
        for(int i = 0; i <= length; i++)
            if(data[i] != dt.data[i])
                return data[i] > dt.data[i];
        return length > dt.length;
    }
    bool DTbinary2f::operator >= (const DTbinary2f & dt) const
    {
        for(int i = 0; i <= length; i++)
            if(data[i] != dt.data[i])
                return data[i] > dt.data[i];
        return length >= dt.length;
    }
    
    /*
    中文本。
    */
    DTbinary4f::DTbinary4f()
        : length(0), data(NULL)
    {
        type = dt_binary4f;
    }
    DTbinary4f::DTbinary4f(const unsigned char * data_, int length_)
        : length(0), data(NULL)
    {
        type = dt_binary4f;
        
        if(length_ > DTtext4f__max_length)
            length_ = DTtext4f__max_length;
        int i = 0;
        for(i = 0; i < length_ && data_[i] != 0; i++);
        length = i;
        data = new unsigned char [length + 1];
        memset(data, 0, sizeof(unsigned char) * (length + 1));
        for(i = 0; i < length; i++)
            data[i] = data_[i];
    }
    DTbinary4f::DTbinary4f(const DTbinary4f & dt)
        : length(0), data(NULL)
    {
        type = dt_binary4f;
        
        length = dt.length;
        data = new unsigned  char [length + 1];
        memset(data, 0, sizeof(unsigned char) * (length + 1));
        for(int i = 0; i < length; i++)
            data[i] = dt.data[i];
    }
    DTbinary4f::~DTbinary4f()
    {
        if(data != NULL)
        {
            delete [] data;
            data = NULL;
            length = 0;
        }
    }
    
    void DTbinary4f::read()
    {
        if(data != NULL)
        {
            delete [] data;
            data = NULL;
            length = 0;
        }
        
        static unsigned char buffer[DTtext4f__max_length + 1];
        int i = 0;
        
        scanf(DTtext4f__scan_mode, buffer);
        for(i = 0; i < DTtext4f__max_length && buffer[i] != 0; i++);
        length = i;
        data = new unsigned char [length + 1];
        memset(data, 0, sizeof(unsigned char) * (length + 1));
        for(i = 0; i < length; i++)
            data[i] = buffer[i];
    }
    void DTbinary4f::write()
    {
        printf("%s", data);
    }
    int DTbinary4f::get_size() const 
    {
        return length + 4;
    }
    
    bool DTbinary4f::operator == (const DTbinary4f & dt) const
    {
        if(length != dt.length)
            return false;
        for(int i = 0; i <= length; i++)
            if(data[i] != dt.data[i])
                return false;
        return true;
    }
    bool DTbinary4f::operator != (const DTbinary4f & dt) const
    {
        if(length != dt.length)
            return true;
        for(int i = 0; i <= length; i++)
            if(data[i] != dt.data[i])
                return true;
        return false;
    }
    bool DTbinary4f::operator < (const DTbinary4f & dt) const
    {
        for(int i = 0; i <= length; i++)
            if(data[i] != dt.data[i])
                return data[i] < dt.data[i];
        return length < dt.length;
    }
    bool DTbinary4f::operator <= (const DTbinary4f & dt) const
    {
        for(int i = 0; i <= length; i++)
            if(data[i] != dt.data[i])
                return data[i] < dt.data[i];
        return length <= dt.length;
    }
    bool DTbinary4f::operator > (const DTbinary4f & dt) const
    {
        for(int i = 0; i <= length; i++)
            if(data[i] != dt.data[i])
                return data[i] > dt.data[i];
        return length > dt.length;
    }
    bool DTbinary4f::operator >= (const DTbinary4f & dt) const
    {
        for(int i = 0; i <= length; i++)
            if(data[i] != dt.data[i])
                return data[i] > dt.data[i];
        return length >= dt.length;
    }
    
    /*
    长文本。
    */
    DTbinary8f::DTbinary8f()
        : length(0), data(NULL)
    {
        type = dt_binary8f;
    }
    DTbinary8f::DTbinary8f(const unsigned char * data_, int length_)
        : length(0), data(NULL)
    {
        type = dt_binary8f;
        
        if(length_ > DTtext8f__max_length)
            length_ = DTtext8f__max_length;
        int i = 0;
        for(i = 0; i < length_ && data_[i] != 0; i++);
        length = i;
        data = new unsigned char [length + 1];
        memset(data, 0, sizeof(unsigned char) * (length + 1));
        for(i = 0; i < length; i++)
            data[i] = data_[i];
    }
    DTbinary8f::DTbinary8f(const DTbinary8f & dt)
        : length(0), data(NULL)
    {
        type = dt_binary8f;
        
        length = dt.length;
        data = new unsigned char [length + 1];
        memset(data, 0, sizeof(unsigned char) * (length + 1));
        for(int i = 0; i < length; i++)
            data[i] = dt.data[i];
    }
    DTbinary8f::~DTbinary8f()
    {
        if(data != NULL)
        {
            delete [] data;
            data = NULL;
            length = 0;
        }
    }
    
    void DTbinary8f::read()
    {
        if(data != NULL)
        {
            delete [] data;
            data = NULL;
            length = 0;
        }
        
        static char buffer[DTtext8f__max_buffer + 1];
        int i = 0;
        
        scanf(DTtext8f__scan_mode, buffer);
        for(i = 0; i < DTtext8f__max_buffer && buffer[i] != 0; i++);
        length = i;
        data = new unsigned char [length + 1];
        memset(data, 0, sizeof(unsigned char) * (length + 1));
        for(i = 0; i < length; i++)
            data[i] = buffer[i];
    }
    void DTbinary8f::write()
    {
        printf("%s", data);
    }
    int DTbinary8f::get_size() const 
    {
        return length + 4;
    }
    
    bool DTbinary8f::operator == (const DTbinary8f & dt) const
    {
        if(length != dt.length)
            return false;
        for(int i = 0; i <= length; i++)
            if(data[i] != dt.data[i])
                return false;
        return true;
    }
    bool DTbinary8f::operator != (const DTbinary8f & dt) const
    {
        if(length != dt.length)
            return true;
        for(int i = 0; i <= length; i++)
            if(data[i] != dt.data[i])
                return true;
        return false;
    }
    bool DTbinary8f::operator < (const DTbinary8f & dt) const
    {
        for(int i = 0; i <= length; i++)
            if(data[i] != dt.data[i])
                return data[i] < dt.data[i];
        return length < dt.length;
    }
    bool DTbinary8f::operator <= (const DTbinary8f & dt) const
    {
        for(int i = 0; i <= length; i++)
            if(data[i] != dt.data[i])
                return data[i] < dt.data[i];
        return length <= dt.length;
    }
    bool DTbinary8f::operator > (const DTbinary8f & dt) const
    {
        for(int i = 0; i <= length; i++)
            if(data[i] != dt.data[i])
                return data[i] > dt.data[i];
        return length > dt.length;
    }
    bool DTbinary8f::operator >= (const DTbinary8f & dt) const
    {
        for(int i = 0; i <= length; i++)
            if(data[i] != dt.data[i])
                return data[i] > dt.data[i];
        return length >= dt.length;
    }
}
