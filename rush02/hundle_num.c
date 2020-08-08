/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundle_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:14:30 by hirelia           #+#    #+#             */
/*   Updated: 2020/08/02 19:24:34 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

char	*check_block_tail(int tail, t_list *list)
{
	char	*a;
	int		i;

	if (tail >= 2)
	{
		a = malloc(tail + 2 * sizeof(char));
		i = 0;
		a[i++] = '1';
		while (i <= tail)
			a[i++] = '0';
		a[i] = '\0';
		if (!list_get_by_id(list, a))
			return (NULL);
		return (a);
	}
	return (NULL);
}

int		print_block_tail(int tail, t_list *list)
{
	char *a;

	a = check_block_tail(tail, list);
	if (a == NULL)
		return (1);
	write(1, " ", 1);
	ft_print_str(list_get_by_id(list, a)->str);
	free(a);
	return (1);
}

int		print_block_head(char *head, t_list *list)
{
	int e;

	if (*(head - 1))
		write(1, " ", 1);
	if (head[0] != '0')
	{
		e = print_one_char(head[0], list);
		print_block_tail(2, list);
		if (head[1] != '0' || head[2] != '0')
			write(1, " ", 1);
	}
	if (head[1] == '0' && head[2] != '0')
		e = print_one_char(head[2], list);
	if (head[1] == '1')
		e = print_two_char(head[1], head[2], list);
	if (head[1] > '1')
	{
		e = print_two_char(head[1], '0', list);
		if (head[2] != '0')
		{
			write(1, "-", 1);
			e = print_one_char(head[2], list);
		}
	}
	return (e);
}

int		hundle_block(char *num, t_list *list)
{
	int tail_count;

	if (!*num)
		return (1);
	if (!(num[0] == '0' && num[1] == '0' && num[2] == '0'))
	{
		if (!print_block_head(num, list))
			return (0);
		tail_count = ft_strlen(num) - 3;
		if (!print_block_tail(tail_count, list))
			return (0);
	}
	num += 3;
	return (hundle_block(num, list));
}

int		hundle_num(char *num, t_list *list)
{
	int		head_count;
	char	head_arr[4];
	int		tail;

	head_count = ft_strlen(num) % 3;
	if (head_count == 0)
		head_count = 3;
	tail = ft_strlen(num) - head_count;
	if (tail > 0 && !check_block_tail(tail, list))
		return (0);
	if (num[0] == '0' && !num[1])
		return (print_one_char(num[0], list));
	head_arr[0] = head_count == 3 ? num[0] : '0';
	head_arr[1] = head_count != 1 ? num[head_count - 2] : '0';
	head_arr[2] = num[head_count - 1];
	head_arr[3] = '\0';
	if (!print_block_head(head_arr, list))
		return (0);
	if (!print_block_tail(tail, list))
		return (0);
	num += head_count;
	return (hundle_block(num, list));
}
