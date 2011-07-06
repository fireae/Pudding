#include <system.h>
ushort *memsetw(ushort *dest, ushort val, int count)
{
  unsigned short *temp = (unsigned short *)dest;
    for( ; count != 0; count--) *temp++ = val;
    return dest;
}
void * memset(void *dest, uchar val, int count)
{
	char *tmp = (char *)dest;
	for(; count != 0; -- count) *tmp++ = val;
	return tmp;
}
void * memcpy(void *dest, const void *src, int count)
{
	const char *tmp = (const char *)src;
	char *pdst = (char *)dest;
	int i = 0;
	for(; *tmp != '\0', count != 0; --count)*dest ++= *tmp ++;
	return pdst;
}
int strlen(const char *str)
{
	int len =0;
	for(len=0; *str != '\0'; ++str)++len;
	return len;
}
uchar inportb(ushort _port)
{
	uchar rv;
	__asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
	return rv;
}
void outportb(ushort _port, uchar _data)
{
	__asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

void main()
{
	while(1);
}