/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushrep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 20:53:41 by dhervy            #+#    #+#             */
/*   Updated: 2016/04/10 23:26:17 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_pushrep(t_tri **list, char *name, int *arg)
{
	t_tri	*tmp;
	t_tri	*tmp2;
	t_tri	*newelem;

	tmp2 = NULL;
	newelem = NULL;
	newelem = ft_initlsrep(name, newelem, arg);
	if (!list)
		*list = newelem;
	else
	{
		tmp = *list;
		while (tmp && (((!arg[T] && ft_strcmp(tmp->name, newelem->name) < 0) ||
				(arg[T] && tmp->time > newelem->time)) || (arg[F] && tmp)))
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		newelem->next = tmp;
		if (tmp2)
			tmp2->next = newelem;
		else
			*list = newelem;
	}
}

void	ft_pushrepr(t_tri **list, char *name, int *arg)
{
	t_tri	*tmp;
	t_tri	*tmp2;
	t_tri	*newelem;

	tmp2 = NULL;
	newelem = NULL;
	newelem = ft_initlsrep(name, newelem, arg);
	if (!list)
		*list = newelem;
	else
	{
		tmp = *list;
		while (tmp && (((!arg[T] && ft_strcmp(tmp->name, newelem->name) > 0) ||
		(arg[T] && tmp->time < newelem->time) || (arg[F] && tmp))))
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		newelem->next = tmp;
		if (tmp2)
			tmp2->next = newelem;
		else
			*list = newelem;
	}
}
