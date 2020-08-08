/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundle_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:27:25 by hirelia           #+#    #+#             */
/*   Updated: 2020/08/02 19:15:47 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

char	*valid_num(char *num)
{
	int i;

	i = 0;
	if (!*num)
		return (NULL);
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9')
			return (NULL);
		i++;
	}
	i = 0;
	while (num[i])
	{
		if (num[i] == '0' && num[i + 1])
			return (NULL);
		if (num[i] > '0')
			return (num);
		i++;
	}
	return (num);
}

int		print_one_char(char a, t_list *list)
{
	char arr[2];

	arr[0] = a;
	arr[1] = '\0';
	if (list_get_by_id(list, arr) == NULL)
		return (0);
	ft_print_str(list_get_by_id(list, arr)->str);
	return (1);
}

int		print_two_char(char a, char b, t_list *list)
{
	char arr[3];

	arr[0] = a;
	arr[1] = b;
	arr[2] = '\0';
	if (list_get_by_id(list, arr) == NULL)
		return (0);
	ft_print_str(list_get_by_id(list, arr)->str);
	return (1);
}
