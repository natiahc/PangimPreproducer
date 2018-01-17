#ifndef PANGIM_PREPRODUCER_GLOBAL_H
#define PANGIM_PREPRODUCER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PANGIM_PREPRODUCER_LIBRARY)
#  define PANGIM_PREPRODUCER_SHARED_EXPORT Q_DECL_EXPORT
#else
#  define PANGIM_PREPRODUCER_SHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PANGIM_PREPRODUCER_GLOBAL_H
