#pragma once
#include <cstring>
#include <functional>
#include <iomanip>
#include <sstream>

namespace mul
{
	typedef struct UnitInfo
	{
		std::string abbrevation;
		std::function<double(double)> toBase;
		std::function<double(double)> fromBase;
	} UnitInfo;

	template<class T, typename ValueT, typename UnitTypeT>
	class Unit
	{
	public:
		ValueT value;
		UnitTypeT unit;

		Unit(ValueT value_, UnitTypeT unit_)
			: value(value_)
			, unit(unit_)
		{}

		static T convert(const T& src, UnitTypeT targetUnit)
		{
			if (src.unit == targetUnit)
			{
				return src;
			}

			// Convert to base unit (RADIAN)
			auto rad = T::unitInfos().at(src.unit).toBase(src.value);

			// Return immediately if targetUnit is base-unit.
			if (targetUnit == T::baseUnit())
			{
				return T(rad, T::baseUnit());
			}

			// Convert from base-unit to targetUnit.
			auto targetValue = T::unitInfos().at(targetUnit).fromBase(rad);
			return T(targetValue, targetUnit);
		}

		static std::string format(const T& u, int precision = 3)
		{
			// Value with fixed precision.
			std::stringstream ss;
			ss << std::fixed << std::setprecision(precision) << u.value;
			// Append abbrevation.
			std::string str = ss.str();
			str.append(T::unitInfos().at(u.unit).abbrevation);
			return str;
		}
	};
}