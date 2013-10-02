#pragma once

#ifdef DLL_EXPORT
#    define FOO_API __declspec(dllexport)
#else
#    define FOO_API __declspec(dllimport)
#endif

namespace MixedModeLibrary
{;

class Native
{
public:
    FOO_API Native(void);
    FOO_API virtual ~Native(void);

    FOO_API virtual bool DoSomething();
};

} // namespace MixedModeLibrary

