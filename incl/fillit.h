/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:25:59 by mfiguera          #+#    #+#             */
/*   Updated: 2017/11/27 10:26:01 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>

typedef	struct	s_tetromino
{
	char				*piece;
	char				letter;
	struct s_tetromino	*next;
}				t_tetromino;

typedef	struct	s_grid
{
	char	**grid;
	int		size;
}				t_grid;

int				ft_parsemap(int fd, t_tetromino **list);
int				ft_errorexit(int errno);
int				ft_exitparamsnot1(void);
int				ft_errorexit(int errno);
int				ft_validate2(char *map, int i, int nb);
int				ft_validate1(char *map, int nb, t_tetromino **list);
void			ft_lstadd(t_tetromino **alst, t_tetromino *new);
char			*ft_strdup(char *s1);
t_tetromino		*ft_lstnew(char *content, int nb);
void			ft_lstrev(t_tetromino **list);
int				ft_sqrroot(int nb);
char			**ft_solving1(t_grid blk, t_tetromino *pieces);
char			**ft_initarray(int nb);
char			**ft_solution(t_tetromino *pieces, int ntetrominos);

#endif
