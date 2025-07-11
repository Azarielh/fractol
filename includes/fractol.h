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

#define FRACTOL_H

# include "../libft/libft.h"
# include "controls.h"
# include "mlx.h"

/**
 * x_min, x_max, y_min,  y_max :
 * ↪ définissent quelle portion du plan mathématique on regarde.
 * y_min,  y_max
 */
typedef struct s_fractol
{
	char			*set;
	char			*theme;
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
	int				rm_color;
	int				background_color;
// Window's Dimension
	int				width;
	int				height;
}					t_fractol;

//____________________  SECURE FUNCTIONS  ____________________
void				*safe_init(t_fractol *f);
void				*safe_win_opener(t_fractol *f, char *title);

//____________________  CONTROLS FUNCTIONS  ____________________
int					mouse_handler(int button, int x, int y, void *param);
void				zoom_at_point(int scroll, int x, int y, t_fractol *f);
int					keys_handler(int key, void *param);
void				resize_handler(t_fractol *f);

//____________________  UTILITY FUNCTIONS  ____________________
void				pixel_to_complex(t_fractol *f, int x, int y, double *real, double *imag);
void				put_px_to_img(t_fractol *f, int x, int y, int color);

//____________________  COLOR FUNCTIONS  ____________________
int					*get_theme(char *theme);
int					get_color(int iterations, int max_iter, t_fractol *f);
void				init_themes(char *themes[4]);
void				init_background(int clr[8]);
void				init_color_palettes(int winter[3], int summer[3], int autumn[3], 
											int spring[3], int *init);
void				cycle_background_color(t_fractol *f);

//____________________  FRACTAL FUNCTIONS  ____________________
void				init_fractol(t_fractol *f, char **set);
void				choose_fractal(t_fractol *f);
void				render_mandelbrot(t_fractol *f);
void				render_julia(t_fractol *f);

//____________________  OUTPUT FUNCTIONS  ____________________
void				param_instructions(void);
void				runwhile_instruction(void);
int					exit_error(char *msg, t_fractol *f, int exit_code);

//____________________  WINDOW FUNCTIONS  ____________________
int					close_window(void *param);
#endif
