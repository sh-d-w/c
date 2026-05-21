/*                       __________________							  */
/*                        S |-| - D - \/\/ 							  */
/*                       ==================							  */
/*																	  */
/*   	   Original code developed during 42.fr curriculum. 		  */
/* 			  Project renamed and refactored for clarity.			  */
/*             Created: 2016-10-20 by S𝔥𝔞⁽ᵃʰⁱ⁾d M𝔞𝔥𝔬𝔪𝔢ᵈ				  */
/*																	  */
/*   Copyright [2026] [S𝔥𝔞⁽ᵃʰⁱ⁾d M𝔞𝔥𝔬𝔪𝔢ᵈ] under Apache 2.0 License	  */

#ifndef B_H
# define B_H
# include <term.h>
# include <termios.h>
# include <termcap.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/ioctl.h>

typedef struct		s_e
{
	struct termios	term;
	int				ac;
	int				cursor;
	char			**av;
	int				*deleted;
	int				*selected;
	int				skip_u;
	int				skip_d;
	int				x;
	int				y;
	int				w;
	int				h;
	int				home;
	int				end;
	int				b;
}					t_e;

int					clear(void);
int					tputs_putchar(int c);
void				i_catchsignal(int i);
t_e					*i_global(t_e *new, int i);
int					tputs_putchar(int c);
void				i_resize(void);
int					i_winsizecheck(t_e *e);
int					i_print(t_e *e);
int					skip(t_e *e);
int					non_canonical(struct termios *term, char *status);
#endif
