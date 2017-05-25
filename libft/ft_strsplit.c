/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:46:56 by dhervy            #+#    #+#             */
/*   Updated: 2016/01/12 13:18:14 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countsplit(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count + 1);
}

static	int	ft_countchar(char const *s, char c, int i)
{
	int count;

	count = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!s || !(s = ft_strtrimi(s, c)))
		return (NULL);
	if (!(new = (char**)ft_memalloc(sizeof(char*) * ft_countsplit(s, c))))
		return (NULL);
	while (s[k + i] != '\0')
	{
		k = i + k;
		i = k;
		i = ft_countchar(s, c, i) - i;
		if (!(new[j] = (char*)ft_memalloc(sizeof(char) * i)))
			return (NULL);
		ft_strncpy(new[j], &s[k], i);
		i++;
		j++;
	}
	return (new);
}
