/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:02:22 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/10 11:30:03 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	if (!(result = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
	{
		return (NULL);
	}
	while (*s1)
	{
		result[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		result[i] = *s2;
		i++;
		s2++;
	}
	result[i] = '\0';
	return (result);
}
