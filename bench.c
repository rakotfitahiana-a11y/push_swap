/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfitahin <nfitahin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 11:11:21 by henirako          #+#    #+#             */
/*   Updated: 2026/03/27 10:25:16 by nfitahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_strategy(double disorder, char *mode)
{
	if (ft_strcmp(mode, "--simple") == 0)
		ft_putstr_fd("\n[bench] strategy: Simple / O(n²)\n", 2);
	else if (ft_strcmp(mode, "--medium") == 0)
		ft_putstr_fd("\n[bench] strategy: Medium / O(n√n)\n", 2);
	else if (ft_strcmp(mode, "--complex") == 0)
		ft_putstr_fd("\n[bench] strategy: Complex / O(n log n)\n", 2);
	else if (ft_strcmp(mode,
			"--adaptive") == 0 || !mode)
	{
		ft_putstr_fd("\n[bench] strategy: Adaptive", 2);
		if (disorder < 0.2)
			ft_putstr_fd(" / O(n²)\n", 2);
		else if (disorder < 0.5)
			ft_putstr_fd(" / O(n√n)\n", 2);
		else
			ft_putstr_fd(" / O(n log n)\n", 2);
	}
	else
		print_error();
}

static void	print_ops(t_bench *bench)
{
	ft_putstr_fd("\n[bench] sa: ", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(bench->pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(bench->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(bench->rrr, 2);
}

void	print_benchmark(char *mode, t_bench *bench)
{
	double	disorder;

	disorder = bench->init_disorder;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd((int)(disorder * 100), 2);
	ft_putstr_fd(".", 2);
	ft_putnbr_fd((int)(disorder * 10000) % 100, 2);
	ft_putstr_fd("%", 2);
	print_strategy(disorder, mode);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(bench->total_ops, 2);
	print_ops(bench);
	ft_putchar_fd('\n', 2);
}
