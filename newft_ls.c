/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:24:29 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/02 15:07:51 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_ls(char *path, unsigned int flag)
{
	DIR *dp = opendir(path);
	struct dirent *ep;
	char newdir[512];

	if (!dp)									//Check old for better handling
	{
		perror(path);
		return;
	}
	if (flag & 2)								//Print out file name if -R
	{
		ft_putstr("\n\n");
		ft_putstr(path);
		ft_putstr(":\n");
	}											//End of print -R
	while ((ep = readdir(dp)))					//Needs to handle -a (strcmp ".")
	{
		ft_putstr(ep->d_name);
		ft_putstr("\t\t");
	}
	closedir(dp);
	dp = opendir(path);
	if (flag & 2)
	{
		while ((ep = readdir(dp)))
		{
			if (flag & 2 && ep->d_type == 4)
			{
				sprintf(newdir, "%s/%s", path, ep->d_name);
				ft_ls(newdir, flag);
			}
		}
	}
	closedir(dp);
}
