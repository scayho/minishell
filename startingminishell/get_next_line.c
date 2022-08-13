/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:10:25 by abelahce          #+#    #+#             */
/*   Updated: 2022/08/13 18:51:04 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*take_line(char *line, int fd)
{
	char		*str;
	ssize_t		i;

	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 1;
	while (i != 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free((void *)str);
			return (NULL);
		}
		str[i] = '\0';
		line = ft_strjoin(line, str);
		if (ft_strchr(line, '\n'))
			break ;
	}
	free((void *)str);
	return (line);
}

char	*separate_line(char	*line)
{
	int		i;
	char	*str;

	i = 0;
	if (ft_strlen(line) == 0)
		return (NULL);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str = cpy_line(line, str, i);
	return (str);
}

char	*save_line(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
	{
		free((void *)line);
		return (NULL);
	}
	str = malloc((ft_strlen(line) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i++;
	while (line[i] != '\0')
	{
		str[j] = line[i++];
		j++;
	}
	str[j] = '\0';
	free((void *)line);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*rest;
	static char		*line;

	if ((10240 < fd && fd < 0) || BUFFER_SIZE <= 0)
		return (0);
	line = take_line(line, fd);
	if (!line)
		return (NULL);
	rest = separate_line(line);
	line = save_line(line);
	return (rest);
}
