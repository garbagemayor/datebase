#ifndef CONST_H_
#define CONST_H_

namespace GarbageMayor
{
    /*
    程序中用到的常量。
    */
    //int上限
    const int max_int = 2147483647;
    //高精度整数在程序中的数组大小。
    const int DTinthp__max_alen = 256;
    //高精度整数最大位数。
    const int DTinthp__max_dlen = 2048;
    //高精度整数的scanf读入模式。
    const char * const DTinthp__scan_mode = "%2048[0-9-]";
    //高精度整数和高精度浮点数压位时10的幂次。
    const int DTinthp__power_10[8] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };
    //32位浮点数相等误差容纳。
    const float DTfloat32__eps = 1e-6;
    //64位浮点数相等误差容纳。
    const double DTfloat64__eps = 1e-12;
    //高精度浮点数在程序中的数组大小。
    const int DTfloathp__max_clen = 256;
    //高精度浮点数的最大位数。
    const int DTfloathp__max_slen = 2048;
    //高精度浮点数的scanf读入模式。
    const char * const DTfloathp__scan_mode = "%2048[0-9.-]";
    //短文本最大长度。
    const int DTtext2f__max_length = 255;
    //短文本的scanf读取模式。
    const char * const DTtext2f__scan_mode = "%255[\x1-\xff]";
    //中文本最大长度。
    const int DTtext4f__max_length = 65535;
    //中文本的scanf读取模式。
    const char * const DTtext4f__scan_mode = "%65535[\x1-\xff]";
    //长文本最大长度。
    const int DTtext8f__max_length = 1073741823;
    //长文本从缓冲区读取的最大长度。
    const int DTtext8f__max_buffer = 1048575;
    //长文本的scanf读取模式。
    const char * const DTtext8f__scan_mode = "%1048575[\x1-\xff]";
    
    //列名称最大长度。
    const int TFcell__max_length = 255;
    
    
    
    
    
    
    
}

#endif // CONST_H_
