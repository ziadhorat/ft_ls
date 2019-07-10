/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 11:54:41 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/10 11:29:56 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(src);
	len++;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
