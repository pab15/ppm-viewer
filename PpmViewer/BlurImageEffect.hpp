#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class BlurImageEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				if (j == 0 && i == 0)
				{
					int average_red = (doc[i][j].red + doc[i][(j + 1)].red) / 2;
					int average_green = (doc[i][j].green + doc[i][(j + 1)].green) / 2;
					int average_blue = (doc[i][j].blue + doc[i][(j + 1)].blue) / 2;
					int new_avg_red = (average_red + doc[(i + 1)][j].red) / 2;
					int new_avg_green = (average_green + doc[(i + 1)][j].green) / 2;
					int new_avg_blue = (average_blue + doc[(i + 1)][j].blue) / 2;
					doc[i][j].red = new_avg_red;
					doc[i][j].green = new_avg_green;
					doc[i][j].blue = new_avg_blue;
				}
				else if (i == 0 && (j + 1) == doc[i].size())
				{
					int average_red = (doc[i][j].red + doc[i][(j - 1)].red) / 2;
					int average_green = (doc[i][j].green + doc[i][(j - 1)].green) / 2;
					int average_blue = (doc[i][j].blue + doc[i][(j - 1)].blue) / 2;
					int new_avg_red = (average_red + doc[(i + 1)][j].red) / 2;
					int new_avg_green = (average_green + doc[(i + 1)][j].green) / 2;
					int new_avg_blue = (average_blue + doc[(i + 1)][j].blue) / 2;
					doc[i][j].red = new_avg_red;
					doc[i][j].green = new_avg_green;
					doc[i][j].blue = new_avg_blue;
				}
				else if (i == 0)
				{
					int average_red = (doc[i][j].red + doc[i][(j + 1)].red) / 2;
					int average_green = (doc[i][j].green + doc[i][(j + 1)].green) / 2;
					int average_blue = (doc[i][j].blue + doc[i][(j + 1)].blue) / 2;
					int new_avg_red = (average_red + doc[(i + 1)][j].red) / 2;
					int new_avg_green = (average_green + doc[(i + 1)][j].green) / 2;
					int new_avg_blue = (average_blue + doc[(i + 1)][j].blue) / 2;
					doc[i][j].red = new_avg_red;
					doc[i][j].green = new_avg_green;
					doc[i][j].blue = new_avg_blue;
				}
				else if ((i + 1) == doc.getHeight() && j == 0)
				{
					int average_red = (doc[i][j].red + doc[i][(j + 1)].red) / 2;
					int average_green = (doc[i][j].green + doc[i][(j + 1)].green) / 2;
					int average_blue = (doc[i][j].blue + doc[i][(j + 1)].blue) / 2;
					int new_avg_red = (average_red + doc[(i - 1)][j].red) / 2;
					int new_avg_green = (average_green + doc[(i - 1)][j].green) / 2;
					int new_avg_blue = (average_blue + doc[(i - 1)][j].blue) / 2;
					doc[i][j].red = new_avg_red;
					doc[i][j].green = new_avg_green;
					doc[i][j].blue = new_avg_blue;

				}
				else if ((i + 1) == doc.getHeight() && (j + 1) == doc[i].size())
				{
					int average_red = (doc[i][j].red + doc[i][(j - 1)].red) / 2;
					int average_green = (doc[i][j].green + doc[i][(j - 1)].green) / 2;
					int average_blue = (doc[i][j].blue + doc[i][(j - 1)].blue) / 2;
					int new_avg_red = (average_red + doc[(i - 1)][j].red) / 2;
					int new_avg_green = (average_green + doc[(i - 1)][j].green) / 2;
					int new_avg_blue = (average_blue + doc[(i - 1)][j].blue) / 2;
					doc[i][j].red = new_avg_red;
					doc[i][j].green = new_avg_green;
					doc[i][j].blue = new_avg_blue;
				}
				else if ((i + 1) == doc.getHeight())
				{
					int average_red = (doc[i][j].red + doc[i][(j - 1)].red + doc[i][(j + 1)].red) / 3;
					int average_green = (doc[i][j].green + doc[i][(j - 1)].green + doc[i][(j + 1)].green) / 3;
					int average_blue = (doc[i][j].blue + doc[i][(j - 1)].blue + doc[i][(j + 1)].blue) / 3;
					int new_avg_red = (average_red + doc[(i - 1)][j].red) / 2;
					int new_avg_green = (average_green + doc[(i - 1)][j].green) / 2;
					int new_avg_blue = (average_blue + doc[(i - 1)][j].blue) / 2;
					doc[i][j].red = new_avg_red;
					doc[i][j].green = new_avg_green;
					doc[i][j].blue = new_avg_blue;
				}
				else if (j == 0)
				{
					int average_red = (doc[i][j].red + doc[i][(j + 1)].red) / 2;
					int average_green = (doc[i][j].green + doc[i][(j + 1)].green) / 2;
					int average_blue = (doc[i][j].blue + doc[i][(j + 1)].blue) / 2;
					int new_avg_red = (average_red + doc[(i - 1)][j].red + doc[(i + 1)][j].red) / 3;
					int new_avg_green = (average_green + doc[(i - 1)][j].green + doc[(i + 1)][j].green) / 3;
					int new_avg_blue = (average_blue + doc[(i - 1)][j].blue + doc[(i + 1)][j].blue) / 3;
					doc[i][j].red = new_avg_red;
					doc[i][j].green = new_avg_green;
					doc[i][j].blue = new_avg_blue;
				}
				else if ((j + 1) == doc.getWidth())
				{
					int average_red = (doc[i][j].red + doc[i][(j - 1)].red) / 2;
					int average_green = (doc[i][j].green + doc[i][(j - 1)].green) / 2;
					int average_blue = (doc[i][j].blue + doc[i][(j - 1)].blue) / 2;
					int new_avg_red = (average_red + doc[(i - 1)][j].red + doc[(i + 1)][j].red) / 3;
					int new_avg_green = (average_green + doc[(i - 1)][j].green + doc[(i + 1)][j].green) / 3;
					int new_avg_blue = (average_blue + doc[(i - 1)][j].blue + doc[(i + 1)][j].blue) / 3;
					doc[i][j].red = new_avg_red;
					doc[i][j].green = new_avg_green;
					doc[i][j].blue = new_avg_blue;
				}
				else
				{
					int average_red = (doc[i][j].red + doc[i][(j - 1)].red + doc[i][(j + 1)].red) / 3;
					int average_green = (doc[i][j].green + doc[i][(j - 1)].green + doc[i][(j + 1)].green) / 3;
					int average_blue = (doc[i][j].blue + doc[i][(j - 1)].blue + doc[i][(j + 1)].blue) / 3;
					int new_avg_red = (average_red + doc[(i - 1)][j].red + doc[(i + 1)][j].red) / 3;
					int new_avg_green = (average_green + doc[(i - 1)][j].green + doc[(i + 1)][j].green) / 3;
					int new_avg_blue = (average_blue + doc[(i - 1)][j].blue + doc[(i + 1)][j].blue) / 3;
					doc[i][j].red = new_avg_red;
					doc[i][j].green = new_avg_green;
					doc[i][j].blue = new_avg_blue;
				}
			}
		}
	}
};