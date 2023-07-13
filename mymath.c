/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymath.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:31:54 by rluiz             #+#    #+#             */
/*   Updated: 2023/07/13 17:30:19 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

n_c	mult_c(n_c a, n_c b)
{
	n_c	c;

	c.re = a.re * b.re - a.img * b.img;
	c.img = a.re * b.img + a.img * b.re;
	return (c);
}

n_c	pow_i(n_c c)
{
	return (mult_c(c, c));
}

n_c	sum_i(n_c a, n_c b)
{
	n_c	c;

	c.re = a.re + b.re;
	c.img = a.img + b.img;
	return (c);
}

double	module(n_c c)
{
	return (sqrt(pow(c.re, 2) + pow(c.img, 2)));
}
