/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:57:24 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/23 20:39:35 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long int	i;
	int			*arr;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (((long)max - (long)min) > (long)2147483647)
		return (-1);
	arr = malloc((max - min) * sizeof(int));
	if (arr == NULL)
		return (-1);
	i = 0;
	while (i < max - min)
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (max - min);
}
