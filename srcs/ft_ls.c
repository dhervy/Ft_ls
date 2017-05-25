/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 15:26:42 by dhervy            #+#    #+#             */
/*   Updated: 2016/04/10 22:35:15 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_push(t_tri **ls, t_tri **lsrep, char **rep, int *arg)
{
	int				i;
	struct stat		buf;

	i = 0;
	while (rep[i])
	{
		lstat(rep[i], &buf);
		if (!S_ISDIR(buf.st_mode) || arg[D])
		{
			if (!arg[R])
				ft_pushrep(ls, rep[i], arg);
			else
				ft_pushrepr(ls, rep[i], arg);
		}
		else
		{
			if (!arg[R])
				ft_pushrep(lsrep, rep[i], arg);
			else
				ft_pushrepr(lsrep, rep[i], arg);
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		*arg;
	char	**rep;
	t_tri	*ls;
	t_tri	*lsrep;
	t_tri	*tmp;

	ls = NULL;
	lsrep = NULL;
	arg = NULL;
	rep = NULL;
	arg = ft_initarg(argc, argv, arg);
	rep = ft_initrep(argc, argv, rep);
	ft_push(&ls, &lsrep, rep, arg);
	tmp = ls;
	if (ls)
		!arg[L] ? ft_printls(ls, 1, "", arg) : ft_printlsl(ls, 1, arg, "");
	tmp = lsrep;
	while (tmp && !arg[D])
	{
		ft_listdir(tmp->name, arg, ft_counttab(rep));
		tmp = tmp->next;
	}
	ft_lsfree(ls);
	ft_lsfree(lsrep);
	ft_freearg(rep, arg);
}
