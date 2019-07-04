/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 09:51:47 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/03 16:16:12 by zmahomed         ###   ########.fr       */
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

#endif
