/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:30:24 by rrebois           #+#    #+#             */
/*   Updated: 2023/01/28 17:30:24 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	extract_array(char **av, int ac, t_data *data)
{
	char	**s;
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	data->arr = (int *)malloc(sizeof(int) * data->len);
	if (data->arr == NULL)
		return ;
	while (i < ac)
	{
		j = 0;
		s = ft_split(av[i], ' ');
		while (s[j] != 0)
		{
			data->arr[k] = ft_atoi(s[j]);
			k++;
			j++;
		}
		ft_free_s(s);
		i++;
	}
}

void	check_digits(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (ft_isdigit(av[i][j]) == 0)
			{
				ft_printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_max_int(char **av, int ac)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		ft_atoi(av[i]);
		i++;
	}
}

void	extract_len(char **av, int ac, t_data *data)
{
	char	**s;
	int		i;

	check_digits(av, ac);
	check_max_int(av, ac);
	i = 1;
	while (i < ac)
	{
		s = ft_split(av[i], ' ');
		data->len += ft_strlen_pp(s);
		ft_free_s(s);
		i++;
	}
	if (data->len == 0)
	{
		ft_printf("Error\n");
		exit (1);
	}
	extract_array(av, ac, data);
}
