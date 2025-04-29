/* Author: Unhedged_

	 Comleted the game for the Codeacademy "Learn C++" course.

		 Description: A text-based adventure game inspired by Alice in Wonderland and Silent Hill.
		 The player navigates through three paths, solving riddles to unlock the truth about their past.

		 The story is a mix of the authors fantasy and ChatGPT's psychological horror elements.
		 The game features a sanity meter that affects the ending, and journal fragments that unlock the "true" ending.


		 
		 The author is not responsible for any damage to your computer or mental health.
		 
		 Enjoy the game!
		 
	Disclaimer: ChatGPT was used only to help with the story and ASCII art generation. For any queries, questions or debbuging issues the author reffered to Stackoverflow, Google and Reddit as he believes
	that with the handholding of ChatGPT, he would not have learned anything.

	The game is a work of fiction. Any resemblance to actual persons, living or dead, or actual events is purely coincidental.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {

	//Title and Genre
	
	std::cout << "Welcome to Alice's Awakening Game! \n \n" << std::endl;

	
	std::cout << "Genre: Fantasy / Psychological Mystery \n" << std::endl;

	std::cout << "Inspiration : Think Alice in Wonderland meets Silent Hill \n\n" << std::endl;

	// Introduction to the game

	std::cout << "You play as Alice, a young woman who wakes up in a strange, twisted version \n" << std::endl;
	std::cout << "of her hometown after a car accident. \n" << std::endl;
	std::cout << "You wonder what happened to your family... \n" << std::endl;
	std::cout << "The streets are warped, the sky is cracked like glass, and your memories are hazy... \n" << std::endl;
	std::cout << "A voice whispers...'Find the truth, or be lost forever'... \n\n" << std::endl;
	std::cout << "In front of you are three paths (choose a letter a-c): \n\n" << std::endl;

	//First set of player choices

	std::cout << "a: The Overgrown Library (Knowledge) // Level: Easy \n" << std::endl;
	std::cout << "b: The Shattered Playground (Innocence) // Level: Medium \n" << std::endl;
	std::cout << "c: The Clocktower (Time) // Level: Hard \n\n" << std::endl;

	char choice; // << This will be used to determine which path the player chooses.

	choice = 'n'; // << This is the default flag, used to check that the player's choice is within the range of a-c.
	
	std::cout << "Choose a path (a/b/c): \n" << std::endl;
	std::cin >> choice; // << The player can choose a path by entering a letter (a, b, or c)
	
	while (!(choice == 'a' || choice == 'b' || choice == 'c')) { //Checking that the player's choice is within the range of a-c and asks the player to choose again until they choose a valid option.

		std::cout << "Invalid choice. Please choose a path (a/b/c): \n" << std::endl;
		std::cin >> choice; // << The player can choose a path by entering a letter (a, b, or c)

	}

	// We define some of the repeated variables that will be used in the game here.

	int sanitymeter = 50; // << The sanity meter will help determine a hidden feature of the game. +50 is the normal baseline. +100 is the top score, 0 is the lowest score.
	int journalfragments = 0; // << The journal fragments will be used to unlock the true ending of the game. Used intereger to save memory.
	const int trials = 3; // Number of attempts to solve the riddle in each one of the branches. The total number will be 3 since the counter will start at 0 and go to 2. By making it a const we are saving on memory.


	// Here is the Mid-Game where all the fun takes place.



	char riddleChoice; // << This will be used to determine if the player wants to solve the riddle of each branch or not.

	std::cout << "Your sanity meter starts at " << sanitymeter << ". This will determine the ending of your story... \n" << std::endl;
	std::cout << "Aim to reach 100 to unlock your full potential. \n" << std::endl;
	std::cout << "Go too low and you may never find the truth...muahahaha \n\n" << std::endl;
	
	
	switch (choice) {

	
	
	//Branch 1: The Overgrown Library (Theme: Knowledge) - Level Easy


	case 'a': {

		std::cout << "You chose path (a), which leads to The Overgrown Library (Level: Easy). \n\n" << std::endl;
		std::cout << "A once-grand library, now overtaken by vines and silence. \n" << std::endl;
		std::cout << "Books shift positions when you are not looking. \n" << std::endl;
		std::cout << "You feel a strange pull towards a specific book. \n\n" << std::endl;
		std::cout << "The Librarian... A tall, robed man who speaks in riddles appears. He Knows your past and softly whispers... \n" << std::endl;
		std::cout << "'Your mind is scattered like the shelves around you. Piece together the truth, or let it rot in silence.' \n\n" << std::endl;

		//Points system explained.

		std::cout << "Solve it and gain +10 sanity points... \n" << std::endl;
		std::cout << "Solve it on the first run and unlock +10 journal fragments... \n" << std::endl;
		std::cout << "For every failed attempt you lose -5 sanity points... \n" << std::endl;
		std::cout << "Or accept the The Librarian's offer to 'take the pain away' -15 sanity. \n\n" << std::endl;
		
		std::cout << " Do you want to try and solve the riddle? (y/n) \n\n" << std::endl; 
		std::cin >> riddleChoice; // << The player can choose to solve the riddle or accept the Librarian's offer
		
		bool solved = false; // Flag to check if the riddle is solved
				

		while (!(riddleChoice == 'y' || riddleChoice == 'n')) { //Checking that the player's choice is within the range of y or n and asks the player to choose again until they choose a valid option.
			std::cout << "Invalid choice. Please choose again (y/n). \n" << std::endl;
			std::cin >> riddleChoice; // << The player can choose Yes (y) or No (n) to solve the riddle.
		}



		if (riddleChoice == 'y') {


			std::cout << "You have chosen to solve the riddle. You have 3 chances. \n\n" << std::endl;

			for (int i = 0; i < trials; i++) {


				std::cout << "Attempt " << (i + 1) << ": \n\n" << std::endl; // << Shows how many times it has been attempted.

				std::vector<int> riddle{ 5, 3, 1, 2, 4 }; // << This is the correct vector format for the riddle.

				std::vector<int> playerAnswer;

				int playerInput;

				// Correct order "I shouldn’t have left her behind, crying in the dark that hollow hour of that final night."

				std::cout << "Rearrange the five book titles to form the correct memory sentence. \n\n" << std::endl;

				std::cout << "1: Crying in the Dark\n" << std::endl;
				std::cout << "2: That Hollow Hour \n" << std::endl;
				std::cout << "3: Left her behind \n" << std::endl;
				std::cout << "4: Of that Final Night \n" << std::endl;
				std::cout << "5: I shouldn’t have \n\n" << std::endl;



				std::cout << "Enter numbers 1-5 in the correct order (type -1 to stop when completed): \n\n";

				

				while (true) {

					std::cin >> playerInput;


					if (playerInput == -1) {

						break;

					}
					if (playerInput >= 1 && playerInput <= 5) { // Check if the input is within the valid range

						playerAnswer.push_back(playerInput);

					}
					else {
						std::cout << "Invalid input. Please enter a number between 1 and 5." << std::endl;
						std::cin >> playerInput; // Prompt for valid input again

					}

				}
				std::cout << "You entered: \n\n";

				std::copy(playerAnswer.begin(), playerAnswer.end(), std::ostream_iterator<int>(std::cout, " ")); // << Prints the player's answer in the correct format.


				// Check that exactly 5 numbers were entered

				if (playerAnswer.size() != 5) {
					std::cout << "You must enter exactly 5 numbers to solve the riddle.\n";
					i--; // Decrement the attempt counter to allow for another try
					continue; // Retry this attempt
				}

				// Check if the player's answer matches the correct answer

				if (playerAnswer == riddle) {

					std::cout << "Congratulations! You solved the riddle. +10 sanity \n\n" << std::endl;

					sanitymeter += 10;

					solved = true; // Set the flag to true if the riddle is solved



					if (i == 0) {

						journalfragments += 10; // Increment journal fragments if solved on the first attempt


						std::cout << "You collect 10 journal fragments because you solved it on the first go. \n" << std::endl;

						std::cout << R"(
																	   _____
																	 /      \       
																	|  () () |      
																	|   /\   |      
																	 \  --  /       
																	 /|____|\       
																  .-'  ====  `-.    

																  The Librarian's eyes glint with eerie pride...
																  Whispers swirl through the library halls...
																  "You've remembered what was meant to be forgotten..."
															)" << std::endl;
						
						std::cout << "Sanity meter: " << sanitymeter << " \n" << std::endl;
						std::cout << "Journal Fragments: " << journalfragments << " \n" << std::endl;

						break; // Exit the loop if solved
					}

					else {

						std::cout << "Sanity meter: " << sanitymeter << " \n" << std::endl;
						std::cout << "Journal Fragments: " << journalfragments << " \n" << std::endl;
						break; // Exit the loop if solved
					}




				}

				else {

				std::cout << R"(

																	 .--.
																   .'    '.
																  |  () () |
																  |   __   |     The books fall silent...
																   \______/
																  /        \
																 |  X    X  |     The vines tighten around you...
																 |   ----   |     The memory is lost
																  \________/
																	 |  |
																	 |  |      [-5 SANITY]
																	/____\ )" << std::endl;
					
					sanitymeter -= 5;

					std::cout << "Sanity meter: " << sanitymeter << " \n" << std::endl;
					std::cout << "Journal Fragments: " << journalfragments << " \n" << std::endl;


				}

				if (i == 2 && !solved) {


					std::cout << "You've failed to solve the riddle after 3 attempts. The Librarian sighs and turns away... \n" << std::endl;

					std::cout << R"(

																 ╭────────────╮
																 │  GAME OVER │
																 ╰────┬──┬────╯
																	  │  │
																 ┌────┘  └────┐
																 │  x      x  │
																 │     ▄▃     │
																 │   \____/   │
																 └────────────┘
															   A porcelain mask lies cracked in the sandbox...
															   The books burn down into shadows...
															   The Librarian whispers, "Wrong memories... wrong child..."

							)" << std::endl;

					return 0; // End the script if the player fails to solve the riddle after 3 attempts
				}
			}




		}

		
		else if (riddleChoice == 'n') {

			std::cout << "You have chosen to accept the Librarian's offer. \n" << std::endl;
			std::cout << "The books burst into flames, and you feel a wave of despair wash over you. \n\n" << std::endl;
			sanitymeter -= 15;
			std::cout << "Sanity meter: " << sanitymeter << " \n" << std::endl;
			std::cout << "Journal Fragments: " << journalfragments << " \n" << std::endl;


		}

		else {

			std::cout << "Invalid choice. Please choose again (y/n). \n" << std::endl;
			std::cin >> riddleChoice; // << The player can choose Yes (y) or No (n) to solve the riddle.

		}

		break; // End of case 'a' for The Overgrown Library

	}

		
	
	//🌿 Branch 2: The Shattered Playground (Theme:Innocence) - Level Medium





	case 'b': {

		std::cout << "You chose path (b), which leads to The Shattered Playground. \n" << std::endl;

		std::cout << "A surreal, broken playground from Alice’s childhood. \n" << std::endl;
		std::cout << "twisted monkey bars, rusting swing sets, shattered mirrors on seesaws. Laughter echoes faintly, but no children are around... \n" << std::endl;
		std::cout << "As you enter the playground, you see a carousel, broken and unmoving.  \n" << std::endl;
		std::cout << "Around it are six scattered toy pieces, each representing a memory from her past. \n\n" << std::endl;
		std::cout << "A shadowy figure, the Toymaker, emerges from a sandbox, wearing a porcelain doll mask and screams...\n\n" << std::endl;
		std::cout << "SIX PIECES, SIX MOMENTS. ONLY THREE ARE TRUE '\n" << std::endl;
		std::cout << "ASSEMBLE YOUR CAROUSEL... BUT CHOOSE WHICH CHILDHOOD YOU BELIEVE IN TO... \n\n" << std::endl;
		std::cout << "The Toymaker's eyes glint with madness, and you feel a pull towards the carousel. \n" << std::endl;

		//Points system explained.

		std::cout << "Solve it and gain +20 sanity points... \n" << std::endl;
		std::cout << "Solve it on the first run and unlock +10 journal fragments... \n" << std::endl;
		std::cout << "For every failed attempt you lose -10 sanity points... \n" << std::endl;
		std::cout << "Or accept the The Toymaker's offer to 'take the pain away' -25 sanity points. \n\n" << std::endl;

		std::cout << " Do you want to try and solve the riddle? (y/n) \n" << std::endl;
		std::cin >> riddleChoice; // << The player can choose to solve the riddle or accept the Toymaker's offer

		bool solved = false; // Flag to check if the riddle is solved

		while (!(riddleChoice == 'y' || riddleChoice == 'n')) { //Checking that the player's choice is within the range of y or n and asks the player to choose again until they choose a valid option.
			std::cout << "Invalid choice. Please choose again (y/n). \n" << std::endl;
			std::cin >> riddleChoice; // << The player can choose Yes (y) or No (n) to solve the riddle.
		}

		
		
		if (riddleChoice == 'y') {


			std::cout << "You have chosen to solve the riddle. You have 2 chances. \n" << std::endl;

			for (int i = 1; i < trials; i++) {

				std::cout << "Attempt " << (i) << ": \n" << std::endl; // << Shows how many times it has been attempted.

				std::vector<int> riddle{ 1, 2, 5 }; 	// << this is the correct vector format of the riddle

				std::vector<int> playerAnswer;

				int playerInput;

				std::cout << "Select the three core memories to form the correct pattern. \n\n" << std::endl;

				std::cout << "1. A Cracked Music Box — A faint lullaby plays. You hear quiet sobbing. \n" << std::endl;
				std::cout << "2. A Stuffed Rabbit — A soft voice says, “This will protect you. \n" << std::endl;
				std::cout << "3. A Wooden Clown Doll — A distorted laugh that fades into static. \n" << std::endl;
				std::cout << "4. A Balloon on a Stick — Laughter and bright lights, but no faces. \n" << std::endl;
				std::cout << "5. A Toy Soldier — Thunder rumbles. Someone is yelling behind a door. \n" << std::endl;

				/* Correct memories are 1, 2, 5. Why are they the real ones?

				“A faint lullaby plays. You hear quiet sobbing.”
				This memory is emotionally grounded, sad, and personal. The sound of a lullaby and quiet crying evokes vulnerability, a real trauma response. It’s not dramatic or theatrical—it feels like a deeply buried moment.

				“A soft voice says, ‘This will protect you.’”

				A specific, direct quote from someone close (likely her sister or mother). The use of an emotional object (a comfort item) and protection theme indicates a sincere moment, likely tied to a protective figure in her past.

				“Thunder rumbles. Someone is yelling behind a door.”

				This evokes a visceral, domestic memory—anger, weather, being on the other side of a door, powerless. It’s not overly surreal, just painful and specific, which makes it believable as a repressed trauma.

				*/


				std::cout << "Enter numbers 1-3 in the correct order (type -1 to stop when completed): \n\n";

				while (true) {

					std::cin >> playerInput;


					if (playerInput == -1) {

						break;

					}

					if (playerInput >= 1 && playerInput <= 5) { // Check if the input is within the valid range

						playerAnswer.push_back(playerInput);
					}

					else {
						std::cout << "invalid input. Please enter a number between 1 and 5. \n" << std::endl; 
						std::cin >> playerInput; // Prompt for valid input again
					}
				}

				std::cout << "You entered:\n\n";

				std::copy(playerAnswer.begin(), playerAnswer.end(), std::ostream_iterator<int>(std::cout, " ")); // << Prints the player's answer in the correct format.


				// Check that exactly 3 numbers were entered

				if (playerAnswer.size() != 3) {
					std::cout << "You must enter exactly 3 numbers to solve the riddle.\n";
					i--; // Decrement the attempt counter to allow for another try
					continue; // Retry this attempt
				}

				// Check if the player's answer matches the correct answer


				if (playerAnswer == riddle) {

					std::cout << "Congratulations! You solved the riddle. +20 sanity \n\n" << std::endl;

					sanitymeter += 20;

					solved = true; // Set the flag to true if the riddle is solved

					
					if (i == 0) {

						journalfragments += 10; // Increment journal fragments if solved on the first attempt

						std::cout << "You collect 10 journal fragments because you solved it on the first go. \n" << std::endl;

						std::cout << R"(

											  ( )   ( )   ( )
											 .-:.-":-:.-":-:-.
										   /                o \
										  |   .------.     o   |
										  |  |      |     o    |
										  |  |      |   o     o|
										   \ '------'    o   o/
											'-.___________.-'

									  🎠 The carousel groans to life...
									  🎵 A lullaby plays in reverse...
									  🧠 Your mind stitches together the forgotten...

									)" << std::endl;
						
						std::cout << "Sanity meter: " << sanitymeter << " \n" << std::endl;
						std::cout << "Journal Fragments: " << journalfragments << " \n" << std::endl;

						break; // Exit the loop if solved
					}
					
					else {
					
						std::cout << "Sanity meter: " << sanitymeter << " \n" << std::endl;
						std::cout << "Journal Fragments: " << journalfragments << " \n" << std::endl;
						break; // Exit the loop if solved
					}

					


				}
				else {

					std::cout << R"(

							  .-- - ._
							 .'       '.
							/  o   o   \    The Toymaker tilts his head.
							|    ^	    | His smile is painted on... it never fades.
			    			|	(_)	    |
							\  '---'   /
							 '._____.'			[-10 SANITY]
							   /	 \
							  | _____ |			“Wrong pieces.Wrong past.”
								| | |
							   (_| |_) )" << std::endl;

					sanitymeter -= 10;

					std::cout << "Sanity meter: " << sanitymeter << " \n" << std::endl;
					std::cout << "Journal Fragments: " << journalfragments << " \n" << std::endl;
				
				}


				if (i == 2 && !solved) {

					std::cout << "You've failed to solve the riddle after 2 attempts. The Toymaker sighs and turns away... \n" << std::endl;

					std::cout << R"(

								 ╭────────────╮
								 │  GAME OVER │
								 ╰────┬──┬────╯
									  │  │
								 ┌────┘  └────┐
								 │  x      x  │
								 │     ▄▃     │
								 │   \____/   │
								 └────────────┘
							   A porcelain mask lies cracked in the sandbox...
							   The carousel melts into shadows...
							   The Toymaker whispers, "Wrong memories... wrong child..."

							)" << std::endl;

					return 0; // End the script if the player fails to solve the riddle after 3 attempts
				}
			}

		}


		else if (riddleChoice == 'n') {

			std::cout << "You have chosen to accept the Toymaker's offer. \n" << std::endl;
			std::cout << "The carousel bursts into flames, and you feel a wave of despair wash over you. \n\n" << std::endl;
			sanitymeter -= 25;

			std::cout << "Sanity meter: " << sanitymeter << " \n" << std::endl;
			std::cout << "Journal Fragments: " << journalfragments << " \n" << std::endl;

			break;
		}

		else {
			
			std::cout << "Invalid choice. Please choose again (y/n). \n" << std::endl;
			std::cin >> riddleChoice; // << The player can choose Yes (y) or No (n) to solve the riddle.
		}



		break; // End of case 'b' for The Shattered Playground


	}

	
	
	
	//🌿 Branch 3: The Clocktower (Theme: Time) - Level Hard


	 /*In the story’s deeper lore, the person Alice "left behind" is her younger sister. 
	 Though this is never explicitly stated at first. 
	 The player is meant to slowly piece it together through fragments, 
	 visual cues, and emotionally loaded dialogue.*/
	
	case 'c': {

		std::cout << "You chose path (c), which leads to The Clocktower (Level: Hard). \n\n" << std::endl;
		std::cout << R"(

			The gears grind slowly overhead. Everything smells of rust and dust. 
			Clocks cover every surface... all stopped at different times.
			A tall figure stands in the center of the room beneath a massive, swinging pendulum. His mask is cracked straight down the middle.

			TIMEKEEPER:

					You have been running from the moment it happened, have you not?

					[He gestures to a chair.]

					Sit. Time asks only for honesty. Can you give it that?

			The Timekeeper raises a golden pocket watch. The glass is cracked. The hands spin slowly, ticking backwards.

			He says:

				One of these hours... never came to pass.  
	    		One was a moment of betrayal.  
				One repeats itself every night.  
				One hides behind a memory you refuse to face.  
				And one... belongs to someone else entirely.

				He tilts his head, listening to something only he can hear.

			TIMEKEEPER:

				 Choose carefully...  
				 Which hour(s) should never have existed?
															)" << std::endl;

		//Points system explained.

		std::cout << "Solve it and gain +30 sanity points... \n" << std::endl;
		std::cout << "Solve it on the first run and unlock +10 journal fragments... \n" << std::endl;
		std::cout << "There are now failed attempts on this level... \n" << std::endl;
		std::cout << "Or accept the The Timekeeper's offer to 'take the pain away' -35 sanity. \n\n" << std::endl;

		std::cout << " Do you want to try and solve the riddle? (y/n) \n\n" << std::endl;
		std::cin >> riddleChoice; // << The player can choose to solve the riddle or accept the Librarian's offer

		bool solved = false; // Flag to check if the riddle is solved


		while (!(riddleChoice == 'y' || riddleChoice == 'n')) { //Checking that the player's choice is within the range of y or n and asks the player to choose again until they choose a valid option.
			std::cout << "Invalid choice. Please choose again (y/n). \n" << std::endl;
			std::cin >> riddleChoice; // << The player can choose Yes (y) or No (n) to solve the riddle.
		}



		if (riddleChoice == 'y') {


			std::cout << "You have chosen to solve the riddle. You have 1 chance. \n\n" << std::endl;

			for (int i = 2; i < trials; i++) {


				std::cout << "Attempt " << (i - 1) << ": \n\n" << std::endl; // << Shows how many times it has been attempted.

				std::vector<int> riddle{ 4 }; // << This is the correct vector format for the riddle.

				std::vector<int> playerAnswer;

				int playerInput;

				// Correct order "I shouldn’t have left her behind, crying in the dark that hollow hour of that final night."

				std::cout << "Choose which hour(s) should have never existed in your memory. \n\n" << std::endl;

				std::cout << "1. 11:11PM – A wish whispered, too late. \n" << std::endl;
				std::cout << "2. 2:22 AM – You watched the door, but never opened it. \n" << std::endl;
				std::cout << "3. 3:33 PM – The footsteps stopped... but you didn’t check. \n" << std::endl;
				std::cout << "4. 4.44 AM – You dreamed of silence. But someone was awake. \n" << std::endl;
				std::cout << "5. 5:55 PM – You opened your eyes… and it was already over. \n\n" << std::endl;

				/* Correct Answer: 4

				Why is it the right answer?

					4.44 AM

						1) 4.44 is not the right notation for time which should be 4:44.



						2)	"You dreamed of silence. But someone was awake"

							It represents false peace. Alice believed nothing was wrong. But something terrible happened — and she didn't even notice.

							It was an illusion. The “dream of silence” was a lie her mind created to shield her from what really happened.

							It’s the hour of failure through ignorance, not intention. Not because she made a bad choice — but because she didn’t even realize a choice was needed.*/

				std::cout << "Enter number(s) 1-5 in the correct order (type -1 to stop when completed): \n\n";



				while (true) {

					std::cin >> playerInput;


					if (playerInput == -1) {

						break;

					}
					if (playerInput >= 1 && playerInput <= 5) { // Check if the input is within the valid range

						playerAnswer.push_back(playerInput);

					}
					else {
						std::cout << "Invalid input. Please enter a number between 1 and 5." << std::endl;
						std::cin >> playerInput; // Prompt for valid input again

					}

				}
				std::cout << "You entered: \n\n";

				std::copy(playerAnswer.begin(), playerAnswer.end(), std::ostream_iterator<int>(std::cout, " ")); // << Prints the player's answer in the correct format.


				// Check that no more than 5 numbers were entered

				if (playerAnswer.size() > 5) {
					std::cout << "You must not enter more than 5 numbers to solve the riddle.\n";
					i--; // Decrement the attempt counter to allow for another try
					continue; // Retry this attempt
				}

				// Check if the player's answer matches the correct answer

				if (playerAnswer == riddle) {

					std::cout << "Congratulations! You solved the riddle. +30 sanity \n\n" << std::endl;

					sanitymeter += 30;

					solved = true; // Set the flag to true if the riddle is solved



					if (i == 2) {

						journalfragments += 10; // Increment journal fragments if solved on the first attempt


						std::cout << "You collect 10 journal fragments because you solved it on the first go. \n" << std::endl;

						std::cout << R"(
																	   _____
																	 /      \       
																	|  () () |      
																	|   /\   |      
																	 \  --  /       
																	 /|____|\       
																  .-'  ====  `-.    

																  The Timekeeper's eyes glint with eerie pride...
																  Whispers swirl through the Clocktower halls...
																  "You've remembered what was meant to be forgotten..."
															)" << std::endl;

						std::cout << "Sanity meter: " << sanitymeter << " \n" << std::endl;
						std::cout << "Journal Fragments: " << journalfragments << " \n" << std::endl;

						break; // Exit the loop if solved
					}

					else {

						std::cout << "Sanity meter: " << sanitymeter << " \n" << std::endl;
						std::cout << "Journal Fragments: " << journalfragments << " \n" << std::endl;
						break; // Exit the loop if solved
					}




				}

				else {

					std::cout << R"(

																 ╭────────────╮
																 │  GAME OVER │
																 ╰────┬──┬────╯
																	  │  │
																 ┌────┘  └────┐
																 │  x      x  │
																 │     ▄▃     │
																 │   \____/   │
																 └────────────┘
															   A porcelain mask lies cracked in the sandbox...
															   The clocks burn down into shadows...
															   The Timekeeper whispers, "Wrong memories... wrong child..."

						)" << std::endl;



					return 0;

				}

			}
		}

		else if (riddleChoice == 'n') {

			std::cout << "You have chosen to accept the Timekeeper's offer. \n" << std::endl;
			std::cout << "The clocks burst into flames, and you feel a wave of despair wash over you. \n\n" << std::endl;
			sanitymeter -= 35;
			std::cout << "Sanity meter: " << sanitymeter << " \n" << std::endl;
			std::cout << "Journal Fragments: " << journalfragments << " \n" << std::endl;


		}

		else {

			std::cout << "Invalid choice. Please choose again (y/n). \n" << std::endl;
			std::cin >> riddleChoice; // << The player can choose Yes (y) or No (n) to solve the riddle.

		}

		break; // End of case 'c' for The Overgrown Library
	}
		

		default:
				
			std::cout << "Invalid choice. Please choose again (a/b/c). \n" << std::endl;
			std::cin >> choice; // << The player can choose a path by entering a letter (a, b, or c)
			break;
			
}


// End of Mid-Game

// Here is the End-Game where players have the chance to redeem themselves.

	std::cout << R"(

										THE MIND PALACE

												The room bends around you.
												A mirror floats in darkness.
												From behind it, a voice speaks:

													Welcome back, Alice.
													One question remains.

													It is not about puzzles.
													It is not about memories.

														It is about Truth.

													But... how deep do you want to go?”

												Choose your final challenge:

													a) Accept what you have seen (Librarian) // Level: Easy
													b) Piece it together (Toymaker) // Level: Medium
													c) Face what you refused to know (Timekeeper) // Level: Hard

)" << std::endl;

	std::cout << "You have reached the final challenge. \n" << std::endl;

	std::cout << "Choose your final challenge (a/b/c): \n" << std::endl;

	char choicef; // << This will be used to determine which path the player chooses.

	choicef = 'n'; // << This is the default flag, used to check that the player's choice is within the range of a-c.

	std::cout << "Choose a path (a/b/c): \n" << std::endl;
	std::cin >> choicef; // << The player can choose a path by entering a letter (a, b, or c)

	while (!(choicef == 'a' || choicef == 'b' || choicef == 'c')) { //Checking that the player's choice is within the range of a-c and asks the player to choose again until they choose a valid option.
		std::cout << "Invalid choice. Please choose a path (a/b/c): \n" << std::endl;
		std::cin >> choicef; // << The player can choose a path by entering a letter (a, b, or c)
	}

	char riddleChoicef; // << This will be used to determine if the player wants to solve the riddle of each branch or not.


	std::cout << "Sanity meter: " << sanitymeter << " \n" << std::endl;
	std::cout << "Journal fragments: " << journalfragments << " \n" << std::endl;


	switch (choicef) {



		//Branch 2.1: Accept what you have seen // Level: Easy


	case 'a': {

		std::cout << "You chose path (a), which leads to the below riddle (Level: Easy). \n\n" << std::endl;
		std::cout << "I live in broken glass, I whisper in cracked skies. What am I? " << " \n" << std::endl;
		std::cout << "1) A dream. \n" << std::endl;
		std::cout << "2) A ghost. \n" << std::endl;
		std::cout << "3) A memory. \n" << std::endl;
		std::cout << "4) A lie. \n" << std::endl;
		std::cout << "5) A shadow. \n" << std::endl;

		std::cout << "The Librarian's voice echoes in your mind, a soft whisper... \n" << std::endl;

		//Points system explained.

		std::cout << "Solve it and gain +10 sanity points... \n" << std::endl;
		std::cout << "Solve it on the first run and unlock +10 journal fragments... \n" << std::endl;
		std::cout << "For every failed attempt you lose -5 sanity points... \n" << std::endl;
		std::cout << "Or accept the The Librarian's offer to 'take the pain away' -15 sanity. \n\n" << std::endl;

		std::cout << " Do you want to try and solve the riddle? (y/n) \n\n" << std::endl;
		std::cin >> riddleChoicef; // << The player can choose to solve the riddle or accept the Librarian's offer

		bool solved = false; // Flag to check if the riddle is solved


		while (!(riddleChoicef == 'y' || riddleChoicef == 'n')) { //Checking that the player's choice is within the range of y or n and asks the player to choose again until they choose a valid option.
			std::cout << "Invalid choice. Please choose again (y/n). \n" << std::endl;
			std::cin >> riddleChoicef; // << The player can choose Yes (y) or No (n) to solve the riddle.
		}



		if (riddleChoicef == 'y') {


			std::cout << "You have chosen to solve the riddle. You have 3 chances. \n\n" << std::endl;

			for (int i = 0; i < trials; i++) {


				std::cout << "Attempt " << (i + 1) << ": \n\n" << std::endl; // << Shows how many times it has been attempted.

				std::vector<int> riddle{ 3 }; // << This is the correct vector format for the riddle.

				std::vector<int> playerAnswer;

				int playerInput;

				// Correct answer "3) A memory."

				std::cout << "Choose the correct answer to the riddle. \n\n" << std::endl;

				std::cout << "Enter the right number 1-5 (type -1 to stop when completed): \n\n";



				while (true) {

					std::cin >> playerInput;


					if (playerInput == -1) {

						break;

					}
					if (playerInput >= 1 && playerInput <= 5) { // Check if the input is within the valid range

						playerAnswer.push_back(playerInput);

					}
					else {
						std::cout << "Invalid input. Please enter a number between 1 and 5." << std::endl;
						std::cin >> playerInput; // Prompt for valid input again

					}

				}
				std::cout << "You entered: \n\n";

				std::copy(playerAnswer.begin(), playerAnswer.end(), std::ostream_iterator<int>(std::cout, " ")); // << Prints the player's answer in the correct format.


				// Check that exactly 1 number was entered

				if (playerAnswer.size() != 1) {
					std::cout << "You must enter exactly 1 number to solve the riddle.\n";
					i--; // Decrement the attempt counter to allow for another try
					continue; // Retry this attempt
				}

				// Check if the player's answer matches the correct answer

				if (playerAnswer == riddle) {

					std::cout << "Congratulations! You solved the riddle. +10 sanity \n\n" << std::endl;

					sanitymeter += 10;

					solved = true; // Set the flag to true if the riddle is solved



					if (i == 0) {

						journalfragments += 10; // Increment journal fragments if solved on the first attempt


						std::cout << "You collect 10 journal fragments because you solved it on the first go. \n" << std::endl;

						std::cout << R"(
																	   _____
																	 /      \
																	|  () () |
																	|   /\   |
																	 \  --  /
																	 /|____|\
																  .-'  ====  `-.

																  The Librarian's eyes glint with eerie pride...
																  Whispers swirl through the library halls...
																  "You've remembered what was meant to be forgotten..."
															)" << std::endl;

						std::cout << "Sanity meter: " << sanitymeter << " \n" << std::endl;
						std::cout << "Journal Fragments: " << journalfragments << " \n" << std::endl;

						break; // Exit the loop if solved
					}

					else {

						std::cout << "Sanity meter: " << sanitymeter << " \n" << std::endl;
						std::cout << "Journal Fragments: " << journalfragments << " \n" << std::endl;
						break; // Exit the loop if solved
					}




				}

				else {

					std::cout << R"(

																	 .--.
																   .'    '.
																  |  () () |
																  |   __   |     The books fall silent...
																   \______/
																  /        \
																 |  X    X  |     The vines tighten around you...
																 |   ----   |     The memory is lost
																  \________/
																	 |  |
																	 |  |      [-5 SANITY]
																	/____\ )" << std::endl;

					sanitymeter -= 5;

					std::cout << "Sanity meter: " << sanitymeter << " \n" << std::endl;
					std::cout << "Journal Fragments: " << journalfragments << " \n" << std::endl;


				}

				if (i == 2 && !solved) {


					std::cout << "You've failed to solve the riddle after 3 attempts. The Librarian sighs and turns away... \n" << std::endl;

					std::cout << R"(

																 ╭────────────╮
																 │  GAME OVER │
																 ╰────┬──┬────╯
																	  │  │
																 ┌────┘  └────┐
																 │  x      x  │
																 │     ▄▃     │
																 │   \____/   │
																 └────────────┘
															   A porcelain mask lies cracked in the sandbox...
															   The books burn down into shadows...
															   The Librarian whispers, "Wrong memories... wrong child..."

							)" << std::endl;

					return 0; // End the script if the player fails to solve the riddle after 3 attempts
				}
			}




		}


		else if (riddleChoicef == 'n') {

			std::cout << "You have chosen to accept the Librarian's offer. \n" << std::endl;
			std::cout << "The memories burst into flames, and you feel a wave of despair wash over you. \n\n" << std::endl;
			sanitymeter -= 15;
			std::cout << "Sanity meter: " << sanitymeter << " \n" << std::endl;
			std::cout << "Journal Fragments: " << journalfragments << " \n" << std::endl;


		}

		else {

			std::cout << "Invalid choice. Please choose again (y/n). \n" << std::endl;
			std::cin >> riddleChoicef; // << The player can choose Yes (y) or No (n) to solve the riddle.

		}

		break; // End of case 'a'

	}



			//🌿 Branch 2.2: Piece it together // Medium Level





	case 'b': {

		std::cout << "You chose path (b), which leads to the below riddle (Level: Medium). \n\n" << std::endl;
		std::cout << "I arrive after thunder, I stay longer than the rain. I am...? " << " \n" << std::endl;
		std::cout << "1) Fear. \n" << std::endl;
		std::cout << "2) Grief. \n" << std::endl;
		std::cout << "3) Calm. \n" << std::endl;
		std::cout << "4) Shadows. \n" << std::endl;
		std::cout << "5) Silence. \n" << std::endl;

		//Points system explained.

		std::cout << "Solve it and gain +20 sanity points... \n" << std::endl;
		std::cout << "Solve it on the first run and unlock +10 journal fragments... \n" << std::endl;
		std::cout << "For every failed attempt you lose -10 sanity points... \n" << std::endl;
		std::cout << "Or accept the The Toymaker's offer to 'take the pain away' -25 sanity points. \n\n" << std::endl;

		std::cout << " Do you want to try and solve the riddle? (y/n) \n" << std::endl;
		std::cin >> riddleChoicef; // << The player can choose to solve the riddle or accept the Toymaker's offer

		bool solved = false; // Flag to check if the riddle is solved

		while (!(riddleChoicef == 'y' || riddleChoicef == 'n')) { //Checking that the player's choice is within the range of y or n and asks the player to choose again until they choose a valid option.
			std::cout << "Invalid choice. Please choose again (y/n). \n" << std::endl;
			std::cin >> riddleChoicef; // << The player can choose Yes (y) or No (n) to solve the riddle.
		}



		if (riddleChoicef == 'y') {


			std::cout << "You have chosen to solve the riddle. You have 2 chances. \n" << std::endl;

			for (int i = 1; i < trials; i++) {

				std::cout << "Attempt " << (i) << ": \n" << std::endl; // << Shows how many times it has been attempted.

				std::vector<int> riddle{ 2 }; 	// << this is the correct vector format of the riddle

				std::vector<int> playerAnswer;

				int playerInput;


				// Correct answer is 2




				std::cout << "Choose the correct answer to the riddle. \n\n" << std::endl;

				std::cout << "Enter the right number 1-5 (type -1 to stop when completed): \n\n";

				while (true) {

					std::cin >> playerInput;


					if (playerInput == -1) {

						break;

					}

					if (playerInput >= 1 && playerInput <= 5) { // Check if the input is within the valid range

						playerAnswer.push_back(playerInput);
					}

					else {
						std::cout << "invalid input. Please enter a number between 1 and 5. \n" << std::endl;
						std::cin >> playerInput; // Prompt for valid input again
					}
				}

				std::cout << "You entered:\n\n";

				std::copy(playerAnswer.begin(), playerAnswer.end(), std::ostream_iterator<int>(std::cout, " ")); // << Prints the player's answer in the correct format.


				// Check that exactly 1 number was entered

				if (playerAnswer.size() != 1) {
					std::cout << "You must enter exactly 1 number to solve the riddle.\n";
					i--; // Decrement the attempt counter to allow for another try
					continue; // Retry this attempt
				}

				// Check if the player's answer matches the correct answer


				if (playerAnswer == riddle) {

					std::cout << "Congratulations! You solved the riddle. +20 sanity \n\n" << std::endl;

					sanitymeter += 20;

					solved = true; // Set the flag to true if the riddle is solved


					if (i == 0) {

						journalfragments += 10; // Increment journal fragments if solved on the first attempt

						std::cout << "You collect 10 journal fragments because you solved it on the first go. \n" << std::endl;

						std::cout << R"(

											  ( )   ( )   ( )
											 .-:.-":-:.-":-:-.
										   /                o \
										  |   .------.     o   |
										  |  |      |     o    |
										  |  |      |   o     o|
										   \ '------'    o   o/
											'-.___________.-'

									  🎠 The carousel groans to life...
									  🎵 A lullaby plays in reverse...
									  🧠 Your mind stitches together the forgotten...

									)" << std::endl;

						std::cout << "Sanity meter: " << sanitymeter << " \n" << std::endl;
						std::cout << "Journal Fragments: " << journalfragments << " \n" << std::endl;

						break; // Exit the loop if solved
					}

					else {

						std::cout << "Sanity meter: " << sanitymeter << " \n" << std::endl;
						std::cout << "Journal Fragments: " << journalfragments << " \n" << std::endl;
						break; // Exit the loop if solved
					}




				}
				else {

					std::cout << R"(

							  .-- - ._
							 .'       '.
							/  o   o   \    The Toymaker tilts his head.
							|    ^	    | His smile is painted on... it never fades.
							|	(_)	    |
							\  '---'   /
							 '._____.'			[-10 SANITY]
							   /	 \
							  | _____ |			“Wrong pieces.Wrong past.”
								| | |
							   (_| |_) )" << std::endl;

					sanitymeter -= 10;

					std::cout << "Sanity meter: " << sanitymeter << " \n" << std::endl;
					std::cout << "Journal Fragments: " << journalfragments << " \n" << std::endl;

				}


				if (i == 2 && !solved) {

					std::cout << "You've failed to solve the riddle after 2 attempts. The Toymaker sighs and turns away... \n" << std::endl;

					std::cout << R"(

								 ╭────────────╮
								 │  GAME OVER │
								 ╰────┬──┬────╯
									  │  │
								 ┌────┘  └────┐
								 │  x      x  │
								 │     ▄▃     │
								 │   \____/   │
								 └────────────┘
							   A porcelain mask lies cracked in the sandbox...
							   The carousel melts into shadows...
							   The Toymaker whispers, "Wrong memories... wrong child..."

							)" << std::endl;

					return 0; // End the script if the player fails to solve the riddle after 3 attempts
				}
			}

		}


		else if (riddleChoicef == 'n') {

			std::cout << "You have chosen to accept the Toymaker's offer. \n" << std::endl;
			std::cout << "The carousel bursts into flames, and you feel a wave of despair wash over you. \n\n" << std::endl;
			sanitymeter -= 25;

			std::cout << "Sanity meter: " << sanitymeter << " \n" << std::endl;
			std::cout << "Journal Fragments: " << journalfragments << " \n" << std::endl;

			break;
		}

		else {

			std::cout << "Invalid choice. Please choose again (y/n). \n" << std::endl;
			std::cin >> riddleChoicef; // << The player can choose Yes (y) or No (n) to solve the riddle.
		}



		break; // End of case 'b' for The Shattered Playground


	}




			//🌿 Branch 2.3: Face what you refused to know // Hard Level

				case 'c': {

					std::cout << "You chose path (c), which leads to the below riddle (Level: Hard). \n\n" << std::endl;
					std::cout << "I was there the night she called you. I watched you turn away. \n" << std::endl;
					std::cout << "1) Fear. \n" << std::endl;
					std::cout << "2) The clock. \n" << std::endl;
					std::cout << "3) The door. \n" << std::endl;
					std::cout << "4) The storm. \n" << std::endl;
					std::cout << "5) Yourself. \n" << std::endl;

					std::cout << "The Librarian's voice echoes in your mind, a soft whisper... \n" << std::endl;

					// Points system explained.
					std::cout << "Solve it and gain +30 sanity points... \n" << std::endl;
					std::cout << "Solve it on the first run and unlock +10 journal fragments... \n" << std::endl;
					std::cout << "There are now failed attempts on this level... \n" << std::endl;
					std::cout << "Or accept the Timekeeper's offer to 'take the pain away' -35 sanity. \n\n" << std::endl;

					std::cout << "Do you want to try and solve the riddle? (y/n) \n\n" << std::endl;
					std::cin >> riddleChoicef;

					// Input validation
					while (!(riddleChoicef == 'y' || riddleChoicef == 'n')) {
						std::cout << "Invalid choice. Please choose again (y/n). \n" << std::endl;
						std::cin >> riddleChoicef;
					}

					if (riddleChoicef == 'y') {

						std::cout << "You have chosen to solve the riddle. You have 1 chance. \n\n" << std::endl;

						for (int i = 2; i < trials; i++) {

							std::cout << "Attempt " << (i - 1) << ": \n\n" << std::endl;

							std::vector<int> riddle{ 5 }; // Correct answer is 5
							std::vector<int> playerAnswer;
							int playerInput;

							std::cout << "Choose which hour(s) should have never existed in your memory. \n\n" << std::endl;
							std::cout << "Enter number(s) 1-5 in the correct order (type -1 to stop when completed): \n\n";

							while (true) {
								std::cin >> playerInput;

								if (playerInput == -1) {
									break;
								}
								if (playerInput >= 1 && playerInput <= 5) {
									playerAnswer.push_back(playerInput);
								}
								else {
									std::cout << "Invalid input. Please enter a number between 1 and 5." << std::endl;
								}
							}

							std::cout << "You entered: \n\n";
							std::copy(playerAnswer.begin(), playerAnswer.end(), std::ostream_iterator<int>(std::cout, " "));
							std::cout << "\n\n";

							// Too many numbers
							if (playerAnswer.size() > 5) {
								std::cout << "You must not enter more than 5 numbers to solve the riddle.\n";
								i--; // Let them retry
								continue;
							}

							// Correct answer
							if (playerAnswer == riddle) {

								std::cout << "Congratulations! You solved the riddle. +30 sanity \n\n" << std::endl;
								sanitymeter += 30;

								if (i == 2) {
									journalfragments += 10;
									std::cout << "You collect 10 journal fragments because you solved it on the first go. \n" << std::endl;

									std::cout << R"(
																			   _____
																			 /      \
																			|  () () |
																			|   /\   |
																			 \  --  /
																			 /|____|\
																		  .-'  ====  `-.

																		  The Timekeeper's eyes glint with eerie pride...
																		  Whispers swirl through the Clocktower halls...
																		  "You've remembered what was meant to be forgotten..."
									)" << std::endl;
								}

								std::cout << "Sanity meter: " << sanitymeter << " \n" << std::endl;
								std::cout << "Journal Fragments: " << journalfragments << " \n" << std::endl;

								break; // Solved successfully, exit loop
							}
							else {
								std::cout << R"(

																			 ╭────────────╮
																			 │  GAME OVER │
																			 ╰────┬──┬────╯
																				  │  │
																			 ┌────┘  └────┐
																			 │  x      x  │
																			 │     ▄▃     │
																			 │   \____/   │
																			 └────────────┘
																		   A porcelain mask lies cracked in the sandbox...
																		   The clocks burn down into shadows...
																		   The Timekeeper whispers, "Wrong memories... wrong child..."

								)" << std::endl;

								return 0; // Game Over
							}
						}

					}
					else if (riddleChoicef == 'n') {

						std::cout << "You have chosen to accept the Timekeeper's offer. \n" << std::endl;
						std::cout << "The clocks burst into flames, and you feel a wave of despair wash over you. \n\n" << std::endl;
						sanitymeter -= 35;
						std::cout << "Sanity meter: " << sanitymeter << " \n" << std::endl;
						std::cout << "Journal Fragments: " << journalfragments << " \n" << std::endl;
					}

					break; // End of case 'c'
				}

				default:
					std::cout << "Invalid choice. Please choose a path (a/b/c): \n" << std::endl;
					std::cin >> choicef;
					break;


		}



		if (sanitymeter <= 0) {
			std::cout << "Your sanity has reached zero. The world around you fades into darkness... \n" << std::endl;
			std::cout << "You have lost your mind, and the game is over. \n" << std::endl;
			return 0; // End the game if sanity meter is zero or below
		}


		//Here I need to finalise the rankings based on sanitymeter and journalfragments scores.

		else {

			std::cout << "You have completed the game. \n" << std::endl;
			std::cout << "Sanity meter" << sanitymeter << " \n" << std::endl;
			std::cout << "Journal fragments" << journalfragments << " \n" << std::endl;

		}



return 0; //This is where the main function ends
}






























