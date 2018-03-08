/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzietsma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:02:15 by lzietsma          #+#    #+#             */
/*   Updated: 2018/03/08 15:41:35 by lzietsma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_replace(char *c_array, int i, char *by);
void	ft_search(char *c_array, char *replace, char *by);
void	ft_putstr(char *c_array);

void	ft_search(char *c_array, char *replace, char *by)
{
	int i;
	int j;
	int equal;

	i = 0;
	while (c_array[i])
	{
		j = 0;
		equal = 0;
		while (c_array[i] && replace[j])
		{
			if (c_array[i] == replace[j])
				equal = 1;
			else
				equal = 0;
			j++;
			i++;
		}
		if (equal == 1)
			ft_replace(c_array, i - j, by);
		i -= j;
		i++;
	}
	ft_putstr(c_array);
}

void	ft_replace(char *c_array, int i, char *by)
{
	int j;

	j = 0;
	while (by[j])
	{
		c_array[i] = by[j];
		i++;
		j++;
	}
}

void	ft_putstr(char *c_array)
{
	int i;

	i = 0;
	while (c_array[i])
	{
		write(1, &c_array[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	if (argc != 4)
		write(1, "\n", 1);
	else
		ft_search(argv[1], argv[2], argv[3]);
	return (0);
}
