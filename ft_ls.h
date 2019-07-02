/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 09:51:47 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/02 08:58:32 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //remove
#include <string.h> //remove
#include <sys/errno.h> //might need to remove
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

void 	ft_ls(char * path, unsigned int flag);
void 	handler(unsigned int flags);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr(char *str);
void	ft_putchar(char c);
