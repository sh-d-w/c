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

char	*i_itoa(int n)
{
	int		t[13];
	char	*s;

	t[11] = -1;
	s = (char *)i_memalloc(sizeof(char) * 11);
	t[12] = -1;
	if (n == 0)
		t[++t[12]] = 0;
	if (s && n < 0 && (s[++t[11]] = '-'))
		n = -n;
	while (n > 0 && ((t[++t[12]] = n % 10) >= 0))
		n /= 10;
	while (s && --t[12] + 1 > -1 && (s[++t[11]] = 48 + t[t[12] + 1]))
		s[t[11] + 1] = '\0';
	return (s);
}
