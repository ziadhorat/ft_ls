/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 09:51:28 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/02 09:23:08 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_ls(char * path, unsigned int flag) 
{
    DIR * dp = opendir(path);
	if (errno == 20)
	{
		ft_putstr(path);
		return;
	}
    else if(!dp) 
	{
		ft_putstr("ft_ls: ");
        perror(path);
        return;
    }
    struct dirent * ep;
    char newdir[512];
	if (flag & 2)
	    printf("\n\n%s:\n", path);
    while((ep = readdir(dp)))
        if(strncmp(ep->d_name, ".", 1))
            printf("%s\t", ep->d_name);
		else if (flag & 4)
            printf("%s\t", ep->d_name);
    closedir(dp);
    dp = opendir(path);
    while((ep = readdir(dp))) if(strncmp(ep->d_name, ".", 1)) 
	{
        if(flag & 2 && ep->d_type == 4) 
		{
            sprintf(newdir, "%s/%s", path, ep->d_name);
            ft_ls(newdir, flag);
        }
    }
    closedir(dp);
	if (!(flag & 2))
		printf("\n");
}
