#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define XRAND rand()%801
#define YRAND rand()%601
#define CRAND al_map_rgb(rand()%256,rand()%256,rand()%256)

int main(){
    // Declarations
    ALLEGRO_DISPLAY * game_display = NULL;
    ALLEGRO_COLOR  aleatoire = {0};
    ALLEGRO_EVENT_QUEUE * fifo =NULL;
    ALLEGRO_TIMER * game_timer = NULL;

    // initialisation
    assert(al_init());
    assert(al_init_primitives_addon());
    assert(al_install_keyboard());

    // creation
    game_display = al_create_display(800, 600);

    fifo = al_create_event_queue();
    game_timer = al_create_timer(1.0/5.0);

    // Sources
    al_register_event_source(fifo, al_get_display_event_source(game_display));
    al_register_event_source(fifo, al_get_timer_event_source(game_timer));
    al_register_event_source(fifo, al_get_keyboard_event_source());

    // Boucle d'événements
    bool fini = false;
    ALLEGRO_EVENT event;
    al_start_timer(game_timer);
    while (!fini){
        // on pioche un event de la file
        al_wait_for_event(fifo, &event);

        // on regarder le type d'evenement
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                fini = true;
                break;
            case ALLEGRO_EVENT_TIMER:
                aleatoire = al_map_rgb(rand()%256, rand()%256, rand()%256);
                //al_clear_to_color(aleatoire);
                al_flip_display();
                break;
            case ALLEGRO_EVENT_DISPLAY_RESIZE:
                printf("La nouvelle taille est (%d x %d) \n", al_get_display_width(game_display), al_get_display_height(game_display));
                break;
            case ALLEGRO_EVENT_KEY_DOWN:
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_T:
                        al_draw_filled_triangle(XRAND,YRAND,XRAND,YRAND,XRAND,YRAND,CRAND);
                        break;
                    case ALLEGRO_KEY_C:
                        al_draw_filled_circle(XRAND, YRAND, XRAND, CRAND);
                        break;

                }
                break;
            default:
                printf("Event non géré\n ");
        }
    }

    // liberation
    al_destroy_display(game_display);
    al_destroy_event_queue(fifo);
    al_destroy_timer(game_timer);
    game_display = NULL;
    return 0;
}