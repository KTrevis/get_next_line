#ifndef GNL_H
# define GNL_H

#ifndef BUFFER_SIZE
#	define BUFFER_SIZE 1
#endif

#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(char *str, int n);

#endif
