/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:50:32 by mimeyer           #+#    #+#             */
/*   Updated: 2019/07/08 15:07:49 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void display(snode *first, unsigned int flag)
{
	snode *ptr;
	ptr = first;
	(void)flag;
	while (ptr != NULL)
	{
		if (flag & 4)
			ft_putendl(ptr->name);
		else if (ft_strncmp(ptr->name,".",1) != 0)
			ft_putendl(ptr->name);
		ptr = ptr->next;
	}
}
