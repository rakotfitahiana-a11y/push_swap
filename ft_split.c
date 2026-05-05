/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfitahin <nfitahin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:51:15 by henirako          #+#    #+#             */
/*   Updated: 2026/03/27 10:39:50 by nfitahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(char const *s, char c)
{
	int	count;
	int	i;
	int	ok;

	count = 0;
	i = 0;
	ok = 0;
	while (s[i])
	{
		if (s[i] != c && ok == 0)
		{
			ok = 1;
			count++;
		}
		else if (s[i] == c)
			ok = 0;
		i++;
	}
	return (count);
}

static void	ft_freetab(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

static int	ft_filltab(char **tab, char const *s, char c, int start)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			tab[j] = ft_substr(s, (unsigned int)start, (size_t)(i - start));
			if (!tab[j])
			{
				ft_freetab(tab, j - 1);
				return (0);
			}
			j++;
		}
	}
	tab[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		start;

	start = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	if (ft_filltab(tab, s, c, start) == 0)
		return (NULL);
	else
		return (tab);
}
