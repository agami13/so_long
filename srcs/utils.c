/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:50:50 by ybouaoud          #+#    #+#             */
/*   Updated: 2024/04/26 12:36:51 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void read_helper(char *line, char **map, char *argv)
{
	int		bytes;
	char	*temp;
	int		fd;
	
	fd = open(argv, O_RDONLY);
	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, line, 1);
		if (bytes == -1)
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("Can't read the map\n", 2);
			close(fd);
			free(line);
			free(*map);
			exit(1);
		}
		line[bytes] = '\0';
		temp = ft_strjoin(*map, line);
		free(*map);
		*map = temp;
	}
	close(fd);
}

char	*read_map(char *argv)
{
	char	*map;
	char	*line;
	map = malloc(1);
	map[0] = '\0';
	line = malloc(2);
	if (!line || !map)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Memory allocation failed\n", 2);
		exit(1);
	}
	read_helper(line, &map, argv);
	free(line);
	ft_printf("%s\n", map);
	return (map);
}