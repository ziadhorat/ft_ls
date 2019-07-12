/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <zmahomed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:27:28 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/12 09:47:06 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				check_flags(char c)
{
	if (c == 'l')
		return (1);
	else if (c == 'a')
		return (2);
	else if (c == 'R')
		return (4);
	else if (c == 'r')
		return (8);
	else if (c == 't')
		return (16);
	else if (c == 'G')
		return (32);
	else if (c == 'f')
		return (64);
	return (0);
}

unsigned char	get_flags2(unsigned char flags)
{
	error_file("-");
	return (flags);
}

void			illega_flag(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putstr("usage: ft_ls [-GRaflrt] [file ...]\n");
	exit(1);
}

int				check_if(char c)
{
	if (check_flags(c) != 0)
		return (1);
	else
		return (0);
}

unsigned char	get_flags(int ac, char **av)
{
	int				i;
	int				j;
	unsigned char	flags;

	i = 1;
	flags = '\0';
	while (i < ac)
	{
		j = 0;
		if (av[i][0] == '-')
		{
			j++;
			if (av[i][1] == '\0')
				return (get_flags2(flags));
			while (check_if(av[i][j]) == 1)
				flags |= check_flags(av[i][j++]);
			if (check_flags(av[i][j]) == 0 && av[i][j] != '\0')
				illega_flag(av[i][j]);
		}
		else
			return (flags);
		i++;
	}
	return (flags);
}
