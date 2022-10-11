#include "../includes/cub3d.h"

void	draw(t_data *data)
{
	int			i;
	double		camera_x;
	t_vector	ray;
	t_tuple		map;
	t_vector	delta_dist;
	t_vector	side_dist;
	double 		perpWallDist;
	t_tuple		step;
	int			hit;
	int			side;
	double		z_buffer[WIN_WIDTH];

	i = -1;
	free_list_nodes(data->drawing_sprites);
	while (++i < WIN_WIDTH)
	{
		hit = 0;
		camera_x = 2 * i / (double)WIN_WIDTH - 1;
		ray.x = data->player.dir.x + data->camera_plane.x * camera_x;
		ray.y = data->player.dir.y + data->camera_plane.y * camera_x;
		map = vector_to_tuple(data->player.pos);
		if (ray.x == 0)
			delta_dist.x = 1e30;
		else
			delta_dist.x = fabs(1 / ray.x);
		if (ray.y == 0)
			delta_dist.y = 1e30;
		else
			delta_dist.y = fabs(1 / ray.y);
		if (ray.x < 0)
		{
			step.x = -1;
			side_dist.x = (data->player.pos.x - map.x) * delta_dist.x;
		}
		else
		{
			step.x = 1;
			side_dist.x = (map.x + 1.0 - data->player.pos.x) * delta_dist.x;
		}
		if (ray.y < 0)
		{
			step.y = -1;
			side_dist.y = (data->player.pos.y - map.y) * delta_dist.y;
		}
		else
		{
			step.y = 1;
			side_dist.y = (map.y + 1.0 - data->player.pos.y) * delta_dist.y;
		}
		while (hit == 0)
		{
			if (side_dist.x < side_dist.y)
			{
				side_dist.x += delta_dist.x;
				map.x += step.x;
				side = 0;
			}
			else
			{
				side_dist.y += delta_dist.y;
				map.y += step.y;
				side = 1;
			}
			if (data->map[map.x][map.y] == '1')
				hit = 1;
			else if (!contains("0NEWS", data->map[map.x][map.y]))
				add_node(data->drawing_sprites, new_lnode(ft_strdup("2")));
		}
		if (side == 0)
			perpWallDist = side_dist.x - delta_dist.x;
		else
			perpWallDist = side_dist.y - delta_dist.y;
		int	lineHeight;
		lineHeight = (int)(WIN_HEIGHT / perpWallDist);
		int	drawStart;
		drawStart = -lineHeight / 2;
		int ceiling_size = -lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		int	drawEnd;
		drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawEnd >= WIN_HEIGHT)
			drawEnd = WIN_HEIGHT - 1;
		double wallX;
		if (side == 0)
			wallX = data->player.pos.y + perpWallDist * ray.y;
		else
			wallX = data->player.pos.x + perpWallDist * ray.x;
		wallX -= floor((wallX));

		int	texWidth = 64;
		int texHeight = 64;
		int texX = (int)(wallX * (double)texWidth);
		if(side == 0 && ray.x > 0)
			texX = texWidth - texX - 1;
		if(side == 0 && ray.x > 0)
			texX = texWidth - texX - 1 + 64;
		if(side == 1 && ray.y < 0)
			texX = texWidth - texX - 1 + 128;
		if(side == 1 && ray.y > 0)
			texX = texWidth - texX - 1 + 192;

		double step = 1.0 * texHeight / lineHeight;
		double texPos = (drawStart - WIN_HEIGHT / 2 + lineHeight / 2) * step;
		// if(side == 0 && ray.x > 0)
		// 	texPos += 4;
		// if(side == 1 && ray.y < 0)
		// 	texPos += 8;
		// if(side == 1 && ray.y > 0)
		// 	texPos += 12;
		vertical_line(data, i, drawStart % WIN_HEIGHT, drawEnd % WIN_HEIGHT, texX, texPos, step, ceiling_size);
		z_buffer[i] = perpWallDist;
	}
	draw_sprites(data);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->window,
		data->frame.img_ptr, 0, 0);
}

void	vertical_line(t_data *data, int i, int draw_start,
				int draw_end, int texX, double texPos, double step, int ceiling_size)
{
	int				col;
	int				texY;
	unsigned int	color_hex;

	col = -1;
	while (++col < WIN_HEIGHT)
	{
		texY = (int)texPos & (64 - 1);
		texPos += step;
		if (col >= draw_start && col <= draw_end)
			color_hex = data->textures->north.texture[texY + 64 * texX];
		else if (col > WIN_HEIGHT / 2)
			color_hex = get_color(*(data->floor_color));
		else
			color_hex = get_color(*(data->ceiling_color));
		*(unsigned int *)(data->frame.data_addr
				+ (col * data->frame.size_line + i
					* (data->frame.bits_per_pixel / 8)))
			= color_hex;
	}
	col = -1;
	while (++col < ceiling_size)
		*(unsigned int *)(data->frame.data_addr
				+ (col * data->frame.size_line + i
					* (data->frame.bits_per_pixel / 8)))
			= get_color(*(data->ceiling_color));
}

void	draw_sprites(t_data *data)
{
	(void) data;
	//SPRITE CASTING
    //sort sprites from far to close
    // for(int i = 0; i < numSprites; i++)
    // {
    //   spriteOrder[i] = i;
    //   spriteDistance[i] = ((posX - sprite[i].x) * (posX - sprite[i].x) + (posY - sprite[i].y) * (posY - sprite[i].y)); //sqrt not taken, unneeded
    // }
    // sortSprites(spriteOrder, spriteDistance, numSprites);

    // //after sorting the sprites, do the projection and draw them
    // for(int i = 0; i < numSprites; i++)
    // {
    //   //translate sprite position to relative to camera
    //   double spriteX = sprite[spriteOrder[i]].x - posX;
    //   double spriteY = sprite[spriteOrder[i]].y - posY;

    //   //transform sprite with the inverse camera matrix
    //   // [ planeX   dirX ] -1                                       [ dirY      -dirX ]
    //   // [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
    //   // [ planeY   dirY ]                                          [ -planeY  planeX ]

    //   double invDet = 1.0 / (planeX * dirY - dirX * planeY); //required for correct matrix multiplication

    //   double transformX = invDet * (dirY * spriteX - dirX * spriteY);
    //   double transformY = invDet * (-planeY * spriteX + planeX * spriteY); //this is actually the depth inside the screen, that what Z is in 3D

    //   int spriteScreenX = int((w / 2) * (1 + transformX / transformY));

    //   //calculate height of the sprite on screen
    //   int spriteHeight = abs(int(h / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
    //   //calculate lowest and highest pixel to fill in current stripe
    //   int drawStartY = -spriteHeight / 2 + h / 2;
    //   if(drawStartY < 0) drawStartY = 0;
    //   int drawEndY = spriteHeight / 2 + h / 2;
    //   if(drawEndY >= h) drawEndY = h - 1;

    //   //calculate width of the sprite
    //   int spriteWidth = abs( int (h / (transformY)));
    //   int drawStartX = -spriteWidth / 2 + spriteScreenX;
    //   if(drawStartX < 0) drawStartX = 0;
    //   int drawEndX = spriteWidth / 2 + spriteScreenX;
    //   if(drawEndX >= w) drawEndX = w - 1;

    //   //loop through every vertical stripe of the sprite on screen
    //   for(int stripe = drawStartX; stripe < drawEndX; stripe++)
    //   {
    //     int texX = int(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth) / 256;
    //     //the conditions in the if are:
    //     //1) it's in front of camera plane so you don't see things behind you
    //     //2) it's on the screen (left)
    //     //3) it's on the screen (right)
    //     //4) ZBuffer, with perpendicular distance
    //     if(transformY > 0 && stripe > 0 && stripe < w && transformY < ZBuffer[stripe])
    //     for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
    //     {
    //       int d = (y) * 256 - h * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
    //       int texY = ((d * texHeight) / spriteHeight) / 256;
    //       Uint32 color = texture[sprite[spriteOrder[i]].texture][texWidth * texY + texX]; //get current color from the texture
    //       if((color & 0x00FFFFFF) != 0) buffer[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
    //     }
    //   }
    // }
}

void	draw_minimap(t_data *data)
{
	int				idx;
	int				jdx;
	int				m;
	int				n;
	unsigned int	color;

	idx = WIN_HEIGHT - MAP_HEIGHT - MAP_OFFSET;
	while (idx < WIN_HEIGHT - MAP_OFFSET)
	{
		jdx = MAP_OFFSET;
		m = idx - (WIN_HEIGHT - MAP_HEIGHT - MAP_OFFSET);
		m = (m - m % MINI_SCALE) / MINI_SCALE;
		while (jdx < MAP_OFFSET + MAP_WIDTH)
		{
			n = jdx - MAP_OFFSET;
			n = (n - n % MINI_SCALE) / MINI_SCALE;
			if (n == (int)data->player.pos.y && m == (int)data->player.pos.x)
				color = 0xFF0000;
			else if (data->map[m][n] == '1')
				color = 0xDEDEDE;
			else if (data->map[m][n] == '0')
				color = 0x433BDE;
			*(unsigned int *)(data->frame.data_addr
					+ (idx * data->frame.size_line + jdx
						* (data->frame.bits_per_pixel / 8)))
				= color;
			jdx++;
		}
		idx++;
	}
}
