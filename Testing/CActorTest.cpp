#include "stdafx.h"
#include "CppUnitTest.h"
#include "Actor.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Gdiplus;

namespace Testing
{
	TEST_CLASS(CActorTest)
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

		TEST_METHOD(TestCActorConstructor)
		{
			CActor actor(L"Harold");
			Assert::AreEqual(std::wstring(L"Harold"), actor.GetName());
		}

		TEST_METHOD(TestCActorEnabled)
		{
			CActor actor(L"Harold");

			Assert::IsTrue(actor.IsEnabled() == true);

			actor.SetEnabled(false);

			Assert::IsTrue(actor.IsEnabled()==false );
		}


		TEST_METHOD(TestCActorClickable)
		{
			CActor actor(L"Harold");

			Assert::IsTrue(actor.IsClickable() == true);

			actor.SetClickable(false);

			Assert::IsTrue(actor.IsClickable() == false);
		}


		TEST_METHOD(TestCActorPosition)
		{
			CActor actor(L"Harold");
			Assert::AreEqual(0, actor.GetPosition().X);
			Assert::AreEqual(0, actor.GetPosition().Y);

			Gdiplus::Point position = Gdiplus::Point(10, 10);
			actor.SetPosition(position);

			Assert::AreEqual(10, actor.GetPosition().X);
			Assert::AreEqual(10, actor.GetPosition().Y);
		}

	};
}