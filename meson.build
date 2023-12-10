project('sdl-template-c', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

executable('sdl-template-c',
           'src/main.c',
           'src/Application.c',
           dependencies: [
            dependency('sdl2'),
            dependency('sdl2_image'),
            dependency('sdl2_ttf')
           ],
           install : true)
