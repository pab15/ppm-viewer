#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class PixelateImageEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i += 3)
		{
			for (int j = 0; j < doc.getWidth(); j += 3)
			{
				Pixel& p = doc[i][j];
				if (i + 1 == doc.getHeight() && j + 1 == doc.getWidth())
				{
					doc[i][j] = p;
				}
				else if (i + 2 == doc.getHeight() && j + 2 == doc.getWidth())
				{
					doc[i][j] = p;
					doc[i][j + 1] = p;
					doc[i + 1][j] = p;
					doc[i + 1][j + 1] = p;
				}
				else if (i + 2 == doc.getHeight() && j + 1 == doc.getWidth())
				{
					doc[i][j] = p;
					doc[i + 1][j] = p;
				}
				else if (i + 1 == doc.getHeight() && j + 2 == doc.getWidth())
				{
					doc[i][j] = p;
					doc[i][j + 1] = p;
				}
				else if (i + 1 == doc.getHeight())
				{
					doc[i][j] = p;
					doc[i][j + 1] = p;
					doc[i][j + 2] = p;
				}
				else if (i + 2 == doc.getHeight())
				{
					doc[i][j] = p;
					doc[i][j + 1] = p;
					doc[i][j + 2] = p;
					doc[i + 1][j] = p;
					doc[i + 1][j + 1] = p;
					doc[i + 1][j + 2] = p;
				}
				else if (j + 1 == doc.getWidth())
				{
					doc[i][j] = p;
					doc[i + 1][j] = p;
					doc[i + 2][j] = p;
				}
				else if (j + 2 == doc.getWidth())
				{
					doc[i][j] = p;
					doc[i][j + 1] = p;
					doc[i + 1][j] = p;
					doc[i + 1][j + 1] = p;
					doc[i + 2][j] = p;
					doc[i + 2][j + 1] = p;
				}
				else
				{
					doc[i][j] = p;
					doc[i][j + 1] = p;
					doc[i][j + 2] = p;
					doc[i + 1][j] = p;
					doc[i + 1][j + 1] = p;
					doc[i + 1][j + 2] = p;
					doc[i + 2][j] = p;
					doc[i][j + 2] = p;
 					doc[i + 2][j + 2] = p;
				}
			}
		}
	}
};