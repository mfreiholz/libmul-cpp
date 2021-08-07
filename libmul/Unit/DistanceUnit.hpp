#pragma once
#include <cinttypes>
#include <map>
#include <cstring>

namespace mul
{
	enum class DistanceUnit : uint8_t
	{
		ANGSTROM,
		FATHOM,
		FURLONG,
		LEAGUE_LAND,
		LEAGUE_NAUTICAL,
		MICRON,
		PICOMETER,
		NANOMETER,
		CENTIMETER,
		METER,
		FEET,
		INCH,
		KILOMETER,
		MILE,
		NAUTICAL_MILE,
		YARD
	};

	typedef struct DistanceUnitInfo
	{
		double scaleFactor; ///< Maps DistanceUnit's to it's value in 1-meter.
		std::string abbrevation; ///< ...
	} DistanceUnitInfo;

	static inline std::map<DistanceUnit, const DistanceUnitInfo> DistanceUnitInfoMap =
	{
		{ DistanceUnit::ANGSTROM, { 0.0000000001, "Å" } },
		{ DistanceUnit::FATHOM, { 1.8288, "ftm" } },
		{ DistanceUnit::FURLONG, { 201.168, "fu" } },
		{ DistanceUnit::LEAGUE_LAND, { 4828.032, "lea" } },
		{ DistanceUnit::LEAGUE_NAUTICAL, { 5556.0, "nl" } },
		{ DistanceUnit::MICRON, { 0.000001, "μm" } },
		{ DistanceUnit::PICOMETER, { 0.000000000001, "pm" } },
		{ DistanceUnit::NANOMETER, { 0.000000001, "nm" } },
		{ DistanceUnit::CENTIMETER, { 0.01, "cm" } },
		{ DistanceUnit::METER, { 1, "m" } },
		{ DistanceUnit::KILOMETER, { 1000, "km" } },
		{ DistanceUnit::FEET, { 0.3048, "ft" } },
		{ DistanceUnit::INCH, { 0.0254, "in" } },
		{ DistanceUnit::MILE, { 1609.344, "mi" } },
		{ DistanceUnit::NAUTICAL_MILE, { 1852, "nmi" } },
		{ DistanceUnit::YARD, { 0.9144, "yd" } },
	};
}