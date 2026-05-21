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

void	*i_memchr(const void *s1, int c, size_t n)
{
	char		t;
	char		*tmp;

	t = (unsigned char)c;
	tmp = (char *)s1;
	while (n--)
	{
		if (*tmp == t)
			return (tmp);
		tmp++;
	}
	return (NULL);
}
