/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:38:59 by rrebois           #+#    #+#             */
/*   Updated: 2023/01/28 18:38:59 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/checker.h"

int	check_sorted(t_lst **lsta, t_lst **lstb)
{
	t_lst	*tmpa;
	int		previous_value;
	size_t	count;

	count = 0;
	tmpa = *lsta;
	previous_value = tmpa->index;
	while (tmpa != NULL)
	{
		if (previous_value < tmpa->index)
		{
			count++;
			previous_value = tmpa->index;
		}
		tmpa = tmpa->next;
	}
	if (count == check_len_lst(*lsta) - 1 && check_len_lst(*lstb) == 0)
	{
		free_lst(*lsta);
		ft_printf("OK\n");
		exit (1);
	}
	if (count == check_len_lst(*lsta) - 1 && check_len_lst(*lstb) != 0)
		return (1);
	return (0);
}
