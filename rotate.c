/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henirako <henirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 11:13:18 by henirako          #+#    #+#             */
/*   Updated: 2026/03/30 08:34:39 by henirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	ra(t_stack **stack_a, t_bench *bench)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
	if (bench && bench->active)
	{
		bench->ra++;
		bench->total_ops++;
	}
}

void	rb(t_stack **stack_b, t_bench *bench)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
	if (bench && bench->active)
	{
		bench->rb++;
		bench->total_ops++;
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	if (bench && bench->active)
	{
		bench->rr++;
		bench->total_ops++;
	}
}
