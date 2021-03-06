//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#ifndef __ELASTOS_DROID_INCALLUI_CGLOWPADWRAPPER_H__
#define __ELASTOS_DROID_INCALLUI_CGLOWPADWRAPPER_H__

#include "Elastos.Droid.Os.h"
#include "_Elastos_Droid_InCallUI_CGlowPadWrapper.h"
#include "elastos/droid/incallui/widget/multiwaveview/GlowPadView.h"
#include <elastos/droid/os/Handler.h>

using Elastos::Droid::InCallUI::Widget::MultiwaveView::IGlowPadViewOnTriggerListener;
using Elastos::Droid::InCallUI::Widget::MultiwaveView::GlowPadView;
using Elastos::Droid::Os::Handler;
using Elastos::Droid::Os::IMessage;

namespace Elastos {
namespace Droid {
namespace InCallUI {

CarClass(CGlowPadWrapper)
    , public GlowPadView
    , public IGlowPadWrapper
    , public IGlowPadViewOnTriggerListener
{
private:
    class InnerListener
        : public Object
        , public IGlowPadViewOnTriggerListener
    {
    public:
        CAR_INTERFACE_DECL()

        InnerListener(
            /* [in] */ CGlowPadWrapper* host);

        // @Override
        CARAPI OnGrabbed(
            /* [in] */ IView* v,
            /* [in] */ Int32 handle);

        // @Override
        CARAPI OnReleased(
            /* [in] */ IView* v,
            /* [in] */ Int32 handle);

        // @Override
        CARAPI OnTrigger(
            /* [in] */ IView* v,
            /* [in] */ Int32 target);

        // @Override
        CARAPI OnGrabbedStateChange(
            /* [in] */ IView* v,
            /* [in] */ Int32 handle);

        CARAPI OnFinishFinalAnimation();

    private:
        CGlowPadWrapper* mHost;
    };

    class PingHandler
        : public Handler
    {
    public:
        PingHandler(
            /* [in] */ CGlowPadWrapper* host)
            : Handler(FALSE)
            , mHost(host)
        {}

        // @Override
        CARAPI HandleMessage(
            /* [in] */ IMessage* msg);

        // @Override
        CARAPI ToString(
            /* [out] */ String* str);

    private:
        CGlowPadWrapper* mHost;
    };

public:
    CAR_INTERFACE_DECL();

    CAR_OBJECT_DECL();

    CGlowPadWrapper();

    CARAPI constructor(
        /* [in] */ IContext* ctx);

    CARAPI constructor(
        /* [in] */ IContext* ctx,
        /* [in] */ IAttributeSet* attrs);

    CARAPI_(void) StartPing();

    CARAPI_(void) StopPing();

    // @Override
    CARAPI OnGrabbed(
        /* [in] */ IView* v,
        /* [in] */ Int32 handle);

    // @Override
    CARAPI OnReleased(
        /* [in] */ IView* v,
        /* [in] */ Int32 handle);

    // @Override
    CARAPI OnTrigger(
        /* [in] */ IView* v,
        /* [in] */ Int32 target);

    // @Override
    CARAPI OnGrabbedStateChange(
        /* [in] */ IView* v,
        /* [in] */ Int32 handle);

    CARAPI OnFinishFinalAnimation();

    CARAPI_(void) SetAnswerListener(
        /* [in] */ IAnswerListener* listener);

protected:
    // @Override
    CARAPI OnFinishInflate();

private:
    CARAPI_(void) TriggerPing();

private:
    // Parameters for the GlowPadView "ping" animation; see triggerPing().
    static const Int32 PING_MESSAGE_WHAT = 101;
    static const Boolean ENABLE_PING_AUTO_REPEAT = TRUE;
    static const Int64 PING_REPEAT_DELAY_MS = 1200;

    AutoPtr<PingHandler> mPingHandler;

    AutoPtr<IAnswerListener> mAnswerListener;
    Boolean mPingEnabled;
    Boolean mTargetTriggered;
};

} // namespace InCallUI
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_INCALLUI_CGLOWPADWRAPPER_H__
