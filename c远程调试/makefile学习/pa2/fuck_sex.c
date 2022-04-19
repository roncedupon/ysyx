#include"stdio.h"
typedef signed long int int64_t;
#define BITMASK(bits) ((1ull << (bits)) - 1)//unsigned long long 64bit~8B
#define BITS(x, hi, lo) (((x) >> (lo)) & BITMASK((hi) - (lo) + 1)) // similar to x[hi:lo] in verilog
// 
#define usigned64 unsigned long int
#define SEXT(x, len) ({ struct { int64_t n : len; } __x = { .n = x };\
(int64_t)__x.n; })
unsigned long int fuck_sex(unsigned int i){
    return SEXT(BITS(i, 8, 5), 4);
}

int main(){
    printf("fuck---------------------------\n");
    //long int fuck_dec=0x1234;
    //printf("%ld\n",sizeof(int));//int 4字节
    int fuck_bin=0b11100001>>5;
    printf("%d\n",fuck_bin);
    unsigned long long fuck_1=1ull;
    printf("%ld\n",sizeof(1ull));
    signed long int fucccck=1;
    //unsigned fuck_u64=usigned64(fucccck);
    printf("%lx---------",(unsigned long int)fucccck);

    printf("算术右移测试①int算术右移\n");
    int fuck_right=-5;          //补码--转为源码:1011-1=1010-->取反:1101(-5)---
    //c语言用的是原码
    //希望变成算术移位
    //fffffffe
    //1000-8
    int fuck_right2=0xfffffffe;
   // show_bits(10);
    printf("%x-----%x\n",fuck_right,fuck_right2);

    //判断int到底是原码还是补码
    struct fuck_str{
        int a:4;
        int b;
    }fuck_str_inst={//1101-1=1100--取反=1011
        .a=0b1101,//如果给定了bit大小,如果输出是-5那么就是原码,如果输出是-3那么就是补码
        //负数是补码,正数则为原码
        .b=0xfffffffd//如果
    }; //
    
    printf("%d--------(%d\n",fuck_str_inst.a,fuck_str_inst.b);


   // SEXT(-5,5)



    return 0;
}