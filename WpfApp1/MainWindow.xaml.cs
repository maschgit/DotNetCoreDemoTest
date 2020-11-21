using System;
using System.Windows;
using System.Runtime.InteropServices;

namespace WpfApp1
{
  /// <summary>
  /// Interaction logic for MainWindow.xaml
  /// </summary>
  public partial class MainWindow : Window
  {
    [DllImport("CPPDLL.dll")]
    private static extern IntPtr Create();

    [DllImport("CPPDLL.dll")]
    private static extern double Add(IntPtr pointer, double a, double b);

    [DllImport("CPPDLL.dll")]
    private static extern double Subtract(IntPtr pointer, double a, double b);

    [DllImport("CPPDLL.dll")]
    private static extern double Delete(IntPtr pointer);

    [DllImport("CPPDLL.dll")]
    private static extern IntPtr ThreadCreate(IntPtr pointer);
    public MainWindow()
    {
      InitializeComponent();
    }

    private void Button_Click(object sender, RoutedEventArgs e)
    {
      var pointer = Create();
      ThreadCreate(pointer);
      MessageBox.Show("The Result of add is: " + Add(pointer, 12, 14) + " Result of Subtract is: " + Subtract(pointer, 14, 16));
      Delete(pointer);
    }
  }
}
