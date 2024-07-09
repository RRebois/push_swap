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

#include "../incs_bonus/checker.h"

void	sort(t_lst **lsta, t_lst **lstb)
{
	char	*s;
	char	*ptr;

	add_index(*lsta);
	s = get_next_line(0);
	while (s != NULL)
	{
		ptr = get_instruction_line(s, lsta, lstb);
		if (check_instruction_valid(ptr, lsta, lstb) == 1)
			free_all(lsta, lstb, ptr, s);
		free(s);
		free(ptr);
		s = get_next_line(0);
	}
	if (s != NULL)
		free(s);
	if (check_sorted(lsta, lstb) == 0 || check_sorted(lsta, lstb) == 1)
		ft_printf("KO\n");
}
