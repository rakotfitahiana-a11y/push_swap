/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henirako <henirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 08:43:57 by henirako          #+#    #+#             */
/*   Updated: 2026/03/20 10:19:41 by henirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_small_cases(t_stack **a, t_stack **b,
	int size, t_bench *bench)
{
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, bench);
	}
	else if (size == 3)
		sort_3(a, bench);
	else if (size == 4)
		sort_4(a, b, bench);
	else if (size == 5)
		sort_5(a, b, bench);
	else
		return (0);
	return (1);
}

static void	handle_big_cases(t_stack **a, t_stack **b,
	int size, t_bench *bench)
{
	double	disorder;

	disorder = compute_disorder(*a);
	if (disorder < 0.2)
		sort_simple(a, b, size, bench);
	else if (disorder < 0.5)
		sort_medium(a, b, size, bench);
	else
		sort_complex(a, b, size, bench);
}

void	sort_adaptive(t_stack **a, t_stack **b, int size, t_bench *bench)
{
	if (handle_small_cases(a, b, size, bench))
		return ;
	handle_big_cases(a, b, size, bench);
}
