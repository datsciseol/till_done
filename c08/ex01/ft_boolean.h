#include <unistd.h>

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

typedef unsigned char	t_bool;

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef EVEN
#  define EVEN(nbr) (nbr % 2 == 0)
# endif

# ifndef EVEN_MSG
#  define EVEN_MSG "I have an even number of arguments.\n"
# endif

# ifndef ODD_MSG
#  define ODD_MSG "I have an odd number of argumnets.\n"
# endif

# ifndef SUCCESS
#  define SUCCESS 0
# endif

#endif
