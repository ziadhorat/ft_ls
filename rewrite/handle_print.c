/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:59:48 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/05 12:41:49 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void display(snode *first, unsigned int flag)
{
	snode *ptr;
	ptr = first;
	while (ptr != NULL)
	{
		if (!(flag & 4) && ft_strncmp(ptr->name, ".", 1)) 
		{
			if (flag & 1)
				ft_putstr(ptr->mode);
			ft_putstr(ptr->name);
			ft_putstr("\n");
		}
		else if (flag & 4)
		{
			ft_putstr(ptr->name);
			ft_putstr("\n");
		}
		ptr = ptr->next;
	}
}
