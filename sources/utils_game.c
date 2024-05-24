/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_game.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/02 23:49:42 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/12 22:38:52 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	sl_free_textures(t_game *my_game)
{
	if (my_game->char_tx)
		mlx_delete_texture(my_game->char_tx);
	if (my_game->wall_tx)
		mlx_delete_texture(my_game->wall_tx);
	if (my_game->col_tx)
		mlx_delete_texture(my_game->col_tx);
	if (my_game->end_tx)
		mlx_delete_texture(my_game->end_tx);
}

void	sl_free_images(t_game *my_game, t_map *my_map)
{
	if (my_game->char_img)
		mlx_delete_image(my_map->mlx, my_game->char_img);
	if (my_game->wall_img)
		mlx_delete_image(my_map->mlx, my_game->wall_img);
	if (my_game->col_img)
		mlx_delete_image(my_map->mlx, my_game->col_img);
	if (my_game->end_img)
		mlx_delete_image(my_map->mlx, my_game->end_img);
	if (my_game->backgr_img)
		mlx_delete_image(my_map->mlx, my_game->backgr_img);
}

void	sl_clean_window(t_game *my_game, t_map *my_map)
{
	sl_free_textures(my_game);
	sl_free_images(my_game, my_map);
	mlx_terminate(my_map->mlx);
}
