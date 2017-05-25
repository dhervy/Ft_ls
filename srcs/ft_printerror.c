/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 14:57:07 by dhervy            #+#    #+#             */
/*   Updated: 2016/04/10 22:32:21 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_printerror(char *repertoir, char *strerror)
{
	int		i;
	char	*str;

	i = ft_strlen(repertoir);
	while (repertoir[i] != '/' && i != 0)
		i--;
	if (i != 0)
		i++;
	str = ft_strdup(&repertoir[i]);
	ft_putstr("ft_ls: ");
	ft_putstr(str);
	ft_putstr(": ");
	ft_putendl_fd(strerror, 2);
	free(str);
	return (-1);
}

void	ft_printnofile(char *name, char *sterrno)
{
	ft_putstr("ft_ls: ");
	ft_putstr(name);
	ft_putstr(": ");
	ft_putendl(sterrno);
}
