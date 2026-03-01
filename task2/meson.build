
project(
  'Task 2. MIEE C basics.',      
  'c',
  version: '0.2.0',
  license: 'Unlicense',
  default_options: [
    'c_std=c11',
    'warning_level=3',
    'werror=true',
    'buildtype=release'
  ],
  meson_version: '>= 0.60.0'
)

cc = meson.get_compiler('c')

inc = include_directories('include')

# Import Ellipse framework
cmake = import('cmake')
llibs_sub = cmake.subproject('llibs')
llibs_dep = llibs_sub.dependency('llibs')

# config.h
conf_data = configuration_data()
conf_data.set('VERSION', meson.project_version())
conf_data.set('PROJECT_NAME', meson.project_name())

configure_file(
  output: 'config.h',
  configuration: conf_data
)

sources = files(
  'src/main.c',
)

# 7. Сборка исполняемого файла
executable(
  'task2',
  sources,
  include_directories: inc,
  dependencies: [ llibs_dep ],
  install: true
)
