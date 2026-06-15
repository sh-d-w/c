/*                       __________________							  */
/*                        S |-| - D - \/\/ 							  */
/*                       ==================							  */
/*																	  */
/*   	   Original code developed during 42.fr curriculum. 		  */
/* 			  Project renamed and refactored for clarity.			  */
/*             Created: 2016-06-18 by S𝔥𝔞⁽ᵃʰⁱ⁾d M𝔞𝔥𝔬𝔪𝔢ᵈ				  */
/*																	  */
/*   Copyright [2026] [S𝔥𝔞⁽ᵃʰⁱ⁾d M𝔞𝔥𝔬𝔪𝔢ᵈ] under Apache 2.0 License	  */

#include "includes/i_ls.h"

void			i_execute(t_structdata *s, int x, int *b)
{
	if (b[3] == 1 && b[4] == 0)
		i_sort(s, x, 0, -1);
	if (b[3] == 0 && b[4] == 0)
		i_sort(s, x, 0, 1);
	if (b[3] == 1 && b[4] == 1)
		i_tsort(s, x, 0, -1);
	if (b[3] == 0 && b[4] == 1)
		i_tsort(s, x, 0, 1);
	x += 1;
	while (--x > -1)
	{
		if (b[0] == 1 && s[x].fn && s[x].fn[0])
			i_l(s[x].fn, s[x].ds);
		if (s[x].fn && s[x].fn[0])
			i_printf("%s\n", s[x].fn);
	}
}

t_structdata	*i_getinfo(t_structdata *t, char *dirname, int *b)
{
	struct dirent	*direntp;
	DIR				*fd;
	int				x[2];

	if (b[1] == 1 && (i_strcmp(dirname, ".") != 0))
		i_printf("\n%s\n", dirname);
	fd = opendir(dirname);
	x[0] = -1;
	while ((direntp = readdir(fd)) != 0)
	{
		if ((b[2] == 0 && direntp->d_name[0] != '.') || b[2] == 1)
		{
			t[++x[0]].fn = direntp->d_name;
			t[x[0]].str = direntp->d_name;
			i_additonalinfo(&t[x[0]], direntp->d_name, b);
		}
	}
	i_execute(t, x[0], b);
	closedir(fd);
	return (0);
}

int				i_init(char *dirname, int *b)
{
	struct dirent	*direntp;
	DIR				*fd;
	int				x[2];
	t_structdata	s[i_counters(dirname, x, b)];

	i_getinfo(s, dirname, b);
	if (b[1] == 1)
	{
		fd = opendir(dirname);
		x[0] = -1;
		while ((direntp = readdir(fd)) != 0)
			i_recdirs(dirname, direntp->d_name, b);
		closedir(fd);
	}
	return (0);
}

void			i_readdir(int ac, char **av, int *b)
{
	struct stat		st;

	if (b[6] == 1 && (b[6] = -1))
		i_init(".", b);
	while (++b[8] != ac && av[b[8]][0] == '-')
		;
	while (b[6] > 0 && b[8] < ac)
	{
		if (0 != access(av[b[8]], 0))
			i_printf("i_ls: %s: No such file or directory\n", av[b[8]]);
		else
		{
			lstat(av[b[8]], &st);
			if (!(S_ISREG(st.st_mode)) != 0 && av[b[8]][0] != '-')
				i_init(av[b[8]], b);
			else if ((S_ISREG(st.st_mode)) != 0 && b[9] != -1)
				i_printf("%s\n", av[b[8]]);
		}
		b[8]++;
	}
}

int				main(int argc, char **argv)
{
	int		b[10];

	i_conditions(b, 0, argc, argv);
	b[5] = argc;
	b[6] = i_countdir(argc, argv);
	b[8] = 0;
	i_readdir(argc, argv, b);
	return (0);
}
