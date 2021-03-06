#ifndef __CRESTARTER_H__
#define __CRESTARTER_H__

#include "elastos/droid/app/Activity.h"
#include "_CRestarter.h"

using Elastos::Droid::App::Activity;

namespace Elastos {
namespace Droid {
namespace DevSamples {
namespace Snowfox {

class CRestarter : public Activity
{
public:
    CARAPI OnCreate(
        /* [in] */ IBundle* savedInstanceState);
};

} // namespace Snowfox
} // namespace DevSamples
} // namespace Droid
} // namespace Elastos

#endif //__CRESTARTER_H__

