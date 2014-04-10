#include "VideoMemory.h"

namespace DirectDrawWrapper
{
	VideoMemory::VideoMemory( HWND hWnd )
	{
		pDDW = new DirectDrawWrapper();

		pDDW->Initialize
		(
			hWnd
		);
	}

	void VideoMemory::CreateDevice()
	{
		pDDW->CreateDevice();

		Width = pDDW->Width; Height = pDDW->Height;
	}

	void VideoMemory::ResetDevice()
	{
		pDDW->ResetDevice();

		Width = pDDW->Width; Height = pDDW->Height;
	}

	void VideoMemory::SetColorFormat( PixelSize pixelSize )
	{
		pDDW->PixelSize = ( int )pixelSize;
	}

	void VideoMemory::SetBackgroundColor( unsigned int color )
	{
		pDDW->BackgroundColor = color;
	}

	bool VideoMemory::ReadyFrame( bool clearFrame )
	{
		if( pDDW->Lock( clearFrame ) )
		{
			VideoMemoryPtr = pDDW->VideoMemory;
			Stride = pDDW->Stride;

			return true;
		}
		return false;
	}

	void VideoMemory::RenderFrame()
	{
		pDDW->Render();
	}

	void VideoMemory::Release()
	{
		pDDW->Release();
	}

	VideoMemory::~VideoMemory()
	{
		delete pDDW;
		pDDW = 0;
	}
}