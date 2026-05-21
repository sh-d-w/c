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

t_list	*i_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*a[3];

	a[1] = f(lst);
	while (a[1] && (lst = lst->next))
	{
		a[0] = (t_list *)i_memalloc(sizeof(t_list));
		a[0] = f(lst);
		a[0]->next = a[1];
		a[1] = a[0];
	}
	a[0] = 0;
	while (a[1])
	{
		a[2] = a[1]->next;
		a[1]->next = a[0];
		a[0] = a[1];
		a[1] = a[2];
	}
	return (a[0]);
}
