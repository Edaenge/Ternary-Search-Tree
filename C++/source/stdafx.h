#pragma once

#if defined _DLL_IMPORT
#define DLL_USAGE __declspec(dllimport)
#else
#define DLL_USAGE __declspec(dllexport)
#endif

template< class T >
static void SAFE_DELETE(T *&a)
{
    if (a != nullptr)
        delete a;

    (a) = nullptr;
}
