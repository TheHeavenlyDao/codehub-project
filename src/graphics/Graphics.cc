#include "graphics/Graphics.h"
#include "graphics/Bitmap.h"
#include <allegro5/allegro.h>

namespace ch {
	namespace Graphics {

		Graphics* Graphics::_last_to_draw = nullptr;

		Graphics::Graphics(Bitmap& canvas) :
			_canvas(&canvas) {}
		Graphics::~Graphics() {

			if (_last_to_draw == this)
				_last_to_draw = nullptr;

		}

		void Graphics::Clear(unsigned char r, unsigned char g, unsigned char b) {

			_prepareCanvas();

			al_clear_to_color(al_map_rgb(r, g, b));

		}
		void Graphics::DrawBitmap(const Bitmap& bitmap, float x, float y) {

			_prepareCanvas();

			al_draw_bitmap(bitmap._bitmap, x, y, 0);

		}


		void Graphics::_prepareCanvas() {

			if (_last_to_draw != this) {
				al_set_target_bitmap(_canvas->_bitmap);
				_last_to_draw = this;
			}

		}

	}
}