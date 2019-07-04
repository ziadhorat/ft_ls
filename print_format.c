/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:45:37 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/04 14:03:34 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void l_print(char *path, struct dirent *ep)
{
	char fullPath[256];
	struct stat fileStat;

	ft_strcpy(fullPath, path);
	ft_strcat(fullPath, "/");
	ft_strcat(fullPath, ep->d_name);
	if (!stat(fullPath, &fileStat))
	{
		ft_putstr((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
		ft_putstr((fileStat.st_mode & S_IRUSR) ? "r" : "-");
		ft_putstr((fileStat.st_mode & S_IWUSR) ? "w" : "-");
		ft_putstr((fileStat.st_mode & S_IXUSR) ? "x" : "-");
		ft_putstr((fileStat.st_mode & S_IRGRP) ? "r" : "-");
		ft_putstr((fileStat.st_mode & S_IWGRP) ? "w" : "-");
		ft_putstr((fileStat.st_mode & S_IXGRP) ? "x" : "-");
		ft_putstr((fileStat.st_mode & S_IROTH) ? "r" : "-");
		ft_putstr((fileStat.st_mode & S_IWOTH) ? "w" : "-");
		ft_putstr((fileStat.st_mode & S_IXOTH) ? "x\t" : "-\t");
	}
	ft_putnbr(fileStat.st_nlink);
	ft_putchar('\t');
	ft_putstr(getUser(fileStat.st_uid));
	ft_putstr("  ");
	ft_putstr(getGroup(fileStat.st_gid));
	ft_putchar('\t');
	ft_putnbr(fileStat.st_size);
	ft_putchar('\t');
	convertDate(ctime(&fileStat.st_mtime));
}

void handle_print(struct dirent *ep, char *path, unsigned int flag)
{
        if (ft_strncmp(ep->d_name, ".", 1))
		{
			if (flag & 1)
				l_print(path, ep);
			ft_putstr(ep->d_name);
			ft_putstr("\t\t");
		}
		else if (flag & 4)
		{
			if (flag & 1)
				l_print(path, ep);
			ft_putstr(ep->d_name);
			ft_putstr("\t\t");
		}
		if (flag & 1)
			ft_putstr("\n");
}
