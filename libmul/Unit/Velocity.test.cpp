#include <iostream>
#include <libmul/Unit/Velocity.hpp>

int main(int argc, char** argv)
{
	using namespace mul;

	// common
	Velocity v1(243.5, VelocityUnit::METER_PER_SECOND);
	Velocity v2(v1);
	Velocity v3 = v2;

	// compare
	// ...

	// convert
	Velocity vMps(83.4, VelocityUnit::METER_PER_SECOND);
	auto vKmh = Velocity::convert(vMps, VelocityUnit::KILOMETER_PER_HOUR);
	auto vMph = Velocity::convert(vMps, VelocityUnit::MILES_PER_HOUR);
	auto vKts = Velocity::convert(vMps, VelocityUnit::KNOTS);

	std::cout << "vMps: " << Velocity::format(vMps) << " - " << Velocity::convert(vMps, Velocity::baseUnit()).value << std::endl;
	std::cout << "vKmh: " << Velocity::format(vKmh) << " - " << Velocity::convert(vKmh, Velocity::baseUnit()).value << std::endl;
	std::cout << "vMph: " << Velocity::format(vMph) << " - " << Velocity::convert(vMph, Velocity::baseUnit()).value << std::endl;
	std::cout << "vKts: " << Velocity::format(vKts) << " - " << Velocity::convert(vKts, Velocity::baseUnit()).value << std::endl;

	return 0;
}