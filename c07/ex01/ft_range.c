/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:01:50 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/23 19:21:32 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	long int	i;
	int			*arr;

	if (min >= max)
		return (NULL);
	arr = malloc(((long)max - (long)min) * sizeof(int));
	i = 0;
	while (i < ((long)max - (long)min))
	{
		arr[i] = min + (int)i;
		i++;
	}
	return (arr);
}
