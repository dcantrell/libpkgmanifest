project('libpkgmanifest',
        'cpp',
        version : '0.5.9',
        default_options : [
            'cxx_std=c++20',
            'warning_level=3',
            'werror=true',
            'buildtype=debugoptimized'
        ],
        license : 'LGPL-2.1-or-later')

cpp = meson.get_compiler('cpp')

# Dependecies
yaml = dependency('yaml-cpp', required : true)

# Include directories for builds
inc = include_directories('include')

# What to build
subdir('src')
subdir('include')

if get_option('python').enabled()
    subdir('bindings')
endif

if get_option('docs').enabled()
    subdir('docs')
endif

if get_option('tests').enabled()
    subdir('tests')
endif
