/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:51:23 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/08 13:36:27 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char *lastChar(char *str, char c)
{
	int i = 0;
	int last = 0;
	while (str[i])
	{
		if (str[i] == c)
			last = i;
		i++;
	}
	return (&str[last+1]);
}

void ft_ls(char *path, unsigned int flag)
{
    DIR * dp = opendir(path);
    struct dirent * ep;
	snode *first = NULL;

	if (error_handle(path, dp, errno, flag) == 1)
		return;
    while((ep = readdir(dp)))
	{
		if (!first)
			first = insert_node_last(ep, path);
		else
			insert_node_last(ep, path);
	}
    closedir(dp);
	mergeSort(&first, flag);
	display(first, flag);

	snode *ptr=first;
	while (ptr != NULL && flag & 2)
	{
		if (ptr->type==4)
		{
			if (ft_strcmp(&ptr->path[ft_strlen(ptr->path)-1],".") != 0
					&&  ft_strcmp(&ptr->path[ft_strlen(ptr->path)-2],"..") != 0)
			{
				if (ptr->name[0] == '.' && flag & 4)
					ft_ls(ptr->path, flag);
				else if (ptr->name[0] != '.')
					ft_ls(ptr->path, flag);
			}
		}
		ptr=ptr->next;
	}

//	deleteList(&first);
}
