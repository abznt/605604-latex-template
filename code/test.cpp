#include "pch.h"
#include "../ShapeLib/Triangle.h"


namespace shape {
	TEST(TriangleTests, TestEquilateralType) {
		Triangle t0{ 3, 3, 3 };        // test integer input
		Triangle t1{ 5, 5, 5 };  // test integer input
		EXPECT_EQ(t0.getType(), Triangle::Type::equilateral);
		EXPECT_EQ(t1.getType(), Triangle::Type::equilateral);
	}

	TEST(TriangleTests, TestIsocelesType) {
		Triangle t0{ 3, 3, 4 };   // test a == b
		Triangle t1{ 7, 10, 7 };  // test a == c
		Triangle t2{ 2, 3, 3 };   // test b == c
		EXPECT_EQ(t0.getType(), Triangle::Type::isosceles);
		EXPECT_EQ(t1.getType(), Triangle::Type::isosceles);
		EXPECT_EQ(t2.getType(), Triangle::Type::isosceles);
	}

	TEST(TriangleTests, TestScaleneType) {
		Triangle t0{ 3, 4, 5 };  // test permutation a < b < c
		Triangle t1{ 4, 3, 5 };  // test permutation b < a < c
		Triangle t2{ 5, 4, 3 };  // test permutation c < b < a
		EXPECT_EQ(t0.getType(), Triangle::Type::scalene);
		EXPECT_EQ(t1.getType(), Triangle::Type::scalene);
		EXPECT_EQ(t2.getType(), Triangle::Type::scalene);
	}

	TEST(TriangleTests, TestInvalidTriangle) {
		// Negative side lengths should cause an InvalidTriangleException
		EXPECT_THROW(Triangle(-1, -1, -1), Triangle::InvalidTriangleException);
		// a + b <= c should cause an InvalidTriangleException
		EXPECT_THROW(Triangle(1, 2, 3), Triangle::InvalidTriangleException);
	}
}