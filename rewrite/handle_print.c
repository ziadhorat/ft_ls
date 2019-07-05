/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:59:48 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/05 12:00:55 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void display(snode *first, unsigned int flag)
{
	snode *ptr;
	ptr = first;
	while (ptr != NULL)
	{
		if (flag & )
		ft_putstr(ptr->name);
		ft_putstr("\t");
		ptr = ptr->next;
	}
}
