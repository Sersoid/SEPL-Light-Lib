#include <stdlib.h>
#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "components/cie_rgb.h"

PyObject *wave_length_to_rgb(PyObject *self, PyObject *args, PyObject *keywds)
{
    PyObject *result;
    unsigned char *rgb;
    double wave_length;
    static char *kwlist[] = {"wave_length", NULL};

    if (! PyArg_ParseTupleAndKeywords(args, keywds, "d", kwlist, &wave_length))
        return NULL;

    rgb = wave_length_to_rgb_c(wave_length);
    if (! rgb)
        return NULL;

    result = Py_BuildValue("(iii)", rgb[0], rgb[1], rgb[2]);
    free(rgb);

    return result;
}
