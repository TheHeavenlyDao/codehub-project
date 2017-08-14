#pragma once

struct ALLEGRO_BITMAP;

namespace ch {
	namespace Graphics {

		class Graphics;

		class Bitmap {
			friend class Graphics;

		public:
			Bitmap(int width, int height);
			Bitmap(ALLEGRO_BITMAP* allegro_bitmap);
			~Bitmap();

			int Width() const;
			int Height() const;

		private:
			ALLEGRO_BITMAP* _bitmap;
			bool _owns_bitmap;

		};

	}
}