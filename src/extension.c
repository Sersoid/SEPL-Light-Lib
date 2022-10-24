#include <stdio.h>
#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "wave/module.h"

#define _STR(x) #x
#define STR(x) _STR(x)

static char version_str[] = STR(SEPLLIGHTLIB_VERSION);
static char author_str[] = STR(SEPLLIGHTLIB_AUTHOR);

static void init_pkginfo(PyObject *module)
{
    PyModule_AddStringConstant(module, "__version__", version_str);
    PyModule_AddStringConstant(module, "__author__", author_str);
}

static PyMethodDef methods[] = {
    {"wave_length_to_rgb", wave_length_to_rgb, METH_VARARGS, ""},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef extension = {
	PyModuleDef_HEAD_INIT,
	"_sepl_light_lib",
	"Library for convenient work with interference phenomena created for BMSTU SEPL",
	-1,
	methods
};

PyMODINIT_FUNC PyInit__sepl_light_lib()
{
    PyObject *module;

    module = PyModule_Create(&extension);
    init_pkginfo(module);

    return module;
}
