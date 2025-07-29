//#include "C:/Wichtig/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/Random.h"
#include "/home/codeleaded/System/Static/Library/Scene.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8080

int sock = 0;
struct sockaddr_in serv_addr;
Scene scene;

void Slider1_React(Slider* s,SliderEvent* se){
	if(se->eid==EVENT_PRESSED){
		int angle = s->scrolled * 180;
		
		char command[1024];
		memset(command,0,1024);
		sprintf(command,"%d %d\n",1,angle);

		send(sock,command,strlen(command),0);
    	printf("Nachricht gesendet\n");
	}
}
void Slider2_React(Slider* s,SliderEvent* se){
	if(se->eid==EVENT_PRESSED){
		int angle = s->scrolled * 180;
		
		char command[1024];
		memset(command,0,1024);
		sprintf(command,"%d %d\n",2,angle);

		send(sock,command,strlen(command),0);
    	printf("Nachricht gesendet\n");
	}
}
void Slider3_React(Slider* s,SliderEvent* se){
	if(se->eid==EVENT_PRESSED){
		int angle = s->scrolled * 180;
		
		char command[1024];
		memset(command,0,1024);
		sprintf(command,"%d %d\n",3,angle);

		send(sock,command,strlen(command),0);
    	printf("Nachricht gesendet\n");
	}
}
void Slider4_React(Slider* s,SliderEvent* se){
	if(se->eid==EVENT_PRESSED){
		int angle = s->scrolled * 180;
		
		char command[1024];
		memset(command,0,1024);
		sprintf(command,"%d %d\n",4,angle);

		send(sock,command,strlen(command),0);
    	printf("Nachricht gesendet\n");
	}
}
void Slider5_React(Slider* s,SliderEvent* se){
	if(se->eid==EVENT_PRESSED){
		int angle = s->scrolled * 180;
		
		char command[1024];
		memset(command,0,1024);
		sprintf(command,"%d %d\n",5,angle);

		send(sock,command,strlen(command),0);
    	printf("Nachricht gesendet\n");
	}
}
void Slider6_React(Slider* s,SliderEvent* se){
	if(se->eid==EVENT_PRESSED){
		int angle = s->scrolled * 180;
		
		char command[1024];
		memset(command,0,1024);
		sprintf(command,"%d %d\n",6,angle);

		send(sock,command,strlen(command),0);
    	printf("Nachricht gesendet\n");
	}
}

void Setup(AlxWindow* w){
	serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

	printf("socket...\n");
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket-Erstellung fehlgeschlagen");
    	window.Running = 0;
		return;
    }
	printf("inet_pton...\n");
    if (inet_pton(AF_INET, "192.168.2.110", &serv_addr.sin_addr) <= 0) {
        perror("Ungültige Adresse/Adresse nicht unterstützt");
    	window.Running = 0;
		return;
    }
	printf("connect...\n");
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Verbindung fehlgeschlagen");
    	window.Running = 0;
		return;
    }
	printf("connected...\n");

    //char *hello = "Hallo vom PC!\n";
    //char buffer[1024] = {0};
    //int valread = read(sock, buffer, 1024);
    //printf("Antwort vom Server: %s\n", buffer);

	scene = Scene_New();

	Scene_Add(&scene,(Slider[]){
		Slider_New(
			(void*)&scene,
			Slider1_React,
			Rect_New((Vec2){ 100.0f,100.0f },(Vec2){ 400.0f,100.0f }),
			RED,
			GREEN
		) 
	},sizeof(Slider));
	Scene_Add(&scene,(Slider[]){
		Slider_New(
			(void*)&scene,
			Slider2_React,
			Rect_New((Vec2){ 100.0f,250.0f },(Vec2){ 400.0f,100.0f }),
			RED,
			GREEN
		) 
	},sizeof(Slider));
	Scene_Add(&scene,(Slider[]){
		Slider_New(
			(void*)&scene,
			Slider3_React,
			Rect_New((Vec2){ 100.0f,400.0f },(Vec2){ 400.0f,100.0f }),
			RED,
			GREEN
		) 
	},sizeof(Slider));
	Scene_Add(&scene,(Slider[]){
		Slider_New(
			(void*)&scene,
			Slider4_React,
			Rect_New((Vec2){ 100.0f,550.0f },(Vec2){ 400.0f,100.0f }),
			RED,
			GREEN
		) 
	},sizeof(Slider));
	Scene_Add(&scene,(Slider[]){
		Slider_New(
			(void*)&scene,
			Slider5_React,
			Rect_New((Vec2){ 100.0f,700.0f },(Vec2){ 400.0f,100.0f }),
			RED,
			GREEN
		) 
	},sizeof(Slider));
	Scene_Add(&scene,(Slider[]){
		Slider_New(
			(void*)&scene,
			Slider6_React,
			Rect_New((Vec2){ 100.0f,850.0f },(Vec2){ 400.0f,100.0f }),
			RED,
			GREEN
		) 
	},sizeof(Slider));
}

void Update(AlxWindow* w){
	Scene_Update(&scene,window.Strokes,GetMouse(),GetMouseBefore());

	Clear(BLACK);

	Scene_Render(WINDOW_STD_ARGS,&scene);
}

void Delete(AlxWindow* w){
    close(sock);

	Scene_Free(&scene);
}

int main(){
    if(Create("Guis",2500,1200,1,1,Setup,Update,Delete))
        Start();
    return 0;
}