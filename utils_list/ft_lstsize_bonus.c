/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:29:52 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/11 18:28:49 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		counter;
	t_list	*head;

	if (!lst)
		return (0);
	counter = 0;
	head = lst;
	while (head != NULL)
	{
		counter++;
		head = head->next;
	}
	return (counter);
}
