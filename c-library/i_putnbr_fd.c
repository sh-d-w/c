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

void	i_putnbr_fd(int n, int fd)
{
	long int	nb;

	if ((nb = n) < 0)
		i_putchar_fd('-', fd + 0 * (nb = nb * -1));
	if (nb >= 10)
		i_putnbr_fd(nb / 10, fd);
	i_putchar_fd(nb % 10 + 48, fd);
}

/*
void	i_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		i_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		i_putnbr_fd(n / 10, fd);
	i_putchar_fd(n % 10 + 48, fd);
}
*/