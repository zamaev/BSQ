/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 19:33:49 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/25 23:06:42 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_stock_str.h"

void	put_nbr(int nb)
{
	char	c;
	char	n;

	if (nb < 0)
		write(1, "-", 1);
	c = nb > 0 ? '0' + nb % 10 : '0' - nb % 10;
	n = nb > 0 ? nb / 10 : nb / 10 * -1;
	if (n != 0)
		put_nbr(n);
	write(1, &c, 1);
}

void	put_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		put_str(par->str);
		put_nbr(par->size);
		write(1, "\n", 1);
		put_str(par->copy);
		par++;
	}
}
