/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 09:51:28 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/01 14:05:56 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void RecDir(char * path, int flag) 
{
    DIR * dp = opendir(path);
    if(!dp) {
        perror(path);
        return;
    }
    struct dirent * ep;
    char newdir[512];
	if (flag == 1)
	    printf("\n\n%s:\n", path);
    while((ep = readdir(dp)))
        if(strncmp(ep->d_name, ".", 1))
            printf("%s\t", ep->d_name);
		else if (flag == 2)
            printf("%s\t", ep->d_name);
    closedir(dp);
    dp = opendir(path);
    while((ep = readdir(dp))) if(strncmp(ep->d_name, ".", 1)) {
        if(flag && ep->d_type == 4) {
            sprintf(newdir, "%s/%s", path, ep->d_name);
            RecDir(newdir, 1);
        }
    }
    closedir(dp);
	if (flag != 1)
		printf("\n");
}

void handler(unsigned int flags)
{
	if (flags & 2)
		RecDir("./",1);
	else if (flags & 4)
		RecDir("./",2);
	else 
		RecDir("./",0);
}
