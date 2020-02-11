/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shpark <shpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 05:39:57 by shpark            #+#    #+#             */
/*   Updated: 2020/02/10 06:04:17 by mseol            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_strlcat.c"

int				main(void)
{
	char	*str_base;
	char	dest[100];
	char	dest2[100];
	char	*src;
	char	*src1;
	char	*src2;
	char	*src3;
	int		index;

	str_base = "Hello";
	src = " World";
	src1 = " Earth";
	src2 = " Home";
	src3 = " 42";
	index = 0;
	while (index < 6)
	{
		dest[index] = str_base[index];
		dest2[index] = str_base[index];
		index++;
	}
	printf("c  : (%lu) $%s$\n", strlcat(dest, src, 6), dest);
	printf("ft : (%d) $%s$\n", ft_strlcat(dest2, src, 6), dest2);
//	printf("c  : (%lu) $%s$\n", strlcat(dest, src, 3), dest);
//	printf("ft : (%d) $%s$\n", ft_strlcat(dest2, src, 3), dest2);
//	printf("c  : (%lu) $%s$\n", strlcat(dest, src, 10), dest);
//	printf("ft : (%d) $%s$\n", ft_strlcat(dest2, src, 10), dest2);
//	printf("c  : (%lu) $%s$\n", strlcat(dest, src1, 0), dest);
//	printf("ft : (%d) $%s$\n", ft_strlcat(dest2, src1, 0), dest2);
//	printf("c  : (%lu) $%s$\n", strlcat(dest, src2, 0), dest);

//	printf("ft : (%d) $%s$\n", ft_strlcat(dest2, src2, 0), dest2);
//	printf("c  : (%lu) $%s$\n", strlcat(dest, src3, 0), dest);
///	printf("ft : (%d) $%s$\n", ft_strlcat(dest2, src3, 0), dest2);
//	printf("c  : (%lu) $%s$\n", strlcat(dest, src3, 2), dest);
//	printf("ft : (%d) $%s$\n", ft_strlcat(dest2, src3, 2), dest2);
}
