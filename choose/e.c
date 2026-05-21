/*                       __________________							  */
/*                        S |-| - D - \/\/ 							  */
/*                       ==================							  */
/*																	  */
/*   	   Original code developed during 42.fr curriculum. 		  */
/* 			  Project renamed and refactored for clarity.			  */
/*             Created: 2016-10-20 by S𝔥𝔞⁽ᵃʰⁱ⁾d M𝔞𝔥𝔬𝔪𝔢ᵈ				  */
/*																	  */
/*   Copyright [2026] [S𝔥𝔞⁽ᵃʰⁱ⁾d M𝔞𝔥𝔬𝔪𝔢ᵈ] under Apache 2.0 License	  */

#include "b.h"

t_e			*i_global(t_e *new, int i)
{
	static t_e	*e;

	return (e + 0 * (!i && (e = new)));
}

int			tputs_putchar(int c)
{
	return (write(2, &c, 1));
}

int			clear(void)
{
	return (tputs(tgetstr("cl", 0), 1, tputs_putchar));
}

static int	i_i_putchar(int c)
{
	return (write(2, &c, 1));
}

int			non_canonical(struct termios *term, char *status)
{
	static int	n;

	if (!strcmp(status, "start"))
	{
		if ((n += (n < 2)) && n == 1)
		{
			tcgetattr(0 * tgetent(0, getenv("TERM")), term);
			tputs(tgetstr("ti", 0), 1, i_i_putchar);
			tputs(tgetstr("ho", 0), 1, i_i_putchar);
		}
		term->c_lflag &= ~(ECHO | ICANON);
		term->c_cc[VMIN] = 1;
		term->c_cc[VTIME] = 0;
		tcsetattr(0, 0, term);
		tputs(tgetstr("vi", 0), 1, i_i_putchar);
	}
	else if (!strcmp(status, "end"))
	{
		term->c_lflag |= (ICANON | ECHO);
		tputs(tgetstr("te", 0), 1, i_i_putchar);
		tputs(tgetstr("ve", 0), 1, i_i_putchar);
		tcsetattr(0, 0, term);
	}
	return (1);
}
