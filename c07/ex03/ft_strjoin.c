/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:40:28 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/23 20:38:24 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		get_str_size(char *str)
{
	int n;

	n = 0;
	while (*str++)
		n++;
	return (n);
}

int		get_full_size(int size, char **strs, char *sep)
{
	int n;
	int i;

	n = 0;
	i = 0;
	while (i < size)
	{
		n += get_str_size(strs[i]);
		i++;
	}
	n += get_str_size(sep) * (size - 1);
	return (n);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*s;

	s = malloc(sizeof(char) * get_full_size(size, strs, sep));
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			s[k++] = strs[i][j++];
		j = 0;
		while (i < (size - 1) && sep[j])
			s[k++] = sep[j++];
		i++;
	}
	s[k] = '\0';
	return (s);
}
