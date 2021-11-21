/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:20:43 by cjang             #+#    #+#             */
/*   Updated: 2021/11/21 18:48:28 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_gnl_strdup(const char *s1)
{
	size_t		i;
	size_t		len;
	char		*cp;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	cp = (char *)malloc(len + 1);
	if (!cp)
		return (NULL);
	while (i < len + 1)
	{
		cp[i] = s1[i];
		i++;
	}
	return (cp);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	char	*s1s2;
	size_t	len[2];
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_gnl_strdup(s2));
	else if (!s2)
		return (ft_gnl_strdup(s1));
	len[0] = ft_gnl_strlen(s1);
	len[1] = ft_gnl_strlen(s2);
	s1s2 = (char *)malloc(len[0] + len[1] + 1);
	if (!s1s2)
		return (NULL);
	while (*s1)
		s1s2[i++] = *s1++;
	while (*s2)
		s1s2[i++] = *s2++;
	s1s2[i] = 0;
	return (s1s2);
}
