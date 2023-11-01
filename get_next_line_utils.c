/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:22:39 by ketrevis          #+#    #+#             */
/*   Updated: 2023/11/01 18:05:16 by ketrevis         ###   ########.fr       */
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

char	*ft_strdup(char *str, int len)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *file, char *buffer, int buffer_len)
{
	int		i;
	int		j;
	char	*str;
	
	if (!file)
		return (ft_strdup(buffer, buffer_len));
	i = 0;
	j = 0;
	str = malloc((buffer_len + ft_strlen(file) + 1) * sizeof(char));
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
	if (file)
		free(file);
	return (str);
}
