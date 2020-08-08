/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 11:42:21 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/26 15:59:04 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		is_sep(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int		get_n(char *str, char *sep)
{
	int i;
	int n;
	int is_str;

	i = 0;
	n = 0;
	while (str[i])
	{
		is_str = 0;
		while (str[i] && is_sep(str[i], sep))
			i++;
		while (str[i] && !is_sep(str[i], sep))
		{
			is_str = 1;
			i++;
		}
		if (is_str)
			n++;
	}
	printf("%d == \n", n);
	return (n);
}

char	*set_new_arr(char *str, int start, int end, char *arr)
{
	int n;
	int i;

	n = end - start;
	if (!(arr = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	while (start < end)
	{
		arr[i] = str[start];
		start++;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		a_i;
	int		start;
	int		end;
	char	**arr;
	int 	is_str = 0;

	if (!(arr = malloc(sizeof(char *) * (get_n(str, charset) + 1))))
		return (NULL);
	i = 0;
	a_i = 0;
	while (str[i])
	{
		is_str = 0;
		while (str[i] && is_sep(str[i], charset))
			start = ++i;
		while (str[i] && !is_sep(str[i], charset))
		{
			end = ++i;
			is_str = 1;
		}
			if (is_str)
		{
			arr[a_i] = set_new_arr(str, start, end, arr[a_i]);
			a_i++;
		}
	}
	arr[a_i] = "\0";
	return (arr);
}
