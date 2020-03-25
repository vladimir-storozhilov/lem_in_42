/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:31:50 by gtristan          #+#    #+#             */
/*   Updated: 2019/09/11 11:47:59 by gtristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			i;
	unsigned int	j;
	char			*snew;
	char			*sold;

	if (s == NULL)
		return (NULL);
	sold = (char *)s;
	i = 0;
	j = 0;
	while (s[i])
		i++;
	snew = (char *)malloc(sizeof(char) * (i + 1));
	if (!snew || (i + 1 == 0))
		return (NULL);
	while (j < i)
	{
		snew[j] = f(j, sold[j]);
		j++;
	}
	snew[j] = '\0';
	return (snew);
}
