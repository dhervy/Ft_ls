/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modiftime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 19:44:33 by dhervy            #+#    #+#             */
/*   Updated: 2016/04/10 21:05:28 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*ft_modifyear(time_t mtime, char *stime, char *str, int i)
{
	int		j;

	j = ft_strlen(str);
	if (mtime > 1443980853)
	{
		while (stime[i - 3] != ':')
			str[j++] = stime[i++];
	}
	else
	{
		i++;
		while (!ft_isspace(stime[i - 1]))
			i++;
		str[j++] = ' ';
		while (ft_isdigit(stime[i]))
			str[j++] = stime[i++];
	}
	return (str);
}

char	*ft_modiftime(time_t mtime, char *stime)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ft_strnew(ft_strlen(stime));
	while (!ft_isspace(stime[i]))
		i++;
	i++;
	while (!ft_isspace(stime[i]))
		str[j++] = stime[i++];
	str[j++] = ' ';
	while (!ft_isdigit(stime[i]))
		i++;
	if (!ft_isdigit(stime[i + 1]))
		str[j++] = ' ';
	while (ft_isdigit(stime[i]))
		str[j++] = stime[i++];
	while (!ft_isdigit(stime[i]))
		i++;
	str[j] = ' ';
	str = ft_strdupfree(ft_modifyear(mtime, stime, str, i));
	free(stime);
	return (str);
}
