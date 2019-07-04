/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:51:23 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/04 14:55:01 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_ls(char * path, unsigned int flag)
{
    DIR * dp = opendir(path);
    struct dirent * ep;

	if (error_handle(path, dp, errno, flag) == 1)
		return;
    while((ep = readdir(dp)))
	{
		ft_putstr(ep->d_name);
	}
    closedir(dp);
}

void illegalFlags(char flag)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(flag);
	ft_putstr("\nusage: ft_ls [-Ralrt] [file ...]\n");
	exit(0);
}

int main(int argc, char **argv)
{
	unsigned char flags = 0;
	int i = 1;
	int j = 0;
	int numFlags = 0;

	while (argv[i])
	{
		j = 1;
		if (strncmp(argv[i],"-",1) == 0)
		{
			while (argv[i][j])
			{
				if (argv[i][j] == 'l')
					flags |= 1;
				else if (argv[i][j] == 'R')
					flags |= 2;
				else if (argv[i][j] == 'a')
					flags |= 4;
				else if (argv[i][j] == 'r')
					flags |= 8;
				else if (argv[i][j] == 't')
					flags |= 16;
				else
					illegalFlags(argv[i][j]);
				if (j == 1)
					numFlags++;
				j++;
			}
		}
		else
			ft_ls(argv[i],flags);
		i++;
	}
	if (numFlags + 1 == argc)
		ft_ls(".",flags);
	return (0);
}
