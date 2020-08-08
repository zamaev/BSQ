/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:45:24 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/19 20:04:55 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	char	*e;

	e = NULL;
	if (!*to_find)
	{
		return (str);
	}
	while (*str)
	{
		i = 0;
		while (str[i] && to_find[i] && str[i] == to_find[i])
		{
			i++;
		}
		if (!to_find[i])
		{
			return (str);
		}
		str++;
	}
	return (e);
}
