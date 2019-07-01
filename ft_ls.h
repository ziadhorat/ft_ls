/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 09:51:47 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/01 14:05:31 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //remove
#include <string.h> //remove
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

void 	RecDir(char * path, int flag);
void 	handler(unsigned int flags);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr(char *str);
void	ft_putchar(char c);
