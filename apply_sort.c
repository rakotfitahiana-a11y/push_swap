/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfitahin <nfitahin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 13:20:55 by henirako          #+#    #+#             */
/*   Updated: 2026/03/27 09:08:40 by nfitahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_sort(t_stack **a, t_stack **b, char *mode, t_bench *bench)
{
	int	size;

	size = get_stack_size(*a);
	index_stack(*a);
	bench->init_disorder = compute_disorder(*a);
	if (!mode || ft_strcmp(mode, "--adaptive") == 0)
		sort_adaptive(a, b, size, bench);
	else if (ft_strcmp(mode, "--simple") == 0)
		sort_simple(a, b, size, bench);
	else if (ft_strcmp(mode, "--medium") == 0)
		sort_medium(a, b, size, bench);
	else if (ft_strcmp(mode, "--complex") == 0)
		sort_complex(a, b, size, bench);
	else
		print_error();
}
