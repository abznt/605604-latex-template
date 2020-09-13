#pragma once
#include <string>
#include <exception>

/// <summary>
/// This class encapsulate a triangle
/// </summary>
namespace shape {
	class Triangle
	{
	private:
		int m_a, m_b, m_c;

	public:
		/// <summary>
		/// Enum class describing a type of triangle (equilateral, isosceles, or scalene)
		/// </summary>
		enum class Type
		{
			equilateral,
			isosceles,
			scalene
		};

		/// <summary>
		/// Constructs a Triangle object given the length of its 3 sides
		/// </summary>
		/// <exception cref="Triangle::InvalidTriangleException">Thrown when the side lengths a, b, and c would create an invalid triangle</exception>
		/// <param name="a">The length of side a</param>
		/// <param name="b">The length of side b</param>
		/// <param name="c">The length of side c</param>
		Triangle(int a, int b, int c);

		/// <summary>
		/// Computes the triangle type based on the length of its sides
		/// </summary>
		/// <returns>A string representing the triangle type (equilateral, isosceles, or scalene)</returns>
		Triangle::Type getType() const;

		class InvalidTriangleException : public std::exception 
		{
		private:
			const int m_a, m_b, m_c;

		public:
			InvalidTriangleException(int a, int b, int c);
			const std::string msg() const throw ();
		};
	};
}

