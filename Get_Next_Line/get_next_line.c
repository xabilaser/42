/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:32:53 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/10/13 15:35:28 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_check_filebt(int filebt, char *bffr)
{
	if (filebt == -1)
		free(bffr);
}

char	*get_next_line(int fd)
{
	int			filebt;
	static char	*holder;
	char		*bffr;
	char		*dest;

	filebt = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bffr = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!bffr)
		return (NULL);
	while (!ft_strchr(holder, '\n') && !ft_strchr(holder, '\0') && filebt != 0)
	{
		filebt = read(fd, bffr, BUFFER_SIZE);
		ft_check_filebt(filebt, bffr);
		if (filebt == -1)
			return (NULL);
		bffr[filebt] = '\0';
		holder = ft_strjoin(holder, bffr);
	}
	free(bffr);
	dest = ft_get_line(holder);
	holder = ft_update_holder(holder);
	return (dest);
}

int	main(void)
{
	char	*dest;
	int		fd;

	fd = "01234567890123456789012345678901234567890";
	dest = get_next_line(fd);
	return(dest);
}
