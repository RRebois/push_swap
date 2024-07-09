/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:17:46 by rrebois           #+#    #+#             */
/*   Updated: 2023/02/02 19:17:46 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/checker.h"

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
