/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henirako <henirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 08:50:22 by nfitahin          #+#    #+#             */
/*   Updated: 2026/03/30 08:31:00 by henirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a, t_bench *bench)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->index;
	y = (*a)->next->index;
	z = (*a)->next->next->index;
	if (x > y && y < z && x < z)
		sa(a, bench);
	else if (x > y && y > z)
	{
		sa(a, bench);
		rra(a, bench);
	}
	else if (x > y && y < z && x > z)
		ra(a, bench);
	else if (x < y && y > z && x < z)
	{
		sa(a, bench);
		ra(a, bench);
	}
	else if (x < y && y > z && x > z)
		rra(a, bench);
}
