/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:24:23 by ketrevis          #+#    #+#             */
/*   Updated: 2023/11/02 17:43:52 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	eol_found(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

int	line_len(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '\0' && file[i] != '\n')
		i++;
	if (file[i] == '\n')
		i++;
	return (i);
}

char	*get_curr_line(char **src)
{
	int		i;
	char	*line;
	char	*file;

	file = *src;
	i = line_len(file);
	if (i == 0)
		return (NULL);
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (line);
	i = -1;
	while (file[++i] != '\0' && file[i] != '\n')
		line[i] = file[i];
	if (file[i] == '\n')
	{
		line[i] = file[i];
		i++;
	}
	line[i] = '\0';
	if (file[i] != '\0')
	{
		*src = ft_strdup(&file[i], ft_strlen(file) - i);
		free(file);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char				*buffer;
	static char	*file;
	int					n;

	n = 1;
	if (fd < 0)
		return (NULL);
	while (n)
	{
		buffer = malloc(BUFFER_SIZE);
		if (!buffer)
			return (buffer);
		n = read(fd, buffer, BUFFER_SIZE);
		file = ft_strjoin(file, buffer, n);
		free(buffer);
		if (n == 0)
			return (NULL);
		if (eol_found(file) || n < BUFFER_SIZE)
			return (get_curr_line(&file));
	}
	return (NULL);
}

int	main(int ac, char **av) {
	(void)ac;
	int fd = open(av[1], O_RDONLY);
	char	*line;

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);
}
