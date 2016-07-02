#ifndef __ELASTOS_DROID_DIALER_LIST_CDRAGDROPCONTROLLER_H__
#define __ELASTOS_DROID_DIALER_LIST_CDRAGDROPCONTROLLER_H__

#include "_Elastos_Droid_Dialer_List_CDragDropController.h"
#include "elastos/apps/dialer/list/DragDropController.h"

namespace Elastos {
namespace Droid {
namespace Dialer {
namespace List {

CarClass(CDragDropController)
    , public DragDropController
{
public:
    CAR_OBJECT_DECL();
};

} // List
} // Dialer
} // Droid
} // Elastos

#endif //__ELASTOS_DROID_DIALER_LIST_CDRAGDROPCONTROLLER_H__