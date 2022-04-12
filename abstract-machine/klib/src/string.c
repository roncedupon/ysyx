#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

/*
check(strcmp(s[0], s[2]) == 0);
	check(strcmp(s[0], s[1]) < 0);
	check(strcmp(s[0] + 1, s[1] + 1) < 0);
	check(strcmp(s[0] + 2, s[1] + 2) < 0);
	check(strcmp(s[0] + 3, s[1] + 3) < 0);
	check(strcmp( strcat(strcpy(str, str1), s[3]), s[4]) == 0);
	check(memcmp(memset(str, '#', 5), s[5], 5) == 0);
*/


#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  panic("Not implemented");
}

// char *strcpy(char *dst, const char *src) {
//   panic("Not implemented");
// }

char * strcpy(char *dst,const char *src)   //[1]
{
    assert(dst != NULL && src != NULL);    //[2]

    char *ret = dst;  //[3]

    while ((*dst++=*src++)!='\0'); //[4]

    return ret;
}

char *strncpy(char *dst, const char *src, size_t n) {
  panic("Not implemented");
}

// char *strcat(char *dst, const char *src) {
//   panic("Not implemented");
// }
char* strcat(char * dest, const char * src)
{
    assert(dest != NULL);
    assert(src != NULL);
	int i = 0;
	for (i = 0; dest[i] != '\0'; i++);
	int j = 0;
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return dest;
}   


int strcmp(const char *str1, const char *str2) {
   while((*str1!='\0')&&(*str1==*str2))
    {
        str1++;
        str2++;
    }
    int t;
    t=*str1-*str2;
    if(t==0)
        return 0;
    if(t>0)
        return 1;
    if(t<0)
        return -1;
    return 0;
}

int strncmp(const char *s1, const char *s2, size_t n) {

  panic("Not implemented");
}

void *memset(void *dest, int set, size_t len) {
  if (dest == NULL || len < 0)
	{
		return NULL;
	}
	char *pdest = (char *)dest;
	while (len-->0)
	{
		*pdest++ = set;
	}
  return dest;
}

void *memmove(void *dst, const void *src, size_t n) {
  panic("Not implemented");
}

void *memcpy(void *out, const void *in, size_t n) {
  panic("Not implemented");
}

int memcmp(const void *s1, const void *s2, size_t count) {
  const void*buf1=s1;
  const void*buf2=s2;
  assert(buf1 != NULL);
	assert(buf2 != NULL);
 
	while (count--)
	{
        //需要强制类型转换成char类型，进行字节位比较
		if (*(char*)buf1 != *(char*)buf2)    //如果该字节数字不同，返回其差值
		{
			return *(char*)buf1 - *(char*)buf2;
		}
		buf1 = (char*)buf1 + 1;              
		buf2 = (char*)buf2 + 1;
	}
	return 0;  
  //panic("Not implemented");
}

#endif
