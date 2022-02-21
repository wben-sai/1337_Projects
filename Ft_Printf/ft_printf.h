/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:08:49 by wben-sai          #+#    #+#             */
/*   Updated: 2019/12/15 16:25:41 by wben-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *args, ...);
int		action_conversions(va_list va_lst, int *i, const char *args);
int		switch_conversion(int conve, va_list va_lst, int i, const char *args);
int		check_conversions(const char *args, int i);

int		ft_atoi(const char *str);
int		ft_strlen(char *s);
int		ft_putstr(const char *s);
int		write_nbr_cs(int nbr, char *s);
char	*filling_ptr(char *p, int x, int n);
int		len_nbr(int n);
int		ft_itoa(int n);
char	*filling_ptr_u(char *p, int x, unsigned int n);
int		len_nbr_u(unsigned int n);
int		ft_itoa_u(int unsigned n);
char	to_hexadecimal(int k);
char	*filling_ptr_x(char *p, int x, unsigned int n);
int		len_nbr_x(int unsigned n);
int		ft_itoa_x(int unsigned n);
char	to_hexadecimal2(int k);
char	*filling_ptr_x2(char *p, int x, unsigned int n);
int		len_nbr_x2(int unsigned n);
int		ft_itoa_x2(int unsigned n);
char	to_hexadecimal_p(int k);
char	*filling_ptr_p(char *p, int x, unsigned long n);
int		len_nbr_p(unsigned long n);
int		ft_itoa_p(unsigned long n);
int		print_por_with_flag_nbr(const char *args, int x, int i);
int		write_n_cs(char c, int n);

int		print_conversion_c(va_list va_lst, int i, const char *args);
int		print_c_with_flag_nbr(int x, char c);

int		print_conversion_d(va_list va_lst, int i, const char *args);
int		d_f_nbr(int x, int d);
int		d_f_nb_psg_neg(int x, int itwl, int d, int xx);
int		d_f_nb_psg(int x, int itwl, int d);
int		print_d_with_flag_nbr(const char *args, va_list va_lst, int x, int i);
int		print_conversion_d_with_flag_itwl(const char *args,
											va_list va_lst, int i);
int		write_psg(int itwl, int d);
int		print_d_with_flag_zero_and_nbr(int x, int d);
int		f0_itl(int x, int itwl, int d);
int		print_d_with_flag_zero(const char *args, va_list va_lst, int x, int i);
int		conversion_d_psg(va_list va_lst, int i, const char *args);
int		normini(int itwl, int *d);
int		print_d_with_flag_minus(const char *args, va_list va_lst, int i);
int		print_d_flag_minus_outpsg(int itwl, int d);
int		print_d_flag_minus_psg(int x, int itwl, int d);
int		print_d_with_flag_zero_and_neg_nbr(int x, int d);
void	print_d_flag_0_and_negnbr_and_psg(int x, int itwl, int d, int *nbr);
void	print_d_flag_0_and_posnbr_and_psg(int x, int itwl, int d, int *nbr);
int		d_with_flag_zero_outnbr(const char *args, va_list va_lst, int i);

int		print_conversion_x2(va_list va_lst, int i, const char *args);
int		x2_f_nbr(int x, unsigned int d);
int		x2_f_nb_psg_neg(int x, int itwl, unsigned int d, int xx);
int		x2_f_nb_psg(int x, int itwl, unsigned int d);
int		print_x2_with_flag_nbr(const char *args, va_list va_lst, int x, int i);
int		print_conversion_x2_with_flag_itwl(const char *args,
											va_list va_lst, int i);
int		write_psg_x2(int itwl, unsigned int d);
int		x2_with_flag_zero_and_nbr(int x, unsigned int d);
int		f0_itl_x2(int x, int itwl, unsigned int d);
int		print_x2_with_flag_zero(const char *args, va_list va_lst, int x, int i);
int		conversion_x2_psg(va_list va_lst, int i, const char *args);
int		normini_x2(int itwl, unsigned int *d);
int		print_x2_with_flag_minus(const char *args, va_list va_lst, int i);
int		print_x2_flag_minus_outpsg(int itwl, unsigned int d);
int		x2_flag_minus_psg(int x, int itwl, unsigned int d);
int		print_x2_with_flag_zero_and_neg_nbr(int x, unsigned int d);
void	x2_flag_0_and_negnbr_and_psg(int x, int itwl, unsigned int d, int *nbr);
void	x2_flag_0_and_posnbr_and_psg(int x, int itwl, unsigned int d, int *nbr);
int		x2_with_flag_zero_outnbr(const char *args, va_list va_lst, int i);
int		x2_with_flag_zero_anditwl(const char *args, va_list va_lst, int i);
int		x2_with_flag_zero_itwl(const char *args, va_list va_lst, int i);

int		print_p_flg_nbr_not_psg(int x, unsigned long d);
int		print_p_with_flag_nbr(const char *args, va_list va_lst, int x, int i);
int		print_conversion_p_with_flag_itwl(va_list va_lst, int i,
										const char *args);
int		print_conversion_p(va_list va_lst, int i, const char *args);
int		print_conversion_p_with_flag_pp(int bx, int box);
int		print_p_with_flag_minus_itwl(va_list va_lst, int i, const char *args);

int		print_por_flg_nbr_not_psg(int x);
int		print_conversion_por_with_flag_itwl(va_list va_lst);
int		print_por_with_flag_zero_and_nbr(int x);
int		print_por_with_flag_zero(const char *args, int x, int i);
int		print_conversion_por(va_list va_lst, int i, const char *args);

int		print_s_flg_nbr_not_psg(int x, char *s);
int		s_f_nb_psg(int x, int itwl, char *s);
int		print_s_with_flag_nbr(const char *args, va_list va_lst, int x, int i);
int		print_conversion_s_with_flag_itwl(const char *args,
											va_list va_lst, int i);
int		print_conversion_s(va_list va_lst, int i, const char *args);
int		s_f_ps(int x);
int		s_f_nb_psg_neg(int x, int itwl, char *s);
int		print_conversion_s_with_flag_minus(const char *args,
											va_list va_lst, int i);

int		print_conversion_u(va_list va_lst, int i, const char *args);
int		u_f_nbr(int x, unsigned int d);
int		u_f_nb_psg_neg(int x, int itwl, unsigned int d, int xx);
int		u_f_nb_psg(int x, int itwl, unsigned int d);
int		print_u_with_flag_nbr(const char *args, va_list va_lst, int x, int i);
int		print_conversion_u_with_flag_itwl(const char *args,
											va_list va_lst, int i);
int		write_psg_u(int itwl, unsigned int d);
int		u_with_flag_zero_and_nbr(int x, unsigned int d);
int		f0_itl_u(int x, int itwl, unsigned int d);
int		print_u_with_flag_zero(const char *args, va_list va_lst, int x, int i);
int		conversion_u_psg(va_list va_lst, int i, const char *args);
int		normini_u(int itwl, unsigned int *d);
int		print_u_with_flag_minus(const char *args, va_list va_lst, int i);
int		print_u_flag_minus_outpsg(int itwl, unsigned int d);
int		u_flag_minus_psg(int x, int itwl, unsigned int d);
int		print_u_with_flag_zero_and_neg_nbr(int x, unsigned int d);
void	u_flag_0_and_negnbr_and_psg(int x, int itwl, unsigned int d, int *nbr);
void	u_flag_0_and_posnbr_and_psg(int x, int itwl, unsigned int d, int *nbr);
int		u_with_flag_zero_outnbr(const char *args, va_list va_lst, int i);
int		u_with_flag_zero_anditwl(const char *args, va_list va_lst, int i);
int		u_with_flag_zero_itwl(const char *args, va_list va_lst, int i);

int		print_conversion_x(va_list va_lst, int i, const char *args);
int		x_f_nbr(int x, unsigned int d);
int		x_f_nb_psg_neg(int x, int itwl, unsigned int d, int xx);
int		x_f_nb_psg(int x, int itwl, unsigned int d);
int		print_x_with_flag_nbr(const char *args, va_list va_lst, int x, int i);
int		print_conversion_x_with_flag_itwl(const char *args,
											va_list va_lst, int i);
int		write_psg_x(int itwl, unsigned int d);
int		x_with_flag_zero_and_nbr(int x, unsigned int d);
int		f0_itl_x(int x, int itwl, unsigned int d);
int		print_x_with_flag_zero(const char *args, va_list va_lst, int x, int i);
int		conversion_x_psg(va_list va_lst, int i, const char *args);
int		normini_x(int itwl, unsigned int *d);
int		print_x_with_flag_minus(const char *args, va_list va_lst, int i);
int		print_x_flag_minus_outpsg(int itwl, unsigned int d);
int		x_flag_minus_psg(int x, int itwl, unsigned int d);
int		print_x_with_flag_zero_and_neg_nbr(int x, unsigned int d);
void	x_flag_0_and_negnbr_and_psg(int x, int itwl, unsigned int d, int *nbr);
void	x_flag_0_and_posnbr_and_psg(int x, int itwl, unsigned int d, int *nbr);
int		x_with_flag_zero_outnbr(const char *args, va_list va_lst, int i);
int		x_with_flag_zero_anditwl(const char *args, va_list va_lst, int i);
int		print_s_flag_minus_psg(const char *args, va_list va_lst, int i, int bx);
int		x_with_flag_zero_itwl(const char *args, va_list va_lst, int i);

#endif
