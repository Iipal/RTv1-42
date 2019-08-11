/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lightning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:04:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/11 14:45:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline void	s_calc_light_intens(Light const *restrict l,
	t_clhelp *restrict const h, __v4df const v)
{
	double_t const	ndl = v_dot(h->n, h->l);

	if (.0f < ndl)
		h->i += l->intens * ndl / (v_len(h->n) * v_len(h->l));
	if (.0f < h->obj_spec)
	{
		h->i += ((l->intens * MAX(ndl, 0.0) + h->obj_spec)
			* (l->intens * pow(MAX(v_dot(h->n, v_norm(v + h->l)), 0.0),
				h->obj_spec))) / pow(v_len(h->p - l->pos), 2);
	}
}

Color				rt_lightning(Scene *restrict const scene,
						t_clhelp *restrict const h,
						__v4df const v)
{
	Object		*shadow;
	Light		*curr_l;
	Color const	bg = sdl_clr_div(h->curr_clr, h->al);
	size_t		i;

	i = ~0UL;
	h->i = 0.0f;
	while (++i < scene->ins_lights)
	{
		curr_l = &scene->lights[i];
		if (.0 >= curr_l->intens)
			continue ;
		h->l = curr_l->pos - h->p;
		scene->tmax = 1.0f;
		if (IS_BIT(g_flags, F_BIT_SHADOWS)
		&& (shadow = rt_closest_inter(h->p, h->l, scene)))
			continue ;
		s_calc_light_intens(curr_l, h, v);
	}
	return (.0f < h->i ? sdl_clrs_bright_inc(bg, h->curr_clr, h->i) : bg);
}
