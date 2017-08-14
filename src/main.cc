#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "graphics/Graphics.h"
#include "graphics/Bitmap.h"
#include <iostream>
using namespace ch::Graphics;

int main(int argc, char* argv[]) {

	al_init();
	al_init_image_addon();

	ALLEGRO_DISPLAY* display = al_create_display(640, 480);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);

	Bitmap backbuffer(al_get_backbuffer(display));
	Graphics graphics(backbuffer);

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	Bitmap box(32, 32);
	Graphics box_drawer(box);
	box_drawer.Clear(255, 0, 0);

	graphics.Clear(0, 0, 0);
	al_flip_display();
	al_start_timer(timer);

	bool do_loop = true;
	bool do_redraw = true;
	
	while (do_loop) {

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		switch (ev.type) {

		case ALLEGRO_EVENT_TIMER:
			do_redraw = true;
			break;

		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			do_loop = false;
			break;

		}

		if (do_redraw && al_is_event_queue_empty(event_queue)) {
			graphics.Clear(0, 0, 0);
			graphics.DrawBitmap(box, 320 - box.Width() / 2, 240 - box.Height() / 2);
			al_flip_display();
			do_redraw = false;
		}
	}

	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);

	// Note: Don't deinitialize Allegro while resources are still alive (e.g., Bitmaps).
	//al_shutdown_image_addon();
	//al_uninstall_system();

	return 0;

}