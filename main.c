/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignore </var/mail/tsignore>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:30:56 by tsignore          #+#    #+#             */
/*   Updated: 2020/11/28 15:47:45 by tsignore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static void ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putstr(char *str)
{
	size_t	size;

	size = 0;
	while (str[size])
		size++;
	write(1, str, size);
}

int	main(void)
{
	int		fd;
	int		rs;
	char	*line;

	fd = open("THING.txt", O_RDONLY);
	rs = get_next_line(fd, &line);
	if (rs < 0)
	{
		ft_putstr("ERROR\n");
		return (0);
	}
	if (rs == 0)
	{
		ft_putstr("FIN.");
		return (0);
	}
	ft_putstr(line);
	ft_putchar('\n');
	while (rs)
	{
		rs = get_next_line(fd, &line);
		if (rs == -1)
		{
			ft_putstr("ERROR\n");
			return (0);
		}
		ft_putstr(line);
		ft_putchar('\n');
	}
	ft_putstr("FIN: ");
	ft_putchar(rs == 0 ? 'O' : 'X');
	return (0);
}
