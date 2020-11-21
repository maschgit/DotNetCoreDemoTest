using System;
using System.Runtime.InteropServices;

namespace ConsoleApp
{
  class Program
  {
    [DllImport(@"CPPDLL.dll")]
    private static extern IntPtr Create();

    [DllImport(@"CPPDLL.dll")]
    private static extern double Add(IntPtr pointer, double a, double b);

    [DllImport(@"CPPDLL.dll")]
    private static extern double Subtract(IntPtr pointer, double a, double b);

    [DllImport(@"CPPDLL.dll")]
    private static extern double Delete(IntPtr pointer);

    static void Main(string[] args)
    {
      Console.WriteLine("Hello World!");
      var pointer = Create();
      Console.WriteLine(" 10 + 5: " + Add(pointer, 10, 5));
      Delete(pointer);
      Console.ReadLine();
    }
  }
}
