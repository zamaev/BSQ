/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 21:16:08 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/16 23:10:52 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int n)
{
	char a;
	char b;

	a = '0' + n / 10;
	b = '0' + n % 10;
	write(1, &a, 1);
	write(1, &b, 1);
}

void	ft_print_comb2(void)
{
	int f;
	int s;

	f = 0;
	while (f <= 99)
	{
		s = f + 1;
		while (s <= 99)
		{
			ft_print(f);
			write(1, " ", 1);
			ft_print(s);
			if (f != 98 || s != 99)
			{
				write(1, ", ", 2);
			}
			s++;
		}
		f++;
	}
}
