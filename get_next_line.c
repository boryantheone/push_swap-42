/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollin <jcollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:03:51 by jcollin           #+#    #+#             */
/*   Updated: 2021/12/27 19:19:00 by jcollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_del_line(char *ost)
{
	int		i;
	int		j;
	char	*new_ost;

	i = 0;
	while (ost[i] && ost[i] != '\n')
		i++;
	if (!ost[i])
	{
		free (ost);
		return (NULL);
	}
	new_ost = (char *)malloc(sizeof(char) * (ft_strlen(ost) - i + 1));
	if (!new_ost)
		return (NULL);
	i++;
	j = 0;
	while (ost[i] != '\0')
		new_ost[j++] = ost[i++];
	new_ost[j] = '\0';
	free (ost);
	return (new_ost);
}

char	*ft_check_ost(char *ost)
{
	int		i;
	char	*line;

	i = 0;
	if (ost[0] == '\0')
		return (NULL);
	while (ost[i] && ost[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (ost[i] && ost[i] != '\n')
	{
		line[i] = ost[i];
		i++;
	}
	if (ost[i] == '\n')
	{
		line[i] = ost[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read(char *str, int fd)
{
	char	*buf;
	int		was_read;

	was_read = 1;
	buf = (char *)malloc((sizeof(char) * 2));
	if (!buf)
		return (NULL);
	while (!ft_strchr(str, '\n') && was_read != 0)
	{
		was_read = read(fd, buf, 1);
		if (was_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[was_read] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*ost;
	char		*line;

	if (fd < 0)
		return (NULL);
	ost = ft_read(ost, fd);
	if (!ost)
		return (NULL);
	line = ft_check_ost(ost);
	ost = ft_del_line(ost);
	return (line);
}
