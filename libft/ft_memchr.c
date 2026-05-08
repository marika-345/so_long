/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumberi <mgumberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:47:53 by mgumberi          #+#    #+#             */
/*   Updated: 2025/06/28 14:10:41 by mgumberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*w;
	unsigned char	f;

	i = 0;
	w = (unsigned char *)s;
	f = (unsigned char)c;
	while (i < n)
	{
		if (w[i] == f)
			return ((void *)(w + i));
		i++;
	}
	return (NULL);
}
