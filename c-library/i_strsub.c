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

char	*i_strsub(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		i;

	i = -1;
	if (s == NULL || (ptr = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (++i < len)
		ptr[i] = s[++start - 1];
	return (ptr + 0 * (ptr[i] = '\0'));
}

/*
char	*i_strsub(char const *s, unsigned int start, size_t len)
{
	char	*t;
	size_t	y;

	y = 0;
	t = (char *)i_memalloc(sizeof(char) * ((len - ((size_t)start)) + 1));
	while ((*(s + (++start) - 1) || *(s + start - 1))\
			&& start - 1 <= (unsigned int)len)
		*(t + y++) = *(s + start - 1);
	return (t);
}
*/