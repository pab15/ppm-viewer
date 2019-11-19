#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class BlurImageEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		vector<vector<Pixel>> copy{};
		copy.resize(doc.getHeight());
		for (int i = 0; i < doc.getWidth; i++)
		{
			copy[i].resize(doc.getWidth);
		}
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				copy[i][j] = doc[i][j];
			}
		}
	}
};