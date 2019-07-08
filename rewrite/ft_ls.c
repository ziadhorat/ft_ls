/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:51:23 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/08 11:12:47 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_ls(char *path, unsigned int flag)
{
    DIR * dp = opendir(path);
    struct dirent * ep;
	snode *first = NULL;

	if (error_handle(path, dp, errno, flag) == 1)
		return;
    while((ep = readdir(dp)))
	{
		if (ft_strcmp(ep->d_name,".")!=0 && ft_strcmp(ep->d_name,"..")!=0)
		{
			if (!first)
				first = insert_node_last(ep, path);
			else
				insert_node_last(ep, path);
		}
	}
    closedir(dp);
	mergeSort(&first, flag);
	display(first, flag);

	snode *ptr=first;
	while (ptr != NULL)
	{
		if (ptr->type==4)
		{
//			ft_putchar('\n');
//			ft_putstr(ptr->path);
			ft_ls(ptr->path, flag);
		}
		ptr=ptr->next;
	}

	deleteList(&first);
}
