/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <zmahomed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:48:22 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/10 14:51:55 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_linkprint(char *path, t_dir *ptr)
{
	char		buffer[65];
	char		*tpath;
	char		*tmp;

	ft_bzero(&buffer, 65);
	tmp = ft_strjoin(path, "/");
	tpath = ft_strjoin(tmp, ptr->name);
	ft_strdel(&tmp);
	readlink(tpath, buffer, 65);
	ft_putstr(" -> ");
	ft_putstr(buffer);
	ft_strdel(&tpath);
}

void	display_blocks(t_dir *ptr, unsigned char flags)
{
	int i;

	i = 0;
	ft_putstr("total ");
	while (ptr)
	{
		if ((ptr->name[0] == '.' && flags & 2) || ptr->name[0] != '.')
			i += ptr->block;
		ptr = ptr->next;
	}
	ft_putnbr(i);
	ft_putstr("\n");
}

void	display_l(t_dir *lst, char *path)
{
	if ((S_ISLNK(lst->mode)))
		ft_putstr("l");
	else
		ft_putstr((S_ISDIR(lst->mode)) ? "d" : "-");
	ft_putstr((lst->mode & S_IRUSR) ? "r" : "-");
	ft_putstr((lst->mode & S_IWUSR) ? "w" : "-");
	ft_putstr((lst->mode & S_IXUSR) ? "x" : "-");
	ft_putstr((lst->mode & S_IRGRP) ? "r" : "-");
	ft_putstr((lst->mode & S_IWGRP) ? "w" : "-");
	ft_putstr((lst->mode & S_IXGRP) ? "x" : "-");
	ft_putstr((lst->mode & S_IROTH) ? "r" : "-");
	ft_putstr((lst->mode & S_IWOTH) ? "w" : "-");
	ft_putstr((lst->mode & S_IXOTH) ? "x " : "- ");
	ft_putnbr(lst->nlink);
	ft_putstr("\t");
	ft_putstr(lst->uid);
	ft_putstr("\t");
	ft_putstr(lst->gid);
	ft_putstr("\t");
	ft_putnbr(lst->size);
	ft_putstr("\t");
	convert_date(ctime(&lst->mtime));
	ft_putstr(lst->name);
	if ((S_ISLNK(lst->mode)))
	{
		ft_linkprint(path, lst);
	}
	ft_putchar('\n');
}

void	print_list(t_dir *list, unsigned char flags, char *path)
{
	t_dir *ptr;
	t_dir *ptr2;

	ptr = list;
	ptr2 = list;
	if (flags & 1)
		display_blocks(ptr2, flags);
	while (ptr != NULL)
	{
		if (flags & 2)
			display_l(ptr, path);
		else if (ft_strncmp(ptr->name, ".", 1) != 0)
			display_l(ptr, path);
		ptr = ptr->next;
	}
}

void	print_normal(t_dir *list, unsigned char flags)
{
	t_dir *ptr;

	ptr = list;
	while (ptr != NULL)
	{
		if (flags & 2)
		{
			ft_putstr(ptr->name);
			ft_putstr("\n");
			ptr = ptr->next;
		}
		else
		{
			if (ptr->name[0] != '.')
			{
				ft_putstr(ptr->name);
				ft_putstr("\n");
			}
			ptr = ptr->next;
		}
	}
}

void	print_output(t_dir *list, unsigned char flags, char *path)
{
	if (flags & 1)
		print_list(list, flags, path);
	else
		print_normal(list, flags);
}
