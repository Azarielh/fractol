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

int	exit_error(char *msg, int exit_code)
{
	int fd;

	fd = 1;
	if (exit_code > 1)
		fd = 2;
	ft_putstr_fd("ERROR :  ", fd);
	ft_putendl_fd(msg, fd);
	if (exit_code == 1)
		print_instructions();
	exit(exit_code);
}
int	exit_n_free(char *msg, t_fractol *f, int exit_code)
{
	ft_putstr_fd("ERROR :  ", 2);
	ft_putendl_fd(msg, 2);
	clean_exit(f);
	exit(exit_code);
}
