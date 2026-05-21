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

int				ft_winsizecheck(t_e *e)
{
	struct winsize		win;
	int					t;
	int					y;

	t = 0;
	y = 0;
	clear();
	e->x = 0;
	e->y = 0;
	ioctl(0, TIOCGWINSZ, &win);
	e->w = win.ws_col;
	e->h = win.ws_row;
	while (++y < e->ac)
	{
		!e->deleted[y] && ++e->y;
		!e->deleted[y] && (t = strlen(e->av[y]));
		!e->deleted[y] && t >= e->x && (e->x = t);
	}
	if (e->x >= e->w || e->y >= e->h)
		return (0 * write(0, "Window is too small.\n", 21));
	return (1);
}

void			ft_resize(void)
{
	t_e				*e;
	struct winsize	win;

	e = ft_global((t_e *)0, 1);
	ioctl(0, TIOCGWINSZ, &win);
	e->w = win.ws_col;
	e->h = win.ws_row;
	skip(e);
	ft_print(e);
}

static void		ft_sigstp(void)
{
	t_e		*e;
	char	v[2];

	e = ft_global((t_e *)0, 1);
	signal(SIGTSTP, SIG_DFL);
	non_canonical(&(e->term), "end");
	v[1] = 0;
	v[0] = e->term.c_cc[VSUSP];
	clear();
	tcsetattr(0, 0, &(e->term));
	ioctl(0, TIOCSTI, v);
}

static void		ft_sigcont(void)
{
	t_e		*e;

	e = ft_global((t_e *)0, 1);
	non_canonical(&(e->term), "start");
	signal(SIGTSTP, ft_catchsignal);
	ft_resize();
}

void			ft_catchsignal(int i)
{
	t_e		*e;

	e = 0;
	if (i == SIGCONT)
		ft_sigcont();
	else if (i == SIGTSTP)
		ft_sigstp();
	else if (i == SIGWINCH)
		ft_resize();
	else
	{
		e = ft_global(e, 1);
		exit(0 * non_canonical(&(e->term), "end"));
	}
}
