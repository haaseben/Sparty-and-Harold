#include "stdafx.h"
#include "CppUnitTest.h"
#include "Drawable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Gdiplus;

namespace Testing
{
	class CDrawableMock : public CDrawable
	{
	public:
		CDrawableMock(const std::wstring &name) : CDrawable(name) {}

		virtual void Draw(Gdiplus::Graphics *graphics) override {}
		virtual bool HitTest(Gdiplus::Point pos) override { return false; }
	};
	TEST_CLASS(CDrawableTest)
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

		TEST_METHOD(TestCDrawableConstructor)
		{
			CDrawableMock drawable(L"Harold");
			Assert::AreEqual(std::wstring(L"Harold"), drawable.GetName());
		}

		TEST_METHOD(TestCDrawablePosition)
		{
			CDrawableMock drawable(L"Harold");
			Assert::AreEqual(0, drawable.GetPosition().X);
			Assert::AreEqual(0, drawable.GetPosition().Y);

			Gdiplus::Point position = Gdiplus::Point(10, 10);
			drawable.SetPosition(position);

			Assert::AreEqual(10, drawable.GetPosition().X);
			Assert::AreEqual(10, drawable.GetPosition().Y);
		}

		TEST_METHOD(TestCDrawableRotation)
		{
			CDrawableMock drawable(L"Harold");

			Assert::AreEqual(0, drawable.GetRotation(), 0.00001);

			double a = 0.333;
			drawable.SetRotation(a);

			Assert::AreEqual(a, drawable.GetRotation(), 0.00001);
		}
	};
}