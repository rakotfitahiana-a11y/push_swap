/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfitahin <nfitahin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:49:44 by henirako          #+#    #+#             */
/*   Updated: 2026/03/27 08:52:40 by nfitahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
{
	int	j;

	j = 0;
	while (split[j])
		free(split[j++]);
	free(split);
}

static int	process_token(char *token, t_stack **a, char **split)
{
	if (ft_strncmp(token, "--", 2) == 0)
		return (1);
	if (!is_number(token))
	{
		free_split(split);
		free_stack(a);
		print_error();
		return (0);
	}
	add_back(a, lst_new(ft_atoi(token, *a)));
	return (1);
}

static void	parse_split_arg(char *arg, t_stack **a)
{
	char	**split;
	int		j;

	split = ft_split(arg, ' ');
	if (!split)
	{
		free_stack(a);
		print_error();
		return ;
	}
	j = 0;
	while (split[j])
	{
		if (!process_token(split[j], a, split))
			return ;
		j++;
	}
	free_split(split);
}

void	parse_input(int argc, char **argv, t_stack **a, int *i)
{
	while (*i < argc)
	{
		if (ft_strchr(argv[*i], ' '))
			parse_split_arg(argv[*i], a);
		else if (ft_strncmp(argv[*i], "--", 2) != 0)
		{
			if (!is_number(argv[*i]))
			{
				free_stack(a);
				print_error();
				return ;
			}
			add_back(a, lst_new(ft_atoi(argv[*i], *a)));
		}
		(*i)++;
	}
}
