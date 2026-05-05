/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfitahin <nfitahin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 13:18:04 by henirako          #+#    #+#             */
/*   Updated: 2026/03/27 10:39:37 by nfitahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_pos(t_stack *stack)
{
	int	max;
	int	pos;
	int	i;

	if (!stack)
		return (-1);
	max = stack->index;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->index > max)
		{
			max = stack->index;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}
