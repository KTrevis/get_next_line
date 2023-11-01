/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:33:02 by ketrevis          #+#    #+#             */
/*   Updated: 2023/11/01 17:31:35 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	eol_found(char *buffer, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (buffer[i] == '\n')
		{
			free(buffer);
			return (1);
		}
		i++;
	}
	return (0);
}

char	*get_curr_line(char **file)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	while ((*file)[i] != '\n')
		i++;
	str = malloc((i + 2) * sizeof(char));
	i = 0;
	while ((*file)[i] != '\n')
	{
		str[i] = (*file)[i];
		i++;
	}
	str[i++] = '\n';
	str[i] = '\0';
	tmp = *file;
	*file = ft_strdup(&(*file)[i], ft_strlen(&(*file)[i]));
	free(tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*file;
	char	*buffer;
	int		n;

	buffer = malloc(BUFFER_SIZE);
	n = 1;
	while (n)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		file = ft_strjoin(file, buffer, n);
		if (eol_found(buffer, n))
			return (get_curr_line(&file));
		free(buffer);
		buffer = malloc(BUFFER_SIZE);
	}
	if (buffer)
		free(buffer);
	return (NULL);
}
