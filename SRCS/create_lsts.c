/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lsts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:36:21 by rrebois           #+#    #+#             */
/*   Updated: 2023/02/20 12:15:00 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	add_index(t_lst *lsta)
{
	t_lst	*tmp;
	t_lst	*buf;
	int		counter;

	tmp = lsta;
	while (tmp != NULL)
	{
		buf = lsta;
		counter = 0;
		while (buf != NULL)
		{
			if (tmp->content > buf->content)
				counter++;
			buf = buf->next;
		}
		tmp->index = counter;
		tmp = tmp->next;
	}
}

static t_lst	*add_new_node(t_data *data, size_t i)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->content = data->arr[i];
	new->next = NULL;
	new->count_a = 0;
	return (new);
}

static void	add_node_back(t_lst *lsta, t_lst *new)
{
	t_lst	*last;

	last = lsta;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

void	start_lsta(t_data *data)
{
	t_lst	*lsta;
	t_lst	*lstb;
	size_t	i;

	i = 0;
	lsta = NULL;
	lstb = NULL;
	if (lsta == NULL)
		lsta = add_new_node(data, i);
	while (++i < data->len)
		add_node_back(lsta, add_new_node(data, i));
	free(data->arr);
	if (data->len < 2)
	{
		free_lst(lsta);
		exit (1);
	}
	sort(&lsta, &lstb);
}
