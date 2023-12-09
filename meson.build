project('sdl-template-c', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

sdl2_dep = dependency('sdl2')

executable('sdl-template-c',
           'src/main.c',
           'src/Application.c',
           dependencies: sdl2_dep,
           install : true)
