/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrebois <rrebois@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:18:50 by rrebois           #+#    #+#             */
/*   Updated: 2023/02/02 19:18:50 by rrebois          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

int		check_sorted(t_lst **lsta, t_lst **lstb);
int		check_instruction_valid(char *s, t_lst **lsta, t_lst **lstb);
size_t	check_len_lst(t_lst *lst);
size_t	ft_strlen_pp(char **s);
void	check_digits(char **av, int ac);
void	check_max_int(char **av, int ac);
void	ft_free_s(char **s);
void	error_no_num(char **s, t_data *data);
void	extract_len(char **av, int ac, t_data *data);
void	extract_array(char **av, int ac, t_data *data);
void	start_lsta(t_data *data);
void	error_duplicate(t_data *data);
void	free_lst(t_lst *lst);
void	swap(t_lst **lst);
void	swap_ab(t_lst **lsta, t_lst **lstb);
void	rotate(t_lst **lst);
void	rotate_ab(t_lst **lsta, t_lst **lstb);
void	rev_rotate(t_lst **lst);
void	rev_rotate_ab(t_lst **lsta, t_lst **lstb);
void	push(t_lst **from, t_lst **to);
void	sort(t_lst **lsta, t_lst **lstb);
void	add_index(t_lst *lsta);
void	free_all(t_lst **lsta, t_lst **lstb, char *ptr, char *s);
char	*get_instruction_line(char *s, t_lst **lsta, t_lst **lstb);

#endif
