# setup.py

from distutils.core import setup, Extension


lanczos_module = Extension('_lanczos', sources=['lanczos_wrap.c', 'lanczos.c'])

setup(name='lanczos', ext_modules=[lanczos_module], py_modules=["lanczos"])