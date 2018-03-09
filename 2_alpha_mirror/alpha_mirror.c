/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzietsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:10:19 by lzietsma          #+#    #+#             */
/*   Updated: 2018/03/09 09:59:22 by lzietsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	mirror(char c)
{
	char new;

	if (c >= 'a' && c <= 'z')
		new = 'z' - c + 'a';
	else if (c >= 'A' && c <= 'Z')
		new = 'Z' - c + 'A';
	write(1, &new, 1);
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc != 2)
		write(1, "\n", 1);
	else
		while (argv[1][i])
		{
			mirror(argv[1][i]);
			i++;
		}
	return (0);
}
