/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:42:45 by rrebois           #+#    #+#             */
/*   Updated: 2023/01/30 20:42:45 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	cost_b(t_lst **lstb)
{
	t_lst	*tmp;
	size_t	i;

	tmp = *lstb;
	i = 0;
	while (tmp != NULL)
	{
		if (i <= (check_len_lst(*lstb) / 2))
			tmp->count_b = i;
		else
			tmp->count_b = i - (check_len_lst(*lstb));
		i++;
		tmp = tmp->next;
	}
}

int	search_smaller_index(t_lst **lsta)
{
	int		smallest_index;
	t_lst	*tmpa;

	tmpa = *lsta;
	smallest_index = tmpa->index;
	while (tmpa != NULL)
	{
		if (tmpa->index < smallest_index)
			smallest_index = tmpa->index;
		tmpa = tmpa->next;
	}
	return (smallest_index);
}

void	cost_a(t_lst **lsta, t_lst **lstb)
{
	t_lst	*tmpa;
	t_lst	*tmpb;
	int		moves;

	tmpb = *lstb;
	while (tmpb != NULL)
	{
		if (tmpb->count_a == INT_MAX)
			tmpb->count_a = search_smaller_index(lsta);
		moves = 0;
		tmpa = *lsta;
		while (tmpa != NULL)
		{
			if (tmpa->index != tmpb->count_a)
				moves++;
			else
				break ;
			tmpa = tmpa->next;
		}
		if (moves <= (int)check_len_lst(*lsta) / 2)
			tmpb->count_a = moves;
		else
			tmpb->count_a = moves - (int)check_len_lst(*lsta);
		tmpb = tmpb->next;
	}
}

void	search_a_index(t_lst **lsta, t_lst **lstb)
{
	t_lst	*tmpa;
	t_lst	*tmpb;
	int		index;

	tmpb = *lstb;
	while (tmpb != NULL)
	{
		index = INT_MAX;
		tmpa = *lsta;
		while (tmpa != NULL)
		{
			if (tmpa->index > tmpb->index && tmpa->index < index)
				index = tmpa->index;
			tmpa = tmpa->next;
		}
		tmpb->count_a = index;
		tmpb = tmpb->next;
	}
	cost_a(lsta, lstb);
}
