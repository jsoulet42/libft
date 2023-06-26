/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:18:35 by jsoulet           #+#    #+#             */
/*   Updated: 2023/02/20 15:18:42 by jsoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*lstf;

	if (!lst)
		return (0);
	new = ft_lstnew((*f)(lst->content));
	if (!new)
		return (NULL);
	lstf = new;
	lst = lst->next;
	while (lst)
	{
		new->next = ft_lstnew((*f)(lst->content));
		if (!new->content)
		{
			ft_lstclear(&lstf, (*del));
			return (0);
		}
		new = new->next;
		lst = lst->next;
	}
	return (lstf);
}
	/*on applique f au premier element de lst que l'on copie
	dans un nouvel élément stocké dans NEW*/
	/*on crée lstf qui pointe ver l'adresse du premier élément de NEW
	pour en sauvgarder l'adresse*/
	/*on passe on prochain élément de lst*/
		/*on passe au prochain élément de new ou on stock l'élément(f) de lst*/
		/* si ca c'est mal passé on clear lstf et return 0*/
		/*on passe au prochain élément de new et lst avant de recommencer la boucle*/