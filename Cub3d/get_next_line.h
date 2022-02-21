/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:57:42 by wben-sai          #+#    #+#             */
/*   Updated: 2020/01/10 12:43:56 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

int		ft_strlen(char *s);
int		chr_bn(char *was_read);
char	*ft_strjoin(char *s1, char *s2);
int		get_next_line(int fd, char **line);
int		chck_save(char **save, char **line);
int		read_fd(char **was_read, int *len_read, int fd);
char	*join_last_cs(char **was_read, char **new_lin, char **save);
char	*new_line(int fd, char **was_read, int *len_read, char **save);
char	*last_cs_save(int *len_read, char **save, char **line, char **was_read);

#endif
