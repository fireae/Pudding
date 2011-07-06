#include <system.h>

ushort *textmemptr;
int attrib = 0x0F;
int csr_x = 0, csr_y = 0;

void scroll(void)
{
	ushort blank, temp;
	blank = 0x20 | (attrib << 8);
	if(csr_y >= 25)
	{
		temp = csr_y - 25 + 1;
		memcpy(textmemptr, textmemptr + temp * 80, (25 - temp) *80 * 2);
		
		memsetw(textmemptr + (25 - temp) * 80, blank, 80);
		csr_y = 25 -1;
	}
}

void move_csr()
{
	ushort temp;
	
	temp = csr_y * 80 + csr_x;
	outportb(0x3D4, 14);
	outportb(0x3D5, temp>>8);
	outportb(0x3D4, 15);
	outportb(0x3D5, temp);
	
}

void cls()
{
	ushort blank;
	blank = 0x20 | (attrib << 8);
	
	int i = 0;
	for(i = 0; i< 25; i++)
	{
		memsetw(textmemptr + i* 80, blank ,80);
	}
	
	csr_x = 0; 
	csr_y = 0;
	move_csr();
}

void putch(uchar c)
{
	ushort *where;
	ushort att = attrib << 8;
	
	if(c == 0x08)
	{
		if(csr_x != 0) csr_x--;
	}
	else if(c == 0x09)
	{
		csr_x = (csr_x + 8) & ~(8 - 1);
	}
	else if(c == '\r')
	{
		csr_x = 0;
	}
	else if(c == '\n')
	{
		csr_x = 0;
		++csr_y;
	}
	else if (c >= '')
	{
		where = textmemptr + (csr_y * 80 + csr_x);
		*where = c | att;
		++ csr_x;
	}
	
	if(csr_x >= 80)
	{
		csr_x = 0;
		++ csr_y;
	}
	
	scroll();
	move_csr();
}

void puts(uchar *text)
{
	int i;
	for(i = 0; i< strlen(text); i++)
	{
		putch(text[i]);
	}
}

void settextcolor(uchar forecolor, uchar backcolor)
{
	attrib = backcolor << 4 | (forecolor & 0x0F);
}

void init_video()
{
	textmemptr = (ushort *)0xB8000;
	cls();
}