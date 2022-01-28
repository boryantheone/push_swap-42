/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollin <jcollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:22:16 by jcollin           #+#    #+#             */
/*   Updated: 2021/12/27 19:24:21 by jcollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		x;
	int		y;
	char	*mass;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (s2 == NULL)
		return (NULL);
	mass = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 2);
	if (!mass)
		return (0);
	y = 0;
	x = 0;
	while (s1[y])
		mass[x++] = s1[y++];
	y = 0;
	while (s2[y])
		mass[x++] = s2[y++];
	mass[x] = '\0';
	free(s1);
	return (mass);
}

char	*ft_strchr(const char *s, char c)
{
	char	*str;
	char	g;

	if (!s)
		return (NULL);
	str = (char *)s;
	g = (char)c;
	while (*str)
	{
		if (*str == g)
			return (str);
		else
			str++;
	}
	return (NULL);
}
