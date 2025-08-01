/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:22:21 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/08 14:22:21 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "../libft/libft.h"
# include "mlx.h"

# define ESC				65307
# define SPACE				32
# define SCROLL_UP			4
# define SCROLL_DOWN		5
# define DESTROYNOTIFY		17
# define CONFIGURENOTIFY	22

typedef struct s_fractol
{
	char			*set;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data;
	int				bits;
	int				line_len;
	int				endian;
// View Setting
	double			x_min;
	double			x_max;
	double			y_min;
	double			y_max;
	int				max_iter;
	int				background_color;
// Window's Dimension
	int				width;
	int				height;
}					t_fractol;

typedef struct s_zoom_data
{
	double			x_min;
	double			x_max;
	double			y_min;
	double			y_max;
}					t_zoom_data;

typedef struct s_draw
{
	double			z_real;
	double			z_imag;
	double			c_real;
	double			c_imag;
}					t_draw;

//____________________  SECURE FUNCTIONS  ____________________
void				*safe_init(void);
void				*safe_win_opener(t_fractol *f, char *title);
void				*safe_new_img(t_fractol *f);
void				clean_exit(t_fractol *f);

//____________________  CONTROLS FUNCTIONS  ____________________
int					mouse_handler(int button, int x, int y, void *param);
void				zoom_at_point(int scroll, int x, int y, t_fractol *f);
int					keys_handler(int key, void *param);
int					resize_handler(t_fractol *f);

//____________________  UTILITY FUNCTIONS  ____________________
double				pixel_to_real(t_fractol *f, int x);
double				pixel_to_imag(t_fractol *f, int y);
void				put_px_to_img(t_fractol *f, int x, int y, int color);

//____________________  COLOR FUNCTIONS  ____________________
int					get_color(int iterations, int max_iter);

//____________________  FRACTAL FUNCTIONS  ____________________
void				init_fractol(t_fractol *f, char **args);
void				choose_fractal(t_fractol *f);
void				render_mandelbrot(t_fractol *f, t_draw *d);
void				render_julia(t_fractol *f, t_draw *d);

//____________________  OUTPUT FUNCTIONS  ____________________
void				print_instructions(void);
void				runwhile_instruction(void);
int					exit_error(char *msg, int exit_code);
int					exit_n_free(char *msg, t_fractol *f, int exit_code);
void				pars_args(char **args, t_fractol *f);

//____________________  WINDOW FUNCTIONS  ____________________
int					close_window(t_fractol *f);
#endif
