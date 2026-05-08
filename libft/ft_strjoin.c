/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumberi <mgumberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:13:37 by mgumberi          #+#    #+#             */
/*   Updated: 2025/02/19 19:47:08 by mgumberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*joinstr;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joinstr = malloc(len1 + len2 + 1);
	if (!joinstr)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		joinstr[i] = s1[i];
		i++;
	}
	while (i < (len1 + len2))
	{
		joinstr[i] = s2[i - len1];
		i++;
	}
	joinstr[i] = '\0';
	return (joinstr);
}

// int	main(void)
// {
// 	char str1[] = "I lo love dogs";
// 	char str2[] = "what about you?";
//  	printf("%s\n", ft_strjoin(str1, str2));
// }
