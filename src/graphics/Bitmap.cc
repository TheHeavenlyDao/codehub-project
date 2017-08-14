#include "graphics/Bitmap.h"
#include <allegro5/allegro.h>
#include <cassert>

namespace ch {
	namespace Graphics {

		Bitmap::Bitmap(int width, int height) {

			_bitmap = al_create_bitmap(width, height);
			_owns_bitmap = true;

			assert(_bitmap != nullptr);

		}
		Bitmap::Bitmap(ALLEGRO_BITMAP* allegro_bitmap) {

			_bitmap = allegro_bitmap;
			_owns_bitmap = false;

		}
		Bitmap::~Bitmap() {

			if (_owns_bitmap && _bitmap != nullptr)
				al_destroy_bitmap(_bitmap);
			_bitmap = nullptr;

		}

		int Bitmap::Width() const {

			if (_bitmap == nullptr)
				return 0;

			return al_get_bitmap_width(_bitmap);

		}
		int Bitmap::Height() const {

			if (_bitmap == nullptr)
				return 0;

			return al_get_bitmap_height(_bitmap);

		}

	}
}