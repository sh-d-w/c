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

t_structdata	*i_tsort(t_structdata *s, int n, int x, int c)
{
	t_structdata	temp;
	int				j;
	int				i;
	int				k;

	i = 0;
	j = -1;
	while (++j < n - i || (++i < n && (j = 0) >= 0))
	{
		x = i_strcmp(s[j].time, s[j + 1].time);
		k = i_strcmp(s[j].str, s[j + 1].str);
		if (((x == 0 && k < 0 && c == 1) ||\
					(x == 0 && k > 0 && c == -1)) ||
				((x > 0 && c == 1) || (x < 0 && c == -1)))
		{
			temp = s[j];
			s[j] = s[j + 1];
			s[j + 1] = temp;
		}
	}
	return (s);
}

t_structdata	*i_sort(t_structdata *s, int n, int x, int c)
{
	t_structdata	temp;
	int				j;
	int				i;

	i = 0;
	j = -1;
	while (++j < n - i || (++i < n && (j = 0) >= 0))
	{
		x = i_strcmp(s[j].str, s[j + 1].str);
		if ((x < 0 && c == 1) || (x > 0 && c == -1))
		{
			temp = s[j];
			s[j] = s[j + 1];
			s[j + 1] = temp;
		}
	}
	return (s);
}

int				i_getdate(t_structdata **s, struct stat st)
{
	time_t			t;
	char			*str;

	t = st.st_mtime;
	str = ctime(&t);
	str[i_strlen(str) - 9] = '\0';
	(**s).ds[0] = '\0';
	i_strcat(i_strcat((**s).ds, &str[4]), " ");
	return (0);
}

void			i_additonalinfo(t_structdata *s, char *filename, int *b)
{
	struct stat		st;

	lstat(filename, &st);
	if (b[0] == 1 || b[4] == 1)
		i_getdate(&s, st);
	if (b[4] == 1)
		i_timesortprep(&s, (*s).ds);
}
