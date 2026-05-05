/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_and_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henirako <henirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 11:12:37 by henirako          #+#    #+#             */
/*   Updated: 2026/03/26 11:12:38 by henirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_atoi(char *str, t_stack *stack)
{
	long	res;
	int		signe;
	int		i;

	res = 0;
	signe = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	res = res * signe;
	if (res < INT_MIN || res > INT_MAX)
		print_error();
	if (has_duplicate(stack, (int)res))
		print_error();
	return ((int)res);
}
