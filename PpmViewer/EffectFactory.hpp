#pragma once
#include "RemoveRedEffect.hpp"
#include "RemoveGreenEffect.hpp"
#include "RemoveBlueEffect.hpp"
#include "NegateRedEffect.hpp"
#include "NegateGreenEffect.hpp"
#include "NegateBlueEffect.hpp"
#include "GrayscaleEffect.hpp"
#include "RandomNoiseEffect.hpp"
#include "HighContrastEffect.hpp"
#include "HorizontalFlipEffect.hpp"
#include "PixelateImageEffect.hpp"
#include "VerticalFlipEffect.hpp"

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

		case ImageEffectType::RandomNoise:
			return new RandomNoiseEffect{};
			break;

		case ImageEffectType::HighContrast:
			return new HighContrastEffect{};
			break;

		case ImageEffectType::HorizontalFlip:
			return new HorizontalFlipEffect{};
			break;

		case ImageEffectType::PixelateImage:
			return new PixelateImageEffect{};
			break;

		case ImageEffectType::VerticalFlip:
			return new VerticalFlipEffect{};
			break;
		default: 
			break;
		}
	}
};