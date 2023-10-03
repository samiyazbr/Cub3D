/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:12:11 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/10 21:12:11 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c += 32);
	return (c);
}

/* int main()
{
    printf("%c", ft_tolower('H'));
} */