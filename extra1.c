/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:33:25 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/05 09:24:35 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void convertDate(char *str)
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
