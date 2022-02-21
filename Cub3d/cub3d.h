/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:34:52 by wben-sai          #+#    #+#             */
/*   Updated: 2020/12/13 18:21:05 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <string.h>
# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include "get_next_line.h"

typedef	struct		s_list
{
	float			x;
	float			y;
	float			dist;
	char			c;
	struct s_list	*next;
}					t_list;

typedef struct		s_map
{
	char			**disp;
	int				x_map;
	int				y_map;
}					t_map;

struct				s_params_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	void			*dataxmpno;
	int				*dataimgno;
	void			*dataxmpso;
	int				*dataimgso;
	void			*dataxmpwe;
	int				*dataimgwe;
	void			*dataxmpea;
	int				*dataimgea;
	void			*dataxmpsp;
	int				*dataimgsp;
	int				up_down;
	char			*namefile;
	int				width;
	int				height;
	int				i;
	char			*wall_no;
	char			*wall_so;
	char			*wall_we;
	char			*wall_ea;
	char			*sprite;
	int				f;
	int				c;
	int				x_xpm;
	int				y_xpm;
	int				x_2xpm;
	int				y_2xpm;
	int				x_3xpm;
	int				y_3xpm;
	int				x_4xpm;
	int				y_4xpm;
	int				offset;
	float			offsetsprite;
	int				color;
	char			directione;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				len_file;
	float			x_player;
	float			y_player;
	float			toor;
	t_map			str_map;
	float			intersection_hx;
	float			intersection_hy;
	float			intersection_vx;
	float			intersection_vy;
	int				x_print;
	int				y_print;
	float			y_step;
	float			res;
	float			end;
	int32_t			img_width;
	int32_t			img_height;
	uint16_t		img_bitcount;
	int				width_pt;
	uint32_t		imagesize;
	uint32_t		bisize;
	uint32_t		bfoffbits;
	uint32_t		filesize;
	uint16_t		biplanes;
	unsigned char	header[55];
	unsigned char	*buf;
	float			*walls_dist;
}					t_win;

char				*ft_strtrim(char *s1, char *set);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				**ft_split(char *s, char c);
int					ft_atoi(char *str);
int					test_max_min(long y, int z);
void				read_file();
int					ft_strlen_without_sp(char *s);
int					ft_strlen(char *s);
char				*ft_strdup(char *s1);
void				print_map(char **disp);
void				print_player(t_list **lst);
void				freeparam(char **param);
int					rgbtoint(int r, int g, int b);
void				ft_error(char *s);
int					len_split(char **s);
int					ft_strncmp(char *s1, char *s2, size_t n);
void				normalise(float *toor);
int					is_number(char *s);
void				param_r(char **param);
void				param_no(char **param, char *line);
void				param_so(char **param, char *line);
void				param_we(char **param, char *line);
void				param_ea(char **param, char *line);
void				param_s(char **param, char *line);
void				param_f(char **param);
void				param_c(char **param);
void				set_param(char **param, char *line);
int					len_c(char *s, char c);
int					deal_key(int key, t_list **lst);
void				key_click_left(t_list **lst);
void				key_click_right(t_list **lst);
void				key_click_up(t_list **lst);
void				key_click_down(t_list **lst);
void				calc_dist_sprite(t_list **lst);
char				*ft_strdup_bylen(char *s1, int len);
void				save_img(void);
void				check_error_map(int y_map, int i, t_list **lst);
void				ckeck_player(int y, char *s, t_list **lst);
float				intersection_h(float toor, char c);
void				first_intersection_h(float toor, int *helper,
					float *x, float *y);
void				last_intersection_h(float toor, int helper,
					float *x, float *y);
void				first_intersection_v(float toor,
					int *helper, float *i, float *j);
void				last_intersection_v(float toor,
					int helper, float *i, float *j);
float				intersection_v(float toor, char c);
void				calc_dist_sprite(t_list **lst);
float				offsetsprite(float x, float y, float ang);
void				ckecksprite(int x, int y, t_list **lst);
void				print_wall(int x, int y, float b, float ang);
float				echonge(float *temp3, float temp2);
void				calc_dist(t_list **lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
t_list				*ft_lstnew(int x, int y, int dist, char c);
void				calc_dist(t_list **lst);
void				print_player(t_list **lst);
float				intersection_pss(float ang);
void				print_wall(int x, int y, float b, float ang);
void				param_color_wall_bo(int x, float yy, float res, float dist);
int					shadow(int color, float dest);
void				clac_x_y_map(char *line);
void				my_mlx_pixel_put(int x, int y, int color);
void				param_directione(float *ang, float *b);
void				sutface(float stah, int x);
int					check_c(char c);
void				ckeck_player(int y, char *s, t_list **lst);
int					ckeck_map(t_list **lst);
void				gestion_param(char **line);
int					lenwords(char const *s, char c);
int					wordlen(char const *s, char c, int start);
char				*getword(char const *s, char c, int *i, char **sp);
void				sheck_resul(void);
void				freepath(t_list **lst);
void				deletelist(t_list **head_ref);
int					ft_tolower(int c);
int					sheck_namexpm(char *s);
int					quit(t_list **lst);
char				*sheck_namexpm2(char *line);
int					len_manexpm(char *s);
void				print__sprite(t_list **lst);

#endif
