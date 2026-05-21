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

char	*i_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len2;

	len2 = i_strlen(s2);
	if (*s2 == '\0')
		return ((char*)s1);
	if (!n)
		return (NULL);
	while (*s1 != '\0' && n >= len2 && (--n || 1))
	{
		if (!i_strncmp(s1, s2, len2))
			return ((char *)s1);
		s1++;
	}
	return (0);
}
