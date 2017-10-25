#include "stdafx.h"
#include "CppUnitTest.h"
#include "PolyDrawable.h"
#include "Drawable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CPolyDrawableTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestNothing)
		{
			// This is an empty test just to ensure the system is working
		}

		TEST_METHOD(TestCPolyDrawableConstructor)
		{
			CPolyDrawable drawable(L"Harold");
			Assert::AreEqual(std::wstring(L"Harold"), drawable.GetName());
		}


		TEST_METHOD(TestCPolyDrawableColor)
		{
			CPolyDrawable drawable(L"Harold");
			Gdiplus::Color color = Gdiplus::Color::Black;

			Assert::IsTrue(GetColorValue(drawable.GetColor(),color)==true);

			Gdiplus::Color redColor = Gdiplus::Color::Red;
			drawable.SetColor(redColor);

			Assert::IsTrue(GetColorValue(drawable.GetColor(), redColor) == true);
		}

		bool GetColorValue(Gdiplus::Color color,Gdiplus::Color color2)
		{
			Gdiplus::ARGB value1 = color.GetValue();
			Gdiplus::ARGB value2 = color2.GetValue();

			if (value1 == value2)
			{
				return true;
			}

			return false;
		}
	};
}