#ifndef _SRC_TERMINAIS_H
#define _SRC_TERMINAIS_H

enum Terminais
{
	TERMINAL_1 = 1,
	TERMINAL_2,
	TERMINAL_3,
	TERMINAL_4
};

extern void terminais_init(void);
extern void set_terminal(enum Terminais t);
extern void terminal_printf(enum Terminais terminal, const char str[], ...);

#endif