#ifndef PTRDECL_HPP_
#define PTRDECL_HPP_

namespace ptrdecl
{
    namespace impl
    {
        template <class... Ts>
        struct PtrHelper;

        template <class T>
        struct PtrHelper<T>
        {
            using Type = T *;
        };

        template <class Ret, class... Args>
        struct PtrHelper<Ret(Args...)>
        {
            using Type = Ret (*)(Args...);
        };

        template <class Cls, class Ret, class... Args>
        struct PtrHelper<Cls, Ret(Args...)>
        {
            using Type = Ret (Cls::*)(Args...);
        };

        template <class Cls, class Field>
        struct PtrHelper<Cls, Field>
        {
            using Type = Field Cls::*;
        };
    } // namespace impl

    template <class... Ts>
    using Ptr = typename impl::PtrHelper<Ts...>::Type;

} // namespace ptrdecl

#endif
