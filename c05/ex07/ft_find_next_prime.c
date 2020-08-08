/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:39:15 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/21 21:55:49 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime_num(int nb)
{
	int i;

	if (nb < 2)
		return (0);
	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime_num(nb))
		nb++;
	return (nb);
}
