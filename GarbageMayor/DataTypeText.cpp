#include <cstdio>
#include <cstring>
#include <assert.h>

#include "Const.h"
#include "DataTypeText.h"

namespace GarbageMayor
{
    /*
    短文本。
    */
    DTtext2f::DTtext2f()
        : length(0), text(NULL)
    {
        type = dt_null;
    }
    DTtext2f::DTtext2f(const char * text_, int length_)
        : length(0), text(NULL)
    {
        type = dt_text2f;
        
        if(length_ == -1 || length_ > DTtext2f__max_length)
            length_ = DTtext2f__max_length;
        int i = 0;
        for(i = 0; i < length_ && text_[i] != 0; i++);
        length = i;
        text = new char [length + 1];
        memset(text, 0, sizeof(char) * (length + 1));
        for(i = 0; i < length; i++)
            text[i] = text_[i];
    }
    DTtext2f::DTtext2f(const DTtext2f & dt)
        : length(0), text(NULL)
    {
        type = dt_text2f;
        
        length = dt.length;
        text = new char [length + 1];
        memset(text, 0, sizeof(char) * (length + 1));
        for(int i = 0; i < length; i++)
            text[i] = dt.text[i];
    }
    DTtext2f::~DTtext2f()
    {
        if(text != NULL)
        {
            delete [] text;
            text = NULL;
            length = 0;
        }
    }
    
    void DTtext2f::read()
    {
        clear();
        type = dt_text2f;
        
        static char buffer[DTtext2f__max_length + 1];
        int i = 0;
        
        scanf(DTtext2f__scan_mode, buffer);
        for(i = 0; i < DTtext2f__max_length && buffer[i] != 0; i++);
        length = i;
        text = new char [length + 1];
        memset(text, 0, sizeof(char) * (length + 1));
        for(i = 0; i < length; i++)
            text[i] = buffer[i];
    }
    void DTtext2f::write() const
    {
        if(type == dt_null)
        {
            printf("NULL");
            return;
        }
        printf("%s", text);
    }
    void DTtext2f::read_fb(FILE * & file)
    {
        clear();
        fread(&type, 1, 1, file);
        fread(&length, 1, 1, file);
        assert(type == dt_text2f || type == dt_null);
        if(type == dt_null)
            clear();
        else
        {
            text = new char [length + 1];
            memset(text, 0, sizeof(char) * (length + 1));
            fread(text, 1, length, file);
        }
    }
    void DTtext2f::write_fb(FILE * & file) const
    {
        fwrite(&type, 1, 1, file);
        fwrite(&length, 1, 1, file);
        if(type != dt_null)
            fwrite(text, 1, length, file);
    }
    int DTtext2f::size() const 
    {
        return 1 + 1 + length;
    }
    void DTtext2f::clear() 
    {
        type = dt_null;
        length = 0;
        if(text != NULL)
        {
            delete [] text;
            text = NULL;
        }
    }
    
    int DTtext2f::get_length() const
    {
        assert(type == dt_text2f);
        return length;
    }
    char * DTtext2f::get_c_str() const
    {
        assert(type == dt_text2f);
        return text;
    }
    
    bool DTtext2f::operator == (const DTtext2f & dt) const
    {
        if(type != dt.type)
            return false;
        if(length != dt.length)
            return false;
        for(int i = 0; i < length; i++)
            if(text[i] != dt.text[i])
                return false;
        return true;
    }
    bool DTtext2f::operator != (const DTtext2f & dt) const
    {
        if(type != dt.type)
            return true;
        if(length != dt.length)
            return true;
        for(int i = 0; i < length; i++)
            if(text[i] != dt.text[i])
                return true;
        return false;
    }
    bool DTtext2f::operator < (const DTtext2f & dt) const
    {
        if(type != dt.type)
            return type < dt.type;
        for(int i = 0; i < length; i++)
            if(text[i] != dt.text[i])
                return text[i] < dt.text[i];
        return length < dt.length;
    }
    bool DTtext2f::operator <= (const DTtext2f & dt) const
    {
        if(type != dt.type)
            return type < dt.type;
        for(int i = 0; i < length; i++)
            if(text[i] != dt.text[i])
                return text[i] < dt.text[i];
        return length <= dt.length;
    }
    bool DTtext2f::operator > (const DTtext2f & dt) const
    {
        if(type != dt.type)
            return type > dt.type;
        for(int i = 0; i < length; i++)
            if(text[i] != dt.text[i])
                return text[i] > dt.text[i];
        return length > dt.length;
    }
    bool DTtext2f::operator >= (const DTtext2f & dt) const
    {
        if(type != dt.type)
            return type > dt.type;
        for(int i = 0; i < length; i++)
            if(text[i] != dt.text[i])
                return text[i] > dt.text[i];
        return length >= dt.length;
    }
    
    /*
    中文本。
    */
    DTtext4f::DTtext4f()
        : length(0), text(NULL)
    {
        type = dt_null;
    }
    DTtext4f::DTtext4f(const char * text_, int length_)
        : length(0), text(NULL)
    {
        type = dt_text4f;
        
        if(length_ == -1 || length_ > DTtext4f__max_length)
            length_ = DTtext4f__max_length;
        int i = 0;
        for(i = 0; i < length_ && text_[i] != 0; i++);
        length = i;
        text = new char [length + 1];
        memset(text, 0, sizeof(char) * (length + 1));
        for(i = 0; i < length; i++)
            text[i] = text_[i];
    }
    DTtext4f::DTtext4f(const DTtext4f & dt)
        : length(0), text(NULL)
    {
        type = dt_text4f;
        
        length = dt.length;
        text = new char [length + 1];
        memset(text, 0, sizeof(char) * (length + 1));
        for(int i = 0; i < length; i++)
            text[i] = dt.text[i];
    }
    DTtext4f::~DTtext4f()
    {
        if(text != NULL)
        {
            delete [] text;
            text = NULL;
            length = 0;
        }
    }
    
    void DTtext4f::read()
    {
        clear();
        type = dt_text4f;
        
        static char buffer[DTtext4f__max_length + 1];
        int i = 0;
        
        scanf(DTtext4f__scan_mode, buffer);
        for(i = 0; i < DTtext4f__max_length && buffer[i] != 0; i++);
        length = i;
        text = new char [length + 1];
        memset(text, 0, sizeof(char) * (length + 1));
        for(i = 0; i < length; i++)
            text[i] = buffer[i];
    }
    void DTtext4f::write() const
    {
        if(type == dt_null)
        {
            printf("NULL");
            return;
        }
        printf("%s", text);
    }
    void DTtext4f::read_fb(FILE * & file)
    {
        clear();
        fread(&type, 1, 1, file);
        fread(&length, 2, 1, file);
        assert(type == dt_text4f || type == dt_null);
        if(type == dt_null)
            clear();
        else
        {
            text = new char [length + 1];
            memset(text, 0, sizeof(char) * (length + 1));
            fread(text, 1, length, file);
        }
    }
    void DTtext4f::write_fb(FILE * & file) const
    {
        fwrite(&type, 1, 1, file);
        fwrite(&length, 2, 1, file);
        if(type != dt_null)
            fwrite(text, 1, length, file);
    }
    int DTtext4f::size() const 
    {
        return 1 + 2 + length;
    }
    void DTtext4f::clear()
    {
        type = dt_null;
        length = 0;
        if(text != NULL)
        {
            delete [] text;
            text = NULL;
        }
    }
    
    int DTtext4f::get_length() const
    {
        assert(type == dt_text4f);
        return length;
    }
    char * DTtext4f::get_c_str() const
    {
        assert(type == dt_text4f);
        return text;
    }
    
    bool DTtext4f::operator == (const DTtext4f & dt) const
    {
        if(type != dt.type)
            return false;
        if(length != dt.length)
            return false;
        for(int i = 0; i < length; i++)
            if(text[i] != dt.text[i])
                return false;
        return true;
    }
    bool DTtext4f::operator != (const DTtext4f & dt) const
    {
        if(type != dt.type)
            return false;
        if(length != dt.length)
            return true;
        for(int i = 0; i < length; i++)
            if(text[i] != dt.text[i])
                return true;
        return false;
    }
    bool DTtext4f::operator < (const DTtext4f & dt) const
    {
        if(type != dt.type)
            return type < dt.type;
        for(int i = 0; i < length; i++)
            if(text[i] != dt.text[i])
                return text[i] < dt.text[i];
        return length < dt.length;
    }
    bool DTtext4f::operator <= (const DTtext4f & dt) const
    {
        if(type != dt.type)
            return type < dt.type;
        for(int i = 0; i < length; i++)
            if(text[i] != dt.text[i])
                return text[i] < dt.text[i];
        return length <= dt.length;
    }
    bool DTtext4f::operator > (const DTtext4f & dt) const
    {
        if(type != dt.type)
            return type > dt.type;
        for(int i = 0; i < length; i++)
            if(text[i] != dt.text[i])
                return text[i] > dt.text[i];
        return length > dt.length;
    }
    bool DTtext4f::operator >= (const DTtext4f & dt) const
    {
        if(type != dt.type)
            return type > dt.type;
        for(int i = 0; i < length; i++)
            if(text[i] != dt.text[i])
                return text[i] > dt.text[i];
        return length >= dt.length;
    }
    
    /*
    长文本。
    */
    DTtext8f::DTtext8f()
        : length(0), text(NULL)
    {
        type = dt_null;
    }
    DTtext8f::DTtext8f(const char * text_, int length_)
        : length(0), text(NULL)
    {
        type = dt_text8f;
        
        if(length_ == -1 || length_ > DTtext8f__max_length)
            length_ = DTtext8f__max_length;
        int i = 0;
        for(i = 0; i < length_ && text_[i] != 0; i++);
        length = i;
        text = new char [length + 1];
        memset(text, 0, sizeof(char) * (length + 1));
        for(i = 0; i < length; i++)
            text[i] = text_[i];
    }
    DTtext8f::DTtext8f(const DTtext8f & dt)
        : length(0), text(NULL)
    {
        type = dt_text8f;
        
        length = dt.length;
        text = new char [length + 1];
        memset(text, 0, sizeof(char) * (length + 1));
        for(int i = 0; i < length; i++)
            text[i] = dt.text[i];
    }
    DTtext8f::~DTtext8f()
    {
        if(text != NULL)
        {
            delete [] text;
            text = NULL;
            length = 0;
        }
    }
    
    void DTtext8f::read()
    {
        clear();
        type = dt_text8f;
        
        static char buffer[DTtext8f__max_buffer + 1];
        int i = 0;
        
        scanf(DTtext8f__scan_mode, buffer);
        for(i = 0; i < DTtext8f__max_buffer && buffer[i] != 0; i++);
        length = i;
        text = new char [length + 1];
        memset(text, 0, sizeof(char) * (length + 1));
        for(i = 0; i < length; i++)
            text[i] = buffer[i];
    }
    void DTtext8f::write() const
    {
        if(type == dt_null)
        {
            printf("NULL");
            return;
        }
        printf("%s", text);
    }
    void DTtext8f::read_fb(FILE * & file)
    {
        clear();
        fread(&type, 1, 1, file);
        fread(&length, 4, 1, file);
        assert(type == dt_text8f || type == dt_null);
        if(type == dt_null)
            clear();
        else
        {
            text = new char [length + 1];
            memset(text, 0, sizeof(char) * (length + 1));
            fread(text, 1, length, file);
        }
    }
    void DTtext8f::write_fb(FILE * & file) const
    {
        fwrite(&type, 1, 1, file);
        fwrite(&length, 4, 1, file);
        if(type != dt_null)
            fwrite(text, 1, length, file);
    }
    int DTtext8f::size() const 
    {
        return 1 + 4 + length;
    }
    void DTtext8f::clear()
    {
        type = dt_null;
        length = 0;
        if(text != NULL)
        {
            delete [] text;
            text = NULL;
        }
    }
    
    int DTtext8f::get_length() const
    {
        assert(type == dt_text8f);
        return length;
    }
    char * DTtext8f::get_c_str() const
    {
        assert(type == dt_text8f);
        return text;
    }
    
    bool DTtext8f::operator == (const DTtext8f & dt) const
    {
        if(type != dt.type)
            return false;
        if(length != dt.length)
            return false;
        for(int i = 0; i < length; i++)
            if(text[i] != dt.text[i])
                return false;
        return true;
    }
    bool DTtext8f::operator != (const DTtext8f & dt) const
    {
        if(type != dt.type)
            return true;
        if(length != dt.length)
            return true;
        for(int i = 0; i < length; i++)
            if(text[i] != dt.text[i])
                return true;
        return false;
    }
    bool DTtext8f::operator < (const DTtext8f & dt) const
    {
        if(type != dt.type)
            return type < dt.type;
        for(int i = 0; i < length; i++)
            if(text[i] != dt.text[i])
                return text[i] < dt.text[i];
        return length < dt.length;
    }
    bool DTtext8f::operator <= (const DTtext8f & dt) const
    {
        if(type != dt.type)
            return type < dt.type;
        for(int i = 0; i < length; i++)
            if(text[i] != dt.text[i])
                return text[i] < dt.text[i];
        return length <= dt.length;
    }
    bool DTtext8f::operator > (const DTtext8f & dt) const
    {
        if(type != dt.type)
            return type > dt.type;
        for(int i = 0; i < length; i++)
            if(text[i] != dt.text[i])
                return text[i] > dt.text[i];
        return length > dt.length;
    }
    bool DTtext8f::operator >= (const DTtext8f & dt) const
    {
        if(type != dt.type)
            return type > dt.type;
        for(int i = 0; i < length; i++)
            if(text[i] != dt.text[i])
                return text[i] > dt.text[i];
        return length >= dt.length;
    }
}
