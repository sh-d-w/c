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

void	i_chmod(char *chmod)
{
	while (*(++chmod - 1))
	{
		if (*(chmod - 1) == '7')
			i_printf("rwx");
		if (*(chmod - 1) == '6')
			i_printf("rw-");
		if (*(chmod - 1) == '5')
			i_printf("r-x");
		if (*(chmod - 1) == '4')
			i_printf("r--");
		if (*(chmod - 1) == '3')
			i_printf("-wx");
		if (*(chmod - 1) == '2')
			i_printf("-w-");
		if (*(chmod - 1) == '1')
			i_printf("--x");
		if (*(chmod - 1) == '0')
			i_printf("---");
	}
	i_printf("  ");
}

int		i_getuser(struct stat st)
{
	struct passwd	*pwd;
	struct group	*grp;

	if ((pwd = getpwuid(st.st_uid)) != NULL)
		i_printf("%s%s", pwd->pw_name, "  ");
	else
		i_printf("%s%s", i_itoa(st.st_uid), "  ");
	if ((grp = getgrgid(st.st_gid)) != NULL)
		i_printf("%s", grp->gr_name);
	else
		i_printf("%s", i_itoa(st.st_gid));
	return (0);
}

int		i_takingtimeandspace(t_structdata ***v, char *s, char *u, char *t)
{
	if (i_strcmp(s, "Jul") == 0)
		i_strcat(i_strcat(u, "6"), &t[6]);
	if (i_strcmp(s, "Aug") == 0)
		i_strcat(i_strcat(u, "7"), &t[6]);
	if (i_strcmp(s, "Sep") == 0)
		i_strcat(i_strcat(u, "8"), &t[6]);
	if (i_strcmp(s, "Oct") == 0)
		i_strcat(i_strcat(u, "9"), &t[6]);
	if (i_strcmp(s, "Nov") == 0)
		i_strcat(i_strcat(u, "a"), &t[6]);
	if (i_strcmp(s, "Dec") == 0)
		i_strcat(i_strcat(u, "b"), &t[6]);
	u[1] = (i_atoi(&t[3]) + 64);
	(***v).time[0] = '\0';
	i_strcat((***v).time, u);
	return (0);
}

int		i_timesortprep(t_structdata **v, char *t)
{
	char	s[i_strlen(t)];
	char	u[i_strlen(&t[2]) + 1];

	u[0] = '\0';
	s[0] = '\0';
	i_strcat(s, t);
	s[3] = '\0';
	if (i_strcmp(s, "Jan") == 0)
		i_strcat(i_strcat(u, "0"), &t[6]);
	if (i_strcmp(s, "Feb") == 0)
		i_strcat(i_strcat(u, "1"), &t[6]);
	if (i_strcmp(s, "Mar") == 0)
		i_strcat(i_strcat(u, "2"), &t[6]);
	if (i_strcmp(s, "Apr") == 0)
		i_strcat(i_strcat(u, "3"), &t[6]);
	if (i_strcmp(s, "May") == 0)
		i_strcat(i_strcat(u, "4"), &t[6]);
	if (i_strcmp(s, "Jun") == 0)
		i_strcat(i_strcat(u, "5"), &t[6]);
	i_takingtimeandspace(&v, s, u, t);
	return (0);
}

int		i_l(char *fn, char *ds)
{
	struct stat		st;

	lstat(fn, &st);
	i_chmod(i_c(st.st_mode & (S_IRWXO | S_IRWXG | S_IRWXU), 8, 'c', 3));
	i_printf("% 1d ", st.st_nlink);
	i_getuser(st);
	i_printf(" % 9d %s", st.st_size, ds);
	return (0);
}
