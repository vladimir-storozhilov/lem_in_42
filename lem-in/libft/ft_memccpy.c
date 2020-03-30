/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:37:01 by gtristan          #+#    #+#             */
/*   Updated: 2020/03/31 00:22:37 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*dst1;
	unsigned char	a;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	src1 = (unsigned char *)src;
	dst1 = (unsigned char *)dst;
	a = (unsigned char)c;
	while (i < n)
	{
		dst1[i] = src1[i];
		if (src1[i] == a)
		{
			i++;
			return (&(dst1[i]));
		}
		i++;
	}
	return (NULL);
}
