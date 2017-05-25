/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countspacemin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 19:07:37 by dhervy            #+#    #+#             */
/*   Updated: 2016/04/10 22:51:54 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_countspacemin(t_tri *list)
{
	int		i;

	i = 0;
	while (list)
	{
		if (ft_countint(list->min) > i)
			i = ft_countint(list->min);
		list = list->next;
	}
	return (i);
}

int		ft_countspacemaj(t_tri *list)
{
	int		i;

	i = 0;
	while (list)
	{
		if (ft_countint(list->maj) > i)
			i = ft_countint(list->maj);
		list = list->next;
	}
	return (i);
}
