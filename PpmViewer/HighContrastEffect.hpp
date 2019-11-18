#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class HighContrastEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc[i][j];
				if (p.red >= 128)
				{
					p.red = 255;
				}
				else
				{
					p.red = 0;
				}
				if (p.green >= 128)
				{
					p.green = 255;
				}
				else
				{
					p.green = 0;
				}
				if (p.blue >= 128)
				{
					p.blue = 255;
				}
				else
				{
					p.blue = 0;
				}
				//not necessary as we're using references but it makes our intent more clear
				doc[i][j] = p;
			}
		}
	}
};