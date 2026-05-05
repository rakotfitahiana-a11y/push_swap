/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henirako <henirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 11:12:54 by henirako          #+#    #+#             */
/*   Updated: 2026/03/30 08:35:13 by henirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = tmp->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dest;
	if (*dest)
		(*dest)->prev = tmp;
	*dest = tmp;
}

void	pa(t_stack **stack_b, t_stack **stack_a, t_bench *bench)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
	if (bench && bench->active)
	{
		bench->pa++;
		bench->total_ops++;
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
	if (bench && bench->active)
	{
		bench->pb++;
		bench->total_ops++;
	}
}
