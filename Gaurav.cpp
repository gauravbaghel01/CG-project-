#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <math.h>

// Improved background with sun, hills, forest
void drawForestBackground() {
// Sky
setfillstyle(SOLID_FILL, LIGHTCYAN);
bar(0, 0, 640, 200);

// Sun  
setcolor(YELLOW);  
setfillstyle(SOLID_FILL, YELLOW);  
fillellipse(560, 60, 40, 40);  

// Distant hills  
setcolor(LIGHTGREEN);  
setfillstyle(SOLID_FILL, LIGHTGREEN);  
ellipse(150, 220, 0, 360, 180, 60);  
floodfill(150, 220, LIGHTGREEN);  

setcolor(GREEN);  
setfillstyle(SOLID_FILL, GREEN);  
ellipse(450, 230, 0, 360, 220, 80);  
floodfill(450, 230, GREEN);  

// Grass  
setcolor(GREEN);  
setfillstyle(SOLID_FILL, GREEN);  
bar(0, 250, 640, 400);  

// Soil  
setcolor(BROWN);  
setfillstyle(SOLID_FILL, BROWN);  
bar(0, 400, 640, 480);  

// Trees with leafy gradient  
for (int i = 50; i <= 600; i += 150) {  
    // Trunk  
    setcolor(BROWN);  
    setfillstyle(SOLID_FILL, BROWN);  
    bar(i, 170, i + 20, 300);  
    // Leaves  
    setcolor(GREEN);  
    setfillstyle(SOLID_FILL, GREEN);  
    fillellipse(i + 10, 150, 30, 25);  
    setcolor(LIGHTGREEN);  
    setfillstyle(SOLID_FILL, LIGHTGREEN);  
    fillellipse(i + 10, 140, 20, 15);  
}  

// Rocks  
setcolor(DARKGRAY);  
setfillstyle(SOLID_FILL, DARKGRAY);  
fillellipse(120, 350, 20, 15);  
fillellipse(500, 355, 25, 20);

}

// Function to draw wheel with rotating spokes
void drawWheel(int x, int y, int r, int spokeAngle) {
setcolor(DARKGRAY);
setfillstyle(SOLID_FILL, BLACK);
fillellipse(x, y, r + 2, r + 2);  // outer tire

setcolor(LIGHTGRAY);  
setfillstyle(SOLID_FILL, LIGHTGRAY);  
fillellipse(x, y, r - 4, r - 4);  // inner wheel  

// Spokes (rotating)  
setcolor(WHITE);  
for (int a = 0; a < 360; a += 45) {  
    int x1 = x + (r - 4) * cos((a + spokeAngle) * 3.14 / 180);  
    int y1 = y + (r - 4) * sin((a + spokeAngle) * 3.14 / 180);  
    line(x, y, x1, y1);  
}

}

// Function to draw upgraded cycle and rider
void drawCycleAndRider(int x, int y, int pedalAngle, int spokeAngle) {
int wheelRadius = 25;

// Wheels  
drawWheel(x, y, wheelRadius, spokeAngle);  
drawWheel(x + 100, y, wheelRadius, spokeAngle);  

// Frame  
setcolor(RED);  
line(x, y, x + 50, y - 40);  
line(x + 50, y - 40, x + 100, y);  
line(x + 25, y, x + 75, y);  
line(x + 50, y - 40, x + 50, y);  
setcolor(YELLOW);  
line(x + 25, y, x + 50, y - 40);  

// Seat  
setcolor(BLUE);  
rectangle(x + 35, y - 55, x + 50, y - 50);  
setfillstyle(SOLID_FILL, BLUE);  
floodfill(x + 36, y - 53, BLUE);  

// Handle  
setcolor(CYAN);  
line(x + 100, y, x + 115, y - 35);  
line(x + 115, y - 35, x + 130, y - 35);  
circle(x + 130, y - 35, 3);  

// Pedal  
int crankX = x + 50;  
int crankY = y;  
int pedalLen = 15;  
int pedalX = crankX + pedalLen * cos(pedalAngle * M_PI / 180.0);  
int pedalY = crankY + pedalLen * sin(pedalAngle * M_PI / 180.0);  
setcolor(WHITE);  
line(crankX, crankY, pedalX, pedalY);  
circle(pedalX, pedalY, 3);  
setfillstyle(SOLID_FILL, YELLOW);  
floodfill(pedalX, pedalY, WHITE);  

// Rider  
int bodyX = x + 45;  
int bodyY = y - 70;  

// Head  
setcolor(MAGENTA);  
setfillstyle(SOLID_FILL, MAGENTA);  
fillellipse(bodyX, bodyY - 20, 10, 15);  

// Eyes  
setcolor(BLACK);  
fillellipse(bodyX - 4, bodyY - 23, 3, 2); // Left eye  
fillellipse(bodyX + 4, bodyY - 23, 3, 2); // Right eye  

// Nose  
setcolor(BLACK);  
line(bodyX, bodyY - 20, bodyX - 2, bodyY - 17);  

// Mouth (smile)  
setcolor(RED);  
arc(bodyX, bodyY - 15, 200, 340, 7);  

// Helmet (more rounded)  
setcolor(BLUE);  
setfillstyle(SOLID_FILL, BLUE);  
pieslice(bodyX, bodyY - 25, 180, 360, 11);  

// Body  
setcolor(BLUE);  
line(bodyX, bodyY - 10, bodyX, bodyY + 15);  

// Arms  
line(bodyX, bodyY, x + 105, y - 25);  

// Legs  
int kneeX = bodyX;  
int kneeY = bodyY + 10 + 5 * sin(pedalAngle * M_PI / 180.0);  
setcolor(BLACK);  
line(bodyX, bodyY + 15, kneeX, kneeY);  
line(kneeX, kneeY, pedalX, pedalY);

}

int main() {
int gd = DETECT, gm;
initgraph(&gd, &gm, "");

int page = 0;  
int pedalAngle = 0;  
int spokeAngle = 0;  

for (int i = 0; i < 500; i++) {  
    setactivepage(page);  
    setvisualpage(1 - page);  
    cleardevice();  

    drawForestBackground();  
    drawCycleAndRider(50 + i, 370, pedalAngle, spokeAngle);  

    pedalAngle = (pedalAngle + 20) % 360;  
    spokeAngle = (spokeAngle + 25) % 360;  

    delay(20);  
    page = 1 - page;  
}  

getch();  
closegraph();  
return 0;

}
