#include "Stdafx.h"

using namespace System;
using namespace Xunit;

#include "Native.h"

namespace CppCliTests 
{;

public ref class CppCliTest
{
public:
    [Fact]
    void CanInstantiateManaged()
    {
        MixedModeLibrary::Managed^ m = gcnew MixedModeLibrary::Managed();
    }

    [Fact]
    void CanInstantiateNative()
    {
        //Uncommenting the following line will cause xUnit to not find the test dll
        //MixedModeLibrary::Native n;
    }

}; // ref class CppCliTest

} // namespace CppCliTests
