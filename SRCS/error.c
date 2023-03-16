/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:30:28 by rrebois           #+#    #+#             */
/*   Updated: 2023/03/16 16:54:49 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	error_duplicate(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data->len)
	{
		j = 0;
		while (j < data->len)
		{
			if (data->arr[i] == data->arr[j] && j != i)
			{
				ft_printf("Error\n");
				free(data->arr);
				exit (1);
			}
			j++;
		}
		i++;
	}
}
