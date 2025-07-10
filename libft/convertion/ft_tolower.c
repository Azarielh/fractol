/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 22:48:06 by jlacaze-          #+#    #+#             */
/*   Updated: 2024/11/11 20:38:13 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c > 255 || c == EOF)
		return (-1);
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

char	*ft_tolower_str(char *str)
{
	int i;
	i = -1;
	while (str[++i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
	}
	return (str);
}
