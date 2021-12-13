#ifndef GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*copy_sentence(char *string);
char	*ft_remainder(char *string);
char	*ft_strchr(const char *s, int c);
char	*join_string(int fd, char **string, int ret, char *buffer);
char	*print_sentence(int fd, char **string, int ret);

#endif