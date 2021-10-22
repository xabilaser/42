/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:37:14 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/10/13 15:24:00 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int		i;
	size_t	j;

	i = 0;
	j = ft_strlen(str);
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[j]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i] != '\0')
		{
			dest[i] = s1[i];
			i++;
		}
	while (s2[j] != '\0')
		dest[i++] = s2[j++];
	dest[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (dest);
}

char	*ft_get_line(char *file)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!file[0])
		return (NULL);
	while (file[i] != '\n' && file[i])
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (file[i] != '\n' && file[i])
	{
		line[i] = file[i];
		i++;
	}
	if (file[i] == '\n')
	{
		line[i] = file [i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_update_holder(char *file)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	while (file[i] != '\n' && file[i])
		i++;
	if (!file[i])
	{
		free(file);
		return (NULL);
	}
	dest = (char *)malloc(sizeof(char) * (ft_strlen(file) - i + 1));
	if (!dest)
		return (NULL);
	i++;
	j = 0;
	while (file[i])
		dest[j++] = file[i++];
	dest[j] = '\0';
	free(file);
	return (dest);
}
