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

int		i_print(t_e *e)
{
	int		y;

	y = 0;
	if (i_winsizecheck(e))
		while (++y < e->ac)
		{
			e->selected[y] && write(0, "\e[7m\e[35m", strlen("\e[7m\e[35m"));
			y == e->cursor && write(0, "\e[4m\e[33m", strlen("\e[4m\e[33m"));
			!e->deleted[y] && write(0, e->av[y], strlen(e->av[y]));
			y == e->cursor && write(0, "\e[0m\e[0m", strlen("\e[0m\e[0m"));
			e->selected[y] && write(0, "\e[0m\e[0m", strlen("\e[0m\e[0m"));
			!e->deleted[y] && write(0, "\n", 1);
		}
	return (0);
}

int		skip(t_e *e)
{
	int	b;

	b = 0;
	e->x = 0;
	e->y = 0;
	e->end = -1;
	e->home = -1;
	e->skip_u = e->cursor;
	e->skip_d = e->cursor;
	while (++e->y < e->ac && ((e->home == -1 && !e->deleted[e->y] &&
					(e->home = e->y)) || 1))
	{
		!e->deleted[e->y] && (e->x = e->y + 1);
		!e->deleted[e->y] && (e->end = e->y);
	}
	while (b < 2)
	{
		b == 1 && e->skip_d + 1 >= e->x && (e->skip_d = 0);
		b == 1 && (e->skip_d += e->skip_d < e->x - 1);
		b == 1 && !e->deleted[e->skip_d] && ++b;
		!b && e->skip_u - 1 == 0 && (e->skip_u = e->x);
		!b && (e->skip_u -= e->skip_u > 1);
		!b && !e->deleted[e->skip_u] && ++b;
	}
	return (0);
}

int		keyhook(t_e *e)
{
	int		b[8];

	skip(e);
	if (e->x < 1)
		return (0);
	i_print(e);
	bzero(b, 8);
	read(0, b, 8);
	if (b[0] == 27 && !b[1])
		exit(0 * non_canonical(&(e->term), "end") * clear());
	b[0] == 4283163 && !b[1] && (e->cursor = e->skip_u);
	b[0] == 4348699 && !b[1] && (e->cursor = e->skip_d);
	(b[0] == 127 || b[0] == 2117294875) && !b[1] &&
		(e->deleted[e->cursor] = !e->deleted[e->cursor]);
	(b[0] == 127 || b[0] == 2117294875) && !b[1] && (e->cursor = e->skip_d);
	b[0] == 32 && !b[1] && (e->selected[e->cursor] = !e->selected[e->cursor]);
	b[0] == 32 && !b[1] && (e->cursor = e->skip_d);
	b[0] == 4741915 && !b[1] && (e->cursor = e->home);
	b[0] == 4610843 && !b[1] && (e->cursor = e->end);
	return (!(b[0] == 10 && !b[1] && ++e->b));
}

int		init(t_e *e)
{
	e->x = -1;
	i_global(e, 0);
	while (++e->x < 32)
		signal(e->x, &i_catchsignal);
	e->y = -1;
	while (++e->y < e->ac && ((e->deleted[e->y] = 0) || 1))
		e->selected[e->y] = 0;
	i_resize();
	return (0);
}

int		main(int ac, char **av)
{
	t_e		e;
	int		selected[ac];
	int		deleted[ac];

	if (((e.ac = ac) || 1) && ac < 2)
		return (0);
	e.b = 0;
	e.av = av;
	e.cursor = 1;
	e.deleted = (int *)&deleted;
	e.selected = (int *)&selected;
	init(&e);
	non_canonical(&(e.term), "start");
	while (keyhook(&e))
		;
	non_canonical(&(e.term), "end");
	clear();
	e.y = 0;
	e.x = 0;
	while (++e.y < e.ac)
		!deleted[e.y] && selected[e.y] && ++e.x && write(1, e.av[e.y],
				strlen(e.av[e.y])) && write(1, " ", 1);
	return (0 * (e.x && write(1, "\n", 1)));
}
