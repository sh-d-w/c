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

void		i_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

/*
void	i_lstadd(t_list **alst, t_list *new)
{
	t_list	*t;

	t = (t_list *)&alst;
	t->next = new;
	t->content = new->content;
	t->content_size = new->content_size;
	t->next = new->next;
}
*/