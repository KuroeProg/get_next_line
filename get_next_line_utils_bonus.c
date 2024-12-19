/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:51:40 by cfiachet          #+#    #+#             */
/*   Updated: 2024/11/13 23:47:29 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size;
	char	*strf;
	size_t	i;
	size_t	y;

	y = 0;
	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	strf = (char *)malloc(size + 1);
	if (!strf)
		return (free(s1), NULL);
	while (s1[i])
	{
		strf[i] = s1[i];
		i++;
	}
	while (s2[y])
	{
		strf[i + y] = s2[y];
		y++;
	}
	strf[i + y] = '\0';
	return (free(s1), strf);
}

char	*ft_strdup(char *s)
{
	char	*dest;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s);
	dest = malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (dest);
	else
	{
		while (s[i])
		{
			dest[i] = s[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
