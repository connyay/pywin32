// This file implements the IInternetBindInfo Interface and Gateway for Python.
// Generated by makegw.py

#include "internet_pch.h"
#include "PyIInternetBindInfo.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIInternetBindInfo::PyIInternetBindInfo(IUnknown *pdisp):
	PyIUnknown(pdisp)
{
	ob_type = &type;
}

PyIInternetBindInfo::~PyIInternetBindInfo()
{
}

/* static */ IInternetBindInfo *PyIInternetBindInfo::GetI(PyObject *self)
{
	return (IInternetBindInfo *)PyIUnknown::GetI(self);
}

// @pymethod |PyIInternetBindInfo|GetBindInfo|Description of GetBindInfo.
PyObject *PyIInternetBindInfo::GetBindInfo(PyObject *self, PyObject *args)
{
	IInternetBindInfo *pIIBI = GetI(self);
	if ( pIIBI == NULL )
		return NULL;
// *** The input argument pbindinfo of type "BINDINFO __RPC_FAR *" was not processed ***
//     Please check the conversion function is appropriate and exists!
	BINDINFO pbindinfo;
	PyObject *obpbindinfo;
	DWORD grfBINDF;
	if ( !PyArg_ParseTuple(args, "O:GetBindInfo", &obpbindinfo) )
		return NULL;
	BOOL bPythonIsHappy = TRUE;
	if (bPythonIsHappy && !PyObject_AsBINDINFO( obpbindinfo, &pbindinfo )) bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIIBI->GetBindInfo( &grfBINDF, &pbindinfo );
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return OleSetOleError(hr);
// *** The output argument pbindinfo of type "BINDINFO __RPC_FAR *" was not processed ***
//     The type 'BINDINFO' (pbindinfo) is unknown.

	PyObject *pyretval = Py_BuildValue("i", grfBINDF);
	return pyretval;
}

// @pymethod |PyIInternetBindInfo|GetBindString|Description of GetBindString.
PyObject *PyIInternetBindInfo::GetBindString(PyObject *self, PyObject *args)
{
	PyErr_SetString(PyExc_RuntimeError, "GetBindString not implemented");
	return NULL;
/****** Is an ARRAY of strings!!!
	IInternetBindInfo *pIIBI = GetI(self);
	if ( pIIBI == NULL )
		return NULL;
	// @pyparm int|ulStringType||Description for ulStringType
	// @pyparm <o unicode>|ppwzStr||Description for ppwzStr
	// @pyparm int|cEl||Description for cEl
	// @pyparm int|pcElFetched||Description for pcElFetched
	PyObject *obppwzStr;
	ULONG ulStringType;
	LPOLESTR ppwzStr;
	ULONG cEl;
	ULONG pcElFetched;
	if ( !PyArg_ParseTuple(args, "iOii:GetBindString", &ulStringType, &obppwzStr, &cEl, &pcElFetched) )
		return NULL;
	BOOL bPythonIsHappy = TRUE;
	if (!PyWinObject_AsBstr(obppwzStr, &ppwzStr)) bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIIBI->GetBindString( ulStringType, &ppwzStr, cEl, &pcElFetched );
	PY_INTERFACE_POSTCALL;
	SysFreeString(ppwzStr);

	if ( FAILED(hr) )
		return OleSetOleError(hr);
	obppwzStr = MakeOLECHARToObj(ppwzStr);

	PyObject *pyretval = Py_BuildValue("Oi", obppwzStr, pcElFetched);
	Py_XDECREF(obppwzStr);
	CoTaskMemFree(ppwzStr);
	return pyretval;
***/
}

// @object PyIInternetBindInfo|Description of the interface
static struct PyMethodDef PyIInternetBindInfo_methods[] =
{
	{ "GetBindInfo", PyIInternetBindInfo::GetBindInfo, 1 }, // @pymeth GetBindInfo|Description of GetBindInfo
	{ "GetBindString", PyIInternetBindInfo::GetBindString, 1 }, // @pymeth GetBindString|Description of GetBindString
	{ NULL }
};

PyComTypeObject PyIInternetBindInfo::type("PyIInternetBindInfo",
		&PyIUnknown::type,
		sizeof(PyIInternetBindInfo),
		PyIInternetBindInfo_methods,
		GET_PYCOM_CTOR(PyIInternetBindInfo));
// ---------------------------------------------------
//
// Gateway Implementation
STDMETHODIMP PyGInternetBindInfo::GetBindInfo(
		/* [out] */ DWORD __RPC_FAR * grfBINDF,
		/* [unique][out][in] */ BINDINFO __RPC_FAR * pbindinfo)
{
	PY_GATEWAY_METHOD;
// *** The input argument pbindinfo of type "BINDINFO __RPC_FAR *" was not processed ***
//   - Please ensure this conversion function exists, and is appropriate
//   - The type 'BINDINFO' (pbindinfo) is unknown.
	PyObject *obpbindinfo = PyObject_FromBINDINFO(pbindinfo);
	if (obpbindinfo==NULL) return PyCom_HandlePythonFailureToCOM();
	PyObject *result;
	HRESULT hr=InvokeViaPolicy("GetBindInfo", &result, "O", obpbindinfo);
	Py_DECREF(obpbindinfo);
	if (FAILED(hr)) return hr;
	// Process the Python results, and convert back to the real params
// *** The output argument pbindinfo of type "BINDINFO __RPC_FAR *" was not processed ***
//     The type 'BINDINFO' (pbindinfo) is unknown.
	if (!PyArg_Parse(result, "i" , grfBINDF)) return PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	Py_DECREF(result);
	return hr;
}

STDMETHODIMP PyGInternetBindInfo::GetBindString(
		/* [in] */ ULONG ulStringType,
		/* [out][in] */ LPOLESTR __RPC_FAR * ppwzStr,
		/* [in] */ ULONG cEl,
		/* [out][in] */ ULONG __RPC_FAR * pcElFetched)
{
	return E_NOTIMPL;
/*****
	PY_GATEWAY_METHOD;
	PyObject *obppwzStr;
	obppwzStr = MakeOLECHARToObj(ppwzStr);
	PyObject *result;
	HRESULT hr=InvokeViaPolicy("GetBindString", &result, "iOii", ulStringType, obppwzStr, cEl, pcElFetched);
	Py_XDECREF(obppwzStr);
	if (FAILED(hr)) return hr;
	// Process the Python results, and convert back to the real params
	PyObject *obppwzStr;
	if (!PyArg_ParseTuple(result, "Oi" , &obppwzStr, pcElFetched)) return PyCom_HandlePythonFailureToCOM();
	BOOL bPythonIsHappy = TRUE;
	if (!PyWinObject_AsBstr(obppwzStr, ppwzStr)) bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) hr = PyCom_HandlePythonFailureToCOM();
	Py_DECREF(result);
	return hr;
****/
}

