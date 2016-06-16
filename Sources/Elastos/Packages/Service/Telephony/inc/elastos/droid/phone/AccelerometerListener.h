#ifndef  __ELASTOS_DROID_PHONE_ACCELEROMETERLISRENER_H__
#define  __ELASTOS_DROID_PHONE_ACCELEROMETERLISRENER_H__

#include "_Elastos.Droid.Server.Telephony.h"
#include "elastos/droid/content/AsyncQueryHandler.h"
#include "elastos/droid/ext/frameworkext.h"

namespace Elastos {
namespace Droid {
namespace Phone {

/**
 * This class is used to listen to the accelerometer to monitor the
 * orientation of the phone. The client of this class is notified when
 * the orientation changes between horizontal and vertical.
 */
class AccelerometerListener
    : public Object
    , public IAccelerometerListener
{
private:
    class MySensorEventListener
        : public Object
        , public ISensorEventListener
    {
    public:
        TO_STRING_IMPL("AccelerometerListener::MySensorEventListener")

        CAR_INTERFACE_DECL()

        MySensorEventListener(
            /* [in] */ AccelerometerListener* host)
            : mHost(host)
        {}

        CARAPI OnSensorChanged(
            /* [in] */ ISensorEvent* event);

        CARAPI OnAccuracyChanged(
            /* [in] */ ISensor* sensor,
            /* [in] */ Int32 accuracy);

    private:
        AccelerometerListener* mHost;
    };

    class MyHandler
        : public Handler
    {
    public:
        TO_STRING_IMPL("AccelerometerListener::MyHandler")

        MyHandler(
            /* [in] */ AccelerometerListener* host);

        CARAPI HandleMessage(
            /* [in] */ IMessage* msg);

    private:
        AccelerometerListener* mHost;
    };

public:
    CAR_INTERFACE_DECL()

    TO_STRING_IMPL("AccelerometerListener")

    AccelerometerListener(
        /* [in] */ IContext* context,
        /* [in] */ IAccelerometerListenerOrientationListener* listener);

    CARAPI Enable(
        /* [in] */ Boolean enable);

private:
    CARAPI_(void) SetOrientation(
        /* [in] */ Int32 orientation);

    CARAPI_(void) OnSensorEvent(
        /* [in] */ Double x,
        /* [in] */ Double y,
        /* [in] */ Double z);

private:
    static const String TAG;
    static const boolean DEBUG;
    static const boolean VDEBUG;

    AutoPtr<ISensorManager> mSensorManager;
    AutoPtr<ISensor> mSensor;

    // mOrientation is the orientation value most recently reported to the client.
    Int32 mOrientation;

    // mPendingOrientation is the latest orientation computed based on the sensor value.
    // This is sent to the client after a rebounce delay, at which point it is copied to
    // mOrientation.
    Int32 mPendingOrientation;

    AutoPtr<IAccelerometerListenerOrientationListener> mListener;

    AutoPtr<ISensorEventListener> mSensorListener;
    AutoPtr<Handler> mHandler;
};

} // namespace Phone
} // namespace Droid
} // namespace Elastos


#endif // __ELASTOS_DROID_PHONE_ACCELEROMETERLISRENER_H__