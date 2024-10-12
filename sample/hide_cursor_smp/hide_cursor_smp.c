// for pc/at
#include <conio.h>
#include <dos.h>

void hide_cursor() {
    union REGS regs;
    regs.h.ah = 0x01;
    regs.h.ch = 0x20;
    regs.h.cl = 0x00;
    int86(0x10, &regs, &regs);
}

void show_cursor() {
    union REGS regs;
    regs.h.ah = 0x03;
    regs.h.bh = 0x00;
    int86(0x10, &regs, &regs);

    regs.h.ah = 0x01;
    //regs.h.ch = 
    //regs.h.cl = 
    int86(0x10, &regs, &regs);
}

int main() {
	hide_cursor();
	cputs("Hit any key.");
	getch();
	show_cursor();
	return 0;
}
