/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_lightning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:04:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/10 11:21:17 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline __attribute__((always_inline)) void	add_calc_light_intens(
	const Light *restrict l,
	t_clhelp *restrict const h,
	const __v4df v)
{
	const double_t	ndl = u_vdot(h->n, h->l);

	if (.0f < ndl)
		h->i += l->intens * ndl / (u_vlen(h->n) * u_vlen(h->l));
	if (.0f < h->obj_spec)
	{
		h->i += ((l->intens * MAX(ndl, 0.0) + h->obj_spec)
			* (l->intens * pow(MAX(u_vdot(h->n, u_vnorm(v + h->l)), 0.0),
				h->obj_spec))) / pow(u_vlen(h->p - l->pos), 2);
	}
}

Color				rt_calc_light(Environment *restrict const env,
									t_clhelp *restrict const h,
									const __v4df v)
{
	Object *restrict	shadow;
	Light *restrict		curr_l;
	const Color			bg = sdl_clr_div(h->curr_clr, env->flags.ambient_light);
	size_t				i;

	i = ~0UL;
	h->i = 0.0f;
	while (++i < env->scene.ins_lights)
	{
		curr_l = &env->scene.lights[i];
		if (.0 >= curr_l->intens)
			continue ;
		h->l = curr_l->pos - h->p;
		env->tmax = 1.0f;
		if (env->scene.is_render_shadow
		&& (shadow = rt_closest_inter(h->p, h->l, env)))
			continue ;
		add_calc_light_intens(curr_l, h, v);
	}
	return (.0f < h->i ? sdl_clrs_bright_inc(bg, h->curr_clr, h->i) : bg);
}
