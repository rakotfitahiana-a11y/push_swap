/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henirako <henirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 08:35:01 by henirako          #+#    #+#             */
/*   Updated: 2026/03/26 13:17:20 by henirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_range(int size)
{
	if (size > 100)
		return (size / 13);
	return (size / 7);
}

static void	push_to_b(t_stack **a, t_stack **b, int range, t_bench *bench)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b, bench);
			i++;
		}
		else if ((*a)->index <= i + range)
		{
			pb(a, b, bench);
			rb(b, bench);
			i++;
		}
		else
			ra(a, bench);
	}
}

static void	push_back_to_a(t_stack **a, t_stack **b, t_bench *bench)
{
	int	max_pos;
	int	b_size;

	while (*b)
	{
		max_pos = get_max_pos(*b);
		b_size = get_stack_size(*b);
		if (max_pos <= b_size / 2)
			while (max_pos--)
				rb(b, bench);
		else
			while (max_pos++ < b_size)
				rrb(b, bench);
		pa(b, a, bench);
	}
}

void	sort_medium(t_stack **a, t_stack **b, int size, t_bench *bench)
{
	int	range;

	range = get_range(size);
	push_to_b(a, b, range, bench);
	push_back_to_a(a, b, bench);
}
