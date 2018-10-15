project('app', 'c',
  version: '1',
)

prefix = get_option('prefix')
libdir = join_paths(prefix, get_option('libdir'))
pkglibdir = join_paths(libdir, 'app')
pluginsdir = join_paths(pkglibdir, 'plugins')

helper_sources = ['helper.c']
helper_headers = ['helper.h']
libhelper = shared_library('helper',
  helper_sources + helper_headers,
  install: true,
  install_dir: pkglibdir,
)
libhelper_dep = declare_dependency(link_with: libhelper)

installed_header_subdir = 'helper'

install_headers(helper_headers, subdir: installed_header_subdir)

pkgconfig = import('pkgconfig')
pkgconfig.generate(
  name: 'helper',
  description: 'helper library for app plugins',
  version: meson.project_version(),
  libraries: libhelper,
  subdirs: [installed_header_subdir],
  variables: ['pluginsdir=' + pluginsdir],
  # Without this line, the plugin & test get their rpath set in the builddir.
  # With it, they don't.
  requires: ['glib-2.0'],
)

config_h = configuration_data()
config_h.set_quoted('PLUGINSDIR', pluginsdir)
config_h_file = configure_file(
  output: 'config.h',
  configuration: config_h,
)

cc = meson.get_compiler('c')
dl_dep = cc.find_library('dl', required: false)

app_sources = ['app.c', config_h_file]
executable('app',
  app_sources,
  dependencies: [libhelper_dep, dl_dep],
  install: true,
  # TODO: couldn't Meson infer this from libhelper's install_dir?
  install_rpath: pkglibdir,
)
