using Xunit;

namespace CSharpTests
{
    public class CSharpTest
    {
        [Fact]
        public void CanInstantiateManaged()
        {
            MixedModeLibrary.Managed m = new MixedModeLibrary.Managed();
            Assert.NotNull(m);
        }
    }
}
