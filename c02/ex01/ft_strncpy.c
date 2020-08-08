/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 18:01:17 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/18 23:36:41 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		if (!src[i])
		{
			dest[i] = '\0';
		}
		else
		{
			dest[i] = src[i];
		}
		i++;
	}
	return (dest);
}
