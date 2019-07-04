/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 09:51:28 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/03 16:19:19 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void converDate(char *str)
{
	char ret[] = "000  0 00:00 ";
	int i = 4;
	int j = 0;
	while (i < 16)
	{
		ret[j] = str[i];
		j++;
		i++;
	}
	ft_putstr(ret);
}

char *getUser(uid_t uid)
{
	struct passwd *pws;
	pws = getpwuid(uid);
	return (pws->pw_name);
}

char *getGroup(gid_t gid)
{
	struct group *pws;
	pws = getgrgid(gid);
	return (pws->gr_name);
}

void ft_ls(char * path, unsigned int flag) 
{
    DIR * dp = opendir(path);
    struct dirent * ep;
	char fullPath[256];
	struct stat fileStat;

	if (errno == 20)
	{
		ft_putstr(path);
		return;
	}
    else if(!dp) 
	{
		if (errno == 13)
		{
        	perror("ft_ls "); //NEED TO CHANGE TO TAKE OUT STDIO.H
			return;
		}
		ft_putstr("ft_ls: ");
        perror(path); //SEE THE OTHER PERROR
        return;
    }
	if (flag & 2)
	{
		ft_putstr("\n\n");
		ft_putstr(path);
		ft_putstr(":\n");
	}
    while((ep = readdir(dp)))
	{
		if (flag & 1) 	//Fix for -a
		{
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
			ft_putchar('\t');
			ft_putstr(getGroup(fileStat.st_gid));
			ft_putchar('\t');
			ft_putnbr(fileStat.st_size);
			ft_putchar('\t');
			converDate(ctime(&fileStat.st_mtime));
		}
        if (ft_strncmp(ep->d_name, ".", 1))
		{
			ft_putstr(ep->d_name);
			ft_putstr("\t\t");
		}
		else if (flag & 4)
		{
			ft_putstr(ep->d_name);
			ft_putstr("\t\t");
		}
		if (flag & 1)
			ft_putstr("\n");
	}
    closedir(dp);
    dp = opendir(path);
    while((ep = readdir(dp))) 
	{
		if (strncmp(ep->d_name, ".", 1)) 
		{
    	   	if (flag & 2 && ep->d_type == 4) 
			{
       	    	ft_ls(ft_strjoin(path, ft_strjoin("/",ep->d_name)), flag);
       		}
		}
		else
		{
    	   	if (flag & 2 && flag & 4 && ep->d_type == 4 && ft_strcmp(ep->d_name, ".") != 0 && ft_strcmp(ep->d_name, "..") != 0) 
			{
       	    	ft_ls(ft_strjoin(path, ft_strjoin("/",ep->d_name)), flag);
			}
		}
	}	
    closedir(dp);
}
