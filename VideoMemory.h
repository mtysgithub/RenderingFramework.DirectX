#pragma once
#include <Windows.h>
#include "DirectDrawUtility.h"

namespace DirectDrawWrapper
{
	enum PixelSize { Real = 1, High = 2, True = 4 };
	class VideoMemory
	{
	public:
		VideoMemory( HWND );

		void CreateDevice();
		void ResetDevice();
		void Release();

		void SetBackgroundColor( unsigned int );
		void SetColorFormat( PixelSize );

		bool ReadyFrame( bool );
		void RenderFrame();

		void *VideoMemoryPtr;
		int Width, Height, Stride;

	protected:
		~VideoMemory();

	private:
		DirectDrawWrapper * pDDW;
	};
}