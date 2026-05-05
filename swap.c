/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henirako <henirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 08:44:52 by henirako          #+#    #+#             */
/*   Updated: 2026/03/30 08:34:18 by henirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	sa(t_stack **stack_a, t_bench *bench)
{
	swap(stack_a);
	write(1, "sa\n", 3);
	if (bench && bench->active)
	{
		bench->sa++;
		bench->total_ops++;
	}
}

void	sb(t_stack **stack_b, t_bench *bench)
{
	swap(stack_b);
	write(1, "sb\n", 3);
	if (bench && bench->active)
	{
		bench->sb++;
		bench->total_ops++;
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
	if (bench && bench->active)
	{
		bench->ss++;
		bench->total_ops++;
	}
}
