/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lightning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:04:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/09/02 21:51:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static __always_inline void	s_calc_light_intens(Light const *restrict l,
	t_clhelp *restrict const h, t_v4df const v)
{
	double_t const	ndl = v_dot(h->n, h->l);

	if (.0f < ndl)
		h->i += l->intens * ndl / (v_len(h->n) * v_len(h->l));
	if (.0f < h->obj_spec)
		h->i += ((l->intens * MAX(ndl, 0.0) + h->obj_spec)
			* (l->intens * pow(MAX(v_dot(h->n, v_norm(v + h->l)), 0.0),
				h->obj_spec))) / pow(v_len(h->p - l->pos), 2.0);
}

Color				rt_lightning(Scene *restrict const scene,
						t_clhelp *restrict const h,
						t_v4df const v)
{
	Object		*shadow;
	Light		*curr_l;
	Color const	bg = sdl_clr_div(h->curr_clr, h->al);
	ssize_t		i;

	h->i = 0.0;
	i = scene->ins_lights;
	while (0 <= --i)
	{
		curr_l = &scene->lights[i];
		if (.0 >= curr_l->intens)
			continue ;
		scene->tmax = 1.0;
		h->l = curr_l->pos - h->p;
		if (IS_BIT(g_flags, F_BIT_SHADOWS)
		&& (shadow = rt_intersection(h->p, h->l, scene)))
			continue ;
		s_calc_light_intens(curr_l, h, v);
	}
	return (.0f < h->i ? sdl_clrs_bright_inc(bg, h->curr_clr, h->i) : bg);
}
