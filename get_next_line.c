/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 16:46:24 by qfrederi      #+#    #+#                 */
/*   Updated: 2021/12/13 16:46:25 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*print_sentence(int fd, char **string, int ret)
{
	char	*tmp;

	if (*ft_strchr(*string, '\n'))
	{
		tmp = copy_sentence(*string);
		if (!tmp)
			return (tmp);
		*string = ft_remainder(*string);
		return (tmp);
	}
	else if (ret != 0)
		return (get_next_line(fd));
	tmp = *string;
	*string = NULL;
	return (tmp);
}

char	*join_string(int fd, char **string, int ret, char *buffer)
{
	char	*tmp;

	if (*string == NULL && ret == 0)
		return (NULL);
	if (*string == NULL && ret)
	{
		*string = ft_strdup(buffer);
		if (!*string)
			return (NULL);
	}
	else
	{
		tmp = ft_strjoin(*string, buffer);
		if (!tmp)
			return (NULL);
		if (string)
			free(*string);
		*string = tmp;
	}
	return (print_sentence(fd, &*string, ret));
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		buffer[BUFFER_SIZE + 1];
	int			ret;

	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret < 0)
		return (NULL);
	buffer[ret] = '\0';
	return (join_string(fd, &string, ret, buffer));
}
