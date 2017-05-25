/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 20:47:32 by dhervy            #+#    #+#             */
/*   Updated: 2016/04/10 21:03:12 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_countspacelink(t_tri *list)
{
	t_tri	*tmp;
	int		i;

	i = 0;
	tmp = list;
	while (tmp)
	{
		if (i < ft_countint(tmp->link))
			i = ft_countint(tmp->link);
		tmp = tmp->next;
	}
	return (i);
}

int		ft_countspaceuser(t_tri *list)
{
	t_tri	*tmp;
	int		i;

	i = 0;
	tmp = list;
	while (tmp)
	{
		if (i < (int)ft_strlen(tmp->user))
			i = (int)ft_strlen(tmp->user);
		tmp = tmp->next;
	}
	return (i);
}

int		ft_countspacegroupe(t_tri *list)
{
	t_tri	*tmp;
	int		i;

	i = 0;
	tmp = list;
	while (tmp)
	{
		if (i < (int)ft_strlen(tmp->groupe))
			i = (int)ft_strlen(tmp->groupe);
		tmp = tmp->next;
	}
	return (i);
}

int		ft_countspacesize(t_tri *list)
{
	t_tri	*tmp;
	int		i;

	i = 0;
	tmp = list;
	while (tmp)
	{
		if (i < ft_countint(tmp->size))
			i = ft_countint(tmp->size);
		tmp = tmp->next;
	}
	return (i);
}
