/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtristan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:09:00 by gtristan          #+#    #+#             */
/*   Updated: 2020/03/27 14:57:10 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//  int	ft_atoi(const char *str)
//  {
//  	unsigned long long	res;
//  	int					sign;

//  	sign = 1;
//  	res = 0;
//  	while (*str == ' ' || (*str >= 9 && *str <= 13))
//  		str++;
//  	if (*str == '-')
//  	{
//  		sign = -1;
//  		str++;
//  	}
//  	else if (*str == '+')
//  		str++;
//  	while (*str >= '0' && *str <= '9')
//  	{
//  		res = res * 10 + (*str - '0');
//  		str++;
//  	}
//  	if (res > 9223372036854775807 && sign == 1)
//  		return (-1);
//  	if (res >= 9223372036854775807 && sign == -1)
//  		return (0);
//  	return (sign * (int)res);
//  }
