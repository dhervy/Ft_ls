/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 19:23:22 by dhervy            #+#    #+#             */
/*   Updated: 2016/04/10 18:38:06 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <time.h>
# include <errno.h>

# define L 0
# define A 1
# define T 2
# define R 3
# define RR 4
# define ONE 5
# define D 6
# define FF 7
# define F 8
# define G 9
# define FICHIER 1
# define REPERTOIR 2
# define CARACTERE 3
# define BLOC 4
# define FIFO 5
# define LINK 6
# define SOCKET 7

typedef struct passwd	t_pass;
typedef struct group	t_group;

typedef struct			s_tri
{
	char				*name;
	char				*path;
	char				*sterrno;
	char				*stime;
	time_t				time;
	char				*date;
	int					type;
	off_t				size;
	char				*groupe;
	char				*user;
	nlink_t				link;
	blkcnt_t			block;
	dev_t				min;
	dev_t				maj;
	char				*permission;
	char				dirlink[1024];
	struct s_tri		*next;
}						t_tri;

int						*ft_initarg(int argv, char **argc, int *arg);
char					**ft_initrep(int argv, char **argc, char **rep);
char					**ft_initnull(char **rep);
int						ft_listdir(char *repertoir, int *arg, int nbr);
t_tri					*ft_initls(char *name, t_tri *new, char *repertoir,\
		int *arg);
void					ft_pushback(t_tri **list, char *repertoir, char *name, \
		int *arg);
void					ft_pushbackr(t_tri **list, char *repertoir, char *name,\
		int *arg);
void					ft_lsfree(t_tri *list);
void					ft_freearg(char **rep, int *arg);
void					ft_printls(t_tri *list, int nbr, char *repertoir,\
		int *arg);
char					*ft_checkperm(t_tri *new, struct stat buf);
void					ft_getusr(t_tri **new, uid_t uid, gid_t gid);
void					ft_printlsl(t_tri *list, int nbr, int *arg,\
		char *repertoir);
char					*ft_modiftime(time_t mtime, char *stime);
int						ft_countspacelink(t_tri *list);
int						ft_countspaceuser(t_tri *list);
int						ft_countspacegroupe(t_tri *list);
int						ft_countspacesize(t_tri *list);
int						ft_checktype(mode_t mode);
void					ft_pushrep(t_tri **list, char *name, int *arg);
void					ft_pushrepr(t_tri **list, char *name, int *arg);
t_tri					*ft_initlsrep(char *name, t_tri *new, int *arg);
int						ft_countspacemaj(t_tri *list);
int						ft_countspacemin(t_tri *list);
char					ft_checkargf(t_tri *new);
int						ft_printerror(char *repertoir, char *strerror);
void					ft_printnofile(char *name, char *sterrno);
void					ft_putstrcolor(t_tri *tmp, int *arg);

#endif
