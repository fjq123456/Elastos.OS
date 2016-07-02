#ifndef __ELASTOS_DROID_DIALERBIND_ANALYTICS_ANALYTICSLISTFRAGMENT_H__
#define __ELASTOS_DROID_DIALERBIND_ANALYTICS_ANALYTICSLISTFRAGMENT_H__

#include "_Elastos.Droid.ContactsCommon.h"
#include <elastos/droid/app/Fragment.h>

using Elastos::Droid::App::Fragment;

namespace Elastos {
namespace Droid {
namespace DialerBind {
namespace Analytics {

class AnalyticsFragment
    : public Fragment
    , public IAnalyticsInterface
{
public:
    CAR_INTERFACE_DECL()

    // @Override
    CARAPI SendHitEvent(
        /* [in] */ const String& categoryId,
        /* [in] */ const String& actionId,
        /* [in] */ const String& labelId);

    // @Override
    CARAPI SendScreenView();
};

} // Analytics
} // DialerBind
} // Droid
} // Elastos

#endif //__ELASTOS_DROID_DIALERBIND_ANALYTICS_ANALYTICSLISTFRAGMENT_H__