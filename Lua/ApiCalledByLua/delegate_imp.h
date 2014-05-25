namespace delegates
{
 
#define DELEGATE_TEMPLATE_COMBINE(a, b)                     DELEGATE_TEMPLATE_COMBINE1(a, b)
#define DELEGATE_TEMPLATE_COMBINE1(a, b)                    a##b
 
#define DELEGATE_TEMPLATE_I_DELEGATE                        DELEGATE_TEMPLATE_COMBINE(IDelegate, DELEGATE_SUFFIX)
 
#define DELEGATE_TEMPLATE_C_STATIC_DELEGATE                 DELEGATE_TEMPLATE_COMBINE(CStaticDelegate, DELEGATE_SUFFIX)
#define DELEGATE_TEMPLATE_C_METHOD_DELEGATE                 DELEGATE_TEMPLATE_COMBINE(CMethodDelegate, DELEGATE_SUFFIX)
 
#define DELEGATE_TEMPLATE_C_DELEGATE                        DELEGATE_TEMPLATE_COMBINE(CDelegate, DELEGATE_SUFFIX)
#define DELEGATE_TEMPLATE_C_MULTI_DELEGATE                  DELEGATE_TEMPLATE_COMBINE(CMultiDelegate, DELEGATE_SUFFIX)
 
 
    // base class of all delegates
    DELEGATE_TEMPLATE   DELEGATE_TEMPLATE_PARAMS
    class DELEGATE_TEMPLATE_I_DELEGATE
    {
    public:
        virtual ~DELEGATE_TEMPLATE_I_DELEGATE() { }
        virtual bool isType( const std::type_info& _type) = 0;
        virtual void invoke( DELEGATE_PARAMS ) = 0;
        virtual bool compare(  DELEGATE_TEMPLATE_I_DELEGATE DELEGATE_TEMPLATE_ARGS  * _delegate) const = 0;
        virtual bool compare(IDelegateUnlink * _unlink) const { return false; }
    };
 
 
    // delegate to a static function
    DELEGATE_TEMPLATE   DELEGATE_TEMPLATE_PARAMS
    class DELEGATE_TEMPLATE_C_STATIC_DELEGATE : public  DELEGATE_TEMPLATE_I_DELEGATE DELEGATE_TEMPLATE_ARGS
    {
    public:
        typedef void (*Func)( DELEGATE_PARAMS );
 
        DELEGATE_TEMPLATE_C_STATIC_DELEGATE (Func _func) : mFunc(_func) { }
 
        virtual bool isType( const std::type_info& _type) { return typeid( DELEGATE_TEMPLATE_C_STATIC_DELEGATE DELEGATE_TEMPLATE_ARGS ) == _type; }
 
        virtual void invoke( DELEGATE_PARAMS )
        {
            mFunc( DELEGATE_ARGS );
        }
 
        virtual bool compare(  DELEGATE_TEMPLATE_I_DELEGATE DELEGATE_TEMPLATE_ARGS  * _delegate) const
        {
            if (0 == _delegate || !_delegate->isType(typeid(DELEGATE_TEMPLATE_C_STATIC_DELEGATE DELEGATE_TEMPLATE_ARGS)) ) return false;
            DELEGATE_TEMPLATE_C_STATIC_DELEGATE DELEGATE_TEMPLATE_ARGS * cast = static_cast<DELEGATE_TEMPLATE_C_STATIC_DELEGATE DELEGATE_TEMPLATE_ARGS *>(_delegate);
            return cast->mFunc == mFunc;
        }
        virtual bool compare(IDelegateUnlink * _unlink) const { return false; }
 
    private:
        Func mFunc;
    };
 
 
    // delegate for the method of the class
    template DELEGATE_T_TEMPLATE_PARAMS
    class DELEGATE_TEMPLATE_C_METHOD_DELEGATE : public  DELEGATE_TEMPLATE_I_DELEGATE DELEGATE_TEMPLATE_ARGS
    {
    public:
        typedef void (T::*Method)( DELEGATE_PARAMS );
 
        DELEGATE_TEMPLATE_C_METHOD_DELEGATE(IDelegateUnlink * _unlink, T * _object, Method _method) : mUnlink(_unlink), mObject(_object), mMethod(_method) { }
 
        virtual bool isType( const std::type_info& _type) { return typeid( DELEGATE_TEMPLATE_C_METHOD_DELEGATE DELEGATE_T_TEMPLATE_ARGS ) == _type; }
 
        virtual void invoke( DELEGATE_PARAMS )
        {
            (mObject->*mMethod)( DELEGATE_ARGS );
        }
 
        virtual bool compare(  DELEGATE_TEMPLATE_I_DELEGATE DELEGATE_TEMPLATE_ARGS  * _delegate) const
        {
            if (0 == _delegate || !_delegate->isType(typeid(DELEGATE_TEMPLATE_C_METHOD_DELEGATE DELEGATE_T_TEMPLATE_ARGS)) ) return false;
            DELEGATE_TEMPLATE_C_METHOD_DELEGATE DELEGATE_T_TEMPLATE_ARGS  * cast = static_cast<  DELEGATE_TEMPLATE_C_METHOD_DELEGATE DELEGATE_T_TEMPLATE_ARGS  * >(_delegate);
            return cast->mObject == mObject && cast->mMethod == mMethod;
        }
 
        virtual bool compare(IDelegateUnlink * _unlink) const
        {
            return mUnlink == _unlink;
        }
 
    private:
        IDelegateUnlink *mUnlink;
        T * mObject;
        Method mMethod;
    };
 
} // namespace delegates
 
// template to create a delegate static function
// parameters: a pointer to a function
// example : newDelegate(funk_name);
// example : newDelegate(class_name::static_method_name);
DELEGATE_TEMPLATE   DELEGATE_TEMPLATE_PARAMS
inline  delegates::DELEGATE_TEMPLATE_I_DELEGATE DELEGATE_TEMPLATE_ARGS  * newDelegate( void (*_func)( DELEGATE_PARAMS ) )
{
    return new delegates::DELEGATE_TEMPLATE_C_STATIC_DELEGATE DELEGATE_TEMPLATE_ARGS  (_func);
}
 
 
// template to create a delegate class method
// options : pointer to the class object and a pointer to a class method
// example : newDelegate(&object_name, &class_name::method_name);
template DELEGATE_T_TEMPLATE_PARAMS
inline  delegates::DELEGATE_TEMPLATE_I_DELEGATE DELEGATE_TEMPLATE_ARGS  * newDelegate( T * _object, void (T::*_method)( DELEGATE_PARAMS ) )
{
    return new delegates::DELEGATE_TEMPLATE_C_METHOD_DELEGATE  DELEGATE_T_TEMPLATE_ARGS  (delegates::GetDelegateUnlink(_object), _object, _method);
}
 
namespace delegates
{
    // pattern of the delegate class
    DELEGATE_TEMPLATE   DELEGATE_TEMPLATE_PARAMS
    class DELEGATE_TEMPLATE_C_DELEGATE
    {
    public:
        typedef  DELEGATE_TEMPLATE_I_DELEGATE DELEGATE_TEMPLATE_ARGS  IDelegate;
 
        DELEGATE_TEMPLATE_C_DELEGATE () : mDelegate(0) { }
        DELEGATE_TEMPLATE_C_DELEGATE (const DELEGATE_TEMPLATE_C_DELEGATE  DELEGATE_TEMPLATE_ARGS& _event)
        {
            // pick up his own
            mDelegate = _event.mDelegate;
            const_cast< DELEGATE_TEMPLATE_C_DELEGATE  DELEGATE_TEMPLATE_ARGS& >(_event).mDelegate = 0;
        }
        ~DELEGATE_TEMPLATE_C_DELEGATE () { clear(); }
 
        bool empty() const { return mDelegate == 0; }
 
        void clear()
        {
            if (mDelegate)
            {
                delete mDelegate;
                mDelegate = 0;
            }
        }
 
        DELEGATE_TEMPLATE_C_DELEGATE  DELEGATE_TEMPLATE_ARGS & operator=(IDelegate* _delegate)
        {
            delete mDelegate;
            mDelegate = _delegate;
            return *this;
        }
 
        DELEGATE_TEMPLATE_C_DELEGATE  DELEGATE_TEMPLATE_ARGS & operator=(const DELEGATE_TEMPLATE_C_DELEGATE  DELEGATE_TEMPLATE_ARGS& _event)
        {
            // pick up his own
            delete mDelegate;
            mDelegate = _event.mDelegate;
            const_cast< DELEGATE_TEMPLATE_C_DELEGATE  DELEGATE_TEMPLATE_ARGS& >(_event).mDelegate = 0;
 
            return *this;
        }
 
        void operator()( DELEGATE_PARAMS )
        {
            if (mDelegate == 0) return;
            mDelegate->invoke( DELEGATE_ARGS );
        }
 
    private:
        IDelegate * mDelegate;
    };
 
 
    // template class multi delegate
    DELEGATE_TEMPLATE   DELEGATE_TEMPLATE_PARAMS
    class DELEGATE_TEMPLATE_C_MULTI_DELEGATE
    {
    public:
        typedef  DELEGATE_TEMPLATE_I_DELEGATE DELEGATE_TEMPLATE_ARGS  IDelegate;
        typedef DELEGATE_TYPENAME std::list<IDelegate* /*, Allocator<IDelegate*>*/ > ListDelegate;
        typedef DELEGATE_TYPENAME ListDelegate::iterator ListDelegateIterator;
        typedef DELEGATE_TYPENAME ListDelegate::const_iterator ConstListDelegateIterator;
 
        DELEGATE_TEMPLATE_C_MULTI_DELEGATE () { }
        ~DELEGATE_TEMPLATE_C_MULTI_DELEGATE () { clear(); }
 
        bool empty() const
        {
            for (ConstListDelegateIterator iter = mListDelegates.begin(); iter!=mListDelegates.end(); ++iter)
            {
                if (*iter) return false;
            }
            return true;
        }
 
        void clear()
        {
            for (ListDelegateIterator iter=mListDelegates.begin(); iter!=mListDelegates.end(); ++iter)
            {
                if (*iter)
                {
                    delete (*iter);
                    (*iter) = 0;
                }
            }
        }
 
        void clear(IDelegateUnlink * _unlink)
        {
            for (ListDelegateIterator iter=mListDelegates.begin(); iter!=mListDelegates.end(); ++iter)
            {
                if ((*iter) && (*iter)->compare(_unlink))
                {
                    delete (*iter);
                    (*iter) = 0;
                }
            }
        }
 
        DELEGATE_TEMPLATE_C_MULTI_DELEGATE  DELEGATE_TEMPLATE_ARGS & operator+=(IDelegate* _delegate)
        {
            for (ListDelegateIterator iter=mListDelegates.begin(); iter!=mListDelegates.end(); ++iter)
            {
                if ((*iter) && (*iter)->compare(_delegate))
                {
                    delete _delegate;
                    return *this;
                    //DELEGATE_TEMPLATE_ASSERT(false, "dublicate delegate");
                }
            }
            mListDelegates.push_back(_delegate);
            return *this;
        }
 
        DELEGATE_TEMPLATE_C_MULTI_DELEGATE  DELEGATE_TEMPLATE_ARGS & operator-=(IDelegate* _delegate)
        {
            for (ListDelegateIterator iter=mListDelegates.begin(); iter!=mListDelegates.end(); ++iter)
            {
                if ((*iter) && (*iter)->compare(_delegate))
                {
                    // verify the identity of the delegates
                    if ((*iter) != _delegate) delete (*iter);
                    (*iter) = 0;
                    break;
                }
            }
            delete _delegate;
            return *this;
        }
 
        void operator()( DELEGATE_PARAMS )
        {
            ListDelegateIterator iter = mListDelegates.begin();
            while (iter != mListDelegates.end())
            {
                if (0 == (*iter))
                {
                    iter = mListDelegates.erase(iter);
                }
                else
                {
                    (*iter)->invoke( DELEGATE_ARGS );
                    ++iter;
                }
            }
        }
 
    private:
        // constructor and operator =, without implementation, just for private
        DELEGATE_TEMPLATE_C_MULTI_DELEGATE (const DELEGATE_TEMPLATE_C_MULTI_DELEGATE  DELEGATE_TEMPLATE_ARGS & _event);
        DELEGATE_TEMPLATE_C_MULTI_DELEGATE  DELEGATE_TEMPLATE_ARGS & operator=(const DELEGATE_TEMPLATE_C_MULTI_DELEGATE  DELEGATE_TEMPLATE_ARGS & _event);
 
 
    private:
        ListDelegate mListDelegates;
 
    };
 
 
#undef DELEGATE_TEMPLATE_COMBINE
#undef DELEGATE_TEMPLATE_COMBINE1
 
#undef DELEGATE_TEMPLATE_I_DELEGATE
 
#undef DELEGATE_TEMPLATE_C_STATIC_DELEGATE
#undef DELEGATE_TEMPLATE_C_METHOD_DELEGATE
 
#undef DELEGATE_TEMPLATE_C_DELEGATE
#undef DELEGATE_TEMPLATE_C_MULTI_DELEGATE
 
#undef DELEGATE_SUFFIX
#undef DELEGATE_TEMPLATE
#undef DELEGATE_TEMPLATE_PARAMS
#undef DELEGATE_TEMPLATE_ARGS
#undef DELEGATE_T_TEMPLATE_PARAMS
#undef DELEGATE_T_TEMPLATE_ARGS
#undef DELEGATE_PARAMS
#undef DELEGATE_ARGS
#undef DELEGATE_TYPENAME
 
}