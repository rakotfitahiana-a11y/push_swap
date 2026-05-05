/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfitahin <nfitahin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 11:11:49 by henirako          #+#    #+#             */
/*   Updated: 2026/03/27 09:08:55 by nfitahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lst_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> value = value;
	new -> index = -1;
	new -> next = NULL;
	new -> prev = NULL;
	return (new);
}

void	add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!stack || !new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last = *stack;
	while (last -> next)
		last = last->next;
	last -> next = new_node;
	new_node -> prev = last;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s_1;
	unsigned char	*s_2;

	s_1 = (unsigned char *)s1;
	s_2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (s_1[i] != '\0' || s_2[i] != '\0'))
	{
		if (s_1[i] != s_2[i])
			return (s_1[i] - s_2[i]);
		i++;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
