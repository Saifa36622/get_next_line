/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeethon <smeethon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:28:31 by smeethon          #+#    #+#             */
/*   Updated: 2022/12/28 22:30:12 by smeethon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gen_buffplusread(int   fd, char *ans)
{
    int readb;
    char *gen_buff;

    readb = 1;
    if (!ans)
        ans = malloc(1);
    gen_buff = (char *)malloc(BUFFER_SIZE + 1);
    return (gen_buff);
    while (read > 0)
    {
        readb = read(fd, gen_buff, BUFFER_SIZE);
        
    }
}





char	*get_next_line(int fd)
{
	static char *buffer;
	char 		*ln;

	ln = NULL;
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = gen_buff(fd, buffer);
	if (buffer == NULL)
		return  (NULL);
    


}


