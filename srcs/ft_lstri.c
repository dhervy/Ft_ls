/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 16:54:46 by dhervy            #+#    #+#             */
/*   Updated: 2016/04/10 23:25:54 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_pushbackr(t_tri **list, char *repertoir, char *name, int *arg)
{
	t_tri	*tmp;
	t_tri	*tmp2;
	t_tri	*newelem;

	tmp2 = NULL;
	newelem = NULL;
	newelem = ft_initls(name, newelem, repertoir, arg);
	if (!list)
		*list = newelem;
	else
	{
		tmp = *list;
		while (tmp && ((!arg[T] && !arg[F] &&
			ft_strcmp(tmp->name, newelem->name) > 0) || (arg[T] && !arg[F] &&
			tmp->time < newelem->time) || (arg[F] && tmp)))
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

void	ft_pushback(t_tri **list, char *repertoir, char *name, int *arg)
{
	t_tri	*tmp;
	t_tri	*tmp2;
	t_tri	*newelem;

	tmp2 = NULL;
	newelem = NULL;
	newelem = ft_initls(name, newelem, repertoir, arg);
	if (!list)
		*list = newelem;
	else
	{
		tmp = *list;
		while (tmp && ((!arg[T] && !arg[F] &&
			ft_strcmp(tmp->name, newelem->name) < 0) || (arg[T] && !arg[F] &&
			tmp->time > newelem->time) || (arg[F] && tmp)))
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
