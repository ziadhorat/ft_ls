/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 13:54:53 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/08 14:42:41 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

unsigned char flag_h(char c, unsigned char flag)
{
	if (c == 'l')
		flag |= 1;
	else if (c == 'R')
		flag |= 2;
	else if (c == 'a')
		flag |= 4;
	else if (c == 'r')
		flag |= 8;
	else if (c == 't')
		flag |= 16;
	else
		illegalFlags(c);
	return (flag);
}

int main(int ac, char **av)
{
	unsigned char flags = 0;
	int i = 1;
	int j = 0;
	int flagState = 0;
	char c;

	(void)ac;
	while (av[i])
	{
		j = 1;
		if (ft_strncmp(av[i],"-",1) == 0 && flagState == 0)
		{
			while (av[i][j])
			{
				c = av[i][j];
				if (c == 'l' || c == 'R' || c == 'a' || c == 'r' || c == 't')
					flags = flag_h(av[i][j], flags);
				j++;
			}
		}
		else if (ft_strncmp(av[i],"-",1) == 0 && flagState == 1)
		{
			illegalDir(av[i]);
		}
		else
		{
			ft_ls(av[i],flags);
			flagState = 1;
		}
		i++;
	}
	if (flagState == 0)
		ft_ls(".",flags);
	return (0);
}
