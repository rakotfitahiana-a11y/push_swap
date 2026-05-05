/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henirako <henirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 09:17:51 by nfitahin          #+#    #+#             */
/*   Updated: 2026/03/30 09:16:09 by henirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_min_to_b(t_stack **a, t_stack **b, t_bench *bench)
{
	int	pos;

	pos = get_min_pos(*a);
	if (pos == 1)
		ra(a, bench);
	else if (pos == 2)
	{
		ra(a, bench);
		ra(a, bench);
	}
	else if (pos == 3)
		rra(a, bench);
	else if (pos == 4)
	{
		rra(a, bench);
		rra(a, bench);
	}
	pb(a, b, bench);
}

void	sort_5(t_stack **a, t_stack **b, t_bench *bench)
{
	push_min_to_b(a, b, bench);
	push_min_to_b(a, b, bench);
	sort_3(a, bench);
	if ((*b)->index < (*b)->next->index)
		sb(b, bench);
	pa(b, a, bench);
	pa(b, a, bench);
}
