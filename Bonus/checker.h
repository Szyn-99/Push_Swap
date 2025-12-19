/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 21:26:11 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/20 00:16:03 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value_raw;
	int				value_index;

	struct s_list	*next;
}					t_list;

typedef struct s_main_data
{
	t_list			*stack_a;
	t_list			*stack_b;
	char			*concat;
	int				status;
}					t_main;

char				*concatenated_string(char *av[]);
int					analyse_string(char *str);
int					initialise_list(t_list **stack_a, char *concat);
int					init_index(t_list **stack_a);
void				ft_putstring_fd(char *s, int fd);
void				ft_lstclear(t_list **lst);
char				*ft_strjoin(char *s1, char *s2);

int					ft_string_cmp(const char *s1, const char *s2);
int					grade_operations(t_list *stack);
int					operations_executor(char *operation, t_list **stack_a,
						t_list **stack_b);

void				op_push(t_list **stack_d, t_list **stack_s);
void				op_push_a(t_list **stack_a, t_list **stack_b,
						int bonus_check);
void				op_push_b(t_list **stack_b, t_list **stack_a,
						int bonus_check);

void				op_rotate_reverse(t_list **stack);
void				op_rotate_reverse_a(t_list **stack_a, int bonus_check);
void				op_rotate_reverse_b(t_list **stack_b, int bonus_check);
void				op_rotate_reverse_r(t_list **stack_a, t_list **stack_b,
						int bonus_check);

void				op_rotate(t_list **stack);
void				op_rotate_a(t_list **stack_a, int bonus_check);
void				op_rotate_b(t_list **stack_b, int bonus_check);
void				op_rotate_rr(t_list **stack_a, t_list **stack_b,
						int bonus_check);

void				op_swap(t_list **stack);
void				op_swap_a(t_list **stack_a, int bonus_check);
void				op_swap_b(t_list **stack_b, int bonus_check);
void				op_swap_ss(t_list **stack_a, t_list **stack_b,
						int bonus_check);

#endif
