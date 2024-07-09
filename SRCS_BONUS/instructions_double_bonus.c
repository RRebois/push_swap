/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_double_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:33:08 by rrebois           #+#    #+#             */
/*   Updated: 2023/02/06 10:47:13 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/checker.h"

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
	swap(lsta);
	swap(lstb);
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
	rotate(lsta);
	rotate(lstb);
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
	rev_rotate(lsta);
	rev_rotate(lstb);
}
