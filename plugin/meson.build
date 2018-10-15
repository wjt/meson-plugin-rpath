project('plugin', 'c',
  version: '1',
)

libhelper_dep = dependency('helper')
pluginsdir = libhelper_dep.get_pkgconfig_variable('pluginsdir')

plugin_sources = ['plugin.c']
plugin = shared_library('plugin',
  plugin_sources,
  dependencies: [libhelper_dep],
  install: true,
  install_dir: pluginsdir,
)
plugin_dep = declare_dependency(
  link_with: plugin,
)

test_exe = executable('plugin-test',
  'test.c',
  dependencies: [plugin_dep],
)
test('plugin-test', test_exe)
