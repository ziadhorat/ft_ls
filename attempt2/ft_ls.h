/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 09:51:47 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/08 14:45:14 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

//# include <string.h> //remove
# include <stdio.h> //remove
# include <sys/errno.h> //might need to remove
# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

typedef struct node
{
    char name[256];
    char path[1096];
	int type;
	mode_t mode;
	nlink_t nlink;
	int uid;
	int gid;
	off_t size;
	time_t mtime;
	int	blocks;
    struct node *next;
} snode;

void ft_ls(char *path, unsigned char flag);
int error_handle(char * path, DIR *dp, int ierrno, unsigned int flag);
void illegalFlags(char flag);
snode *insert_node_last(struct dirent *ep, char *path);
void display(snode *first, unsigned int flag);
void mergeSort(snode** head_in, unsigned int flag);
void deleteList(snode** head_in);
void FrontBackSplit(snode* source, snode** frontRef, snode** backRef);
void illegalDir(char *str);

#endif
