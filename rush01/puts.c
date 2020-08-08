/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 20:58:07 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/26 20:58:10 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int a)
{
	char c;

	c = '0' + a;
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	print_arr(int *arr)
{
	int i;

	i = 0;
	while (i < 16)
	{
		ft_putnbr(arr[i]);
		if ((i + 1) % 4 == 0)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		i++;
	}
}
