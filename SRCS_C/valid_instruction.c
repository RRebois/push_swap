/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:21:21 by rrebois           #+#    #+#             */
/*   Updated: 2023/02/06 11:21:21 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/checker.h"

int	check_instruction_valid(char *s, t_lst **lsta, t_lst **lstb)
{
	if (ft_strncmp(s, "sa", ft_strlen(s)) == 0)
		swap(lsta);
	else if (ft_strncmp(s, "sb", ft_strlen(s)) == 0)
		swap(lstb);
	else if (ft_strncmp(s, "ss", ft_strlen(s)) == 0)
		swap_ab(lsta, lstb);
	else if (ft_strncmp(s, "ra", ft_strlen(s)) == 0)
		rotate(lsta);
	else if (ft_strncmp(s, "rb", ft_strlen(s)) == 0)
		rotate(lstb);
	else if (ft_strncmp(s, "rr", ft_strlen(s)) == 0)
		rotate_ab(lsta, lstb);
	else if (ft_strncmp(s, "rra", ft_strlen(s)) == 0)
		rev_rotate(lsta);
	else if (ft_strncmp(s, "rrb", ft_strlen(s)) == 0)
		rev_rotate(lstb);
	else if (ft_strncmp(s, "rrr", ft_strlen(s)) == 0)
		rev_rotate_ab(lsta, lstb);
	else if (ft_strncmp(s, "pa", ft_strlen(s)) == 0)
		push(lstb, lsta);
	else if (ft_strncmp(s, "pb", ft_strlen(s)) == 0)
		push(lsta, lstb);
	else
		return (1);
	return (0);
}

char	*get_instruction_line(char *s, t_lst **lsta, t_lst **lstb)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(sizeof(*ptr) * ft_strlen(s));
	if (ptr == NULL)
	{
		if (check_len_lst(*lsta) > 0)
			free_lst(*lsta);
		if (check_len_lst(*lstb) > 0)
			free_lst(*lstb);
		exit(1);
	}
	while (s[i] != '\0' && s[i] != '\n')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
