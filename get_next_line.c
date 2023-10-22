/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:49:40 by ketrevis          #+#    #+#             */
/*   Updated: 2023/10/22 13:46:20 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	eol_found(char *buffer, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*update_stash(char *stash, char *buffer, int n)
{
	char	*temp;
	int		i;
	int		j;

	if (!stash)
		return (ft_strdup(buffer, n));
	i = 0;
	j = 0;
	temp = malloc((ft_strlen(stash) + n + 1) * sizeof(char));
	while (stash[i])
	{
		temp[i] = stash[i];
		i++;
	}
	while (j < n)
		temp[i++] = buffer[j++];
	temp[i] = '\0';
	free(stash);
	return (temp);
}

char	*get_curr_line(char *stash, char *buffer) 
{
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	free(buffer);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i] = '\n';
	line[i] = '\0';
	temp = ft_strdup(&stash[i + 1], ft_strlen(stash) - i);
	free(stash);
	stash = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	int		n;
	static char	*stash;

	n = 1;
	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	while (n)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n <= 0)
			return (NULL);
		// printf("Buffer\n");
		// for (int i = 0; i < n; i++)
		// 	printf("%c", buffer[i]);
		// printf("\n");
		stash = update_stash(stash, buffer, n);
		if (eol_found(buffer, n))
			return (get_curr_line(stash, buffer));
		free(buffer);
		buffer = malloc(BUFFER_SIZE);
	}
	return (NULL);
}

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
}
