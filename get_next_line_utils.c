#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char		*destination;
	char		*pointer;
	size_t		len;

	len = 0;
	while (s1[len])
	{
		len++;
	}
	destination = malloc (len + 1);
	if (destination == NULL)
		return (destination);
	pointer = destination;
	while (*s1)
	{
		*pointer = *s1;
		pointer++;
		s1++;
	}
	*pointer = '\0';
	return (destination);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	i;
	char	*pointer;

	i = 0;
	s1len = ft_strlen (s1);
	s2len = ft_strlen (s2);
	pointer = malloc (s1len + s2len + 1);
	if (pointer == NULL)
		return (pointer);
	while (s1[i] != '\0')
	{
		pointer[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{	
		pointer[s1len + i] = s2[i];
		i++;
	}
	pointer[s1len + s2len] = '\0';
	return (pointer);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (i >= 0)
	{
		if (s[i] == (unsigned char) c)
			return (&((char *)s)[i]);
		if (s[i] == '\0')
			return (&((char *)s)[i]);
		i++;
	}	
	return (0);
}

char	*copy_sentence(char *string)
{
	size_t	i;
	size_t	size;
	char	*sentence;

	size = ft_strlen(string) - ft_strlen(ft_strchr(string, '\n'));
	sentence = malloc(sizeof(char) * (size + 2));
	if (!sentence)
		return (NULL);
	i = 0;
	while (i < size)
	{
		sentence[i] = string[i];
		i++;
	}
	sentence[i] = '\n';
	sentence[i + 1] = '\0';
	return (sentence);
}

char	*ft_remainder(char *string)
{
	char	*temp;

	temp = ft_strchr(string, '\n') + 1;
	if (*temp)
	{
		temp = ft_strdup(temp);
		if (!temp)
			return (0);
		free(string);
		return (temp);
	}
	free(string);
	return (0);
}
