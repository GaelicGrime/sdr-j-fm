#
/*
 *    Copyright (C) 2010, 2011, 2012
 *    Jan van Katwijk (J.vanKatwijk@gmail.com)
 *    Lazy Chair Computing
 *
 *    This file is part of the SDR-J.
 *    Many of the ideas as implemented in SDR-J are derived from
 *    other work, made available through the GNU general Public License. 
 *    All copyrights of the original authors are recognized.
 *
 *    SDR-J is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 2 of the License, or
 *    (at your option) any later version.
 *
 *    SDR-J is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with SDR-J; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
#ifndef	SPECTROGRAM_QWT5
#define	SPECTROGRAM_QWT5

#include	<stdio.h>
#include	<stdlib.h>

class	SpectrogramData: public QwtRasterData {
public:
	double	*data;		// pointer to actual data
	int	left;		// index of left most element in raster
	int	width;		// raster width
	int	height;		// rasterheigth
	int	datawidth;	// width of matrix
	int	dataheight;	// for now == rasterheigth
	double	max;

	SpectrogramData (double *data, int left, int width, int height,
	                 int datawidth, double max):
        QwtRasterData (QwtDoubleRect((double)left, 0.0,
	                                     (double)width - 1, height - 1)) {
	this	-> left		= left;
	this	-> width	= width;
	this	-> data		= data;
	this	-> max		= max;
	this	-> height	= height;
	this	-> datawidth	= datawidth;
	this	-> dataheight	= height;
}

	~SpectrogramData () {
}

double value (double x, double y) const {
	   x = x - left;
	   x = x / width * datawidth;
	   return data [(int)y * datawidth + (int)x];
}

virtual QwtRasterData *copy() const {
        return new SpectrogramData (data, left, width, height, datawidth, max);
}

virtual QwtDoubleInterval range() const {
        return QwtDoubleInterval (0.0, max);
}

};

#endif

