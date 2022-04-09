//find
PyObject * appGetTime(PyObject * poSelf, PyObject * poArgs)
{
	return Py_BuildValue("f", CPythonApplication::Instance().GetGlobalTime());
}

//add after
#ifdef MAINTENANCE_INFO
PyObject * appGetLocalTime(PyObject * poSelf, PyObject * poArgs)
{
	return Py_BuildValue("f", ELTimer_GetMSec() / 1000.0f);
}
#endif

//find
		{ "GetGlobalTime",				appGetGlobalTime,				METH_VARARGS },
		
//add after
#ifdef MAINTENANCE_INFO
		{ "GetLocalTime",				appGetLocalTime,				METH_VARARGS },
#endif

//find
	PyModule_AddIntConstant(poModule, "CAMERA_STOP",			CPythonApplication::CAMERA_STOP);
	
//add after
#ifdef MAINTENANCE_INFO
	PyModule_AddIntConstant(poModule, "MAINTENANCE_INFO", 1);
#else
	PyModule_AddIntConstant(poModule, "MAINTENANCE_INFO", 0);
#endif