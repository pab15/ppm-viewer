#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class PixelateImageEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i += 2)
		{
			for (int j = 0; j < doc.getWidth(); j += 2)
			{
				Pixel& p = doc[i][j];
				if (i + 1 == doc.getHeight() && j + 1 == doc.getWidth())
				{
					doc[i][j] = p;
				}
				else if (i + 1 == doc.getHeight())
				{
					doc[i][j] = p;
					doc[i][j + 1] = p;
				}
				else if (j + 1 == doc.getWidth())
				{
					doc[i][j] = p;
					doc[i + 1][j] = p;
				}
				else
				{
					doc[i][j] = p;
					doc[i][j + 1] = p;
					doc[i + 1][j] = p;
					doc[i + 1][j + 1] = p;
				}
			}
		}
	}
};