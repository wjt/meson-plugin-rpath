project('plugin', 'c',
  version: '1',
)

libhelper_dep = dependency('helper')
pluginsdir = libhelper_dep.get_pkgconfig_variable('pluginsdir')

impl_sources = ['impl.c']
impl_headers = ['impl.h']

# I thought the problem might be that I used an internal static library against which the plugin & the test both link, but no.
impl = static_library('impl',
  impl_sources + impl_headers,
  dependencies: [libhelper_dep]
)
impl_dep = declare_dependency(
  link_with: impl,
  dependencies: [libhelper_dep],
)

plugin_sources = ['plugin.c']
plugin = shared_library('plugin',
  plugin_sources, # + impl_sources + impl_headers,
  dependencies: [
    impl_dep,
    # libhelper_dep,
  ],
  install: true,
  install_dir: pluginsdir,
)
plugin_dep = declare_dependency(
  link_with: plugin,
)

test_exe = executable('plugin-test',
  'test.c',
  dependencies: [impl_dep],
)
test('plugin-test', test_exe)
