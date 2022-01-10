/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:13:31 by salimon           #+#    #+#             */
/*   Updated: 2021/01/17 15:12:15 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*f_lst;

	f_lst = ft_lstnew((*f)(lst->content));
	if (!f_lst)
	{
		ft_lstclear(&lst, (*del));
		return (NULL);
	}
	new_lst = f_lst;
	lst = lst->next;
	while (lst)
	{
		f_lst = ft_lstnew((*f)(lst->content));
		if (!f_lst)
		{
			ft_lstclear(&lst, (*del));
			ft_lstclear(&new_lst, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new_lst, f_lst);
		lst = lst->next;
	}
	return (new_lst);
}
