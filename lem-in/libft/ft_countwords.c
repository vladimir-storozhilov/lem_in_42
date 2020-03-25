/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:50:49 by gtristan          #+#    #+#             */
/*   Updated: 2019/09/13 17:31:21 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char *s)
{
	size_t	i;
	size_t	j;

	i = 0;
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
