#ifndef CONST_H_
#define CONST_H_

namespace GarbageMayor
{
    /*
    程序中用到的常量。
    */
    const int DTintbig__max_alen = 256;
    const int DTintbig__max_dlen = DTintbig__max_alen * 8;
    const int DTintbig__power_10[8] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };
    const int DTfloat32__eps = 1e-6;
    const int DTfloat64__eps = 1e-12;
    const int DTfloathp__max_clen = 256;
    const int DTfloathp__max_slen = (DTfloathp__max_clen - 1) * 8;
    
    const int DTtextc2f__max_len = 255;
}

#endif // CONST_H_
