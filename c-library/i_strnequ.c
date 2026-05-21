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

int		i_strnequ(char const *s1, char const *s2, size_t n)
{
	int		x[2];

	x[1] = 0;
	x[0] = -1;
	while (s1[++x[0]] && s2[x[0]] && (x[0] < ((int)n)) && x[1] == 0)
		if (s1[x[0]] != s2[x[0]])
			x[1]++;
	if (x[1] == 0)
		return (1);
	return (0);
}
