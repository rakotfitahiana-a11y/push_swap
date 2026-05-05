/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfitahin <nfitahin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 10:59:54 by nfitahin          #+#    #+#             */
/*   Updated: 2026/03/27 10:59:59 by nfitahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		i;

	current = stack;
	while (current)
	{
		i = 0;
		compare = stack;
		while (compare)
		{
			if (current -> value > compare -> value)
				i++;
			compare = compare->next;
		}
		current->index = i;
		current = current->next;
	}
}
