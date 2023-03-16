/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:30:28 by rrebois           #+#    #+#             */
/*   Updated: 2023/02/06 10:47:02 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/checker.h"

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

void	error_no_num(char **s, t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i] != 0)
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			if (s[i][j] > 47 && s[i][j] < 58)
				j++;
			else if (s[i][j] == '-' && s[i][j + 1] != '\0' && \
			j + 1 < ft_strlen(s[i]) && (s[i][j + 1] > 47 && s[i][j + 1] < 58))
				j++;
			else
			{
				ft_printf("Error\n");
				free(data->arr);
				exit (1);
			}
		}
		i++;
	}
}
