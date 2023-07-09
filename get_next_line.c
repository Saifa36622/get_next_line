/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeethon <smeethon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:28:31 by smeethon          #+#    #+#             */
/*   Updated: 2023/07/09 23:45:23 by smeethon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *box)
{
	char	*buffer;
	int		checker;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	checker = 1;
	while (checker > 0 && !ft_strchr(box, '\n'))
	{
		checker = read(fd, buffer, BUFFER_SIZE);
		if (checker == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[checker] = '\0';
		box = ft_strjoin(box, buffer);
	}
	free(buffer);
	return (box);
}

char	*ft_make_line(char *ans)
{
	char	*line;
	int		len;
	int		i;

	i = 0;
	len = ft_linelen(ans);
	if (!ans[0])
		return (NULL);
	line = malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = ans[i];
		i++;
	}
	if (ans[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_keep_buffer(char *ans)
{
	char	*line;
	int		len;
	int		i;

	i = 0;
	len = ft_linelen(ans);
	if (!ans[len])
	{
		free(ans);
		return (NULL);
	}
	line = malloc(sizeof(char) * (strlen(ans) - len + 1));
	if (!line)
		return (NULL);
	len++;
	while (ans[len])
		line[i++] = ans[len++];
	line[i] = '\0';
	free(ans);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*ans;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (0);
	if (temp == '\0')
	{
		temp = malloc(1);
		temp[0] = '\0';
	}
	return (ans);
}

// int main(void) {
//     int fd;                 // File descriptor
//     char *line;             // Pointer to store the read line
//     int ret_value;          // Return value of get_next_line

//     fd = open("example.txt", O_RDONLY); // Open the file in read-only mode

//     if (fd == -1) {
//         perror("Error opening the file");
//         return 1;
//     }

//     while ((ret_value = get_next_line(fd, &line)) > 0) {
//         printf("%s\n", line);   // Print the line read from the file
//         free(line);             // Free the memory allocated by get_next_line
//     }

//     if (ret_value == -1) {
//         perror("Error reading the file");
//         return 1;
//     }

//     close(fd);              // Close the file

//     return 0;
// }
// ***********************************************************
// read(int fd, void *buf, size_t count);
// - fd is the file descriptor of the file to be read.
// - buf is the buffer where the read content will be stored.
// - count is the maximum number of bytes to be read.
// ***********************************************************

// ans should be static because it will use in keep the str in the fuction 
// everytime we have to call and it will be use in ft_makeline and keep buffer 
// if ans is normal variable ,srtin sotr in ans will not be keep

// ft_make line use to make line ,it input the ans that have 
// str that read with buffer size so this fuction will make line and return
// the line 

// ft keep buffer will take the remain thing that ft make line cut out and left 
// it in ans and store it back to ans with \0 in the end and clear the ans to 
// make it ready to store another buffer
