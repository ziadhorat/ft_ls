/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:28:56 by zmahomed          #+#    #+#             */
/*   Updated: 2019/07/10 11:29:51 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_pwr(int base, int exponent)
{
	int i;
	int result;

	i = 1;
	result = base;
	if (exponent == 0)
		return (1);
	if (exponent == 1)
		return (result);
	if (exponent < 0)
		return (0);
	while (i < exponent)
	{
		result *= base;
		i++;
	}
	return (result);
}
