/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 17:29:49 by dhervy            #+#    #+#             */
/*   Updated: 2016/04/10 22:31:42 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

void	ft_recusive(t_tri *list, int *arg)
{
	t_tri	*tmp;

	tmp = list;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, ".") && ft_strcmp(tmp->name, "..") && \
		tmp->type == REPERTOIR)
			ft_listdir(tmp->path, arg, 0);
		tmp = tmp->next;
	}
}

int		ft_listdir(char *repertoir, int *arg, int nbr)
{
	DIR				*rep;
	struct dirent	*fichier;
	t_tri			*list;

	errno = 0;
	rep = NULL;
	fichier = NULL;
	list = NULL;
	if ((rep = opendir(repertoir)) == NULL)
		return (ft_printerror(repertoir, strerror(errno)));
	while ((fichier = readdir(rep)) != NULL)
	{
		if (!arg[R])
			ft_pushback(&list, repertoir, fichier->d_name, arg);
		else
			ft_pushbackr(&list, repertoir, fichier->d_name, arg);
	}
	closedir(rep);
	arg[L] && !arg[ONE] ? ft_printlsl(list, nbr, arg, repertoir) : \
		ft_printls(list, nbr, repertoir, arg);
	if (arg[RR])
		ft_recusive(list, arg);
	ft_lsfree(list);
	return (1);
}
