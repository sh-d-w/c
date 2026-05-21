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

char	*i_strstr(const char *s1, const char *s2)
{
	int		cmp;
	int		cmp2;

	cmp2 = 0;
	cmp = -1;
	if (!s2[0])
		return ((char *)(s1));
	while (s1[++cmp])
	{
		if (s1[cmp] == s2[cmp2])
			cmp2++;
		else
		{
			cmp -= cmp2;
			cmp2 = 0;
		}
		if (!s2[cmp2])
			return ((char *)(s1 + cmp - cmp2 + 1));
	}
	return (NULL);
}
/*
char	*i_strstr(const char *big, const char *little)
{
	int		x;
	int		v[2];

	v[0] = (int)i_strlen(little);
	v[1] = -1;
	if (v[0] <= (int)i_strlen(big))
		while (big[++v[1]] && ((x = -1) || v[0] == v[0]))
		{
			while (little[++x] && big[v[1] + x] && little[x] == big[v[1] + x])
				;
			if (x == v[0])
				return ((char *)&big[v[1]]);
		}
	return ((char *)&big[0]);
}
*/