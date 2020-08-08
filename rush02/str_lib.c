/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:27:10 by hirelia           #+#    #+#             */
/*   Updated: 2020/08/02 17:17:00 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

void	ft_print_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

char	*ft_strdup(char *src)
{
	int		str_len;
	char	*pt;

	str_len = ft_strlen(src);
	pt = (char*)malloc(str_len * sizeof(int));
	if (pt == NULL)
		return (NULL);
	ft_strcpy(pt, src);
	return (pt);
}
