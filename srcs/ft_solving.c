/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solving.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:29:00 by mfiguera          #+#    #+#             */
/*   Updated: 2018/01/04 14:50:35 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_initarray(int nb)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	if (!(arr = (char**)malloc(sizeof(char*) * (nb) + 1)))
		return (NULL);
	while (i < nb)
	{
		arr[i] = (char*)malloc(sizeof(char) * (nb) + 1);
		j = 0;
		while (j < nb)
		{
			arr[i][j++] = '.';
		}
		arr[i++][j] = 0;
	}
	arr[i] = 0;
	return ((char**)arr);
}

char	**ft_rmarray(int nb, char **grid, char letter)
{
	int i;
	int j;

	i = 0;
	while (i < nb)
	{
		j = 0;
		while (j < nb)
		{
			if (grid[i][j] == letter)
				grid[i][j] = '.';
			j++;
		}
		i++;
	}
	return (grid);
}

char	**ft_solving2(t_grid blk, t_tetromino *pcs, int i, int j)
{
	int p;

	p = 0;
	while ((pcs->piece)[p] == '.' || pcs->piece[p] == '\n')
		p++;
	while ((pcs->piece)[p])
	{
		if ((pcs->piece)[p] == '\n')
		{
			p++;
			i++;
			j -= 4;
		}
		else if ((pcs->piece)[p] && (pcs->piece)[p] != '.' && j >= 0 &&
			j <= 26 && i < blk.size && (blk.grid)[i][j] == '.')
			(blk.grid)[i][j++] = pcs->piece[p++];
		else if ((pcs->piece)[p] == '.')
		{
			p++;
			j++;
		}
		else if (i >= blk.size || j < 0 || j > 26 || (blk.grid)[i][j] != '.')
			return (NULL);
	}
	return (ft_solving1(blk, pcs->next));
}

char	**ft_solving1(t_grid blk, t_tetromino *pieces)
{
	int		i;
	int		j;
	char	**ret;

	i = 0;
	if (!pieces)
		return (blk.grid);
	while ((blk.grid)[i])
	{
		j = 0;
		while (blk.grid[i][j] != 0)
		{
			if ((blk.grid)[i][j] == '.')
			{
				if ((ret = ft_solving2(blk, pieces, i, j)) != NULL)
					return (ret);
				(blk.grid) = ft_rmarray(blk.size, (blk.grid), pieces->letter);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

char	**ft_solution(t_tetromino *pieces, int ntetr)
{
	char	**solution;
	t_grid	blk;

	blk.size = ft_sqrroot(ntetr * 4);
	blk.grid = ft_initarray(blk.size);
	while (!(solution = ft_solving1(blk, pieces)))
	{
		blk.size++;
		blk.grid = ft_initarray(blk.size);
	}
	return (solution);
}
