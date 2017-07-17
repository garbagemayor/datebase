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
    
    void DTbase::assert_type()
    {
        assert(type!=dt_error);
    }
}
