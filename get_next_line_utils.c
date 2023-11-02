/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:08:19 by ketrevis          #+#    #+#             */
/*   Updated: 2023/11/02 17:08:38 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src, int len)
{
	int		i;
	char	*str;

	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (str);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *file, char *buffer, int buffer_len)
{
	char	*str;
	int		i;
	int		j;

	if (!file)
		return (ft_strdup(buffer, buffer_len));
	str = malloc((ft_strlen(file) + buffer_len + 1) * sizeof(char));
	if (!str)
		return (str);
	i = 0;
	j = 0;
	while (file[i])
	{
		str[i] = file[i];
		i++;
	}
	while (j < buffer_len)
	{
		str[i] = buffer[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(file);
	return (str);
}
