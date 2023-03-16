/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_double.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:33:08 by rrebois           #+#    #+#             */
/*   Updated: 2023/01/30 20:29:06 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	swap_ab(t_lst **lsta, t_lst **lstb)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*lsta != NULL)
		i = check_len_lst(*lsta);
	if (*lstb != NULL)
		j = check_len_lst(*lstb);
	if (i < 2 && j < 2)
		return ;
	swap(lsta, 's');
	swap(lstb, 's');
	ft_printf("ss\n");
}

void	rotate_ab(t_lst **lsta, t_lst **lstb)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (lsta != NULL)
		i = check_len_lst(*lsta);
	if (lstb != NULL)
		j = check_len_lst(*lsta);
	if (i < 2 && j < 2)
		return ;
	rotate(lsta, 's');
	rotate(lstb, 's');
	ft_printf("rr\n");
}

void	rev_rotate_ab(t_lst **lsta, t_lst **lstb)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (lsta != NULL)
		i = check_len_lst(*lsta);
	if (lstb != NULL)
		j = check_len_lst(*lsta);
	if (i < 2 && j < 2)
		return ;
	rev_rotate(lsta, 'r');
	rev_rotate(lstb, 'r');
	ft_printf("rrr\n");
}
