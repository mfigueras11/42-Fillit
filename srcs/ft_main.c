/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:22:42 by mfiguera          #+#    #+#             */
/*   Updated: 2018/01/04 14:50:32 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putendl(char const *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_printit(char **arr)
{
	while (*arr)
	{
		ft_putendl(*arr);
		arr++;
	}
}

int		ft_exitparamsnot1(void)
{
	write(1, "usage:	fillit path_to_map_file\n", 31);
	return (0);
}

int		ft_errorexit(int errno)
{
	if (errno == 1)
		write(1, "error\n", 6);
	return (0);
}

int		main(int argc, char const *argv[])
{
	int			fd;
	t_tetromino	*pieces;
	int			npieces;

	pieces = 0;
	if (argc != 2)
		return (ft_exitparamsnot1());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_errorexit(1));
	if (0 == (npieces = ft_parsemap(fd, &pieces)))
		return (ft_errorexit(1));
	ft_printit(ft_solution(pieces, npieces));
	if (close(fd) == -1)
		return (0);
	return (1);
}
