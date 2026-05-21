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

char	*i_strcat(char *s1, const char *s2)
{
	return (strcat(s1, s2));
}
/*
{
	int		v[3];
	char	*s3;

	s3 = (char *)i_memalloc(sizeof(i_strlen(s2) + i_strlen(s1)));
	v[0] = -1;
	v[1] = -1;
	v[2] = -1;
	while (s1[++v[0]])
		s3[v[0]] = s1[v[0]];
	while (s2[++v[1]] && (s3[v[0]] = '\0'))
		s3[++v[0] - 1] = s2[v[1]];
	while (s3[++v[2]] || s3[v[2] - 1])
		s1[v[2]] = s3[v[2]];
	return (s3);
}
*/
