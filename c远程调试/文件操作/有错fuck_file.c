#include<string.h>
#include<stdio.h>
// #include<conio.h>
// #include<io.h>
void flush(FILE *stream);
int main(void)
{
    FILE *stream;
    char msg[]="Thisisatest";
    /*createafile*/
    stream=fopen("DUMMY.FIL","w");
    /*writesomedatatothefile*/
    fwrite(charmsg,strlen(charmsg),1,stream);
    clrscr();
    printf("PressanykeytoflushDUMMY.FIL:");
    getch();
    /*flushthedatatoDUMMY.FILwithout\
      closingit*/
    flush(stream);
    printf("\nFilewasflushed,Pressanykey\toquit:");
    getch();
    return 0;
}
 
void flush(FILE* stream)
{
    int duphandle;
    /*flushthestream'sinternalbuffer*/
    fflush(stream);
    /*makeaduplicatefilehandle*/
    duphandle=dup(fileno(stream));
    /*closetheduplicatehandletoflushtheDOSbuffer*/
    close(duphandle);
}