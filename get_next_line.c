/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:24:23 by ketrevis          #+#    #+#             */
/*   Updated: 2023/11/02 17:32:56 by ketrevis         ###   ########.fr       */
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

char	*get_curr_line(char **src)
{
	int		i;
	char	*str;
	char	*file;

	i = 0;
	file = *src;
	while (file[i] != '\0' && file[i] != '\n')
		i++;
	if (file[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (str);
	i = -1;
	while (file[++i] != '\0' && file[i] != '\n')
		str[i] = file[i];
	if (file[i] == '\n')
	{
		str[i] = file[i];
		i++;
	}
	str[i] = '\0';
	if (file[i] != '\0')
	{
		*src = ft_strdup(&file[i], ft_strlen(file) - i);
		free(file);
	}
	return (str);
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
		if (n < BUFFER_SIZE)
			return (get_curr_line(&file));
		if (eol_found(file))
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
}
