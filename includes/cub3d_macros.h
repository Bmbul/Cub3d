#ifndef CUB3D_MACROS_H
# define CUB3D_MACROS_H

// boolean
# define TRUE				1
# define FALSE				0


# define ERROR_CODE			1

// textures
# define TEXTURES_COUNT		4

// map
# define MAP_CHARS			"01NEWS "
# define MAP_CHARS_WN		"01NEWS \n"
# define WALL				'1'
# define GROUND				'0'
# define NORTH				'N'
# define EAST				'E'
# define WEST				'W'
# define SOUTH				'S'
# define EMPTY				' '

// colors
# define BLACK_TERM			"\033[0;30m"				
# define RED_TERM			"\033[1;31m"			
# define WHITE_TERM			"\033[0;37m"
# define GREEN_TERM			"\033[1;32m"
# define SEP_TERM			"\033[1;36m"

// directions
# define _NORTH				0
# define _EAST				1
# define _WEST				2
# define _SOUTH				3

#endif