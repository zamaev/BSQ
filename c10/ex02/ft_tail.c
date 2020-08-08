/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 12:49:34 by hirelia           #+#    #+#             */
/*   Updated: 2020/07/28 17:54:07 by hirelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>



int	main(int argc, char **argv)
{
	int in;
	//int n;

	in = 0;
	if (argv[1][0] != '-' || argv[1][1] != 'c')
	{
		write(1, "Error option\n", 13);
	  	return (0);	
	}
	if (argv[2])
	{
		write(1, "2", 1);
		//n = 3 //str_to_num(argv[2]);
	}
	if (argv[3])
	{
		write(1, "3", 1);
		//in = open(
	}

	

/*
	int		n;
	char	c;
	int		f;

	f =  open(argv[1], O_RDWR);
	while (1)
	{
		n = read(f, &c, 1);
		if (!n)
			break ;
	
		write(1, &c, 1);
	}
	write(1, "\n", 1);
	write(f, "\b\b\b", 3);
	read(f, &c, 1);
	write(1, &c, 1);

	*/
	
	(void)argc;
	(void)argv;
	return (0);
}
