/*                       __________________							  */
/*                        S |-| - D - \/\/ 							  */
/*                       ==================							  */
/*																	  */
/*   	   Original code developed during 42.fr curriculum. 		  */
/* 			  Project renamed and refactored for clarity.			  */
/*             Created: 2016-11-18 by S𝔥𝔞⁽ᵃʰⁱ⁾d M𝔞𝔥𝔬𝔪𝔢ᵈ				  */
/*																	  */
/*   Copyright [2026] [S𝔥𝔞⁽ᵃʰⁱ⁾d M𝔞𝔥𝔬𝔪𝔢ᵈ] under Apache 2.0 License	  */

#include "clibrary.h"

char		*i_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (i_strlen(s) + 1));
	if (!str)
		return (0);
	while (s[i] == '\n' || s[i] == '\t' || s[i] == 32)
		i++;
	while (s[i] != '\0')
		str[++j - 1] = s[++i - 1];
	--j;
	while (str[j] == '\n' || str[j] == '\t' || str[j] == 32)
		j--;
	str[j + 1] = '\0';
	return (str);
}
/*
char	*i_strtrim(char const *s)
{
	int		w;
	int		x;
	int		y;
	char	*t;

	x = 0;
	w = -1;
	y = 0;
	y = i_strlen(s);
	t = (char *)i_memalloc(i_strlen(s));
	while (s[x] && (s[x] == ' ' || s[x] == '\t' || s[x] == '\n'))
		x++;
	while (s[y - 1] == ' ' || s[y - 1] == '\t' || s[y - 1] == '\n')
		t[y--] = '\0';
	while (s[++x - 1] && x - 1 <= y)
		t[++w] = s[x - 1];
	return (t);
}
*/