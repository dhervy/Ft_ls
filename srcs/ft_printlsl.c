/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlsl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 23:06:19 by dhervy            #+#    #+#             */
/*   Updated: 2016/04/11 19:59:16 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_checktypec(t_tri *list)
{
	while (list)
	{
		if (list->type == CARACTERE)
			return (1);
		list = list->next;
	}
	return (0);
}

void	ft_printcaractere(t_tri *list, t_tri *tmp)
{
	if (tmp->type == CARACTERE || tmp->type == BLOC)
	{
		ft_putspace(ft_countspacemaj(list) - ft_countint(tmp->maj));
		ft_putnbr(tmp->maj);
		ft_putchar(',');
		ft_putspace((ft_countspacemin(list) - ft_countint(tmp->min)) + 1);
		ft_putnbr(tmp->min);
	}
	else
	{
		if (ft_checktypec(list))
		{
			if (ft_countspacesize(list) > ft_countspacemin(list))
				ft_putspace(ft_countspacemaj(list) + ft_countspacesize(list));
			else
				ft_putspace(ft_countspacemaj(list) + ft_countspacemin(list));
		}
		else
			ft_putspace(ft_countspacesize(list) - ft_countint(tmp->size));
		ft_putnbr(tmp->size);
	}
}

void	ft_printl(t_tri *list, t_tri *tmp, int *arg)
{
	ft_putstr(tmp->permission);
	ft_putspace((ft_countspacelink(list) - ft_countint(tmp->link)) + 2);
	ft_putnbr(tmp->link);
	ft_putspace(1);
	ft_putstr(tmp->user);
	ft_putspace((ft_countspaceuser(list) - ft_strlen(tmp->user)) + 2);
	ft_putstr(tmp->groupe);
	ft_putspace((ft_countspacegroupe(list) - ft_strlen(tmp->groupe)) + 2);
	ft_printcaractere(list, tmp);
	ft_putspace(1);
	ft_putstr(tmp->stime);
	ft_putspace(1);
	ft_putstrcolor(tmp, arg);
	if (arg[FF])
		ft_putchar(ft_checkargf(tmp));
	if (tmp->type == LINK)
	{
		readlink(tmp->path, tmp->dirlink, 1024);
		ft_putstr(" -> ");
		ft_putstr(tmp->dirlink);
	}
	ft_putchar('\n');
}

void	ft_printtotal(t_tri *tmp, int *arg)
{
	blkcnt_t	block;
	t_tri		*tmp2;
	int			i;

	block = 0;
	i = 0;
	tmp2 = tmp;
	while (tmp2)
	{
		if (tmp2->name[0] != '.')
			i++;
		tmp2 = tmp2->next;
	}
	if (i > 0 || arg[A])
	{
		ft_putstr("total ");
		while (tmp)
		{
			block = block + tmp->block;
			tmp = tmp->next;
		}
		ft_putnbr(block);
		ft_putstr("\n");
	}
}

void	ft_printlsl(t_tri *list, int nbr, int *arg, char *repertoir)
{
	t_tri		*tmp;

	tmp = list;
	if (nbr != 1)
	{
		ft_putchar('\n');
		ft_putstr(repertoir);
		ft_putendl(":");
	}
	if (!tmp->sterrno)
		ft_printtotal(tmp, arg);
	tmp = list;
	while (tmp)
	{
		if (tmp->name[0] != '.' || arg[A] || arg[F] || arg[D])
			tmp->sterrno ? ft_printnofile(tmp->name, tmp->sterrno) :
				ft_printl(list, tmp, arg);
		tmp = tmp->next;
	}
}
