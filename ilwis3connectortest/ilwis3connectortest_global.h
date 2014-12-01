#ifndef ILWIS3CONNECTORTEST_GLOBAL_H
#define ILWIS3CONNECTORTEST_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ILWIS3CONNECTORTEST_LIBRARY)
#  define ILWIS3CONNECTORTESTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define ILWIS3CONNECTORTESTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // ILWIS3CONNECTORTEST_GLOBAL_H
