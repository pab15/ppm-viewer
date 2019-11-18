#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class RandomNoiseEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		srand(time(NULL));
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc[i][j];
				int random = (rand() % 20);
				int random_number = random - 10;
				if ((p.red + random_number) >= 255)
				{
					p.red = 255;
				}
				else if ((p.red - random_number) <= 0)
				{
					p.red = 0;
				}
				else
				{
					p.red = p.red + random_number;
				}
				random = (rand() % 20);
				random_number = random - 10;
				if ((p.green + random_number) >= 255)
				{
					p.green = 255;
				}
				else if ((p.green - random_number) <= 0)
				{
					p.green = 0;
				}
				else
				{
					p.green = p.green + random_number;
				}
				random = (rand() % 20);
				random_number = random - 10;
				if ((p.blue + random_number) >= 255)
				{
					p.blue = 255;
				}
				else if ((p.blue - random_number) <= 0)
				{
					p.blue = 0;
				}
				else
				{
					p.blue = p.blue + random_number;
				}
				//not necessary as we're using references but it makes our intent more clear
				doc[i][j] = p;
			}
		}
	}
};