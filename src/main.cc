#include <allegro5/allegro.h>

int main(int argc, char* argv[]) {

	al_init();

	ALLEGRO_DISPLAY* display = al_create_display(640, 480);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();

	bool do_loop = true;

	while (do_loop) {

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		switch (ev.type) {

		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			do_loop = false;
			break;

		}

	}

	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	al_uninstall_system();

	return 0;

}