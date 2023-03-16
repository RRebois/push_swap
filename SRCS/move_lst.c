/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:44:03 by rrebois           #+#    #+#             */
/*   Updated: 2023/02/01 09:44:03 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	put_min_index_top(t_lst **lsta)
{
	t_lst	*tmpa;
	int		moves;

	tmpa = *lsta;
	if (tmpa->index == 0)
		return ;
	while (tmpa->index != 0)
	{
		moves++;
		tmpa = tmpa->next;
	}
	if (moves > (int)check_len_lst(*lsta) / 2 - 1)
		moves = moves - (int)check_len_lst(*lsta);
	while (moves > 0)
	{
		rotate(lsta, 'a');
		moves--;
	}
	while (moves < 0)
	{
		rev_rotate(lsta, 'a');
		moves++;
	}
}

void	move_single_lsta(t_lst **lsta, t_check *v)
{
	while (v->a > 0)
	{
		rotate(lsta, 'a');
		v->a--;
		v->t--;
	}
	while (v->a < 0)
	{
		rev_rotate(lsta, 'a');
		v->a++;
		v->t--;
	}
}

void	move_single_lstb(t_lst **lstb, t_check *v)
{
	while (v->b > 0)
	{
		rotate(lstb, 'b');
		v->b--;
		v->t--;
	}
	while (v->b < 0)
	{
		rev_rotate(lstb, 'b');
		v->b++;
		v->t--;
	}
}

void	move_both_lst(t_lst **lsta, t_lst **lstb, t_check *c)
{
	while ((c->a > 0 && c->b > 0))
	{
		rotate_ab(lsta, lstb);
		c->a--;
		c->b--;
		c->t--;
	}
	while ((c->a < 0 && c->b < 0))
	{
		rev_rotate_ab(lsta, lstb);
		c->a++;
		c->b++;
		c->t--;
	}
	if (c->a != 0)
		move_single_lsta(lsta, c);
	if (c->b != 0)
		move_single_lstb(lstb, c);
	if (c->t == 0)
		push(lstb, lsta, 'a');
}

void	check_min_tot_moves(t_lst **lsta, t_lst **lstb)
{
	int		min_tot;
	t_check	values;
	t_lst	*tmpb;

	tmpb = *lstb;
	min_tot = tmpb->count_tot;
	while (tmpb != NULL)
	{
		if (tmpb->count_tot < min_tot)
			min_tot = tmpb->count_tot;
		tmpb = tmpb->next;
	}
	tmpb = *lstb;
	while (tmpb != NULL)
	{
		if (min_tot == tmpb->count_tot)
		{
			values.a = tmpb->count_a;
			values.b = tmpb->count_b;
			values.t = tmpb->count_tot;
			break ;
		}
		tmpb = tmpb->next;
	}
	move_both_lst(lsta, lstb, &values);
}
