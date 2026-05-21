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

int		i_strcmp(const char *s1, const char *s2)
{
	return (strcmp(s1, s2));
}

/*
{
	int		v[3];

	v[0] = -1;
	while (s1[++v[0]] || s2[v[0]])
	{
		v[1] = s1[v[0]];
		v[2] = s2[v[0]];
		if (s1[v[0]] < 0)
			v[1] += 256;
		if (s2[v[0]] < 0)
			v[2] += 256;
		if (v[1] != v[2])
			return (v[1] - v[2]);
	}
	return (0);
}
*/
