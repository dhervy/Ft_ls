/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 22:45:52 by dhervy            #+#    #+#             */
/*   Updated: 2016/04/11 19:32:30 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_checktype(mode_t mode)
{
	int i;

	i = 0;
	if (S_ISREG(mode))
		i = FICHIER;
	else if (S_ISDIR(mode))
		i = REPERTOIR;
	else if (S_ISCHR(mode))
		i = CARACTERE;
	else if (S_ISBLK(mode))
		i = BLOC;
	else if (S_ISFIFO(mode))
		i = FIFO;
	else if (S_ISLNK(mode))
		i = LINK;
	else if (S_ISSOCK(mode))
		i = SOCKET;
	return (i);
}

char	ft_checkargf(t_tri *new)
{
	char	c;

	c = '\0';
	if (new->type == FIFO)
		c = '|';
	else if (new->type == LINK)
		c = '@';
	else if (new->type == REPERTOIR)
		c = '/';
	else if (new->type == FICHIER && new->permission[3] != '-')
		c = '*';
	return (c);
}

t_tri	*ft_initlsl(t_tri *new, struct stat buf, int *arg)
{
	!arg[A] && new->name[0] == '.' ? new->block = 0 :
	(new->block = buf.st_blocks);
	ft_getusr(&new, buf.st_uid, buf.st_gid);
	new->link = buf.st_nlink;
	new->stime = ft_strdupfree(ft_modiftime(new->time, new->stime));
	new->min = minor(buf.st_rdev);
	new->maj = major(buf.st_rdev);
	return (new);
}

t_tri	*ft_initls(char *name, t_tri *new, char *repertoir, int *arg)
{
	char			*path;
	struct stat		buf;

	errno = 0;
	if (ft_strcmp(repertoir, "/") != 0)
		path = ft_strjoin(repertoir, "/");
	else
		path = ft_strdup(repertoir);
	path = ft_strjoinfree(path, name, 0);
	lstat(path, &buf);
	if (!(new = (t_tri*)ft_memalloc(sizeof(t_tri))))
		ft_exiterror("ft_ls: Error malloc\n");
	new->sterrno = errno ? ft_strdup(strerror(errno)) : NULL;
	new->time = buf.st_mtimespec.tv_sec;
	new->stime = ft_strdup(ctime((time_t*)&(buf.st_mtime)));
	new->type = ft_checktype(buf.st_mode);
	new->name = ft_strdup(name);
	new->path = ft_strdupfree(path);
	new->next = NULL;
	new->permission = ft_strdupfree(ft_checkperm(new, buf));
	new->size = buf.st_size;
	if (arg[L] && !arg[ONE])
		new = ft_initlsl(new, buf, arg);
	return (new);
}

t_tri	*ft_initlsrep(char *name, t_tri *new, int *arg)
{
	struct stat		buf;

	errno = 0;
	if (!(new = (t_tri*)ft_memalloc(sizeof(t_tri))))
		ft_exiterror("ft_ls: Error malloc\n");
	lstat(name, &buf);
	new->sterrno = errno ? ft_strdup(strerror(errno)) : NULL;
	new->name = ft_strdup(name);
	new->time = buf.st_mtimespec.tv_sec;
	new->stime = ft_strdup(ctime((time_t*)&(buf.st_mtime)));
	new->type = ft_checktype(buf.st_mode);
	new->next = NULL;
	new->permission = ft_strdupfree(ft_checkperm(new, buf));
	new->size = buf.st_size;
	if (arg[L])
	{
		ft_getusr(&new, buf.st_uid, buf.st_gid);
		new->link = buf.st_nlink;
		new->stime = ft_strdupfree(ft_modiftime(new->time, new->stime));
		new->min = minor(buf.st_rdev);
		new->maj = major(buf.st_rdev);
	}
	return (new);
}
