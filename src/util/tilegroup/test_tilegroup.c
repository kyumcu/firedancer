#include "../fd_util.h"

int
main( int     argc,
      char ** argv ) {
  fd_boot( &argc, &argv );

  fd_halt();
  return 0;
}

