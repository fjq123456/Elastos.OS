#ifndef  __ELASTOS_DROID_PHONE_ADNLIST_H__
#define  __ELASTOS_DROID_PHONE_ADNLIST_H__

#include "_Elastos.Droid.Server.Telephony.h"
#include "elastos/droid/content/AsyncQueryHandler.h"
#include "elastos/droid/ext/frameworkext.h"

namespace Elastos {
namespace Droid {
namespace Phone {

/**
 * Abbreviated Dial Numbers (ADN) list activity for the Phone app. By default, this class will show
 * you all Service Dialing Numbers (SDN) that are supported by a service provider.  SDNs are a form
 * of speed dial for accessing service provider contacts like "#MIN" for getting user minutes.
 * To see this class in use, trigger the radio info screen by dialing *#*#INFO#*#* and open the
 * menu.
 * This class can also be used as a base class for simple contact lists that can be represented with
 * only labels and numbers.
 */
class ADNList
    : public ListActivity
    , public IADNList
{
private:
    class QueryHandler
        : public AsyncQueryHandler
    {
    public:
        QueryHandler(
            /* [in] */ IContentResolver* cr);

    protected:
        //@Override
        CARAPI OnQueryComplete(
            /* [in] */ Int32 token,
            /* [in] */ IInterface* cookie,
            /* [in] */ ICursor* cursor);

        //@Override
        CARAPI OnInsertComplete(
            /* [in] */ Int32 token,
            /* [in] */ IInterface* cookie,
            /* [in] */ IUri* uri);

        //@Override
        CARAPI OnUpdateComplete(
            /* [in] */ Int32 token,
            /* [in] */ IInterface* cookie,
            /* [in] */ Int32 result);

        //@Override
        CARAPI OnDeleteComplete(
            /* [in] */ Int32 token,
            /* [in] */ IInterface* cookie,
            /* [in] */ Int32 result);
    private:
        ADNList* mHost;
    };

public:
    CAR_INTERFACE_DECL()

    ADNList()
        : mInitialSelection(-1)
    {}

    CARAPI constructor();

    CARAPI ResolveIntent(
        /* [out] */ IUri** uri);

    CARAPI NewAdapter(
        /* [out] */ ICursorAdapter** adapter);

protected:
    //@Override
    CARAPI OnCreate(
        /* [in] */ IBundle* savedInstanceState);

    //@Override
    CARAPI OnResume();

    //@Override
    CARAPI OnStop();

    CARAPI_(void) Log(
        /* [in] */ const String& msg);

private:
    CARAPI_(void) Query();

    CARAPI_(void) ReQuery();

    CARAPI_(void) SetAdapter();

    CARAPI_(void) DisplayProgress(
        /* [in] */ Boolean loading);

    static CARAPI_(Boolean) IsAirplaneModeOn(
        /* [in] */ IContext* context);


protected:
    static const String TAG;
    static const Boolean DBG;

    static const Int32 NAME_COLUMN;
    static const Int32 NUMBER_COLUMN;
    static const Int32 EMAILS_COLUMN;

    static const Int32 QUERY_TOKEN;
    static const Int32 INSERT_TOKEN;
    static const Int32 UPDATE_TOKEN;
    static const Int32 DELETE_TOKEN;

    AutoPtr<QueryHandler> mQueryHandler;
    AutoPtr<ICursorAdapter> mCursorAdapter;
    AutoPtr<ICursor> mCursor;

    Int32 mInitialSelection;

private:
    static const AutoPtr<ArrayOf<String> > COLUMN_NAMES;

    static const AutoPtr<ArrayOf<Int32> > VIEW_NAMES;

    AutoPtr<ITextView> mEmptyText;
};

} // namespace Phone
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_PHONE_ADNLIST_H__