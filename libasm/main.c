/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:24:58 by wben-sai          #+#    #+#             */
/*   Updated: 2021/01/01 16:55:19 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

unsigned long	ft_strlen(char*);
char			*ft_strcpy(char*, char*);
int				ft_strcmp(char*, char*);
size_t			ft_write(int, const void*, size_t);
size_t			ft_read(int, void*, size_t);
char			*ft_strdup(char*);

int main()
{

    printf("============== test ft_strlen ================\n");
    char *test_len0 = "abcdef";
    char *test_len1 = "abc ddss def";
    char *test_len2 = "fsfdsf sdvdsdsfdsf\0 sdfdsf";
    char *test_len3 = "";
    
    printf("strlen :    %lu \n", strlen(test_len0));
    printf("ft_strlen : %lu \n\n", ft_strlen(test_len0));
    
    printf("strlen :    %lu \n", strlen(test_len1));
    printf("ft_strlen : %lu \n\n", ft_strlen(test_len1));
    
    printf("strlen :    %lu \n", strlen(test_len2));
    printf("ft_strlen : %lu \n\n", ft_strlen(test_len2));
    
    printf("strlen :    %lu \n", strlen(test_len3));
    printf("ft_strlen : %lu \n\n", ft_strlen(test_len3));
    printf("==============================================\n");
    
    printf("============== test ft_strcpy ================\n");
    char test_cpy0[7]  = "abcdef";
    char test_cpy1[7]  = "abcdef";
    char test_cpy2[11] = "ab  cde  f";
    char test_cpy3[24] = "ab dfdf dfdf dfgdf cdef";
    char test_cpy4[39] = "abcdfv dfdv dfdf df   c cdvd   dfdf def";
    char test_cpy5[30] = "abcdfv dfdv dffghfgb \0 sdfsdf";
    char test_cpy6[1]  = "";
    
    
    printf("strcpy :    \"%s\" \n",  strcpy(test_cpy1, test_cpy0));
    printf("ft_strcpy : \"%s\" \n\n",  ft_strcpy(test_cpy1, test_cpy0));

    printf("strcpy :    \"%s\" \n", strcpy(test_cpy3, test_cpy2));
    printf("ft_strcpy : \"%s\" \n\n", ft_strcpy(test_cpy3, test_cpy2));

    printf("strcpy :    \"%s\" \n", strcpy(test_cpy4, test_cpy5));
    printf("ft_strcpy : \"%s\" \n\n", ft_strcpy(test_cpy4, test_cpy5));
    
    printf("strcpy :    \"%s\" \n", strcpy(test_cpy2, test_cpy6));
    printf("ft_strcpy : \"%s\" \n\n", ft_strcpy(test_cpy2, test_cpy6));
    printf("==============================================\n");
    
    printf("============== test ft_strcpy ================\n");
    char test_cmp0[7]  = "abcdef";
    char test_cmp1[7]  = "abcdef";
    char test_cmp2[11] = "ab  cde  f";
    char test_cmp3[24] = "ab dfdf dfdf dfgdf cdef";
    char test_cmp4[39] = "abcdfv dfdv dfdf df   c cdvd   dfdf def";
    char test_cmp5[30] = "abcdfv dfdv dffghfgb \0 sdfsdf";
    char test_cmp6[1]  = "";
    
    
    printf("strcmp :    \"%d\" \n",  strcmp(test_cmp1, test_cmp0));
    printf("ft_strcmp : \"%d\" \n\n",  ft_strcmp(test_cmp1, test_cmp0));

    printf("strcmp :    \"%d\" \n", strcmp(test_cmp3, test_cmp2));
    printf("ft_strcmp : \"%d\" \n\n", ft_strcmp(test_cmp3, test_cmp2));

    printf("strcmp :    \"%d\" \n", strcmp(test_cmp4, test_cmp5));
    printf("ft_strcmp : \"%d\" \n\n", ft_strcmp(test_cmp4, test_cmp5));
    
    printf("strcmp :    \"%d\" \n", strcmp(test_cmp2, test_cmp6));
    printf("ft_strcmp : \"%d\" \n\n", ft_strcmp(test_cmp2, test_cmp6));
    printf("==============================================\n");
    
    printf("============== test ft_write ================\n");
    
    printf("==%zd==\n", write(1,NULL, 6));
    printf("==%zd==\n\n", ft_write(1, NULL, 6));

    printf("==%zd==\n", write(1,"hi", 2));
    printf("==%zd==\n\n", ft_write(1, "hi", 2));

    printf("==%zd==\n", write(10,"", 6));
    printf("==%zd==\n\n", ft_write(10, "", 6));

    printf("==%zd==\n", write(10,NULL, 6));
    printf("==%zd==\n\n", ft_write(10, NULL, 6));

    printf("==%zd==\n", write(1,NULL, 6));
    printf(" Value of errno: %d\n", errno);
    printf("==%zd==\n", ft_write(1, NULL, 6));
    printf(" Value of errno: %d\n\n", errno);

    printf("==%zd==\n", write(55,"NULL", 6));
    printf(" Value of errno: %d\n", errno);
    printf("==%zd==\n", ft_write(55, "NULL", 6));
    printf(" Value of errno: %d\n\n", errno);
    
    int fd_w = open("aa.txt",   O_CREAT | O_RDWR , 777); 
    write(fd_w, "aa", 2);
    close(fd_w);
    
    int fd_w2 = open("bb.txt",  O_CREAT | O_RDWR , 777); 
    ft_write(fd_w2, "aa", 2);
    close(fd_w2);
    
    printf("==============================================\n");

    printf("============== test ft_read ==================\n");
    char *buff;
    char *buff2;
    
    buff = malloc(sizeof(char *) * 3);
    buff2 = malloc(sizeof(char *) * 3);

    int fd_r = open("aa.txt",  O_RDONLY , 777); 
    printf("%zd\n", read(fd_r, buff, 2));
    buff[2] = '\0';
    printf("=%s=\n",buff);
    close(fd_r);
    
    int fd_r2 = open("bb.txt", O_RDONLY , 777); 
    printf("%zd\n", ft_read(fd_r2, buff2, 2));
    buff2[2] = '\0';
    printf("=%s=\n\n",buff2);
    close(fd_r2);
        
    printf("%zd\n", read(55, buff, 4));
    printf(" Value of errno: %d\n", errno);
    printf("%zd\n", ft_read(55, buff2, 4));
    printf(" Value of errno: %d\n", errno);
    
    
    printf("==============================================\n"); 
    
    printf("============== test ft_strdup ================\n");

    printf("==%s==\n", ft_strdup("123456"));
    printf("==%s==\n\n", strdup("123456"));

    printf("==%s==\n", ft_strdup(""));
    printf("==%s==\n\n", strdup(""));

    printf("==%s==\n", ft_strdup("123  456"));
    printf("==%s==\n\n", strdup("123  456"));

    char *s = ft_strdup("gg fb  fgfd");
    char *s2 = strdup("gg fb  fgfd");

    printf("==%s==\n", s);
    printf("==%s==\n\n", s2);
    
    
    printf("==============================================\n"); 
    
    return(0);
}

