/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szyn <szyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:01:49 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/14 23:00:57 by szyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
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
int duplicate_detector(int array[], int list_size);
int					ft_isdigit(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
void				ft_putstring(char *s);
size_t				ft_strlength(char *s);
char				**ft_split(char const *s, char c);
int					ft_isspace(int c);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strdup(char *s);

/*parsing functions*/
int					analyse_string(char *str);
void				initialise_list(t_list **stack_a, char *concat);
void				init_index(t_list **stack_a);

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

/*Binary Radix Sort*/
typedef struct s_bss
{
	t_list			*iteration;
	int				size;
	int				i;
	int				bits_to_shift;
}					t_bss;
void				binary_radix_sort(t_list **stack_a, t_list **stack_b);

/*Chunks Sort*/
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

/*Macros*/
# ifndef MAX
#  define MAX 0x7fffffff
# endif

# ifndef BIT_MAX
#  define BIT_MAX 32
# endif

# ifndef MIN
#  define MIN 0x80000000
# endif

#endif
