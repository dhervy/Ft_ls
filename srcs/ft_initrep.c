/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initrep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:24:43 by dhervy            #+#    #+#             */
/*   Updated: 2016/04/10 21:04:34 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_countrep(int argv, char **argc)
{
	int i;

	i = 1;
	while (argc[i][0] == '-' && i < argv)
	{
		i++;
		if (i == argv)
			return (0);
	}
	return (i);
}

char	**ft_initnull(char **rep)
{
	rep = (char**)ft_memalloc(sizeof(char*) * 2);
	rep[0] = (char*)ft_memalloc(sizeof(char) * 2);
	rep[0][0] = '.';
	return (rep);
}

char	**ft_initrep(int argv, char **argc, char **rep)
{
	int		i;
	int		j;

	if (argv == 1)
		return (ft_initnull(rep));
	j = 0;
	i = ft_countrep(argv, argc);
	if (i == 0)
		return (ft_initnull(rep));
	rep = (char**)ft_memalloc(sizeof(char*) * (argv - i) + 1);
	while (i < argv)
	{
		rep[j] = ft_strdup(argc[i]);
		j++;
		i++;
	}
	rep[j] = NULL;
	return (rep);
}
