/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 19:54:38 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/28 04:32:25 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		f;
	char	c;
	int		n;

	if (argc < 2)
		write(1, "File name missing.\n", 19);
	if (argc > 2)
		write(1, "Too many arguments.\n", 20);
	if (argc != 2)
		return (0);
	f = open(argv[1], O_RDONLY);
	if (f < 0)
	{
		write(1, "Cannot read file.\n", 18);
		return (0);
	}
	n = read(f, &c, 1);
	while (n)
	{
		write(1, &c, 1);
		n = read(f, &c, 1);
	}
	close(f);
	return (0);
}
