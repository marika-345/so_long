/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumberi <mgumberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:00:00 by mgumberi          #+#    #+#             */
/*   Updated: 2026/05/07 12:00:00 by mgumberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*read_all(int fd)
{
	char	buf[READ_BUF + 1];
	char	*res;
	char	*tmp;
	ssize_t	n;

	res = ft_strdup("");
	if (!res)
		return (NULL);
	n = read(fd, buf, READ_BUF);
	while (n > 0)
	{
		buf[n] = '\0';
		tmp = ft_strjoin(res, buf);
		free(res);
		if (!tmp)
			return (NULL);
		res = tmp;
		n = read(fd, buf, READ_BUF);
	}
	if (n < 0)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

static int	validate_content(const char *s)
{
	int	i;

	if (!s || !*s || s[0] == '\n')
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}

static void	strip_trailing_nl(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if (len > 0 && s[len - 1] == '\n')
		s[len - 1] = '\0';
}

static int	read_and_split(t_game *g, int fd)
{
	char	*content;

	content = read_all(fd);
	if (!content)
		return (0);
	if (!validate_content(content))
	{
		free(content);
		return (0);
	}
	strip_trailing_nl(content);
	g->map.grid = ft_split(content, '\n');
	free(content);
	if (!g->map.grid || !g->map.grid[0])
		return (0);
	return (1);
}

int	load_map(t_game *g, const char *path)
{
	int	fd;
	int	ret;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	ret = read_and_split(g, fd);
	close(fd);
	return (ret);
}
