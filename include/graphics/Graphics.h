#pragma once

namespace ch {
	namespace Graphics {

		class Bitmap;

		class Graphics {
			
		public:
			Graphics(Bitmap& canvas);
			~Graphics();

			void Clear(unsigned char r, unsigned char g, unsigned char b);
			void DrawBitmap(const Bitmap& bitmap, float x, float y);

		private:
			static Graphics* _last_to_draw;
			Bitmap* _canvas;

			void _prepareCanvas();

		};

	}
}