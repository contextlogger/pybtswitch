//
// Copyright 2008 Helsinki Institute for Information Technology (HIIT)
// and the authors. All rights reserved.
//
// Authors: Tero Hasu <tero.hasu@hut.fi>
//

// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation files
// (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge,
// publish, distribute, sublicense, and/or sell copies of the Software,
// and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
// BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// For info on the API we are using here, see
// http://wiki.forum.nokia.com/index.php/Bluetooth_Engine_API.

#include <e32std.h>
#include <bteng.h>

#include <Python.h>
#include <symbian_python_ext_util.h>
#include "local_epoc_py_utils.h"

// -------------------------------------------------------
// Python module...

static PyObject *_fn__pybtswitch__get_power_state(PyObject *aPyMod, PyObject *)
{
  CBTMCMSettings* settings = NULL;

  // The NewL takes an optional callback argument.
  TRAPD(error, settings = CBTMCMSettings::NewL());
  if ((error != KErrNone)) {
    return SPyErr_SetFromSymbianOSErr(error);
  }

  TBool powerState;
  error = settings->GetPowerState(powerState);
  delete settings;

  if ((error != KErrNone)) {
    return SPyErr_SetFromSymbianOSErr(error);
  }
  
  return Py_BuildValue("i", powerState ? 1 : 0);
}

static PyObject *_fn__pybtswitch__set_power_state(PyObject *aPyMod, PyObject *aPyArgs)
{
  int intPowerState;
  if (!PyArg_ParseTuple(aPyArgs, "i", &intPowerState))
    {
      return NULL;
    }
  TBool powerState = (intPowerState ? ETrue : EFalse);

  CBTMCMSettings* settings = NULL;
  TRAPD(error, settings = CBTMCMSettings::NewL());
  if ((error != KErrNone)) {
    return SPyErr_SetFromSymbianOSErr(error);
  }

  error = settings->SetPowerState(powerState);
  delete settings;
  
  if ((error != KErrNone)) {
    return SPyErr_SetFromSymbianOSErr(error);
  }

  RETURN_NO_VALUE;
}

static PyMethodDef const _ft__pybtswitch[] = {
  {"get_power_state", reinterpret_cast<PyCFunction>(_fn__pybtswitch__get_power_state), METH_NOARGS, NULL},
  {"set_power_state", reinterpret_cast<PyCFunction>(_fn__pybtswitch__set_power_state), METH_VARARGS, NULL},
  {NULL}};

EXPORT_C void initpybtswitch()
{
  PyObject *pyMod = Py_InitModule("pybtswitch", const_cast<PyMethodDef *>((&_ft__pybtswitch[0])));
  if ((pyMod == NULL)) {
    return;
  }
}

#ifndef EKA2
GLDEF_C TInt E32Dll(TDllReason)
{
  return KErrNone;
}
#endif
