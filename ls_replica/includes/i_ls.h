/*                       __________________							  */
/*                        S |-| - D - \/\/ 							  */
/*                       ==================							  */
/*																	  */
/*   	   Original code developed during 42.fr curriculum. 		  */
/* 			  Project renamed and refactored for clarity.			  */
/*             Created: 2016-06-18 by S𝔥𝔞⁽ᵃʰⁱ⁾d M𝔞𝔥𝔬𝔪𝔢ᵈ				  */
/*																	  */
/*   Copyright [2026] [S𝔥𝔞⁽ᵃʰⁱ⁾d M𝔞𝔥𝔬𝔪𝔢ᵈ] under Apache 2.0 License	  */


#ifndef i_LS_H
# define i_LS_H
# include "clibrary.h"
# include <stdio.h>
# include <dirent.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <langinfo.h>

typedef struct
{
	char		*fn;
	char		ds[13];
	char		time[13];
	char		*str;
}				t_structdata;

int				i_printf(const char *s, ...);
int				i_getuser(struct stat st);
int				i_takingtimeandspace(t_structdata ***v, \
		char *s, char *u, char *t);
int				i_timesortprep(t_structdata **v, char *t);
int				i_l(char *fn, char *ds);
int				i_getdate(t_structdata **s, struct stat st);
int				i_isdir(char *s);
int				i_counters(char *s, int *x, int *b);
int				i_countdir(int ac, char **av);
int				*i_conditions(int b[10], int k, int ac, char **av);
int				i_recdirs(char *dirname, char *d_name, int *b);
int				i_init(char *dirname, int *b);
char			*i_c(long long unsigned int n, int b, char c, char d);
void			i_chmod(char *chmod);
void			i_execute(t_structdata *s, int x, int *b);
void			i_readdir(int ac, char **av, int *b);
void			i_additonalinfo(t_structdata *s, char *filename, int *b);
t_structdata	*i_sort(t_structdata *s, int n, int x, int c);
t_structdata	*i_tsort(t_structdata *s, int n, int x, int c);
t_structdata	*i_getinfo(t_structdata *t, char *dirname, int *b);

#endif
