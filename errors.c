/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:37:58 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/04 15:03:48 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int error_handle(char * path, DIR *dp, int ierrno, unsigned int flag)
{
	if (ierrno == 20)
	{
		ft_putstr(path);
		return (1);
	}
    else if(!dp)
	{
		if (ierrno == 13)
		{
			ft_putstr("ft_ls: ");
			if (path[ft_strlen(path) - 1] != '/')
				ft_putstr(path);
			ft_putstr(": Permission denied\n");
			return (1);
		}
		ft_putstr("ft_ls: ");
		ft_putstr(path);
		ft_putstr(": No such file or directory\n");
        return (1);
    }
	if (flag & 2)
	{
		ft_putstr("\n\n");
		ft_putstr(path);
		ft_putstr(":\n");
	}
	return (0);
}
