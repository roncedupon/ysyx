#include"stdio.h"
int main(){
    int a=0b1111;
    printf("%x/d",a&~1);//最低有效位设置为0
}