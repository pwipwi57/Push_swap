/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:51:10 by tlamarch          #+#    #+#             */
/*   Updated: 2024/04/08 16:19:09 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	stash[100][BUFFER_SIZE];
	char		*tempbuf;
	ssize_t		charread;
	int			stopn;

	tempbuf = malloc(1);
	if (tempbuf == NULL || !(-1 < fd && fd < 100))
		return (free(tempbuf), NULL);
	initvar(tempbuf, &charread);
	if (checkempty(stash[fd]))
		ft_test_backn(&tempbuf, stash[fd], checkempty(stash[fd]), &charread);
	while (charread > 0)
	{
		charread = read(fd, stash[fd], BUFFER_SIZE);
		if (charread == -1 || (!stash[fd][0] && !tempbuf[0]))
			return (free(tempbuf), NULL);
		stopn = checkbackn(stash[fd]);
		tempbuf = ft_realloc(tempbuf, stash[fd], 0);
		if (tempbuf == NULL)
			return (NULL);
		if (stopn != BUFFER_SIZE)
			break ;
	}
	return (tempbuf);
}

int	checkempty(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] != 0)
			return (i);
		i++;
	}
	return (0);
}

int	checkbackn(char *buf)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (BUFFER_SIZE);
}

void	*ft_realloc(char *tempbuf, char *buffer, int begin)
{
	int		sizebuf;
	int		sizebuffer;
	char	*newbuffer;

	sizebuf = ft_strlenp(tempbuf, 0, 1);
	sizebuffer = ft_strlenp(buffer, begin, 2) - begin;
	newbuffer = NULL;
	newbuffer = malloc(sizeof(char) * (sizebuf + sizebuffer + 1));
	if (newbuffer == NULL)
		return (free(tempbuf), (NULL));
	newbuffer[0] = 0;
	ft_strcat(newbuffer, tempbuf, 0, 1);
	ft_strcat(newbuffer, buffer, begin, 2);
	free(tempbuf);
	return (newbuffer);
}

int	ft_strlenp(char *tempbuf, int begin, int mod)
{
	int	i;

	if (tempbuf == NULL)
		return (0);
	i = begin;
	if (mod == 1)
		while (tempbuf[i])
			i++;
	else if (mod == 2)
		while (i < BUFFER_SIZE && tempbuf[i] && tempbuf[i] != '\n')
			i++;
	if (i < BUFFER_SIZE && tempbuf[i] == '\n')
		i++;
	return (i);
}

// #include <fcntl.h>
// #include <fcntl.h>

// int main(void)
// {
//     int fd;
// 		char *line;
//     fd = open("test.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Erreur lors de l'ouverture du fichier");
//         return 1;
//     }
//     line = get_next_line(fd);
//     while (line != NULL)
//     {
//         printf("%s //", line);
//         free(line); // Libérer la mémoire de la ligne lue
//         line = get_next_line(fd);
//     }
// 	free (line);
//     close(fd); // N'oubliez pas de fermer le fichier à la fin
//     return 0;
// }
