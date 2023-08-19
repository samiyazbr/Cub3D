# include "../mlx_linux/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

#define screenWidth 800
#define screenHeight 600
#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

typedef struct {
    double posX;
    double posY;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
	double time;
	double oldTime;
} Player;

// Define ColorRGB struct
typedef struct {
    int r;
    int g;
    int b;
} ColorRGB;

// Define RGB constants
#define RGB_Red     ((ColorRGB){255, 0, 0})
#define RGB_Green   ((ColorRGB){0, 255, 0})
#define RGB_Blue    ((ColorRGB){0, 0, 255})
#define RGB_White   ((ColorRGB){255, 255, 255})
#define RGB_Yellow  ((ColorRGB){255, 255, 0})

Player player = {22, 12, -1.0, 0.0, 0.0, 0.66, 0, 0};

double get_time_in_microseconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)tv.tv_sec * 1000000 + (double)tv.tv_usec;
}

void draw_line(void *mlx, void *win, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        mlx_pixel_put(mlx, win, x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 < dx) { err += dx; y0 += sy; }
    }
}

void display_text(void *mlx, void *win, int x, int y, int color, char *text)
{
    mlx_string_put(mlx, win, x, y, color, text);
}


int render_frame(void *param)
{
    void *mlx = ((void **)param)[0];
    void *mlx_window = ((void **)param)[1];

	// Calculate frame time
    static double prevFrameTime = 0.0;
    double currentTime = get_time_in_microseconds();
    double frameTime = (currentTime - prevFrameTime) / 1000.0;
    prevFrameTime = currentTime;

	// Calculate desired frame time for 20 FPS
    double desiredFrameTime = 1000.0 / 20.0;

    // Calculate delay needed to achieve 20 FPS
    double delayTime = desiredFrameTime - frameTime;
    if (delayTime > 0) {
        usleep((unsigned int)(delayTime * 1000));
    }

    // Clear the window
    mlx_clear_window(mlx, mlx_window);

    // Draw scene (walls, player, etc.)
    for (int x = 0; x < screenWidth; x++)
    {
        // Calculate ray parameters and perform ray casting for each column
        double cameraX = 2 * x / (double)screenWidth - 1;
        double rayDirX = player.dirX + player.planeX * cameraX;
        double rayDirY = player.dirY + player.planeY * cameraX;
        // Perform ray casting and calculate wall parameters
		int	mapX = (int) player.posX;
		int mapY = (int)player.posY;
		double sideDistX;
		double sideDistY;
		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1.0 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1.0 / rayDirY);
		int stepX;
		int stepY;
		int hit = 0;
		int side;

		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (player.posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - player.posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (player.posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - player.posY) * deltaDistY;
		}
		while(hit == 0)
			{
				if (sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				}
				else
				{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				if (worldMap[mapX][mapY] > 0) hit = 1;
			}

		// Calculate the distance from the player to the wall
		double wallDistance;
		if (side == 0) {
			wallDistance = (mapX - player.posX + (1 - stepX) / 2) / rayDirX;
		} else {
			wallDistance = (mapY - player.posY + (1 - stepY) / 2) / rayDirY;
		}
		int lineHeight = (int)(screenHeight / wallDistance);

		// Calculate the starting and ending pixels for the wall slice on the screen
		int drawStart = -lineHeight / 2 + screenHeight / 2;
		if (drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + screenHeight / 2;
		if (drawEnd >= screenHeight) drawEnd = screenHeight - 1;
		
		//Setting up wall colors
		ColorRGB color;
			switch(worldMap[mapX][mapY])
			{
				case 1:	color = RGB_Red;	break;
				case 2:	color = RGB_Green;	break;
				case 3:	color = RGB_Blue;	break;
				case 4:	color = RGB_White;	break;
				default: color = RGB_Yellow;	break;
			}
		if (side == 1) { color.r /= 2; color.g /= 2; color.b /= 2; }

		// Calculate and display the frame rate
		double frameRate = 1000.0 / frameTime;
		int text_color = 0xFFFFFF;
		char frameRateText[30];
		snprintf(frameRateText, sizeof(frameRateText), "Frame Rate: %.2f FPS", frameRate);
		display_text(mlx, mlx_window, 10, screenHeight - 20, text_color, frameRateText);
		// Draw the pixel with the calculated color
       for (int y = drawStart; y <= drawEnd; y++)
        {
            mlx_pixel_put(mlx, mlx_window, x, y, color.r * 65536 + color.g * 256 + color.b); 
        }
    }
    // Loop indefinitely
	mlx_loop(mlx);
    return (0);
}

// Player movement
void move_player(int direction)
{
    double moveSpeed = 0.05;
    double newPosX = player.posX + player.dirX * moveSpeed * direction;
    double newPosY = player.posY + player.dirY * moveSpeed * direction;

    if (worldMap[(int)newPosX][(int)player.posY] == 0)
        player.posX = newPosX;

    if (worldMap[(int)player.posX][(int)newPosY] == 0)
        player.posY = newPosY;
}

//Player rotation
void rotate_player(int direction)
{
    double rotSpeed = 0.05;

    double oldDirX = player.dirX;
    player.dirX = player.dirX * cos(rotSpeed * direction) - player.dirY * sin(rotSpeed * direction);
    player.dirY = oldDirX * sin(rotSpeed * direction) + player.dirY * cos(rotSpeed * direction);

    double oldPlaneX = player.planeX;
    player.planeX = player.planeX * cos(rotSpeed * direction) - player.planeY * sin(rotSpeed * direction);
    player.planeY = oldPlaneX * sin(rotSpeed * direction) + player.planeY * cos(rotSpeed * direction);
}

//Control Keybindings for Linux
int key_hook(int keycode, void *param)
{
    void *mlx = ((void **)param)[0];
    void *mlx_window = ((void **)param)[1];

    if (keycode == 65307) // ESC key
        exit(0);
    if (keycode == 119) // W key
        move_player(1);
    if (keycode == 115) // S key
        move_player(-1);
    if (keycode == 100) // D key
        rotate_player(-1);
    if (keycode == 97) // A key
        rotate_player(1);

    mlx_clear_window(mlx, mlx_window);
    render_frame(param);

    return (0);
}
//Control Key bindings for Mac OS
// int key_hook(int keycode, void *param)
// {
//     void *mlx = ((void **)param)[0];
//     void *mlx_window = ((void **)param)[1];

//     if (keycode == 53) // ESC key on macOS
//         exit(0);
//     if (keycode == 13) // W key on macOS
//         move_player(1);
//     if (keycode == 1) // S key on macOS
//         move_player(-1);
//     if (keycode == 2) // D key on macOS
//         rotate_player(-1);
//     if (keycode == 0) // A key on macOS
//         rotate_player(1);

//     mlx_clear_window(mlx, mlx_window);
//     render_frame(param);

//     return (0);
// }

int main()
{
    void *mlx;
    void *mlx_window;
    void *param[2];

    mlx = mlx_init();
    mlx_window = mlx_new_window(mlx, screenWidth, screenHeight, "Cub3D");

    param[0] = mlx;
    param[1] = mlx_window;

    mlx_loop_hook(mlx, render_frame, param);
    mlx_hook(mlx_window, 2, 1L << 0, key_hook, param);
    mlx_loop(mlx);

    return 0;
}

