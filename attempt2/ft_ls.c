/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:39:24 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/08 15:18:15 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_ls(char *path, unsigned char flag)
{
	DIR * dp = opendir(path);
	struct dirent * ep;
	snode *first = NULL;
	snode *tmp = NULL;

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

	tmp = first;
	while (tmp != NULL)
	{
		if (strncmp(tmp->name, ".", 1) != 0)
		{
			if (flag & 2 && tmp->type == 4)
			{
				ft_ls(tmp->path, flag);
			}
		}
		else
		{
			if (flag & 2 && flag & 4 && tmp->type == 4 && ft_strcmp(tmp->name, ".") 
					!= 0 && ft_strcmp(tmp->name, "..") != 0)
			{
				ft_ls(tmp->path, flag);
			}
		}
		tmp = tmp->next;
	}
//	deleteList(&first);
}
