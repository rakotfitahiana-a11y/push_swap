/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henirako <henirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 09:22:06 by nfitahin          #+#    #+#             */
/*   Updated: 2026/03/26 13:17:44 by henirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_pos(t_stack *stack)
{
	int	min;
	int	pos;
	int	i;

	min = stack->value;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}
