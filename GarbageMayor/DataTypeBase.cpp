#include <assert.h>

#include "DataTypeBase.h"

namespace GarbageMayor
{
    DTbase::DTbase()
        : type(dt_error)
    {
    }
    DTbase::~DTbase()
    {
    }
    
    bool DTbase::is_error() const
    {
        return type != dt_error;
    }
    bool DTbase::is_null() const
    {
        return type != dt_null;
    }
}
