/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrcolor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 16:07:53 by dhervy            #+#    #+#             */
/*   Updated: 2016/04/10 22:19:58 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_putstrcolor(t_tri *tmp, int *arg)
{
	char	*colorone;

	if (tmp->type == FICHIER && (tmp->permission[3] == 's' || tmp->permission[3]
			== 'S') && arg[G])
		colorone = "\033[7;40;31m";
	else if (tmp->type == FICHIER && (tmp->permission[6] == 's' ||
			tmp->permission[6] == 'S') && arg[G])
		colorone = "\033[7;40;36m";
	else if (tmp->type == FICHIER && tmp->permission[3] != '-' && arg[G])
		colorone = "\033[1;31m";
	else if (tmp->type == REPERTOIR && tmp->permission[8] == 'w' && arg[G])
		colorone = "\033[7;40;33m";
	else if (tmp->type == REPERTOIR && arg[G])
		colorone = "\033[1;36m";
	else if (tmp->type == CARACTERE && arg[G])
		colorone = "\033[7;44;33m";
	else if (tmp->type == LINK && arg[G])
		colorone = "\033[1;35m";
	else if (tmp->type == BLOC && arg[G])
		colorone = "\033[7;44;36m";
	else
		colorone = "\033[0;m";
	ft_putstr(colorone);
	ft_putstr(tmp->name);
	ft_putstr("\033[0;m");
}
