#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Source.cpp"
#include "../Project1/prim.h"
#include "../Project1/prim.cpp"
#include <cmath>

float prim(float x, float y);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MyTests
{
    TEST_CLASS(MathFunctionsTests)
    {
    public:

        TEST_METHOD(TestPrim_Basic)
        {
            float x = 1.0f, y = 1.0f;
            float result = prim(x, y);

            float r = sqrt(x * x + y * y) / exp(log(x));
            float s = pow(cos(3.14 / 4 * x), 2);
            float pr = std::max(r, s);

            Assert::AreEqual(pr, result, 0.001f);
        }//(1,1)

        TEST_METHOD(TestX_Zero)
        {
            float x = 0.0f, y = 1.0f;
            float result = prim(x, y);

            Assert::IsTrue(std::isinf(result));
        }//(0,1) = inf


        TEST_METHOD(Test_Negative)
        {
            float x = -1.0f, y = 2.0f;
            float result = prim(x, y);

            Assert::IsTrue(std::isnan(result));
        }//(-1,2) = nan

        TEST_METHOD(TestY_Zero)
        {
            float x = 2.0f, y = 0.0f;
            float result = prim(x, y);

            float r = sqrt(x * x + y * y) / exp(log(x));
            float s = pow(cos(3.14 / 4 * x), 2);
            float expected = std::max(r, s);

            Assert::AreEqual(expected, result, 0.001f);
        }//(2,0) = 1

        TEST_METHOD(TestP_Sqrt)
        {
            float x = 0.5f, y = 0.1f;
            float result = prim(x, y);

            float r = sqrt(x * x + y * y) / exp(log(x));
            float s = pow(cos(3.14 / 4 * x), 2);
            float expected = std::max(r, s);

            Assert::AreEqual(expected, result, 0.001f);
        }//(0.5,0.1)

        TEST_METHOD(Test_XSmall)
        {
            float result = prim(0.001f, 0.002f);
            Assert::AreEqual(2.236f, result, 0.001f);
        }//(0.001, 0.002) = 2.236

    };
}
