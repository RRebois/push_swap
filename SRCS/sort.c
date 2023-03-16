/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:30:42 by rrebois           #+#    #+#             */
/*   Updated: 2023/01/28 17:30:42 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	sort_three_numbers(t_lst **lsta, t_lst **lstb)
{
	t_lst	*tmpa;

	tmpa = *lsta;
	while (tmpa != NULL)
	{
		tmpa->new_index = tmpa->index;
		tmpa = tmpa->next;
	}
	add_index(*lsta);
	sorting_three_algo(lsta, lstb);
	tmpa = *lsta;
	while (tmpa != NULL)
	{
		tmpa->index = tmpa->new_index;
		tmpa = tmpa->next;
	}
}

void	push_by_index(t_lst **lsta, t_lst **lstb)
{
	int	i;

	i = 100;
	while (check_len_lst(*lsta) > 3)
	{
		while ((int)check_len_lst(*lstb) != i)
		{
			if (check_len_lst(*lsta) == 3)
				break ;
			if ((*lsta)->index < i)
				push(lsta, lstb, 'b');
			else
				rotate(lsta, 'a');
		}
		i += 100;
	}
}

void	sort(t_lst **lsta, t_lst **lstb)
{
	add_index(*lsta);
	check_sorted(lsta, lstb);
	if (check_len_lst(*lsta) > 3)
		push_by_index(lsta, lstb);
	if (check_sorted(lsta, lstb) == 0)
		sort_three_numbers(lsta, lstb);
	while (check_len_lst(*lstb) > 0)
	{
		cost_b(lstb);
		search_a_index(lsta, lstb);
		check_tot_moves(lstb);
		check_min_tot_moves(lsta, lstb);
	}
	put_min_index_top(lsta);
	free_lst(*lsta);
}
