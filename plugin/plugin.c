#include <helper.h>
#include "plugin.h"

int
plugin_get_four (void)
{
  return helper_get_three () + 1;
}
