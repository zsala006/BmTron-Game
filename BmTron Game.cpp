#include<allegro.h>
#include<stdio.h>
#include<stdlib.h>


volatile long redtimer = 0;
volatile long bluetimer = 0;

volatile long speed_counter = 0; 

int keypressed();

void increment_speed_counter() {
	speed_counter++;
}
END_OF_FUNCTION(increment_speed_counter);

void increment_time_counter() {
    redtimer++;
    bluetimer++;
}
END_OF_FUNCTION(increment_time_counter); 
 
int main(int argc, char *argv[]){
    //declaring and installing allegro variables
    allegro_init();
    install_keyboard();
    install_mouse();
    
    LOCK_VARIABLE(speed_counter); 
	LOCK_FUNCTION(increment_speed_counter);
	LOCK_VARIABLE(redtimer); 
	LOCK_VARIABLE(bluetimer);
	LOCK_FUNCTION(increment_time_counter);
	install_int_ex(increment_time_counter, BPS_TO_TIMER(1));		
    install_int_ex(increment_speed_counter, BPS_TO_TIMER(1000)); 

	set_color_depth(desktop_color_depth()); 
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 900,900,0,0);  
	
	BITMAP *frame1 = load_bitmap("redbikeup.bmp", NULL); 
	BITMAP *frame2 = load_bitmap("redbikedown.bmp", NULL); 
	BITMAP *frame3 = load_bitmap("redbikeright.bmp", NULL);
	BITMAP *frame4 = load_bitmap("redbikeleft.bmp", NULL);
	
	BITMAP *blue1 = load_bitmap("bluebikeup.bmp", NULL);
	BITMAP *blue2 = load_bitmap("bluebikedown.bmp", NULL);
	BITMAP *blue3 = load_bitmap("bluebikeright.bmp", NULL);
	BITMAP *blue4 = load_bitmap("bluebikeleft.bmp", NULL);
	
	BITMAP *buffer = create_bitmap(900,900);
	
	int redtron_x = 600; 
	int redtron_y = 450; 
	int bluetron_x = 300;
	int bluetron_y = 450;
	int redtrail_x[10000];
	int redtrail_y[10000];
	int bluetrail_x[10000];
	int bluetrail_y[10000];
	int i = 0;
	int r = 0;
	int j = 0;
	int z = 0;
	int b = 0;

    //declaring variables
    FILE *bmfile;
    char bmcontrols[300];
    int cursor_x = 20;
    int cursor_y = 20;
    int rules_x = 350;
    int rules_y = 200;
    int rulemouse_x = 550;
    int rulesmouse_y = 300;
    int play_x = 350;
    int play_y = 450;
    int quit_x = 200;
    int quit_y = 700;
    int bmtronrules_x = 0;
    int bmtronrules_y = 0;
    int back_x = 550; 
    int back_y = 450;
    int background_x = 0;
    int background_y = 0;
    int backgroundmenu_x = 200;
    int backgroundmenu_y = 50;
    int titlemenu_x = 200;
    int titlemenu_y = 50;
           
    BITMAP *quit = NULL;
    BITMAP *play = NULL;
    BITMAP *rules = NULL;
    BITMAP *bmtronrules = NULL;
    BITMAP *background = NULL; 
    BITMAP *backgroundmenu = NULL;
    BITMAP *titlemenu = NULL;
		          
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 900,900,0,0);
    //BITMAP *buffer = create_bitmap(900,900);
    show_mouse(screen);
         
    //load bitmaps of pictures into the program
    background = load_bitmap("background.bmp", NULL);
    backgroundmenu = load_bitmap("backgroundmenu.bmp", NULL);
    rules = load_bitmap("rules_pic.bmp", NULL); 
    play =  load_bitmap("play_pic.bmp", NULL);
    quit =  load_bitmap("quit_pic1.bmp", NULL);
    titlemenu = load_bitmap("Lightbikemenu.bmp", NULL);
           
    //draws the bitmaps onto the screen
    draw_sprite(screen, background, background_x, background_y);
    draw_sprite(screen, backgroundmenu, backgroundmenu_x, backgroundmenu_y);
    draw_sprite(screen, titlemenu, titlemenu_x, titlemenu_y);
    draw_sprite(screen, rules, rules_x, rules_y);
    draw_sprite(screen, play, play_x, play_y);
    draw_sprite(screen, quit, quit_x, quit_y);
           
    blit(background, screen, 0,0,background_x,background_y, 900, 900);
    blit(backgroundmenu, screen, 0,0,backgroundmenu_x,backgroundmenu_y, 900, 900);
    blit(titlemenu, screen, 0,0,titlemenu_x,titlemenu_y, 900, 900);  
    blit(rules, screen, 0,0,rules_x,rules_y, 900, 900);
    blit(play, screen, 0,0,play_x,play_y, 900, 900);
    blit(quit, screen, 0,0,quit_x,quit_y, 900, 900);
           
    //while the user does not press the ESC key  
    while(!key[KEY_ESC]){
        //if the user clicks on the rules picture 
        while (mouse_x < 900 && mouse_y < 900){
            // printf("x%d, y%d\n", mouse_x, mouse_y);
            if(mouse_b == 1 && mouse_x > 370 && mouse_x < 530 && mouse_y > 230 && mouse_y < 330){ 
                bmfile = fopen("controls.txt", "r");
                while(fgets(bmcontrols, 100, bmfile)) {
                    printf("%s\n", bmcontrols);
                }
                BITMAP *bmtronrules = NULL;
                BITMAP *back = NULL;
                BITMAP *black = create_bitmap(900,900); 
                     
                printf("in the loop"); 
                blit(black, screen, 0,0,0,0,900,900); 
                      
                bmtronrules = load_bitmap("bmtronrules1.bmp", NULL);
                back = load_bitmap("back.bmp", NULL);
                draw_sprite(screen, bmtronrules, bmtronrules_x, bmtronrules_y);
                draw_sprite(screen, back, back_x, back_y);
                blit(bmtronrules, screen, 0,0,0,0, 900, 900);
                blit(back, screen, 0,0,550,650, 900, 900);
                         
                printf("test");
                      
            }
   	        //if the user click the back button
            if(mouse_b == 1 && mouse_x > 545 && mouse_x < 810 && mouse_y > 645 && mouse_y < 845){
                BITMAP *black = create_bitmap(900,900);
                blit(black, screen, 0,0,0,0,900,900);
                   
                draw_sprite(screen, backgroundmenu, backgroundmenu_x, backgroundmenu_y);
                draw_sprite(screen, titlemenu, titlemenu_x, titlemenu_y);
                draw_sprite(screen, background, background_x, background_y);
                draw_sprite(screen, rules, 350, 100);
                draw_sprite(screen, play, play_x, play_y);
                draw_sprite(screen, quit, quit_x, quit_y);
                        
                blit(background, screen, 0,0,background_x,background_y, 900, 900);
                blit(backgroundmenu, screen, 0,0,backgroundmenu_x,backgroundmenu_y, 900, 900);
                blit(titlemenu, screen, 0,0,titlemenu_x,titlemenu_y, 900, 900);
                blit(rules, screen, 0,0,350,200, 900, 900);
                blit(play, screen, 0,0,play_x,play_y, 900, 900);
                blit(quit, screen, 0,0,quit_x,quit_y, 900, 900);
            }
            //if the user clicks on the play picture
            if (mouse_x < 900 && mouse_y < 900){
                if(mouse_b == 1 && mouse_x > 370 && mouse_x < 510 && mouse_y > 460 && mouse_y < 630){
                    redtimer = 0;
                    bluetimer = 0; 
                    draw_sprite(buffer, blue1, bluetron_x, bluetron_y);
                    draw_sprite(buffer, frame1, redtron_x, redtron_y);
                    blit(buffer, screen, 0,0,0,0,900,900);
                    blit(buffer, screen, 0,0,0,0,900,900);	
    
                    clear_bitmap(buffer);
    			      
	                while (!key[KEY_ESC]) {
		                while (speed_counter > 0) {
                            //Movement of Red Player and Collision detection
                            if (key[KEY_RIGHT]) {
                                //Keeping track of the x axis trail for the red player
                                redtrail_x[i] = redtron_x;
                                //Drawing the red player
                                draw_sprite(buffer, frame3, redtron_x, redtron_y);
                                blit(buffer, screen, 0,0,0,0,900,900);
                                //Edge of screen collision detection
                                if (redtron_x<0 || redtron_x>900) {
                                    allegro_message("Redtron has hit the edge of the screen.\nBluetron is the Winner!!");
                                    return 1;
                                }
                                //Head on collision detection 
                                if (redtron_x == bluetron_x && redtron_y == bluetron_y) {
                                    allegro_message("You have both died");
                                    return 1;
                                }
                                //Timer for movement. Player cannot stay still for more than two seconds
                                if (!key[KEY_LEFT] && !key[KEY_UP] && !key[KEY_DOWN] && !key[KEY_RIGHT]) {
                                    redtimer++;
                                }
                                if (redtimer >= 2) {
                                    allegro_message("Redtron has died because of time.\nBluetron is the Winner!!!");
                                    return 1;
                                }
                                //Trail collision detection
                                for (j = 0; j<1000; j++) {
                                    if (redtrail_x[j] == redtron_x && redtrail_y[j] == redtron_y) {
                                        allegro_message("Redtron hit his own trail.\nBluetron is the Winner!!!");
                                        return 1;
                                    }
                                    if (bluetrail_x[j] == bluetron_x && bluetrail_y[j] == bluetron_y) {
                                        allegro_message("Bluetron hit his own trail.\nRedtron is the Winner!!!");
                                        return 1;
                                    }
                                    if (redtrail_x[j] == bluetron_x && redtrail_y[j] == bluetron_y) {
                                        allegro_message("Bluetron hit Red's trail.\nRedtron is the Winner!!!");
                                        return 1;
                                    }
                                    if (bluetrail_x[j] == redtron_x && bluetrail_y[j] == redtron_y) {
                                        allegro_message("Redtron hit Blue's trail.\nBluetron is the Winner!!!");
                                        return 1;
                                    }
                                }   
                                //Resetting the timer and moving the player           
                                redtimer = 0;
                                redtron_x +=2;   
                                i++;    
                            }   
			                else if (key[KEY_LEFT]) {
                                //Keeping track of the x axis trail for the red player
                                redtrail_x[i] = redtron_x;
                                //Drawing the red player
                                draw_sprite(buffer, frame4, redtron_x, redtron_y); 
                                blit(buffer, screen, 0,0,0,0,900,900);
                                //Edge of screen collision detection
                                if (redtron_x<0 || redtron_x>900) {
                                    allegro_message("Redtron has hit the edge of the screen.\nBluetron is the Winner!!");
                                    return 1;
                                }
                                //Head on collision detection
                                if (redtron_x == bluetron_x && redtron_y == bluetron_y) {
                                    allegro_message("You have both died");
                                    return 1;
                                }
                                //Timer for movement. Player cannot stay still for more than two seconds
                                if (!key[KEY_LEFT] && !key[KEY_UP] && !key[KEY_DOWN] && !key[KEY_RIGHT]) {
                                    redtimer++;
                                }
                                if (redtimer >= 2) {
                                    allegro_message("Redtron has died because of time\nBluetron is the Winner!!!");
                                    return 1;
                                }
                                //Trail collision detection
                                for (j = 0; j<1000; j++) {
                                    if (redtrail_x[j] == redtron_x && redtrail_y[j] == redtron_y) {
                                        allegro_message("Redtron hit his own trail.\nBluetron is the Winner!!!");
                                        return 1;
                                    }
                                    if (bluetrail_x[j] == bluetron_x && bluetrail_y[j] == bluetron_y) {
                                        allegro_message("Bluetron hit his own trail.\nRedtron is the Winner!!!");
                                        return 1;
                                    }
                                    if (redtrail_x[j] == bluetron_x && redtrail_y[j] == bluetron_y) {
                                        allegro_message("Bluetron hit Red's trail.\nRedtron is the Winner!!!");
                                        return 1;
                                    }
                                    if (bluetrail_x[j] == redtron_x && bluetrail_y[j] == redtron_y) {
                                        allegro_message("Redtron hit Blue's trail.\nBluetron is the Winner!!!");
                                        return 1;
                                    }
                                }
                                //Resetting the timer and moving the player
                                redtimer = 0;
                                redtron_x -=2;   
                                i++;
                            }       
			                else if (key[KEY_UP]) {
                                //Keeping track of the y trail coordinates for the red player
                                redtrail_y[r] = redtron_y;
                                //Drawing the player
                                draw_sprite(buffer, frame1, redtron_x, redtron_y);
                                blit(buffer, screen, 0,0,0,0,900,900);  
                                //Edge of screen collision detection
                                if (redtron_y<0 || redtron_y>900) {
                                    allegro_message("Redtron has hit the edge of the screen\nBluetron is the Winner!!!");
                                    return 1;
                                } 
                                //Head on collision detection
                                if (redtron_x == bluetron_x && redtron_y == bluetron_y) {
                                    allegro_message("You have both died");
                                    return 1;
                                }
                                //Timer for movement. Player cannot stay still for 2 or more seconds
                                if (!key[KEY_LEFT] && !key[KEY_UP] && !key[KEY_DOWN] && !key[KEY_RIGHT]) {
                                    redtimer++;
                                }
                                if (redtimer >= 2) {
                                    allegro_message("Redtron has died because of time\nBluetron is the Winner!!!");
                                    return 1;
                                }
                                //Trail collision detection
                                for (j = 0; j<1000; j++) {
                                    if (redtrail_x[j] == redtron_x && redtrail_y[j] == redtron_y) {
                                        allegro_message("Redtron hit his own trail.\nBluetron is the Winner!!!");
                                        return 1;
                                    }
                                    if (bluetrail_x[j] == bluetron_x && bluetrail_y[j] == bluetron_y) {
                                        allegro_message("Bluetron hit his own trail.\nRedtron is the Winner!!!");
                                        return 1;
                                    }
                                    if (redtrail_x[j] == bluetron_x && redtrail_y[j] == bluetron_y) {
                                        allegro_message("Bluetron hit Red's trail.\nRedtron is the Winner!!!");
                                        return 1;
                                    }
                                    if (bluetrail_x[j] == redtron_x && bluetrail_y[j] == redtron_y) {
                                        allegro_message("Redtron hit Blue's trail.\nBluetron is the Winner!!!");
                                        return 1;
                                    }
                                } 
                                //Resetting the timer and moving the player
                                redtimer = 0;
                                redtron_y -=2;  
                                r++;
                            }    
			                else if (key[KEY_DOWN]) {
                                //Keeping track of the y trail coordinates for the red player
                                redtrail_y[r] = redtron_y;
                                //Drawing the player
                                draw_sprite(buffer, frame2, redtron_x, redtron_y);
                                blit(buffer, screen, 0,0,0,0,900,900);  
                                //Edge of screen collision detection
                                if (redtron_y<0 || redtron_y>900) {
                                    allegro_message("Redtron has hit the edge of the screen\nBluetron is the Winner!!!");
                                    return 1;
                                } 
                                //Head on collision detection
                                if (redtron_x == bluetron_x && redtron_y == bluetron_y) {
                                    allegro_message("You have both died");
                                    return 1;
                                }
                                //Timer for movement. Player cannot stay still for 2 or more seconds
                                if (!key[KEY_LEFT] && !key[KEY_UP] && !key[KEY_DOWN] && !key[KEY_RIGHT]) {
                                    redtimer++;
                                }
                                if (redtimer >= 2) {
                                    allegro_message("Redtron has died because of time\nBluetron is the Winner!!!");
                                    return 1;
                                }
                                //Trail collision detection
                                for (j = 0; j<1000; j++) {
                                    if (redtrail_x[j] == redtron_x && redtrail_y[j] == redtron_y) {
                                        allegro_message("Redtron hit his own trail.\nBluetron is the Winner!!!");
                                        return 1;
                                    }
                                    if (bluetrail_x[j] == bluetron_x && bluetrail_y[j] == bluetron_y) {
                                        allegro_message("Bluetron hit his own trail.\nRedtron is the Winner!!!");
                                        return 1;
                                    }
                                    if (redtrail_x[j] == bluetron_x && redtrail_y[j] == bluetron_y) {
                                        allegro_message("Bluetron hit Red's trail.\nRedtron is the Winner!!!");
                                        return 1;
                                    }
                                    if (bluetrail_x[j] == redtron_x && bluetrail_y[j] == redtron_y) {
                                        allegro_message("Redtron hit Blue's trail.\nBluetron is the Winner!!!");
                                        return 1;
                                    }
                                } 
                                //Resetting the timer and moving the player
                                redtimer = 0;
                                redtron_y +=2;  
                                r++;
                            }   
			                //Blue Player Movement
			                if (key[KEY_D]) {
                                //Keeping track of the trail x coordinates for the blue player
                                bluetrail_x[z] = bluetron_x;
                                //Drawing the player
                                draw_sprite(buffer, blue3, bluetron_x, bluetron_y);
                                blit(buffer, screen, 0,0,0,0,900,900);
                                //Edge of screen collision detection
                                if (bluetron_x<0 || bluetron_x>900) {
                                    allegro_message("Bluetron has hit the edge of the screen.\nRedtron is the Winner!!!");
                                    return 1;
                                }
                                //Head on collision detection
                                if (redtron_x == bluetron_x && redtron_y == bluetron_y) {
                                    allegro_message("You have both died");
                                    return 1;
                                }
                                //Timer for movement. Player cannot stay still for 2 or more seconds
                                if (!key[KEY_D] && !key[KEY_S] && !key[KEY_A] && !key[KEY_W]) {
                                    bluetimer++;
                                }
                                if (bluetimer >= 2) {
                                    allegro_message("Bluetron has died because of time\nRedtron is the Winner!!!");
                                    return 1;
                                }
                                //Trail collision detection
                                for (j = 0; j<1000; j++) {
                                    if (redtrail_x[j] == redtron_x && redtrail_y[j] == redtron_y) {
                                        allegro_message("Redtron hit his own trail.\nBluetron is the Winner!!!");
                                        return 1;
                                    }
                                    if (bluetrail_x[j] == bluetron_x && bluetrail_y[j] == bluetron_y) {
                                        allegro_message("Bluetron hit his own trail.\nRedtron is the Winner!!!");
                                        return 1;
                                    }
                                    if (redtrail_x[j] == bluetron_x && redtrail_y[j] == bluetron_y) {
                                        allegro_message("Bluetron hit Red's trail.\nRedtron is the Winner!!!");
                                        return 1;
                                    }
                                    if (bluetrail_x[j] == redtron_x && bluetrail_y[j] == redtron_y) {
                                        allegro_message("Redtron hit Blue's trail.\nBluetron is the Winner!!!");
                                        return 1;
                                    }
                                } 
                                //Restting the timer and moving the player 
                                bluetimer = 0;
                                bluetron_x +=2; 
                                z++;
                            }
			                else if (key[KEY_A]) {
                                //Keeping track of the trail x coordinates for the blue player
                                bluetrail_x[z] = bluetron_x;
                                //Drawing the player
                                draw_sprite(buffer, blue4, bluetron_x, bluetron_y);
                                blit(buffer, screen, 0,0,0,0,900,900);  
                                //Edge of screen collision detection
                                if (bluetron_x<0 || bluetron_x>900) {
                                    allegro_message("Bluetron has hit the edge of the screen.\nRedtron is the Winner!!!");
                                    return 1;
                                }
                                //Head on collision detection
                                if (redtron_x == bluetron_x && redtron_y == bluetron_y) {
                                    allegro_message("You have both died");
                                    return 1;
                                }
                                //Timer for movement. Player cannot stay still for 2 or more seconds
                                if (!key[KEY_D] && !key[KEY_S] && !key[KEY_A] && !key[KEY_W]) {
                                    bluetimer++;
                                }
                                if (bluetimer >= 2) {
                                    allegro_message("Bluetron has died because of time\nRedtron is the Winner!!!");
                                    return 1;
                                }
                                //Trail collision detection
                                for (j = 0; j<1000; j++) {
                                    if (redtrail_x[j] == redtron_x && redtrail_y[j] == redtron_y) {
                                        allegro_message("Redtron hit his own trail.\nBluetron is the Winner!!!");
                                        return 1;
                                    }
                                    if (bluetrail_x[j] == bluetron_x && bluetrail_y[j] == bluetron_y) {
                                        allegro_message("Bluetron hit his own trail.\nRedtron is the Winner!!!");
                                        return 1;
                                    }
                                    if (redtrail_x[j] == bluetron_x && redtrail_y[j] == bluetron_y) {
                                        allegro_message("Bluetron hit Red's trail.\nRedtron is the Winner!!!");
                                        return 1;
                                    }
                                    if (bluetrail_x[j] == redtron_x && bluetrail_y[j] == redtron_y) {
                                        allegro_message("Redtron hit Blue's trail.\nBluetron is the Winner!!!");
                                        return 1;
                                    }
                                }
                                //Restting the timer and moving the player    
                                bluetimer = 0;
                                bluetron_x -=2;   
                                z++;
                            }     
			                else if (key[KEY_W]) {
                                //Keeping track of the trail y coordinates for the blue player 
                                bluetrail_y[b] = bluetron_y;
                                //Drawing the player
                                draw_sprite(buffer, blue1, bluetron_x, bluetron_y);
                                blit(buffer, screen, 0,0,0,0,900,900);
                                //Edge of screen collision detection
                                if (bluetron_y<0 || bluetron_y>900) {
                                    allegro_message("Bluetron has hit the edge of the screen.\nRedtron is the Winner!!!");
                                    return 1;
                                }
                                //Head on collision detection
                                if (redtron_x == bluetron_x && redtron_y == bluetron_y) {
                                    allegro_message("You have both died");
                                    return 1;
                                }
                                //Timer for moevemt. Player cannot stay still for two or more seconds
                                if (!key[KEY_D] && !key[KEY_S] && !key[KEY_A] && !key[KEY_W]) {
                                    bluetimer++;
                                }
                                if (bluetimer >= 2) {
                                    allegro_message("Bluetron has died because of time\nRedtron is the Winner!!!");
                                    return 1;
                                }
                                //Trail collision detection
                                for (j = 0; j<1000; j++) {
                                    if (redtrail_x[j] == redtron_x && redtrail_y[j] == redtron_y) {
                                        allegro_message("Redtron hit his own trail.\nBluetron is the Winner!!!");
                                        return 1;
                                    }
                                    if (bluetrail_x[j] == bluetron_x && bluetrail_y[j] == bluetron_y) {
                                        allegro_message("Bluetron hit his own trail.\nRedtron is the Winner!!!");
                                        return 1;
                                    }
                                    if (redtrail_x[j] == bluetron_x && redtrail_y[j] == bluetron_y) {
                                        allegro_message("Bluetron hit Red's trail.\nRedtron is the Winner!!!");
                                        return 1;
                                    }
                                    if (bluetrail_x[j] == redtron_x && bluetrail_y[j] == redtron_y) {
                                        allegro_message("Redtron hit Blue's trail.\nBluetron is the Winner!!!");
                                        return 1;
                                    }
                                }
                                //Restting the timer and moving the player
                                bluetimer = 0;
                                bluetron_y -=2;   
                                b++;
                            }   
			                else if (key[KEY_S]) {
                                //Keeping track of the trail y coordinates for the blue player 
                                bluetrail_y[b] = bluetron_y;
                                //Drawing the player
                                draw_sprite(buffer, blue2, bluetron_x, bluetron_y);
                                blit(buffer, screen, 0,0,0,0,900,900);
                                //Edge of screen collision detection
                                if (bluetron_y<0 || bluetron_y>900) {
                                    allegro_message("Bluetron has hit the edge of the screen.\nRedtron is the Winner!!!");
                                    return 1;
                                }
                                //Head on collision detection
                                if (redtron_x == bluetron_x && redtron_y == bluetron_y) {
                                    allegro_message("You have both died");
                                    return 1;
                                }
                                //Timer for moevemt. Player cannot stay still for two or more seconds
                                if (!key[KEY_D] && !key[KEY_S] && !key[KEY_A] && !key[KEY_W]) {
                                    bluetimer++;
                                }
                                if (bluetimer >= 2) {
                                    allegro_message("Bluetron has died because of time\nRedtron is the Winner!!!");
                                    return 1;
                                }
                                //Trail collision detection
                                for (j = 0; j<1000; j++) {
                                    if (redtrail_x[j] == redtron_x && redtrail_y[j] == redtron_y) {
                                        allegro_message("Redtron hit his own trail.\nBluetron is the Winner!!!");
                                        return 1;
                                    }
                                    if (bluetrail_x[j] == bluetron_x && bluetrail_y[j] == bluetron_y) {
                                        allegro_message("Bluetron hit his own trail.\nRedtron is the Winner!!!");
                                        return 1;
                                    }
                                    if (redtrail_x[j] == bluetron_x && redtrail_y[j] == bluetron_y) {
                                        allegro_message("Bluetron hit Red's trail.\nRedtron is the Winner!!!");
                                        return 1;
                                    }
                                    if (bluetrail_x[j] == redtron_x && bluetrail_y[j] == redtron_y) {
                                        allegro_message("Redtron hit Blue's trail.\nBluetron is the Winner!!!");
                                        return 1;
                                    }
                                }
                                //Restting the timer and moving the player
                                bluetimer = 0;
                                bluetron_y +=2;   
                                b++;
                            }    
             //**********************End of Movement*****************************
            
			//**************************Collision*******************************
                            if (key[KEY_DOWN] && key[KEY_UP]) {
                                allegro_message("Redtron has died\n Bluetron is the Winner!!!");
                                return 1;
                            }
			                if (key[KEY_RIGHT] && key[KEY_LEFT]) {
                                allegro_message("Redtron has died\n Bluetron is the Winner!!!");
                                return 1;
                            }
                            if (key[KEY_A] && key[KEY_D]) {
                                allegro_message("Bluetron has died\n Redtron is the Winner!!!");
                                return 1;
                            }
			                if (key[KEY_W] && key[KEY_S]) {
                                allegro_message("Bluetron has died!\n Redtron is the Winner!!!");
                                return 1;
                            }
            //**********************End of Collision**************************** 
                            speed_counter--;
                        }    																																												
                    }    
                    if (key[KEY_ESC]) {
                        allegro_message("Game has ended.");
                        return 1;
                    } 
                    destroy_bitmap(buffer);   
                }   
            }             
            //if the user clicks on the quit pictures
   		    if (mouse_x < 900 && mouse_y < 900){
       		    if(mouse_b == 1 && mouse_x > 340 && mouse_x < 585 && mouse_y > 760 && mouse_y < 850){
      			    quit_x = mouse_x;
          			quit_y = mouse_y;
          			allegro_message("Thanks for Playing!!");
          			return 1;
           		}
       		}
    	}           
	}
    			     
    //deletes bitmaps
    destroy_bitmap(rules);  
    destroy_bitmap(quit); 
    destroy_bitmap(play);
 
    getchar ();
    return 0;
}
//end of allegro
END_OF_MAIN() 
