/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 23:27:02 by dhervy            #+#    #+#             */
/*   Updated: 2016/04/10 22:50:08 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <sys/ioctl.h>

int		ft_column(void)
{
	struct winsize	w;
	int				column;

	ioctl(0, TIOCGWINSZ, &w);
	column = w.ws_col;
	return (column);
}

void	ft_printlsone(t_tri *list, int *arg)
{
	t_tri	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->name[0] != '.' || arg[A] || arg[F] || arg[D])
		{
			if (tmp->sterrno)
				ft_printnofile(tmp->name, tmp->sterrno);
			else
			{
				ft_putstrcolor(tmp, arg);
				if (arg[FF])
					ft_putchar(ft_checkargf(tmp));
				ft_putchar('\n');
			}
		}
		tmp = tmp->next;
	}
	return ;
}

void	ft_print(t_tri *list, int size, int nbr, int *arg)
{
	int		i;
	t_tri	*tmp;

	i = 0;
	tmp = list;
	while (tmp)
	{
		if (tmp->name[0] != '.' || arg[A] || arg[F] || arg[D])
		{
			tmp->sterrno ? ft_printnofile(tmp->name, tmp->sterrno) :
				ft_putstrcolor(tmp, arg);
			if (arg[FF])
				ft_putchar(ft_checkargf(tmp));
			if (++i < nbr)
				ft_putspace(size - ft_strlen(tmp->name));
			else
			{
				ft_putchar('\n');
				i = 0;
			}
		}
		tmp = tmp->next;
	}
	ft_putstr("\n");
}

void	ft_printls(t_tri *list, int nbr, char *repertoir, int *arg)
{
	t_tri	*tmp;
	int		i;
	int		j;

	if (arg[ONE])
		return (ft_printlsone(list, arg));
	i = 0;
	j = 0;
	tmp = list;
	if (nbr != 1)
	{
		ft_putstr(repertoir);
		ft_putstr(":\n");
	}
	while (tmp)
	{
		if (i < (int)ft_strlen(tmp->name))
			i = (int)ft_strlen(tmp->name);
		tmp = tmp->next;
	}
	j = ft_column() / (i + 1);
	ft_print(list, i + 1, j, arg);
	ft_putstr("\n");
}
