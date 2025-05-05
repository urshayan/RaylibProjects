#include <raylib.h>
#include <iostream>
#include "Player1.h"
#include "Player2.h"
#include "Block.h"
#include <vector>


bool running = false;


int main() {
	
	bool isTimeup = false;

	int screenWidth = 900;
	int screenHeight = 800;
	InitWindow(screenWidth, screenHeight, "Catch The N*gga!");
	InitAudioDevice();
	SetTargetFPS(60);

	// Loading All the Assets!
	Sound collisionSound = LoadSound("Assets/hitsound.mp3");
	Music bgMusic = LoadMusicStream("Assets/bgmusic.mp3");
	Music Ingame = LoadMusicStream("Assets/ingamemusic.mp3");
	Music niggaWin = LoadMusicStream("Assets/nigga.mp3");
	Music emojiwin = LoadMusicStream("Assets/emoji.mp3");
	PlayMusicStream(bgMusic);
	PlayMusicStream(Ingame);
	PlayMusicStream(niggaWin);
	PlayMusicStream(emojiwin);
	// A little trick to tknow the co-ordinates of the desired place!
	/*
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
	Vector2 mousePos = GetMousePosition();
	std::cout << "Clicked at: (" << mousePos.x << ", " << mousePos.y << ")\n";
}
	*/
	Texture2D txt1 = LoadTexture("Assets/player1.png");
	Texture2D txt2 = LoadTexture("Assets/player2.png");

	Player1 player1(txt1 , {300 , 200});
	Player2 player2(txt2, { 520 , 550 });
/*		Clicked at : (51, 55)
		Clicked at : (66, 240)
		Clicked at : (87, 465)
		Clicked at : (80, 629)
		Clicked at : (391, 587)
		Clicked at : (358, 399)
		Clicked at : (358, 399)
		Clicked at : (489, 137)
		Clicked at : (679, 249)
		Clicked at : (723, 413)
		Clicked at : (758, 652)
		Clicked at : (249, 692)
		*/



	// Placing the stupid Blocks!.... This will take an hour....
	// kINDA lIKE INITIALZIN THE BLOCKS!
	std::vector<Block>walls = {
	Block({128, 64}, {64, 192}, BLUE),        // Left side vertical
	Block({320, 64}, {128, 64}, YELLOW),        // Top horizontal
	Block({576, 64}, {128, 64}, YELLOW),        // Top right horizontal

	Block({160, 256}, {128, 64}, YELLOW),       // Mid left horizontal
	Block({384, 256}, {64, 192}, YELLOW),       // Mid vertical block
	Block({608, 256}, {128, 64}, YELLOW),       // Mid right horizontal

	Block({128, 448}, {64, 192}, YELLOW),       // Bottom left vertical
	Block({704, 448}, {64, 192},BLUE),       // Bottom right vertical

	Block({320, 576}, {128, 64}, BLUE),       // Bottom middle horizontal
	Block({512, 640}, {64, 128}, BLUE),       // Lower vertical block

	Block({256, 704}, {128, 64}, BLUE),       // Near bottom left
	Block({640, 704}, {128, 64}, BLUE),
  };




	while (!WindowShouldClose()) {
			
		UpdateMusicStream(bgMusic);
		
		// Menu For The Game 
		// Drawing the Game Menu and the Logic! and also the animation
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("---CATCH THE N*GGA--- ", 4, 200, 70, BLUE);
		DrawText("Press Enter To Start!", 320, 280, 20, RED);
		DrawText("Player1  : Arrow Keys" , 100 , 450 , 20,BLUE);
		DrawText("Player2  : WASD Keys", 550, 450, 20, DARKBROWN);
		DrawTextureEx(txt1, { 100 , 500 }, 0.0f, 3.0f, WHITE);
		DrawTextureEx(txt2, { 550 , 500 }, 0.0f, 3.0f, WHITE);

		if (IsKeyPressed(KEY_ENTER)) {
			running = true;

		}


		// Also Show The Instructions!


		EndDrawing();


		float timer = 60.0f;

		while (running) {
			UpdateMusicStream(Ingame); 

			// Timer Logic!
			if (!isTimeup) {
				timer -= GetFrameTime();
			}
			
			
			
	
			// Update Positions -- 
			player1.update();
			player2.update();

			// Drawing Thingsss... -- 
			BeginDrawing();
			ClearBackground(LIGHTGRAY);
			player1.Draw();
			player2.Draw();

			char timeText[50];
			sprintf_s(timeText, "Time Left: %.1f", timer);
			DrawText(timeText, 20, 20, 40, DARKPURPLE);



			// Drawing the Blocks
			for (const Block& wall : walls) {
				//Player1
				wall.Draw();
				Rectangle wallRect = wall.GetRect();
				if (CheckCollisionRecs(player1.getRect(), wallRect)) {
					if (IsKeyDown(KEY_RIGHT)) player1.position.x -= 7;
					if (IsKeyDown(KEY_LEFT))  player1.position.x += 7;
					if (IsKeyDown(KEY_DOWN))  player1.position.y -= 7;
					if (IsKeyDown(KEY_UP))    player1.position.y += 7;
					PlaySound(collisionSound);
				}

				// player2
			
				if (CheckCollisionRecs(player2.getRect(), wallRect)) {
					if (IsKeyDown(KEY_D)) player2.position.x -= 7;
					if (IsKeyDown(KEY_A))  player2.position.x += 7;
					if (IsKeyDown(KEY_S))  player2.position.y -= 7;
					if (IsKeyDown(KEY_W))    player2.position.y += 7;
					PlaySound(collisionSound);
				}
			}

			// Checking For Player Collisions -- Change it to Game Collision for Game Over etc!
			if (CheckCollisionRecs(player1.getRect(), player2.getRect())) {
				// Say something!
				while (true) {
					UpdateMusicStream(emojiwin);
					BeginDrawing();
					DrawText("N*gga Has Been Caught!!...Player 1 Won!", 120, 100, 30, DARKBLUE);
					DrawText("Press R to return to Menu!", 120, 200, 30, BLUE);
					DrawTextureEx(txt1, { 300 , 340 }, 0.0f, 6.0f, WHITE);
					
					//player Reset Positions
					player1.Reset();
					player2.Reset();

					ClearBackground(BLACK);
					running = false;
					EndDrawing();
					if (IsKeyDown(KEY_R)) {
						break;
					}
				}	
				}
			
				// The Timer Logic! --- Win Condition for player 2!
			if (timer <= 0) {
				while (true)
				{
					UpdateMusicStream(niggaWin);
					BeginDrawing();
					ClearBackground(BLUE);
					DrawText("The N*gga Escaped!!!!.. Player 2 Won!!", 80, 200, 30, BLACK);
					DrawText("Press R to retuun to Menu!", 80, 100, 30,RED );
					DrawTextureEx(txt2, { 300 , 340 }, 0.0f, 6.0f, WHITE);

					player1.Reset();
					player2.Reset();
					running = false;
					EndDrawing();

					if (IsKeyPressed(KEY_R)) {
						break;
					}
				}


				}

			EndDrawing();
			}

			

		}
		CloseWindow();
		UnloadSound(collisionSound);
		UnloadMusicStream(bgMusic);
		UnloadMusicStream(Ingame);
		UnloadMusicStream(niggaWin);
		UnloadMusicStream(emojiwin);
	}




