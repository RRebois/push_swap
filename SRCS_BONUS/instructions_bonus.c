/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:37:52 by rrebois           #+#    #+#             */
/*   Updated: 2023/02/06 11:21:57 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/checker.h"

void	swap(t_lst **lst)
{
	t_lst	*tmp;
	t_lst	*buf;

	if (!(*lst))
		return ;
	if (check_len_lst(*lst) < 2)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	buf = *lst;
	buf = buf->next;
	tmp->next = buf;
	(*lst)->next = tmp;
}

void	rotate(t_lst **lst)
{
	t_lst	*tmp;
	t_lst	*last;

	if (*lst == NULL)
		return ;
	if (check_len_lst(*lst) < 2)
		return ;
	tmp = *lst;
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	*lst = (*lst)->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	rev_rotate(t_lst **lst)
{
	t_lst	*last;
	size_t	i;

	if (*lst == NULL)
		return ;
	i = check_len_lst(*lst);
	if (i < 2)
		return ;
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = *lst;
	while (i - 2 > 0)
	{
		*lst = (*lst)->next;
		i--;
	}
	(*lst)->next = NULL;
	*lst = last;
}

void	push(t_lst **from, t_lst **to)
{
	size_t	i;
	t_lst	*tmp;

	i = check_len_lst(*from);
	if (!(*from))
		return ;
	if (i < 1)
		return ;
	tmp = *from;
	if (i > 1)
		*from = (*from)->next;
	else if (i == 1)
		*from = NULL;
	if (to == NULL)
		*to = tmp;
	else
	{
		tmp->next = *to;
		*to = tmp;
	}
}
