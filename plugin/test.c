#include "impl.h"

int
main (int argc,
      char **argv)
{
  int ok = impl_get_four () == 4;
  return !ok;
}
