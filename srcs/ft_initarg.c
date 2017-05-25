/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 15:56:34 by dhervy            #+#    #+#             */
/*   Updated: 2016/04/10 21:03:54 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_illegaloption(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ls [-FGRadflrt1] [file ...]\n", 2);
	exit(1);
}

int		*ft_check(char c, int *arg)
{
	if (c == 'l')
		arg[L] = 1;
	else if (c == 'a')
		arg[A] = 1;
	else if (c == 't')
		arg[T] = 1;
	else if (c == 'r')
		arg[R] = 1;
	else if (c == 'R')
		arg[RR] = 1;
	else if (c == '1')
		arg[ONE] = 1;
	else if (c == 'F')
		arg[FF] = 1;
	else if (c == 'f')
		arg[F] = 1;
	else if (c == 'd')
		arg[D] = 1;
	else if (c == 'G')
		arg[G] = 1;
	else if (c != '-')
		ft_illegaloption(c);
	return (arg);
}

int		*ft_checkarg(int argv, char **argc, int *arg)
{
	int i;
	int j;

	j = 0;
	i = 1;
	while (i < argv)
	{
		if (argc[i][j++] == '-')
		{
			while (argc[i][j] != '\0')
			{
				arg = ft_check(argc[i][j], arg);
				j++;
			}
		}
		else
			return (arg);
		i++;
		j = 0;
	}
	return (arg);
}

int		*ft_initarg(int argv, char **argc, int *arg)
{
	arg = ft_memalloc(sizeof(int) * 10);
	arg = ft_checkarg(argv, argc, arg);
	return (arg);
}
