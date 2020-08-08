/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 11:40:52 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/23 19:22:09 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

char	*ft_strdup(char *str)
{
	int		n;
	char	*s;

	n = 0;
	while (str[n])
		n++;
	s = malloc(sizeof(char) * n);
	if (s == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	n = 0;
	while (*str)
		s[n++] = *str++;
	return (s);
}
