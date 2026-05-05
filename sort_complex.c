/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henirako <henirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 08:44:24 by henirako          #+#    #+#             */
/*   Updated: 2026/03/20 09:01:05 by henirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_complex(t_stack **a, t_stack **b, int size, t_bench *bench)
{
	int	max_bits;
	int	i;
	int	j;

	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a, bench);
			else
				pb(a, b, bench);
			j++;
		}
		while (*b)
			pa(b, a, bench);
		i++;
	}
}
