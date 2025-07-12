/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:34:56 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/09 21:34:56 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = -1;
	while (((unsigned char *)str1)[++i] && ((unsigned char *)str2)[i])
		if (((unsigned char *)str1)[i] != ((unsigned char *)str2)[i])
			return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
	return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
}

int	ft_strcmp_2(char *str1, char *str2, char *abr)
{
	ft_tolower_str(str1);
	ft_tolower_str(str2);
	ft_tolower_str(abr);
	if (ft_strcmp(str1, str2) == 0 || ft_strcmp(str1, abr) == 0)
		return (0);
	return (ft_strcmp(str1, str2));
}
