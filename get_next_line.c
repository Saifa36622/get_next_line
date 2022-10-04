/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeethon <smeethon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:40:17 by smeethon          #+#    #+#             */
/*   Updated: 2022/10/03 23:49:14 by smeethon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	static char	*size;
	char		*str;

	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0 || fd < 0)
		return (0);
	if (!size)
	{
		size = malloc(1);
		size[0] = '\0';
	}
	size = read_file (size, fd);
	if (!size)
	{
		free(size);
		return (0);
	}
	str = get_the_line(size);
	size = plus_line(size);
	return (str);
}

char	read_file(char *size, int fd)
{
	char	*x;
	int	check;
	x = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!x)
		return (0);

}