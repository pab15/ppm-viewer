#pragma once
#include "RemoveRedEffect.hpp"
#include "RemoveGreenEffect.hpp"
#include "RemoveBlueEffect.hpp"
#include "NegateRedEffect.hpp"
#include "NegateGreenEffect.hpp"
#include "NegateBlueEffect.hpp"
#include "GrayscaleEffect.hpp"

enum class ImageEffectType
{
	RemoveRed = 1,
	RemoveGreen = 2,
	RemoveBlue = 3,
	NegateRed = 4,
	NegateGreen = 5,
	NegateBlue = 6,
	Greyscale = 7,
	RandomNoise = 8,
	HighContrast = 9,
	HorizontalFlip = 10,
	VerticalFlip = 11,
	PixelateImage = 12,
	BlurImage = 13,
	Rotate90 = 14
};

class EffectFactory
{
public:
	static ImageEffect* createEffect(ImageEffectType effect_type)
	{
		switch (effect_type)
		{
		case ImageEffectType::RemoveRed:
			return new RemoveRedEffect{};
			break;

		case ImageEffectType::RemoveGreen:
			return new RemoveGreenEffect{};
			break;

		case ImageEffectType::RemoveBlue:
			return new RemoveBlueEffect{};
			break;

		case ImageEffectType::NegateRed:
			return new NegateRedEffect{};
			break;

		case ImageEffectType::NegateGreen:
			return new NegateGreenEffect{};
			break;

		case ImageEffectType::NegateBlue:
			return new NegateBlueEffect{};
			break;

		case ImageEffectType::Greyscale:
			return new GreyscaleEffect{};
			break;

		default: 
			break;
		}
	}
};