/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 19:09:05 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/25 23:36:59 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

char				*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;
	char		*str;
	int			n;

	if (ac < 0)
		return (NULL);
	if (!(tab = malloc(sizeof(t_stock_str) * (ac + 1))))
		return (NULL);
	i = 0;
	while (i < ac)
	{
		n = ft_strlen(av[i]);
		if (!(str = malloc(sizeof(char) * (n + 1))))
			return (NULL);
		tab[i].size = n;
		tab[i].str = av[i];
		tab[i].copy = ft_strcpy(str, av[i]);
		i++;
	}
	tab[ac].str = 0;
	return (tab);
}
