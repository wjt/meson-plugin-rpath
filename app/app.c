#include <stdio.h>
#include <limits.h>
#include <dlfcn.h>

#include "helper.h"
#include "config.h"

int
main (int argc,
      char **argv)
{
  char pluginpath[PATH_MAX];
  void *plugin;

  printf ("helper_get_three: %d\n", helper_get_three ());

  snprintf (pluginpath, PATH_MAX, "%s/%s", PLUGINSDIR, "libplugin.so");
  plugin = dlopen (pluginpath, RTLD_NOW | RTLD_LOCAL);
  if (!plugin)
    {
      printf ("can't load %s: %s\n", pluginpath, dlerror());
      return 1;
    }

  int (*plugin_get_four)(void) = dlsym (plugin, "plugin_get_four");
  if (!plugin_get_four)
    {
      printf ("oh no: %s\n", dlerror());
      return 1;
    }

  printf ("plugin_get_four: %d\n", plugin_get_four ());
  return 0;
}
