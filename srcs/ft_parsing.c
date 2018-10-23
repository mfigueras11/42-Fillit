/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:57:03 by mfiguera          #+#    #+#             */
/*   Updated: 2018/01/05 13:54:18 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_validate2(char *map, int i, int nb)
{
	int n;
	int s;
	int e;
	int w;

	if (map[i] == '#')
	{
		map[i] = 'A' + nb;
		if (i >= 5)
			n = ft_validate2(map, i - 5, nb);
		else
			n = 0;
		if (i % 5 != 0)
			w = ft_validate2(map, i - 1, nb);
		else
			w = 0;
		e = ft_validate2(map, i + 1, nb);
		if (i <= 15)
			s = ft_validate2(map, i + 5, nb);
		else
			s = 0;
	}
	else
		return (0);
	return (1 + n + s + e + w);
}

int			ft_validate1(char *map, int nb, t_tetromino **list)
{
	int i;
	int value;

	i = 0;
	value = 0;
	while ((map[i] == '.' || map[i] == '\n' || map[i] == '#') &&
		!(i % 5 == 4 && map[i] != '\n') && i < 21)
	{
		value = value + map[i];
		i++;
	}
	if (!(value == 742 || (value == 732 && !map[20])))
		return (0);
	i = 0;
	while ((map[i] == '.' || map[i] == '\n') && map[i] != '#')
		i++;
	if (ft_validate2(map, i, nb) != 4)
		return (0);
	if (nb)
		ft_lstadd(&(*list), ft_lstnew(map, nb));
	else
		*list = ft_lstnew(map, nb);
	return (1);
}

int			ft_parsemap(int fd, t_tetromino **list)
{
	char	piece[21];
	char	temp[21];
	int		red;
	int		npieces;
	int		i;

	npieces = 0;
	piece[20] = 0;
	while ((red = read(fd, piece, 21)))
	{
		i = 0;
		if (npieces == 26 || !ft_validate1(piece, npieces, list))
			return (0);
		while (i < 22)
		{
			temp[i] = piece[i];
			piece[i++] = 0;
		}
		npieces++;
	}
	if (temp[20] != 0)
		return (0);
	if (npieces >= 2)
		ft_lstrev(list);
	return (npieces);
}
