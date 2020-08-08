/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 00:13:31 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/28 13:23:06 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

void	print_error(char *file, char *error)
{
	write(1, "ft_cat: ", 8);
	while (*file)
		write(1, file++, 1);
	write(1, ": ", 2);
	while (*error)
		write(1, error++, 1);
	write(1, "\n", 1);
}

void	print_input(char *file, int fin)
{
	int		n;
	char	c;

	errno = 0;
	while (1)
	{
		n = read(fin, &c, 1);
		if (errno)
		{
			print_error(file, strerror(errno));
			errno = 0;
			break ;
		}
		if (n == 0)
			break ;
		write(1, &c, 1);
	}
}

int		main(int argc, char **argv)
{
	int	fin;
	int i;

	if (argc == 1)
		print_input("stdin", 0);
	i = 1;
	while (i < argc)
	{
		errno = 0;
		if (argv[i][0] == '-' && argv[i][1] == '\0')
			print_input("stdin", 0);
		else
		{
			fin = open(argv[i], O_RDONLY);
			if (errno)
				print_error(basename(argv[i]), strerror(errno));
			else
				print_input(basename(argv[i]), fin);
			close(fin);
			fin = 0;
		}
		i++;
	}
	return (0);
}
