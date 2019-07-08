/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:30:01 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/08 14:38:28 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void illegalDir(char *str)
{
	ft_putstr("ft_ls: ");
	ft_putstr(str);
	ft_putstr(": No such file or directory\n");
}

void illegalFlags(char flag)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(flag);
	ft_putstr("\nusage: ft_ls [-Ralrt] [file ...]\n");
	exit(0);
}

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
		illegalDir(path);
        return (1);
    }
	if (flag & 2)
	{
		if (ft_strcmp(path, ".") != 0)
		{
			ft_putstr("\n");
			ft_putstr(path);
			ft_putstr(":\n");
		}
	}
	return (0);
}
