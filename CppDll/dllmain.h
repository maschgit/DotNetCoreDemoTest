#pragma once
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

namespace MathFuncs
{
  // namespace Cpp
  // {
  class __declspec(dllexport) MyMathFuncs
  {
  public:
#if 1
    // Returns a + b
    double Add(double a, double b);// const;

    // Returns a - b
    double Subtract(double a, double b);

    //// Returns a * b
    //double Multiply(double a, double b);

    //// Returns a / b
    //// Throws DivieByZeroException if b is 0
    //double Divide(double a, double b);


    HANDLE CreateThreads(MyMathFuncs* obj);
    static DWORD WINAPI runner(void* lpParam);
#else
    // Returns a + b
    __declspec(dllexport) double Add(double a, double b);

    // Returns a - b
    static __declspec(dllexport) double Subtract(double a, double b);

    // Returns a * b
    static __declspec(dllexport) double Multiply(double a, double b);

    // Returns a / b
    // Throws DivieByZeroException if b is 0
    static __declspec(dllexport) double Divide(double a, double b);


    static __declspec(dllexport) HANDLE CreateThreads(MyMathFuncs* obj);

    static DWORD WINAPI runner(void* lpParam);
#endif
  private:
    char pDataArray[100];
    DWORD   dwThreadId;
    HANDLE  hThreadArray;
  };
  // }
}

extern "C" {

  extern __declspec(dllexport) MathFuncs::MyMathFuncs* Create() { return new MathFuncs::MyMathFuncs(); }
  extern __declspec(dllexport) double Add(MathFuncs::MyMathFuncs* pointer, double a, double b) { return pointer->Add(a, b); }
  extern __declspec(dllexport) double Subtract(MathFuncs::MyMathFuncs* pointer, double a, double b) { return pointer->Subtract(a, b); }
  extern __declspec(dllexport) void Delete(MathFuncs::MyMathFuncs* pointer) { delete pointer; }
  extern __declspec(dllexport) void* ThreadCreate(MathFuncs::MyMathFuncs* pointer) { return pointer->CreateThreads(pointer); }
}

