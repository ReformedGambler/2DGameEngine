# 2DGameEngine
Current architecture:
main		->	Main entry point into the game loop
vector2		->	Base shared functionality
entity		->	Base shared functionality
player		->	Player-specific functionality
enemy		->	Enemy-specific functionality (controls its own bullet behaviour)
bullet		->	Bullet-specific functionality
collision	->	Detects collision between player and objects
renderer	->	Main Rendering functions (renders debugging hitboxes)
update		->	Main Update functions (updates deltaTime)
window		->	Boilerplate for window application

Normal updates:
1) Changed enemy and its bullets debug rendering colour to red.
2) Modified bullet handling in enemy to be dynamic,
   can now make different types of bullets for each attack.

Problem updates:
1)
Problem:
	Brushes kept being created which led to a memory leak.
Solution:
	Initialize once in constructor.
2)
Problem:
	Bullets were not destroyed which led to more memory leakage.
Solution:
	Loop through each bullet in the vector then erase it, else move on.