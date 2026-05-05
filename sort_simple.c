/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henirako <henirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 08:44:42 by henirako          #+#    #+#             */
/*   Updated: 2026/03/20 09:08:28 by henirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(t_stack **a, t_stack **b, int size, t_bench *bench)
{
	int	pos;

	while (size > 0)
	{
		pos = get_min_pos(*a);
		if (pos <= size / 2)
		{
			while (pos--)
				ra(a, bench);
		}
		else
		{
			while (pos++ < size)
				rra(a, bench);
		}
		pb(a, b, bench);
		size--;
	}
	while (*b)
		pa(b, a, bench);
}
