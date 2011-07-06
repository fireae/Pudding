#ifndef __SYSTEM_H
#define __SYSTEM_H
#define public extern 
#define	uchar unsigned char 
#define ushort unsigned short 

public ushort 	*memsetw(ushort *dest, ushort val, int count);
public void 	*memset(void *dest, char val, int count);
public void 	*memcpy(void *dest, const void *src, int count);
public int 		strlen(const char *str);
public uchar 	inportb(ushort _port);
public void	 	outportb(ushort _port, uchar _data);
public void 	cls();
public void 	putch(unsigned char c);
public void 	puts(unsigned char *str);
public void 	settextcolor(unsigned char forecolor, unsigned char backcolor);
public void 	init_video();

#endif