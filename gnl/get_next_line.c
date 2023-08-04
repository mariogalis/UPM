/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:08:23 by ceaizkor          #+#    #+#             */
/*   Updated: 2023/08/04 14:47:30 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_rest(char *all)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (all[i] && all[i] != '\n')
		i++;
	if (!all[i])
	{
		free(all);
		return (NULL);
	}
	str = (char *)(malloc(sizeof(char) * (ft_strlen(all) - i)));
	if (!str)
	{
		free(all);
		return (NULL);
	}
	i++;
	j = 0;
	while (all[i])
		str[j++] = all[i++];
	str[j] = '\0';
	free(all);
	return (str);
}

static char	*ft_getline(char *line)
{
	int		c;
	char	*new;

	c = 0;
	if (!line)
		return (NULL);
	while (line[c] && line[c] != '\n')
		c++;
	new = (char *)malloc(sizeof(char) * (c + 2));
	if (!new)
		return (NULL);
	c = 0;
	while (line[c] && line[c] != '\n')
	{
		new[c] = line[c];
		c++;
	}
	if (line[c] == '\n')
	{
		new[c] = line[c];
		c++;
	}
	new[c] = '\0';
	return (new);
}

static char	*ft_read(int fd, char *all)
{
	char	*line;
	int		rd_bytes;

	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(all, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, line, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(all);
			free(line);
			return (NULL);
		}
		line[rd_bytes] = '\0';
		all = ft_strjoin(all, line);
	}
	free(line);
	return (all);
}

char	*get_next_line(int fd)
{
	char		    *line;
	static char	    *all;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	all = ft_read(fd, all);
	if (!all)
		return (NULL);
	line = ft_getline(all);
	all = ft_rest(all);
	return (line);
}
