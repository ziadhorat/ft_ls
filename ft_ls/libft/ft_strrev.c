/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 11:57:27 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/10 11:30:19 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int count;
	int len;
	int ascii;

	len = ft_strlen(str);
	count = 0;
	while (count < len / 2)
	{
		ascii = str[count];
		str[count] = str[len - count - 1];
		str[len - count - 1] = ascii;
		count++;
	}
	return (str);
}
