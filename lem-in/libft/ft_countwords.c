/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:50:49 by gtristan          #+#    #+#             */
/*   Updated: 2020/03/31 00:23:23 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char *s)
{
	size_t	j;

	j = 0;
	while (*s)
	{
		if (!ft_isspace(*s))
		{
			j++;
			while (!ft_isspace(*s) && *s)
				s++;
		}
		while (ft_isspace(*s))
			s++;
	}
	return (j);
}
