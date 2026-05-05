/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henirako <henirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 09:16:51 by nfitahin          #+#    #+#             */
/*   Updated: 2026/03/20 09:51:49 by henirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4(t_stack **a, t_stack **b, t_bench *bench)
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
	pb(a, b, bench);
	sort_3(a, bench);
	pa(b, a, bench);
}
