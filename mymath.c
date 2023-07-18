/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymath.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:31:54 by rluiz             #+#    #+#             */
/*   Updated: 2023/07/18 16:50:36 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_c	mult_c(t_c a, t_c b)
{
	t_c	c;

	c.re = a.re * b.re - a.img * b.img;
	c.img = a.re * b.img + a.img * b.re;
	return (c);
}

t_c	pow_i(t_c c)
{
	return (mult_c(c, c));
}

t_c	pow_inti(t_c c)
{
	if (c.re < 0)
		c.re = -c.re;
	if (c.img < 0)
		c.img = -c.img;
	c.re = c.re * c.re - c.img * c.img;
	c.img = 2 * c.re * c.img;
	return (c);
}

t_c	sum_i(t_c a, t_c b)
{
	t_c	c;

	c.re = a.re + b.re;
	c.img = a.img + b.img;
	return (c);
}

double	module(t_c c)
{
	return (sqrt(pow(c.re, 2) + pow(c.img, 2)));
}
