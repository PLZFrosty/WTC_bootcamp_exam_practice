/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzietsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 10:19:56 by lzietsma          #+#    #+#             */
/*   Updated: 2018/03/09 12:33:00 by lzietsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	check_double(char *c_array, char c, int i)
{
	while (i >= 0)
	{
		i--;
		if (c_array[i] == c)
			i = -2;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (argc != 3)
		write(1, "\n", 1);
	else
	{
		while (argv[1][i])
		{
			if (check_double(argv[1], argv[1][i], i) > -2)
				write(1, &argv[1][i], 1);
			i++;
		}
		while (argv[2][j])
		{
			if (check_double(argv[2], argv[2][j], j) > -2 &&
				check_double(argv[1], argv[2][j], i) > -2)
				write(1, &argv[2][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
