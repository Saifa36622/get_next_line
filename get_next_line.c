/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeethon <smeethon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:28:31 by smeethon          #+#    #+#             */
/*   Updated: 2022/12/28 23:21:07 by smeethon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *getli

char    *freetmp(char *ans,char *buff)
{
        char    *tmp;
        tmp = ft_strjoin(ans, buff);
        free(buff);
        return (tmp);
}

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
        if (readb == -1)
        {
            free(gen_buff);
            return(NULL);
        }
        gen_buff[readb] = 0;
        ans = freetmp(ans, gen_buff);
        if (ft_strchr(gen_buff,'\n'))
            break;
    }
    free(gen_buff);
    return (ans);
}

char	*get_next_line(int fd)
{
	static char *buffer;
	char 		*ln;

	ln = NULL;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = gen_buffplusread(fd, buffer);
	if (buffer == NULL)
		return  (NULL);
    line = getline(buffer);
    
    


}


