/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henirako <henirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 11:13:03 by henirako          #+#    #+#             */
/*   Updated: 2026/03/30 08:34:52 by henirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_stack **stack_a, t_bench *bench)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
	if (bench && bench->active)
	{
		bench->rra++;
		bench->total_ops++;
	}
}

void	rrb(t_stack **stack_b, t_bench *bench)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
	if (bench && bench->active)
	{
		bench->rrb++;
		bench->total_ops++;
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
	if (bench && bench->active)
	{
		bench->rrr++;
		bench->total_ops++;
	}
}
