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

size_t		i_strlcat(char *dst, const char *src, size_t size)
{
	size_t	div;
	size_t	length;

	length = 0;
	while (length < size && *dst && *(dst++))
		length++;
	if (!(div = size - length))
		return (length + i_strlen(src));
	while (*src && ++length)
	{
		if (div != 1 && (--div || 1))
			*(dst++) = *src;
		src++;
	}
	*dst = '\0';
	return (length);
}

/*
size_t	i_strlcat(char *dst, const char *src, size_t size)
{
	int		v[2];
	char	*s;

	*(v + 0) = -1;
	*(v + 1) = -1;
	s = (char *)i_memalloc(size);
	while (*(dst + (++v[0])))
		*(s + v[0]) = *(dst + v[0]);
	while ((++v[0] <= (int)size) && *(src + (++v[1])))
		*(s + v[0] - 1) = *(src + v[1]);
	*(s + v[0]) = '\0';
	dst = s;
	return ((size_t)s);
}
*/