/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:31:08 by rrebois           #+#    #+#             */
/*   Updated: 2023/02/20 10:15:42 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/checker.h"

void	free_all(t_lst **lsta, t_lst **lstb, char *ptr, char *s)
{
	free_lst(*lsta);
	free_lst(*lstb);
	free(ptr);
	free(s);
	ft_printf("Error\n");
	exit(1);
}

void	free_lst(t_lst *lst)
{
	t_lst	*tmp;

	tmp = lst;
	if (check_len_lst(lst) < 1)
		return ;
	while (lst->next != NULL)
	{
		lst = lst->next;
		free(tmp);
		tmp = lst;
	}
	free(tmp);
}

size_t	ft_strlen_pp(char **s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

void	ft_free_s(char **s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
}

size_t	check_len_lst(t_lst *lst)
{
	size_t	i;
	t_lst	*tmp;

	i = 0;
	tmp = NULL;
	if (lst)
		tmp = lst;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
