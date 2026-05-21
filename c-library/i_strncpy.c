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

char	*i_strncpy(char *s1, const char *s2, size_t n)
{
	int	i;

	i = -1;
	while (n > 0 && s2[++i] != '\0')
	{
		s1[i] = s2[i];
		n--;
	}
	while (n--)
	{
		s1[i] = '\0';
		i++;
	}
	return (s1);
}
