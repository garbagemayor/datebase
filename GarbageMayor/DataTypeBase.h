#ifndef DATATYPEBASE_H
#define DATATYPEBASE_H

namespace GarbageMayor
{
    
    /*
    确定数据类型的枚举元。
    */
    enum DTenum
    {
        dt_int8,        //8位整数
        dt_int16,       //16位整数
        dt_int32,       //32位整数
        dt_int64,       //64位整数
        dt_inthp,       //高精度整数，不超过2048个十进制位
        
        dt_float32,     //32位浮点数
        dt_float64,     //64位浮点数
        dt_floathp,     //高精度浮点数，不超过2048个十进制位
        
        dt_timey,       //年yyyy
        dt_timed,       //年月日yyyymmdd
        dt_times,       //时分秒hhmmss
        dt_timeds,      //年月日时分秒yyyymmddhhmmss
        dt_timedsu,     //年月日时分秒毫微yyyymmddhhmmssmmmuuu
        
        dt_text2f,     //短文本，长度不超过255字节
        dt_text4f,     //中文本，长度不超过65535字节
        dt_text8f,     //长文本，长度不超过1073741823字节
        
        dt_binary2f,   //短二进制串，长度不超过255字节
        dt_binary4f,   //中二进制串，长度不超过65535字节
        dt_binary8f,   //长二进制串，长度不超过1073741823字节
        
        dt_error = -1,  //没有确定类型时报错
    };
    
    /*
    数据类型基类。
    */
    class DTbase
    {
    public:
        DTenum type;
        
    public:
        DTbase();
        ~DTbase();
        
    public:
        void assert_type();

    private:
        virtual void read() = 0;
        virtual void write() = 0;
        virtual int get_size() const = 0;
    };
}

#endif // DATATYPEBASE_H
