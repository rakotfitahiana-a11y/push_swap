/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_context.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henirako <henirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 08:26:08 by nfitahin          #+#    #+#             */
/*   Updated: 2026/03/30 08:26:20 by henirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sort_flag(char *s)
{
	return (ft_strcmp(s, "--simple") == 0
		|| ft_strcmp(s, "--medium") == 0
		|| ft_strcmp(s, "--complex") == 0
		|| ft_strcmp(s, "--adaptive") == 0);
}

static char	*flag_to_literal(char *token)
{
	if (ft_strcmp(token, "--simple") == 0)
		return ("--simple");
	if (ft_strcmp(token, "--medium") == 0)
		return ("--medium");
	if (ft_strcmp(token, "--complex") == 0)
		return ("--complex");
	if (ft_strcmp(token, "--adaptive") == 0)
		return ("--adaptive");
	return (NULL);
}

static void	free_split(char **split)
{
	int	j;

	j = 0;
	while (split[j])
		free(split[j++]);
	free(split);
}

static int	process_split(char **split, t_bench *bench, char **mode)
{
	int		j;
	char	*literal;

	j = 0;
	while (split[j])
	{
		if (ft_strcmp(split[j], "--bench") == 0)
			bench->active = 1;
		else if (is_sort_flag(split[j]))
		{
			if (*mode)
			{
				free_split(split);
				return (0);
			}
			literal = flag_to_literal(split[j]);
			*mode = literal;
		}
		j++;
	}
	free_split(split);
	return (1);
}

int	init_context(int argc, char **argv, t_bench *bench, char **mode)
{
	char	**split;
	int		i;

	ft_memset(bench, 0, sizeof(t_bench));
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (0);
		if (!process_split(split, bench, mode))
			return (0);
		i++;
	}
	if (!*mode)
		*mode = "--adaptive";
	return (1);
}
