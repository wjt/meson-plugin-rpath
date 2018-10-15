#include "plugin.h"

int
main (int argc,
      char **argv)
{
  int ok = plugin_get_four () == 4;
  return !ok;
}
