/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:21:14 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/02 09:24:12 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
			ft_ls(argv[i],flags); //need to handle error
		i++;
	}
	if (numFlags + 1 == argc)
		ft_ls(".",flags);
//	ft_putchar('\n');
	return (0);
}
