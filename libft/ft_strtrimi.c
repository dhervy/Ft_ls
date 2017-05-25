/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:55:48 by dhervy            #+#    #+#             */
/*   Updated: 2015/12/10 18:31:50 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_startend(char const *s, int c)
{
	int		start;
	int		end;
	char	*new;

	start = 0;
	end = ft_strlen(s);
	while (s[start] == c)
		start++;
	while (s[end] == c)
		end--;
	if (start == 0 && (size_t)end == ft_strlen(s))
	{
		if (!(new = ft_strdup(s)))
			return (NULL);
		return (new);
	}
	if (!(new = ft_strndup(&s[start], end - start + 1)))
		return (NULL);
	return (new);
}

char			*ft_strtrimi(char const *s, int c)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	if (!(new = ft_startend(s, c)))
		return (NULL);
	while (new[i] != '\0')
	{
		if (new[i] == c && new[i + 1] == c)
		{
			j = i;
			while (new[j] != '\0')
			{
				new[j] = new[j + 1];
				j++;
			}
		}
		else
			i++;
	}
	return (new);
}
