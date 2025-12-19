/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:01:49 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/19 19:52:32 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

/*list*/
typedef struct s_list
{
	int				value_raw;
	int				value_index;

	struct s_list	*next;
}					t_list;
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst);
void				ft_lstdelone(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(int value);
int					ft_lstsize(t_list *lst);

/*Parsing helpers*/
int					duplicate_detector(int array[], int list_size,
						t_list **stack_a);
int					ft_isdigit(int c);
long long			ft_atoi(const char *nptr);
void				ft_putstring_fd(char *s, int fd);
size_t				ft_strlength(char *s);
char				**ft_split(char const *s, char c);
int					ft_isspace(int c);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strdup(char *s);
void				clear_strings(char **str);

/*parsing functions*/
int					analyse_string(char *str);
int					initialise_list(t_list **stack_a, char *concat);
int					init_index(t_list **stack_a);
int					sorted_input_guard(int array[], int list_size,
						t_list **clear);
/*Operations*/
void				op_push(t_list **stack_d, t_list **stack_s);
void				op_push_a(t_list **stack_a, t_list **stack_b);
void				op_push_b(t_list **stack_b, t_list **stack_a);

void				op_rotate_reverse(t_list **stack);
void				op_rotate_reverse_a(t_list **stack_a);
void				op_rotate_reverse_b(t_list **stack_b);
void				op_rotate_reverse_r(t_list **stack_a, t_list **stack_b);

void				op_rotate(t_list **stack);
void				op_rotate_a(t_list **stack_a);
void				op_rotate_b(t_list **stack_b);
void				op_rotate_rr(t_list **stack_a, t_list **stack_b);

void				op_swap(t_list **stack);
void				op_swap_a(t_list **stack_a);
void				op_swap_b(t_list **stack_b);
void				op_swap_ss(t_list **stack_a, t_list **stack_b);

/*Chunks Sort && Edge cases functions*/
typedef struct s_Chunk_Sort
{
	int				start;
	int				end;
	int				size;
	int				max_index;
	int				position;
	int				size_now;
}					t_ChS;
void				chunks_sort(t_list **stack_a, t_list **stack_b);
int					find_min_v2(t_list *stack);
int					find_position_v2(t_list *stack, int value);
void				sort_five_numbers(t_list **stack_a, t_list **stack_b);
void				sort_three_and_two_numbers(t_list **stack);

/*controlling ERRORS*/

typedef struct s_main_data
{
	t_list			*stack_a;
	t_list			*stack_b;
	char			*concat;
	int				status;
}					t_main;

# ifndef INT_MAX
#  define INT_MAX 0x7FFFFFFF
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

#endif
