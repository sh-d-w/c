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

int		i_isdir(char *s)
{
	struct stat		st;

	if (0 != access(s, 0))
		return (0);
	else
	{
		lstat(s, &st);
		if (!(S_ISREG(st.st_mode)) != 0)
			return (1);
	}
	return (0);
}

int		i_counters(char *s, int *x, int *b)
{
	struct dirent	*direntp;
	DIR				*fd;

	x[1] = -2;
	x[0] = 0;
	fd = opendir(s);
	while ((direntp = readdir(fd)) != 0)
	{
		if ((b[2] == 0 && direntp->d_name[0] != '.') || b[2] == 1)
			x[0] += 1;
		x[1] += i_isdir(direntp->d_name);
	}
	closedir(fd);
	return (x[0]);
}

int		i_countdir(int ac, char **av)
{
	int		k[2];

	k[0] = 0;
	k[1] = 1;
	while (++k[0] != ac)
		if (av[k[0]][0] != '-')
			k[1] += 1;
	return (k[1]);
}

int		*i_conditions(int b[10], int k, int ac, char **av)
{
	int		j;

	b[0] = 0;
	while (++b[0] < 10)
		b[b[0]] = 0;
	b[0] = 0;
	b[9] = 0;
	while (++k != ac && av[k][0] == '-' && (j = -1))
		while (av[k][++j])
		{
			b[0] = 1 * (av[k][j] == 'l') + b[0] * (av[k][j] != 'l');
			b[1] = 1 * (av[k][j] == 'R') + b[1] * (av[k][j] != 'R');
			b[2] = 1 * (av[k][j] == 'a') + b[2] * (av[k][j] != 'a');
			b[3] = 1 * (av[k][j] == 'r') + b[3] * (av[k][j] != 'r');
			b[4] = 1 * (av[k][j] == 't') + b[4] * (av[k][j] != 't');
		}
	return (b);
}

int		i_recdirs(char *dirname, char *d_name, int *b)
{
	char	t[i_strlen(dirname) + i_strlen(d_name) + 1];

	t[0] = '\0';
	i_strcat(t, dirname);
	if (i_strcmp(".", d_name) != 0 && \
			i_strcmp("..", d_name) != 0)
		if ((d_name[0] == '.' && (b[2] == 1)) || \
				d_name[0] != '.')
			if (i_isdir(i_strcat(i_strcat(t, "/"), d_name)))
				i_init(t, b);
	return (0);
}
