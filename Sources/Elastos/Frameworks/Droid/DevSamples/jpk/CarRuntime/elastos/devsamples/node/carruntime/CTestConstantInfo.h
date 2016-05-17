
#ifndef __CTESTCONSTANTINFO_H__
#define __CTESTCONSTANTINFO_H__

#include "_Elastos_DevSamples_Node_CarRuntime_CTestConstantInfo.h"

#include <elastos/droid/ext/frameworkdef.h>
#include <elastos/core/Object.h>

namespace Elastos {
namespace DevSamples {
namespace Node {
namespace CarRuntime {

CarClass(CTestConstantInfo)
    , public Object
    , public ITestConstantInfo
{
public:
    CAR_INTERFACE_DECL()

    CAR_OBJECT_DECL()

    CARAPI GetName(
        /* [out] */ String * pName);

    CARAPI GetValue(
        /* [out] */ Int32 * pValue);

    CARAPI GetModuleInfo(
        /* [out] */ ITestModuleInfo ** ppModuleInfo);

    CARAPI constructor();

    CARAPI constructor(
        /* [in] */ IConstantInfo * pConstantInfo);

private:
    // TODO: Add your private member variables here.
};

}
}
}
}

#endif // __CTESTCONSTANTINFO_H__