#include "pch.h"

#include "dllmain.h"
//#include "TaskCreateClass.h"
#include <stdexcept>
#include <iostream>

#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

using namespace std;

namespace MathFuncs
{
  double MyMathFuncs::Add(double a, double b)// const
  {
    return a + b;
  }

  double MyMathFuncs::Subtract(double a, double b)
  {
    return a - b;
  }

  void* MyMathFuncs::CreateThreads(MyMathFuncs* obj)
  {
    obj->hThreadArray = CreateThread(
      NULL,
      0,
      obj->runner,
      obj->pDataArray,
      0,
      &obj->dwThreadId
    );
    return (void*)obj->hThreadArray;
  }

  DWORD WINAPI MyMathFuncs::runner(void* lpParam)
  {
    auto counter = 0;
    while (1)
    {
      std::cout << "Run. Counter value is: " << std::hex << counter++ << std::endl;
      Sleep(250);
      std::cout << "Test. Counter value is: " << std::dec << counter << std::endl;
    }
    return 0;
  }
}