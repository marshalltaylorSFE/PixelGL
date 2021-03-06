#ifndef LOOPERPANEL_H_INCLUDED
#define LOOPERPANEL_H_INCLUDED

#include <OctoWS2811.h>

class RGBA8
{
public:
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  uint8_t alpha;

};

#define PIXELMEMSIZE sizeof(RGBA8)


class viewport : public OctoWS2811
{
public:
	viewport(uint32_t hwL_numPerStrip, void *hwL_frameBuf, void *hwL_drawBuf, uint8_t hwL_config = WS2811_GRB, uint32_t hwL_width = 16, uint32_t hwL_height = 10) : OctoWS2811(hwL_numPerStrip, hwL_frameBuf, hwL_drawBuf, hwL_config), width(hwL_width), height(hwL_height) {};
	void setPixelXY(uint32_t x, uint32_t y, int color);
//private:
	uint32_t width;
	uint32_t height;
};

//class pGLObject
//{
//public:
//	pGLObject( void );
//	void setPoints( int32_t, int32_t, int32_t, int32_t );
//	int32_t x1;
//	int32_t x2;
//	int32_t y1;
//	int32_t y2;
//};

class Layer
{
public:
	Layer( int32_t, int32_t, int32_t, int32_t );
	void clear( void );
	void debugClear( void );
	void setPixelXY( int32_t x, int32_t y, RGBA8* color );
	void getPixelXY( int32_t x, int32_t y, RGBA8*);
	void process( void );
//private
	int32_t xLowerLimit;
	int32_t xUpperLimit;
	int32_t yLowerLimit;
	int32_t yUpperLimit;
	int32_t width;
	int32_t height;
	
	RGBA8* layerMemory;
	int32_t xOffset;
	int32_t yOffset;
	
};

class viewpage
{
public:
	viewpage( viewport* );
	void clear( void );
	void setPixelXY( int32_t x, int32_t y, RGBA8* color );
	void getPixelXY( int32_t x, int32_t y, RGBA8* );
	void show( void );
	void setLayer( Layer*, uint8_t );
	void setLayerOffset( uint8_t, int32_t, int32_t );
	
//private
	int32_t xLowerLimit;
	int32_t xUpperLimit;
	int32_t yLowerLimit;
	int32_t yUpperLimit;
	int32_t width;
	int32_t height;
	RGBA8* viewpageMemory;
	viewport* linkedViewport;
	//pGLObject* linkedObjectHead;
	
	Layer* layers[10];
	
};

class PaintTools
{
public:
	PaintTools( void );
	void dot( Layer*, float, float, RGBA8* );
	void line( Layer*, float, float, float, float, RGBA8* );	
	
	
};

#endif