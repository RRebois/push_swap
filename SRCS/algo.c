/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:00:51 by rrebois           #+#    #+#             */
/*   Updated: 2023/02/20 13:00:51 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	sorting_three_algo(t_lst **lsta, t_lst **lstb)
{
	t_lst	*tmpa;
	int		index;

	tmpa = *lsta;
	index = tmpa->index;
	tmpa = tmpa->next;
	if (index == 0 && tmpa->index == 2)
	{
		push(lsta, lstb, 'b');
		swap(lsta, 'a');
		push(lstb, lsta, 'a');
	}
	else if (index == 1 && tmpa->index == 2)
		rev_rotate(lsta, 'a');
	else if (index == 1 && tmpa->index == 0)
		swap(lsta, 'a');
	else if (index == 2 && tmpa->index == 0)
		rotate(lsta, 'a');
	else
	{
		swap(lsta, 'a');
		rev_rotate(lsta, 'a');
	}
}
