#pragma once
#include <sstream>
#include <iomanip>
#include <libmul/Unit/AngleUnit.hpp>

namespace mul
{
	class Angle
	{
	public:
		double value;
		AngleUnit unit;

		Angle(double value_, AngleUnit unit_)
			: value(value_)
			, unit(unit_)
		{}

		static Angle convert(const Angle& src, AngleUnit targetUnit)
		{
			if (src.unit == targetUnit)
			{
				return src;
			}
			// Convert to base unit (RADIAN)
			auto rad = AngleUnitInfoMap[src.unit].toRadian(src.value);
			// Return immediately if targetUnit is base-unit.
			if (targetUnit == AngleUnit::RADIAN)
			{
				return Angle(rad, AngleUnit::RADIAN);
			}
			// Convert from base-unit to targetUnit.
			auto targetValue = AngleUnitInfoMap[targetUnit].fromRadian(rad);
			return Angle(targetValue, targetUnit);
		}

		static std::string format(const Angle& angle, int precision)
		{
			// Value with fixed precision.
			std::stringstream ss;
			ss << std::fixed << std::setprecision(precision) << angle.value;
			// Append abbrevation.
			std::string str = ss.str();
			str.append(AngleUnitInfoMap[angle.unit].abbrevation);
			return str;
		}
	};
}