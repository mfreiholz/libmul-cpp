#pragma once
#include <cinttypes>
#include <map>
#include <cstring>
#include <functional>
#include <libmul/Unit/Unit.hpp>

namespace mul
{
	enum class VelocityUnit : uint8_t
	{
		METER_PER_SECOND,
		KILOMETER_PER_HOUR,
		MILES_PER_HOUR,
		KNOTS
	};

	class Velocity : public Unit<Velocity, double, VelocityUnit>
	{
	public:
		Velocity(double value_, VelocityUnit unit_)
			: Unit(value_, unit_)
		{}

		static VelocityUnit baseUnit()
		{
			return VelocityUnit::METER_PER_SECOND;
		}

		static std::map<VelocityUnit, UnitInfo> unitInfos()
		{
			static std::map<VelocityUnit, UnitInfo> m =
			{
				{
					VelocityUnit::METER_PER_SECOND,
					{
						"m/s",
						[](double v) { return v; },
						[](double v) { return v; }
					}
				},
				{
					VelocityUnit::KILOMETER_PER_HOUR,
					{
						"km/h",
						[](double v) { return v / 3.6; },
						[](double v) { return v * 3.6; }
					}
				},
				{
					VelocityUnit::MILES_PER_HOUR,
					{
						"mph",
						[](double v) { return v / 2.23693629; },
						[](double v) { return v * 2.23693629; }
					}
				},
				{
					VelocityUnit::KNOTS,
					{
						"kts",
						[](double v) { return v / 1.9438444924423; },
						[](double v) { return v * 1.9438444924423; }
					}
				}
			};
			return m;
		}
	};
}