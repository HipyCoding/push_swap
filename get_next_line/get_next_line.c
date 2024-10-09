/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christian <christian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:07:36 by christian         #+#    #+#             */
/*   Updated: 2024/10/09 16:05:29 by christian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *safe)
{
	int		check;
	char	*buffer;

	check = 1;
	buffer = malloc (sizeof (char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free (safe);
		return (NULL);
	}
	while (check && !ft_strchr(safe, '\n'))
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
		{
			free (buffer);
			free (safe);
			return (NULL);
		}
		buffer[check] = '\0';
		safe = ft_strjoin(safe, buffer);
	}
	free (buffer);
	return (safe);
}

static char	*ft_next(char **stash)
{
	char	*p;
	char	*line;

	p = stash[0];
	while (*p && *p != '\n')
		p++;
	if (*p == '\n')
		p++;
	line = ft_substr(stash[0], 0, (size_t)(p - stash[0]));
	if (!line)
	{
		free (*stash);
		return (NULL);
	}
	p = ft_substr(&p[0], 0, ft_strlen(p));
	if (!p)
	{
		free (*stash);
		return (NULL);
	}
	free (*stash);
	*stash = p;
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*safe;
	char			*ret;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!safe)
		safe = ft_strdup("");
	if (!safe)
		return (NULL);
	safe = ft_read (fd, safe);
	if (!safe || !*safe)
	{
		free (safe);
		safe = NULL;
		return (NULL);
	}
	ret = ft_next(&safe);
	return (ret);
}

// #include <stdio.h>
// #include <fcntl.h>
// #include "get_next_line.h" 

// int main(void)
// {
//   int    fd;
//   char  *next_line;
//   int  count;

//   count = 0;
//   fd = open("test.txt", O_RDONLY);
//   while (1)
//   {
//     next_line = get_next_line(fd);
//     if (next_line == NULL)
//       break ;
//     count++;
//     printf("[%d]:%s\n", count, next_line);
//     next_line = NULL;
//   }
//   close(fd);
//   return (0);
// }
