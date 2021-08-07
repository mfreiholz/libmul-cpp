#include <iostream>
#include <libmul/Unit/Distance.hpp>

inline bool logically_equal(double a, double b, double error_factor = 1.0)
{
	return a == b ||
		std::abs(a - b) < std::abs(std::min(a, b)) * std::numeric_limits<double>::epsilon() *
		error_factor;
}

int main(int argc, char** argv)
{
	using namespace mul;

	// common
	Distance d(1234.5, DistanceUnit::METER);
	Distance d2(d);
	Distance d3 = d2;

	// compare
	// ... TODO ...

	// convert
	Distance dMeter(2950.0, DistanceUnit::METER);

	Distance dAngstrom = Distance::convert(dMeter, DistanceUnit::ANGSTROM);
	Distance dFurlong = Distance::convert(dMeter, DistanceUnit::FURLONG);
	Distance dCentimeter = Distance::convert(dMeter, DistanceUnit::CENTIMETER);
	Distance dKilometer = Distance::convert(dMeter, DistanceUnit::KILOMETER);
	Distance dFeet = Distance::convert(dMeter, DistanceUnit::FEET);
	
	// debug output
	std::cout << "dMeter: " << dMeter.value << std::endl;
	std::cout << "dAngstrom: " << dAngstrom.value << " - " << Distance::format(dAngstrom, 5) << std::endl;
	std::cout << "dFurlong: " << dFurlong.value << " - " << Distance::format(dFurlong, 5) << std::endl;
	std::cout << "dCentimeter: " << dCentimeter.value << std::endl;
	std::cout << "dKilometer: " << dKilometer.value << std::endl;
	std::cout << "dFeet: " << dFeet.value << std::endl;
	std::cout << "meter (converted): " << Distance::convert(dFurlong, DistanceUnit::METER).value << std::endl;
	return 0;
}