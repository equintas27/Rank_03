/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equintas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:13:07 by equintas          #+#    #+#             */
/*   Updated: 2026/02/02 12:41:09 by equintas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strchr(char *s, int c)
{
	int i;

	if (!s)
		return (NULL);
	i = 0;

	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
	
	if (!dest || !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

size_t ft_strlen(char *s)
{
  size_t i = 0;
  if (!s)
	  return (0);
  while (s[i])
  {
	  i++;
  }
  return (i);
}

int str_append_mem(char **s1, char *s2, size_t size2)
{
  size_t size1 = ft_strlen(*s1);
  char *tmp = malloc(size2 + size1 + 1);
  if (!tmp)
    return 0;
  if (*s1)
  	ft_memcpy(tmp, *s1, size1);
  ft_memcpy(tmp + size1, s2, size2);
  tmp[size1 + size2] = '\0';
  if (*s1)
 	 free(*s1);
  *s1 = tmp;
  return 1; 
}

int str_append_str(char **s1, char *s2)
{
  return str_append_mem(s1, s2, ft_strlen(s2));
}

char *get_next_line(int fd)
{
  static char b[BUFFER_SIZE + 1] = "";
  char *ret = NULL;
  char *tmp = ft_strchr(b, '\n');
  while(!tmp)
  {
    if (!str_append_str(&ret, b))
      return (NULL);
    int read_ret = read(fd, b, BUFFER_SIZE);
    if (read_ret <= 0)
    {
	b[0] = 0;
	if (read_ret == 0 && ret && *ret)
		return (ret);
	free (ret);
	return (NULL);
    }
    b[read_ret] = 0;
    tmp = ft_strchr(b, '\n');
  }
  if (!str_append_mem(&ret, b, tmp - b + 1))
  {
    free(ret);
    return NULL;
  }
  char *rest = tmp + 1;
  int i = 0;
  while (rest[i])
  {
	  b[i] = rest[i];
	  i++;
  }
  b[i] = 0;
  return ret;
}

