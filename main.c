/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfitahin <nfitahin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 08:25:51 by nfitahin          #+#    #+#             */
/*   Updated: 2026/03/27 10:22:39 by nfitahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_sort(t_stack **a, t_stack **b, char *mode, t_bench *bench)
{
	if (compute_disorder(*a) == 0.0)
	{
		if (bench->active)
			print_benchmark(mode, bench);
		free_stack(a);
		free_stack(b);
		return ;
	}
	apply_sort(a, b, mode, bench);
	if (bench->active)
		print_benchmark(mode, bench);
	free_stack(a);
	free_stack(b);
}

static int	parse_and_sort(int argc, char **argv, char *mode, t_bench *bench)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
	parse_input(argc, argv, &a, &i);
	if (!a)
	{
		free_stack(&a);
		return (0);
	}
	run_sort(&a, &b, mode, bench);
	return (1);
}

int	main(int argc, char **argv)
{
	t_bench	bench;
	char	*mode;

	mode = NULL;
	if (argc < 2)
		return (0);
	if (!init_context(argc, argv, &bench, &mode))
	{
		print_error();
		return (1);
	}
	parse_and_sort(argc, argv, mode, &bench);
	return (0);
}
