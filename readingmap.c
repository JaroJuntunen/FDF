/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readingmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:58:47 by jjuntune          #+#    #+#             */
/*   Updated: 2022/02/03 15:23:25 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*fillarrey(int *arrey, char *line)
{
	int		i;
	int		j;
	int		x;
	char	temp[100];

	i = 0;
	x = 0;
	while (line[i] != '\0')
	{
		j = 0;
		while (line[i] != '\0' && line[i] == ' ')
			i++;
		while (line[i] != '\0' &&  line[i] >= '0' && line[i] <= '9')
		{
			temp[j] = line[i];
			i++;
			j++;
		}
		temp[j] = '\0';
		arrey[x] = ft_atoi(temp);
		x++;
	}
	return (arrey);
}

int		*create_arrey(char *line)
{
	int *arrey;
	int nbrcount;
	int *tmp;

	nbrcount = ft_wordcount(line , ' ');
	arrey = (int *)malloc((sizeof(int) * nbrcount));
	if (arrey == NULL)
		return (NULL);
	tmp = fillarrey(arrey, line);
	return (tmp);
}

int		file_line_len(char **argv, char *line)
{
	int line_count;
	int fd;

	fd = open(argv[1], O_RDONLY);
	line_count = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ft_strdel(&line);
		line_count++;
	}
	close(fd);
	return (line_count);
}

int		**readcoordinates(char **argv)
{
	int	**coordinates;
	int	z;
	int	fd;
	int	len;
	char *line;

	z = 0;
	len = file_line_len(argv, line);
	coordinates = (int **)malloc((sizeof(int *) * len));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (z < len)
	{

		if (get_next_line(fd, &line) > 0)
		{
			coordinates[z++] = create_arrey(line);
		}
		ft_strdel(&line);
	}
	close(fd);
	coordinates[z] = NULL;
	return (coordinates);
}
