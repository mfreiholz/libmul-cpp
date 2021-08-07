#pragma once
#include <cinttypes>
#include <cstring>
#include <functional>
#include <map>
#include <libmul/Defines.hpp>

namespace mul
{
	enum class AngleUnit : uint8_t
	{
		RADIAN,
		DEGREE
	};

	typedef struct AngleUnitInfo
	{
		std::string abbrevation;
		std::function<double(double)> toRadian;
		std::function<double(double)> fromRadian;
	} AngleUnitInfo;

	static inline std::map<AngleUnit, const AngleUnitInfo> AngleUnitInfoMap =
	{
		{
			AngleUnit::RADIAN,
			{
				"rad",
				[](double v) { return v; },
				[](double v) { return v; }
			}
		},
		{
			AngleUnit::DEGREE,
			{
				"°",
				[](double v) { return v * LIBMUL_MATH_PI / 180.0; },
				[](double v) { return v * 180.0 / LIBMUL_MATH_PI; }
			}
		},
	};
}