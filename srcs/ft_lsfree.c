/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsfree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 23:30:11 by dhervy            #+#    #+#             */
/*   Updated: 2016/04/10 21:05:10 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_lsfree(t_tri *list)
{
	if (list)
	{
		if (list->next)
			ft_lsfree(list->next);
		if (list->path)
			free(list->path);
		if (list->stime)
			free(list->stime);
		if (list->name)
			free(list->name);
		if (list->sterrno)
			free(list->sterrno);
		if (list->user)
			free(list->user);
		if (list->groupe)
			free(list->groupe);
		if (list->permission)
			free(list->permission);
		free(list);
	}
}

void	ft_freearg(char **rep, int *arg)
{
	int i;

	i = 0;
	while (rep[i])
	{
		free(rep[i]);
		++i;
	}
	free(rep);
	free(arg);
}
