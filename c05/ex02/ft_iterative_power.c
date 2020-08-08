/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 19:40:40 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/21 19:54:32 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int p;

	p = 1;
	if (power < 0)
		return (0);
	while (power-- > 0)
		p *= nb;
	return (p);
}