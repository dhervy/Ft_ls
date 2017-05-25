/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkperm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 17:52:51 by dhervy            #+#    #+#             */
/*   Updated: 2016/04/10 21:02:57 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*ft_istype(int type, char *permission)
{
	permission = ft_strdup("----------");
	if (type == REPERTOIR)
		permission[0] = 'd';
	else if (type == CARACTERE)
		permission[0] = 'c';
	else if (type == BLOC)
		permission[0] = 'b';
	else if (type == FIFO)
		permission[0] = 'p';
	else if (type == LINK)
		permission[0] = 'l';
	else if (type == SOCKET)
		permission[0] = 's';
	return (permission);
}

char	*ft_isperm(mode_t mode, char *permission)
{
	mode & S_IRUSR ? permission[1] = 'r' : '-';
	mode & S_IWUSR ? permission[2] = 'w' : '-';
	if (mode & S_ISUID)
		permission[3] = (mode & S_IXUSR ? 's' : 'S');
	else
		mode & S_IXUSR ? permission[3] = 'x' : '-';
	mode & S_IRGRP ? permission[4] = 'r' : '-';
	mode & S_IWGRP ? permission[5] = 'w' : '-';
	if (mode & S_ISGID)
		permission[6] = (mode & S_IXGRP ? 's' : 'S');
	else
		mode & S_IXGRP ? permission[6] = 'x' : '-';
	mode & S_IROTH ? permission[7] = 'r' : '-';
	mode & S_IWOTH ? permission[8] = 'w' : '-';
	if (mode & S_ISVTX)
		permission[9] = (mode & S_IXOTH ? 't' : 'T');
	else
		mode & S_IXOTH ? permission[9] = 'x' : '-';
	return (permission);
}

char	*ft_checkperm(t_tri *new, struct stat buf)
{
	char	*permission;
	int		i;

	i = 0;
	permission = NULL;
	permission = ft_strdupfree(ft_istype(new->type, permission));
	permission = ft_strdupfree(ft_isperm(buf.st_mode, permission));
	return (permission);
}
