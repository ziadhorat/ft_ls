/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:58:31 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/10 11:29:52 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_sqrt(long num)
{
	long i;

	if (num <= 0)
		return (0);
	i = 1;
	while ((i * i) <= num)
	{
		if ((i * i) == num)
			return (i);
		i++;
	}
	return (0);
}
