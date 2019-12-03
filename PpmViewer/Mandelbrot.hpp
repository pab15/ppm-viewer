#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class MandelbrotGenerator : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{	
		srand(time(NULL));
		int dimensions = 512;
		vector<vector<Pixel>> temp{};
		temp.resize(dimensions);
		for (int i = 0; i < dimensions; i++)
		{
			temp[i].resize(dimensions);
		}

		int maxN = (rand() % 255);
		double minR = (-1 * (rand() % 3)), maxR = (rand() % 3), minI = (-1 * (rand() % 3)), maxI = (rand() % 2);
		
		for (int i = 0; i < dimensions; i++)
		{
			for (int j = 0; j < dimensions; j++)
			{
				double cr = doc.realMandelbrot(j, dimensions, minR, maxR);
				double ci = doc.imaginaryMandelbrot(i, dimensions, minI, maxI);
				int n = doc.findN(cr, ci, maxN);

				temp[i][j].red = (n * (rand() % n) % 255);
				temp[i][j].green = (n * (rand() % n) % 255);
				temp[i][j].blue = (n * (rand() % n) % 255);
			}
		}

		doc.setHeight(dimensions);
		doc.setWidth(dimensions);
		doc.setColorDepth(256);
		doc.resizeRGBY(dimensions);
		doc.resizeRGBX(dimensions);

		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				doc[i][j] = temp[i][j];
			}
		}
	}
};