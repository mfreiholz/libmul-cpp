#pragma once
#include <sstream>
#include <iomanip>
#include <libmul/Unit/DistanceUnit.hpp>

namespace mul
{
	class Distance
	{
	public:
		double value = 0.0;
		DistanceUnit unit = DistanceUnit::METER;

		Distance(double value_, DistanceUnit unit_ = DistanceUnit::METER)
			: value(value_)
			, unit(unit_)
		{}

		static Distance convert(const Distance& src, DistanceUnit targetUnit)
		{
			// Do not convert same units.
			if (src.unit == targetUnit)
			{
				return src;
			}
			// Special case: Convert to base-unit (METER)
			if (targetUnit == DistanceUnit::METER)
			{
				auto& unitInfo = DistanceUnitInfoMap.at(src.unit);
				return Distance(unitInfo.scaleFactor * src.value, DistanceUnit::METER);
			}
			// Normal case: Convert "src" to base-unit before continue.
			Distance tmp = src;
			if (src.unit != DistanceUnit::METER)
			{
				tmp = Distance::convert(src, DistanceUnit::METER);
			}
			auto dstfac = DistanceUnitInfoMap[targetUnit].scaleFactor;
			return Distance(tmp.value / dstfac, targetUnit);
		}

		static std::string format(const Distance& distance, int precision)
		{
			// Value with fixed precision.
			std::stringstream ss;
			ss << std::fixed << std::setprecision(precision) << distance.value;
			// Append abbrevation.
			std::string str = ss.str();
			str.append(DistanceUnitInfoMap[distance.unit].abbrevation);
			return str;
		}
	};
}