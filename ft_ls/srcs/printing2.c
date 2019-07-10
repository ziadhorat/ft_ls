/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:15:43 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/10 15:17:54 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_linkprint(char *path, t_dir *ptr)
{
	char		buffer[65];
	char		*tpath;
	char		*tmp;

	ft_bzero(&buffer, 65);
	tmp = ft_strjoin(path, "/");
	tpath = ft_strjoin(tmp, ptr->name);
	ft_strdel(&tmp);
	readlink(tpath, buffer, 65);
	ft_putstr(" -> ");
	ft_putstr(buffer);
	ft_strdel(&tpath);
}
