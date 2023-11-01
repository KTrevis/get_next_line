#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

int		ft_strlen(char *str);
int		eol_found(char *str, int len);
char	*ft_strdup(char *src, int len);
char	*ft_strjoin(char *file, char *buffer, int dest_len);
char	*get_next_line(int fd);

#endif
