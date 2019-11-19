#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class HorizontalFlipEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			reverse(doc[i].begin(), doc[i].end());
		}
	}
};