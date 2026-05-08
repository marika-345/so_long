/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumberi <mgumberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:13:37 by mgumberi          #+#    #+#             */
/*   Updated: 2025/02/19 19:47:08 by mgumberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void to_upper(unsigned int i, char *c)
// {
// 	if (i % 2 == 1 && *c >= 'a' && *c <= 'z')
// 		*c = *c - 32;
// }

// int	main(void)
// {
// 	char str[] = "hello world!";
// 	ft_striteri(str, to_upper);
// 	printf("Result: %s\n", str); // Expected: "hElLo wOrLd!"
// 	return (0);
// }
