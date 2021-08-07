#include <iostream>
#include <libmul/Unit/Angle.hpp>

int main(int argc, char** argv)
{
	using namespace mul;

	// common
	Angle angle(180.0, AngleUnit::DEGREE);
	Angle angle2(angle);
	Angle angle3 = angle2;

	// compare
	// ... todo ...

	// convert
	Angle aRad(2.0, AngleUnit::RADIAN);

	Angle aDegree = Angle::convert(aRad, AngleUnit::DEGREE);
	std::cout << "aDegree=" << aDegree.value << "; rad=" << Angle::convert(aDegree, AngleUnit::RADIAN).value << std::endl;
}