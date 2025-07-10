/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:01:31 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/08 16:01:31 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	exit_error(char *msg, t_fractol *f, int exit_code)
{
	ft_putstr_fd("ERROR :  ", 2);
	ft_putendl_fd(msg, 2);
	if (exit_code == 1)
		param_instructions();
	else
	{
		mlx_destroy_image(f->mlx_ptr, f->img_ptr);
		mlx_destroy_window(f->mlx_ptr, f->win_ptr);
		mlx_destroy_display(f->mlx_ptr);
		free(f->mlx_ptr);
	}
	exit(exit_code);
}
