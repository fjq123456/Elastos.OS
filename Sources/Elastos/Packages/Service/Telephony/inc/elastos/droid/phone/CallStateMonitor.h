#ifndef  __ELASTOS_DROID_PHONE_CALLSTATEMONITOR_H__
#define  __ELASTOS_DROID_PHONE_CALLSTATEMONITOR_H__

#include "_Elastos.Droid.Server.Telephony.h"
#include "elastos/droid/ext/frameworkext.h"

namespace Elastos {
namespace Droid {
namespace Phone {

/**
 * Dedicated Call state monitoring class.  This class communicates directly with
 * the call manager to listen for call state events and notifies registered
 * handlers.
 * It works as an inverse multiplexor for all classes wanted Call State updates
 * so that there exists only one channel to the telephony layer.
 *
 * TODO: Add manual phone state checks (getState(), etc.).
 */
class CallStateMonitor
    : public Handler
{
public:
    TO_STRING_IMPL("CallLogger")

    // Events generated internally:
    CallStateMonitor(
        /* [in] */ ICallManager* callManager);

    CARAPI AddListener(
        /* [in] */ IHandler* handler);

    //@Override
    CARAPI HandleMessage(
        /* [in] */ IMessage* msg);

    /**
     * When radio technology changes, we need to to reregister for all the events which are
     * all tied to the old radio.
     */
    CARAPI UpdateAfterRadioTechnologyChange();

private:
    /**
     * Register for call state notifications with the CallManager.
     */
    CARAPI_(void) RegisterForNotifications();

public:
    // Events from the Phone object:
    static const Int32 PHONE_STATE_CHANGED;
    static const Int32 PHONE_NEW_RINGING_CONNECTION;
    static const Int32 PHONE_DISCONNECT;
    static const Int32 PHONE_UNKNOWN_CONNECTION_APPEARED;
    static const Int32 PHONE_STATE_DISPLAYINFO;
    static const Int32 PHONE_STATE_SIGNALINFO;
    static const Int32 PHONE_CDMA_CALL_WAITING;
    static const Int32 PHONE_ENHANCED_VP_ON;
    static const Int32 PHONE_ENHANCED_VP_OFF;
    static const Int32 PHONE_RINGBACK_TONE;
    static const Int32 PHONE_RESEND_MUTE;
    static const Int32 PHONE_ON_DIAL_CHARS;

    // Other events from call manager
    static const Int32 EVENT_OTA_PROVISION_CHANGE;

private:
    static const String LOG_TAG;
    static const Boolean DBG;

    AutoPtr<ICallManager> mCallManager;
    AutoPtr<IArrayList> mRegisteredHandlers;
};

} // namespace Phone
} // namespace Droid
} // namespace Elastos


#endif // __ELASTOS_DROID_PHONE_CALLSTATEMONITOR_H__