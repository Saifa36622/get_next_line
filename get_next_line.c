/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeethon <smeethon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:28:31 by smeethon          #+#    #+#             */
/*   Updated: 2022/12/28 22:13:49 by smeethon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *gen_buff(char *buffer)
{

}





char *get_next_line(int fd)
{
    static char *buffer;
    char *ln;

    ln = NULL;
    if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
    buffer = gen_buff(buffer);
    if (buffer == NULL)
        return  (NULL);
    


}


