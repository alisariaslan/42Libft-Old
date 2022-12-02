/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:00:30 by ali               #+#    #+#             */
/*   Updated: 2022/12/02 15:15:38 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_read(int fd, char *str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = get_next_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_get_line(str[fd]);
	str[fd] = ft_new_str(str[fd]);
	return (line);
}
