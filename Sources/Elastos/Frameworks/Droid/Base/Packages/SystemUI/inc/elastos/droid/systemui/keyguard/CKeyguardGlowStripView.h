
#ifndef __ELASTOS_DROID_SYSTEMUI_KEYGUARD_CKEYGUARDGLOWSTRIPVIEW_H__
#define __ELASTOS_DROID_SYSTEMUI_KEYGUARD_CKEYGUARDGLOWSTRIPVIEW_H__

#include "_Elastos_Droid_SystemUI_Keyguard_CKeyguardGlowStripView.h"
#include <elastos/droid/widget/LinearLayout.h>

using Elastos::Droid::Widget::LinearLayout;

namespace Elastos {
namespace Droid {
namespace SystemUI {
namespace Keyguard {

CarClass(CKeyguardGlowStripView)
    , public LinearLayout
    , public IKeyguardGlowStripView
{
private:
    class MyAnimatorListenerAdapter
        : public AnimatorListenerAdapter
    {
    public:
        TO_STRING_IMPL("CKeyguardGlowStripView::MyAnimatorListenerAdapter")

        MyAnimatorListenerAdapter(
            /* [in] */ CKeyguardGlowStripView* host)
            : mHost(host)
        {}

        //@Override
        CARAPI OnAnimationEnd(
            /* [in] */ IAnimator* animation);

        //@Override
        CARAPI OnAnimationStart(
            /* [in] */ IAnimator* animation);

    private:
        CKeyguardGlowStripView* mHost;
    };

    class MyAnimatorUpdateListener
        : public Object
        , public IAnimatorUpdateListener
    {
    public:
        CAR_INTERFACE_DECL();

        MyAnimatorUpdateListener(
            /* [in] */ CKeyguardGlowStripView* host)
            : mHost(host)
        {}

        //@Override
        CARAPI OnAnimationUpdate(
            /* [in] */ IValueAnimator* animation);

    private:
        CKeyguardGlowStripView* mHost;
    };

public:
    CAR_OBJECT_DECL()

    CKeyguardGlowStripView();

    CARAPI constructor(
        /* [in] */ IContext* context);

    CARAPI constructor(
        /* [in] */ IContext* context,
        /* [in] */ IAttributeSet* attrs);

    CARAPI constructor(
        /* [in] */ IContext* context,
        /* [in] */ IAttributeSet* attrs,
        /* [in] */ Int32 defStyle);

    CARAPI MakeEmGo();

protected:
    CARAPI OnSizeChanged(
        /* [in] */ Int32 w,
        /* [in] */ Int32 h,
        /* [in] */ Int32 oldw,
        /* [in] */ Int32 oldh);

    //@Override
    CARAPI DispatchDraw(
        /* [in] */ ICanvas* canvas);

private:
    static const Int32 DURATION;

    static const Float SLIDING_WINDOW_SIZE;
    Int32 mDotStripTop;
    Int32 mHorizontalDotGap;

    Int32 mDotSize;
    Int32 mNumDots;
    AutoPtr<IDrawable> mDotDrawable;
    Boolean mLeftToRight;

    Float mAnimationProgress;
    Boolean mDrawDots;
    AutoPtr<IValueAnimator> mAnimator;
    AutoPtr<IInterpolator> mDotAlphaInterpolator;
};

} // namespace Keyguard
} // namespace SystemUI
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_SYSTEMUI_KEYGUARD_CKEYGUARDGLOWSTRIPVIEW_H__