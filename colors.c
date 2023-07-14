/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:48:13 by rluiz             #+#    #+#             */
/*   Updated: 2023/07/15 00:57:56 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	**getlist(double b)
{
	int		N;
	double	*rs;
	double	*x;
	int		**LIST;
	double	*u;
	int		*X;

	N = 200;
	rs = malloc(N * sizeof(double));
	x = malloc(N * sizeof(double));
	LIST = malloc(N * sizeof(int *));
	u = malloc(N * sizeof(double));
	for (int i = 0; i < N; i++)
	{
		rs[i] = 3.98 + ((3.985 - 3.98) / N) * i;
	}
	x[0] = 0.5 + b * 0.0001;
	for (int n = 1; n < N; n++)
	{
		x[n] = rs[n] * x[n - 1] * (1 - x[n - 1]);
	}
	for (int i = 0, j = 95; i < N && j < N; i++, j++)
	{
		u[i] = x[j];
	}
	X = malloc(N * sizeof(int));
	for (int j = 0; j < N; j++)
	{
		X[j] = round(u[j % N] * 255);
	}
	for (int j = 0; j < N; j += 4)
	{
		LIST[j / 4] = malloc(3 * sizeof(int));
		LIST[j / 4][0] = X[j] * X[(j + 4) % N] % 256;
		LIST[j / 4][1] = X[(j + 1) % N] * X[(j + 4) % N] % 256;
		LIST[j / 4][2] = X[(j + 2) % N] * X[(j + 4) % N] % 256;
	}
	free(rs);
	free(x);
	free(u);
	free(X);
	return (LIST);
}

int	colors(int m, int max_iter, t_data img)
{
	int	*color;
	int	i;
	int	c;

	c = 22;
	i = img.colorint;
	color = malloc(sizeof(int) * 3);
	if (color == NULL)
	{
		return (0);
	}
	if (m == max_iter)
	{
		color[0] = (int)(img.colorset[0][0] / 100);
		color[1] = (int)(img.colorset[0][1] / 100);
		color[2] = (int)(img.colorset[0][2] / 100);
	}
	else
	{
		for (int i = 0; i < c; i++)
		{
			if (m < max_iter / c * (i + 1))
			{
				color[0] = 2 * cos(m * 2 / 100) * img.colorset[i][0] * (m
					- max_iter / c * i) / (max_iter / c);
				color[1] = img.colorset[i][1] * (m - max_iter / c * i)
					/ (max_iter / c);
				color[2] = img.colorset[i][2] * (m - max_iter / c * i)
					/ (max_iter / c);
				break ;
			}
		}
	}
	i = create_trgb(0, color[0], color[1], color[2]);
	free(color);
	return (i);
}
