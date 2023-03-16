/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:03:54 by rrebois           #+#    #+#             */
/*   Updated: 2023/02/20 13:04:04 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;

	data.len = 0;
	if (ac < 2)
		return (1);
	extract_len(av, ac, &data);
	error_duplicate(&data);
	start_lsta(&data);
	return (0);
}
