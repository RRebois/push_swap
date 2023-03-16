/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:18:10 by rrebois           #+#    #+#             */
/*   Updated: 2023/01/31 11:18:10 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static int	tot_move_same_sign(int a, int b)
{
	int	tot;

	tot = 0;
	if (a < 0 || b < 0)
	{
		a *= -1;
		b *= -1;
	}
	if (a > b)
		tot = a;
	else
		tot = b;
	return (tot);
}

static int	tot_move_diff_sign(int a, int b)
{
	int	tot;

	tot = 0;
	if (a < 0)
		tot = (a * -1) + b;
	else
		tot = a + (b * -1);
	return (tot);
}

void	check_tot_moves(t_lst **lstb)
{
	t_lst	*tmpb;

	tmpb = *lstb;
	while (tmpb != NULL)
	{
		if ((tmpb->count_a >= 0 && tmpb->count_b >= 0) || \
		(tmpb->count_a <= 0 && tmpb->count_b <= 0))
			tmpb->count_tot = tot_move_same_sign(tmpb->count_a, tmpb->count_b);
		else if ((tmpb->count_a > 0 && tmpb->count_b < 0) || \
		(tmpb->count_a < 0 && tmpb->count_b > 0))
			tmpb->count_tot = tot_move_diff_sign(tmpb->count_a, tmpb->count_b);
		tmpb = tmpb->next;
	}
}
