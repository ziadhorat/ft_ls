/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <zmahomed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:48:22 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/12 09:37:11 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	handle_col(t_dir *lst, unsigned char flags)
{
	if (flags & 32)
	{
		if ((S_ISLNK(lst->mode)))
			ft_putstr("\033[0;35m");
		else if (S_ISDIR(lst->mode))
			ft_putstr("\033[0;34m");
		else if (lst->mode & S_IXOTH)
			ft_putstr("\033[0;31m");
		ft_putstr(lst->name);
		ft_putstr("\033[0m");
	}
	else
		ft_putstr(lst->name);
}

void	display_l(t_dir *lst, char *path, unsigned char flags)
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
	ft_putendt(lst->uid);
	ft_putendt(lst->gid);
	ft_putnbr(lst->size);
	ft_putstr("\t");
	convert_date(ctime(&lst->mtime));
	handle_col(lst, flags);
	if ((S_ISLNK(lst->mode)))
		ft_linkprint(path, lst);
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
			display_l(ptr, path, flags);
		else if (ft_strncmp(ptr->name, ".", 1) != 0)
			display_l(ptr, path, flags);
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
			handle_col(ptr, flags);
			ft_putstr("\n");
			ptr = ptr->next;
		}
		else
		{
			if (ptr->name[0] != '.')
			{
				handle_col(ptr, flags);
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
