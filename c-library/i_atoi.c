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

int		i_atoi(const char *str)
{
	int		v[3];

	v[0] = 0;
	v[2] = str[0] == '-' ? -1 : 1;
	v[1] = -1 + (str[0] == '-' || str[0] == '+');
	while (str && ((str[v[1] + 1] >= '\t' && str[v[1] + 1] <= '\r') ||
		str[v[1] + 1] == 32))
		v[1]++;
	while (str && str[++v[1]] && str[v[1]] >= '0' && str[v[1]] <= '9')
		v[0] = v[0] * 10 + (str[v[1]] - 48);
	return (v[0] * v[2]);
}
