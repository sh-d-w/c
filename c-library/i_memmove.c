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

void	*i_memmove(void *s1, const void *s2, size_t n)
{
	char		*ss1;
	const char	*ss2;
	char		tmp[n];
	size_t		i;

	i = 0;
	ss1 = (char *)s1;
	ss2 = (const char *)s2;
	while (i < n && ((tmp[i] = ss2[i]) || 1))
		i++;
	i = 0;
	while (i < n && ((ss1[i] = tmp[i]) || 1))
		i++;
	return (s1);
}