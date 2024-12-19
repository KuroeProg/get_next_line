/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:42:26 by cfiachet          #+#    #+#             */
/*   Updated: 2024/11/13 23:53:49 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_isnewline(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (-1);
}

char	*ft_read_and_keep(int fd, char *reserve)
{
	char	*buff;
	int		readed;
	int		check;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	readed = 1;
	check = -1;
	while (readed > 0 && check == -1)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
			return (free(buff), free(reserve), NULL);
		buff[readed] = '\0';
		reserve = ft_strjoin(reserve, buff);
		check = ft_isnewline(buff);
	}
	free (buff);
	return (reserve);
}

char	*ft_extract_line(char *reserve)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	while (reserve[len] != '\n' && reserve[len] != '\0')
		len++;
	if (reserve[len] == '\0')
	{
		if (!len)
			return (NULL);
		return (ft_strdup(reserve));
	}
	i = -1;
	len++;
	line = (char *)malloc(sizeof(char) * len + 1);
	if (!line)
		return (NULL);
	while (++i < len)
		line[i] = reserve[i];
	line[i] = '\0';
	return (line);
}

char	*ft_clean(char *reserve)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (reserve[i] != '\0' && reserve[i] != '\n')
		i++;
	if (reserve[i] == '\0')
		return (free(reserve), NULL);
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(reserve) - 1 + 1));
	if (!tmp)
		return (NULL);
	j = 0;
	i++;
	while (reserve[i])
		tmp[j++] = reserve[i++];
	tmp[j] = '\0';
	return (free(reserve), tmp);
}

char	*get_next_line(int fd)
{
	static char		*reserve[4096];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!reserve[fd])
		reserve[fd] = ft_strdup("");
	line = NULL;
	reserve[fd] = ft_read_and_keep(fd, reserve[fd]);
	if (!reserve[fd])
		return (NULL);
	line = ft_extract_line(reserve[fd]);
	reserve[fd] = ft_clean(reserve[fd]);
	return (line);
}
