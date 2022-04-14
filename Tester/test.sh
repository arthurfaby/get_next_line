

GNL_PATH=..



CC=gcc
FLAGS="-Wall -Wextra -Werror"

function compil()
{
	$CC $FLAGS $GNL_PATH/get_next_line.c $GNL_PATH/get_next_line_utils.c -D BUFFER_SIZE=$1 
} 

compil 42
