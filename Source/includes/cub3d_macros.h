#ifndef CUB3D_MACROS_H
# define CUB3D_MACROS_H

//  GAME
# define WIN_WIDTH			640
# define WIN_HEIGHT			480
# define SENSITIVITY		0.05
# define MOVEMENT_SPEED		0.1

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

// keys
# define KEY_ESC 			53

# define UP_ARROW			126
# define DOWN_ARROW 		125
# define LEFT_ARROW			123
# define RIGHT_ARROW		124

# define KEY_ONE 			18
# define KEY_TWO 			19
# define KEY_THREE 			20
# define KEY_FOUR 			21
# define KEY_FIVE 			23
# define KEY_SIX 			22
# define KEY_SEVEN 			26
# define KEY_EIGHT 			28
# define KEY_NINE 			25
# define KEY_ZERO 			29

# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_T 17
# define KEY_Y 16

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_G 5
# define KEY_H 4

# define MOUSE_LEFT_CLK 1
# define MOUSE_SCRL_CLK 3
# define MOUSE_RIGHT_CLK 2
# define MOUSE_SCRL_UP 5
# define MOUSE_SCRL_DOWN 4

#endif
