/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sidefunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 10:33:38 by mfiguera          #+#    #+#             */
/*   Updated: 2017/11/29 10:33:40 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_sqrroot(int nb)
{
	int i;

	i = 1;
	while (i * i < nb)
		i++;
	return (i);
}

void		ft_lstrev(t_tetromino **list)
{
	t_tetromino *tmp;
	t_tetromino *nextt;

	tmp = NULL;
	while (*list)
	{
		nextt = (*list)->next;
		(*list)->next = tmp;
		tmp = (*list);
		if (nextt)
			(*list) = nextt;
		else
			return ;
	}
}

void		ft_lstadd(t_tetromino **alst, t_tetromino *new)
{
	new->next = (*alst);
	*alst = new;
}

char		*ft_strdup(char *s1)
{
	int		i;
	char	*sret;

	i = 0;
	while (s1[i])
		i++;
	sret = (char *)malloc(sizeof(*s1) * (i + 1));
	if (!sret)
		return (sret);
	i = 0;
	while (s1[i])
	{
		sret[i] = s1[i];
		i++;
	}
	sret[20] = '\0';
	return (sret);
}

t_tetromino	*ft_lstnew(char *content, int nb)
{
	t_tetromino *list;

	if (!(list = (t_tetromino*)malloc(sizeof(t_tetromino))))
		return (NULL);
	list->piece = ft_strdup(content);
	list->next = NULL;
	list->letter = 'A' + nb;
	return (list);
}
