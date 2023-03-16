/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:31:08 by rrebois           #+#    #+#             */
/*   Updated: 2023/02/01 16:10:24 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	free_lst(t_lst *lst)
{
	t_lst	*tmp;

	tmp = lst;
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
