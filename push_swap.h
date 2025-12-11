/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:01:49 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/11 17:31:04 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#include <stdlib.h>
#include <unistd.h>

/*Parsing Functions*/

int ft_isdigit(int c);
int ft_strncmp(const char *s1, const char *s2, size_t n);
int ft_atoi(const char *str);
void ft_putstring(char *s);
size_t ft_strlength(char *s);
char **ft_split(char const *s, char c);
int	ft_isspace(int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);

/*Macros*/
#ifndef MAX
#define MAX 0x7fffffff
#endif

#ifndef MIN
#define MIN 0x80000000
#endif
/*list*/
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int value);
int	ft_lstsize(t_list *lst);

typedef struct s_list
{
    int value_raw;
    int value_index;

    struct s_list *next;
} t_list;

#endif