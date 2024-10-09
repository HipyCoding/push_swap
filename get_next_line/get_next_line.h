/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christian <christian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:08:38 by christian         #+#    #+#             */
/*   Updated: 2024/10/09 15:55:02 by christian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

char	        *get_next_line(int fd);

char            *ft_substr(char const *s, unsigned int start, size_t len);
char            *ft_strjoin(char *s1, char const *s2);
char	        *ft_strdup(const char *s1);
size_t	        ft_strlen(const char *str);
char	        *ft_strchr(const char *s, int c);

#endif
