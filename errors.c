/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:37:58 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/04 13:38:13 by zmahomed         ###   ########.fr       */
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
        	perror("ft_ls "); //NEED TO CHANGE TO TAKE OUT STDIO.H
			return (1);
		}
		ft_putstr("ft_ls: ");
        perror(path); //SEE THE OTHER PERROR
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
