This project exists to demonstrate a specific bug in xUnit: 

When a C++/Cli test dll links to both managed and native code, the xUnit cannot find/open the mixed mode dll.

To see the bug, compile the project; everything should work as expected and both tests in CppCliTests should show up in VS Test Explorer (or your runner of choice).


Open the CanInstantiateNative test and uncomment the line that instantiates the native class:


	[Fact]
    void CanInstantiateNative()
    {
        //Uncommenting the following line will cause xUnit to not find the test dll
        MixedModeLibrary::Native n;
    }

Now xUnit excepts with:

	xUnit.net: Exception discovering tests from D:\internal\xUnitBug\bin\Release\CppCliTests.dll: System.IO.FileNotFoundException: Could not load file or assembly 'CppCliTests.DLL' or one of its dependencies. The specified module could not be found.
	File name: 'CppCliTests.DLL'
	   at System.Reflection.RuntimeAssembly._nLoad(AssemblyName fileName, String codeBase, Evidence assemblySecurity, RuntimeAssembly locationHint, StackCrawlMark& stackMark, IntPtr pPrivHostBinder, Boolean throwOnFileNotFound, Boolean forIntrospection, Boolean suppressSecurityChecks)
	   at System.Reflection.RuntimeAssembly.InternalLoadAssemblyName(AssemblyName assemblyRef, Evidence assemblySecurity, RuntimeAssembly reqAssembly, StackCrawlMark& stackMark, IntPtr pPrivHostBinder, Boolean throwOnFileNotFound, Boolean forIntrospection, Boolean suppressSecurityChecks)
	   at System.Reflection.Assembly.Load(AssemblyName assemblyRef)
	   at Xunit.Sdk.Executor..ctor(String assemblyFilename)
	   at Xunit.ExecutorWrapper.RethrowWithNoStackTraceLoss(Exception ex)
	   at Xunit.ExecutorWrapper.CreateObject(String typeName, Object[] args)
	   at Xunit.ExecutorWrapper..ctor(String assemblyFilename, String configFilename, Boolean shadowCopy)
	   at Xunit.Runner.VisualStudio.VsTestRunner.DiscoverTests(IEnumerable`1 sources, IDiscoveryContext discoveryContext, IMessageLogger logger, ITestCaseDiscoverySink discoverySink)