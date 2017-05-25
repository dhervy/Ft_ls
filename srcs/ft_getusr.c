/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getusr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 18:25:20 by dhervy            #+#    #+#             */
/*   Updated: 2016/04/10 20:44:31 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <pwd.h>
#include <grp.h>

void	ft_getusr(t_tri **new, uid_t uid, gid_t gid)
{
	t_pass	*pass;
	t_group	*group;
	t_tri	*tmp;

	tmp = *new;
	pass = getpwuid(uid);
	tmp->user = ft_strdup(pass->pw_name);
	group = getgrgid(gid);
	if (group == NULL)
		tmp->groupe = ft_strdup("101");
	else
		tmp->groupe = ft_strdup(group->gr_name);
}
