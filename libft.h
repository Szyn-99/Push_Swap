/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:11:19 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/11 16:34:07 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <unistd.h>

int ft_isdigit(int c);
int ft_strncmp(const char *s1, const char *s2, size_t n);
int ft_atoi(const char *str);
char **ft_split(char const *s, char c);

#ifndef MAX
#define MAX 0x7fffffff
#endif

#ifndef MIN
#define MIN 0x80000000
#endif


#endif
