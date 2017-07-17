#ifndef DATATIMETEXT_H_
#define DATATIMETEXT_H_

#include <cstdio>
#include <cstring>

/*
各种文本。
*/
namespace GarbageMayor
{
    /*
    定长短文本。
    长度255。
    */
    class DTtextc2f
        : public DataTypeBase
    {
    public:
        char text[max_length_DTtext8 + 1];
        
        DTtextc2f()
        {
            memset(text, 0, sizeof(char) * (max_length_DTtext8 + 1));
        }
        DTtextc2f(char * const text_)
        {
            memset(text, 0, sizeof(char) * (max_length_DTtext8 + 1));
            for(int i = 0; i < max_length_DTtext8 && text[i] != 0; i ++)
                text[i] = text_[i];
        }
        DTtextc2f(const DTtextc2f & dt)
        {
            memset(text, 0, sizeof(char) * (max_length_DTtext8 + 1));
            for(int i = 0; i < max_length_DTtext8 && dt.text[i] != 0; i ++)
                text[i] = dt.text[i];
        }
        ~DTtextc2f() {} 
        
    public:
        inline void read()
        {
            memset(text, 0, sizeof(char) * (max_length_DTtext8 + 1));
            scanf("%s", text);
            for(int i = 0; i < max_length_DTtext8 && text[i] != 0; i++);
            text[i] = 0;
        }
        inline void read_line()
        {
            memset(text, 0, sizeof(char) * (max_length_DTtext8 + 1));
            scanf("%[^\n]", text)
            for(int i = 0; i < max_length_DTtext8 && text[i] != 0; i++);
            text[i] = 0;
        }
        inline void write()
        {
            printf("%s", text);
        }
        
    public:
        inline bool operator == (const DTtextc2f & dt) const 
        {
            for(int i = 0; i < max_length_DTtext8 && text[i] != 0; i++)
            {
                if(text[i] != dt.text[i])
                    return false;
                if(text[i] == 0)
                    break;
            }
            return true;
        }
        inline bool operator != (const DTtextc2f & dt) const 
        {
            for(int i = 0; i < max_length_DTtext8 && text[i] != 0; i++)
            {
                if(text[i] != dt.text[i])
                    return true;
                if(text[i] == 0)
                    break;
            }
            return false;
        }
        inline bool operator < (const DTtextc2f & dt) const
        {
            for(int i = 0; i < max_length_DTtext8 && text[i] != 0; i++)
            {
                if(text[i] != dt.text[i])
                    return text[i] < dt.text[i];
                if(text[i] == 0)
                    break;
            }
            return false;
        }
        inline bool operator <= (const DTtextc2f & dt) const
        {
            for(int i = 0; i < max_length_DTtext8 && text[i] != 0; i++)
            {
                if(text[i] != dt.text[i])
                    return text[i] < dt.text[i];
                if(text[i] == 0)
                    break;
            }
            return true;
        }
        inline bool operator > (const DTtextc2f & dt) const 
        {
            for(int i = 0; i < max_length_DTtext8 && text[i] != 0; i++)
            {
                if(text[i] != dt.text[i])
                    return text[i] > dt.text[i];
                if(text[i] == 0)
                    break;
            }
            return false;
        }
        inline bool operator >= (const DTtextc2f & dt) const
        {
            for(int i = 0; i < max_length_DTtext8 && text[i] != 0; i++)
            {
                if(text[i] != dt.text[i])
                    return text[i] > dt.text[i];
                if(text[i] == 0)
                    break;
            }
            return true;
        }
    };
}


#endif // DATATIMETEXT_H_
