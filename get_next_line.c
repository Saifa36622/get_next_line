/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeethon <smeethon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:28:31 by smeethon          #+#    #+#             */
/*   Updated: 2023/07/10 02:39:18 by smeethon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*readfile(int fd, char *temp)
// {
// 	char	*buffer;
// 	int		checker;

// 	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buffer)
// 		return (NULL);
// 	checker = 1;
// 	while (checker > 0)
// 	{
// 		checker = read(fd, buffer, BUFFER_SIZE);
// 		if (checker < 0)
// 		{
// 			free(buffer);
// 			return (NULL);
// 		}
// 		buffer[checker] = '\0';
// 		temp = ft_strjoin(temp, buffer);
// 		if (ft_find_n(buffer))
// 			break ;
// 	}
// 	free(buffer);
// 	return (temp);
// }
char	*ft_readfile(int fd, char *box)
{
	char	*buffer;
	int		checker;
	char	*temp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	checker = 1;
	while (checker > 0 && !ft_strchr(box, '\n'))
	{
		checker = read(fd, buffer, BUFFER_SIZE);
		if (checker < 0)
			break ;
		buffer[checker] = '\0';
		temp = ft_strjoin(box, buffer);
		free(box);
		box = temp;
	}
	free(buffer);
	if (checker < 0)
	{
		free(box);
		return (NULL);
	}
	return (box);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*ans;
	size_t		ans_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!temp)
	{
		temp = malloc(1);
		temp[0] = '\0';
	}
	temp = readfile(fd, temp);
	if (!temp)
	{
		free (temp);
		return (NULL);
	}
	ans = get_this_line(temp);
	ans_len = ft_strlen_n(ans, '\n');
	temp = keep_this_line(temp, ans_len);
	return (ans);
}

// int main(void) {
//     int fd;                 // File descriptor
//     char *line;             // Pointer to store the read line

//     fd = open("example.txt", O_RDONLY); // Open the file in read-only mode

//     if (fd == -1) {
//         perror("Error opening the file");
//         return 1;
//     }

//     while ((line = get_next_line(fd)) != NULL) {
//         printf("%s\n", line);   // Print the line read from the file
//         free(line);             // Free the memory allocated by get_next_line
//     }

//     close(fd);              // Close the file

//     return 0;
// }
//
// ***********************************************************
// read(int fd, void *buf, size_t count);
// - fd is the file descriptor of the file to be read.
// - buf is the buffer where the read content will be stored.
// - count is the maximum number of bytes to be read.
// ***********************************************************

// temp should be static because it will use in keep the str in the fuction 
// everytime we have to call and it will be use in ft_makeline and keep buffer 
// if temp is normal variable ,str that store in temp will not be keep

// ft_make line use to make line ,it input the temp that have 
// str that read with buffer size so this fuction will make line and return
// the line 

// ft keep buffer will take the remain thing that ft make line cut out and left 
// it in temp and store it back to 
// temp with \0 in the end and clear the temp to 
// make it ready to store another buffer
//
//
// char	*ft_make_line(char *ans)
// {
// 	char	*line;
// 	size_t	len;
// 	size_t	i;

// 	i = 0;
// 	len = ft_linelen(ans);
// 	if (!ans[0])
// 		return (NULL);
// 	line = malloc(sizeof(char) * (len + 2));
// 	if (!line)
// 		return (NULL);
// 	while (i < len)
// 	{
// 		line[i] = ans[i];
// 		i++;
// 	}
// 	if (ans[i] == '\n')
// 		line[i++] = '\n';
// 	line[i] = '\0';
// 	return (line);
// }
