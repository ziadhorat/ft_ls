/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 09:51:47 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/04 13:54:45 by zmahomed         ###   ########.fr       */
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

void 	ft_ls(char * path, unsigned int flag);
void 	handler(unsigned int flags);
char *getGroup(gid_t gid);
char *getUser(uid_t uid);
void convertDate(char *str);
int error_handle(char * path, DIR *dp, int ierrno, unsigned int flag);
void l_print(char *path, struct dirent *ep);
void handle_print(struct dirent *ep, char *path, unsigned int flag)

#endif
