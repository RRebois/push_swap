/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:27:43 by rrebois           #+#    #+#             */
/*   Updated: 2023/03/16 16:54:45 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/incs/libft.h"

typedef struct s_data
{
	int		*arr;
	size_t	len;
}				t_data;

typedef struct s_lst
{
	int				content;
	int				index;
	int				new_index;
	struct s_lst	*next;
	int				count_a;
	int				count_b;
	int				count_tot;
}				t_lst;

typedef struct s_check
{
	int	a;
	int	b;
	int	t;
}				t_check;

int		search_smaller_index(t_lst **lsta);
int		check_sorted(t_lst **lsta, t_lst **lstb);
size_t	check_len_lst(t_lst *lst);
size_t	ft_strlen_pp(char **s);
void	check_digits(char **av, int ac);
void	check_max_int(char **av, int ac);
void	ft_free_s(char **s);
void	extract_len(char **av, int ac, t_data *data);
void	extract_array(char **av, int ac, t_data *data);
void	start_lsta(t_data *data);
void	error_duplicate(t_data *data);
void	free_lst(t_lst *lst);
void	swap(t_lst **lst, char c);
void	swap_ab(t_lst **lsta, t_lst **lstb);
void	rotate(t_lst **lst, char c);
void	rotate_ab(t_lst **lsta, t_lst **lstb);
void	rev_rotate(t_lst **lst, char c);
void	rev_rotate_ab(t_lst **lsta, t_lst **lstb);
void	push(t_lst **from, t_lst **to, char c);
void	sort(t_lst **lsta, t_lst **lstb);
void	add_index(t_lst *lsta);
void	sort_three_numbers(t_lst **lsta, t_lst **lstb);
void	sorting_three_algo(t_lst **lsta, t_lst **lstb);
void	cost_b(t_lst **lstb);
void	search_a_index(t_lst **lsta, t_lst **lstb);
void	cost_a(t_lst **lsta, t_lst **lstb);
void	check_tot_moves(t_lst **lstb);
void	check_min_tot_moves(t_lst **lsta, t_lst **lstb);
void	move_both_lst(t_lst **lsta, t_lst **lstb, t_check *c);
void	move_single_lsta(t_lst **lsta, t_check *v);
void	move_single_lstb(t_lst **lstb, t_check *v);
void	put_min_index_top(t_lst **lsta);
void	push_by_index(t_lst **lsta, t_lst **lstb);

#endif
