# 2DGameEngine
Current architecture (.cpp and .h files):
main			->	Main entry point into the game loop
|
vector2			->	Base shared functionality for inheritance of coordinates
|
entity			->	Base shared functionality for inheritance of characters
player			->	Player-specific functionality
enemy			->	Enemy-specific functionality
|
bullet			->	Bullet-specific functionality
bulletpatterns	->	Provides reusable variables and methods for inheritance
straightdown	->	StraightDown bullet-pattern-specific functionality
spiral			->	Spiral bullet-pattern-specific functionality
|
physics			->	WIP
|
collision		->	WIP
|
renderer		->	Main Rendering functions (renders debugging hitboxes and sprites in the future)
update			->	Main Update functions (updates deltaTime and entities)
|
window			->	Boilerplate for window application

* Next commit should be fixing the memory leakage and separating physics into reusable functions

Normal updates:
1)	Replaced deltaTime datatype from double to float
2)	Added acceleration and deceleration to player movement

Problem updates:
1)
Problem:	Memory usage is still increasing slowly indefinitely
Solution:	...
Outcome:	...
2)
Problem:	After changing deltaTime from double to float, rendering had skipping frames effect
Solution:	I did not change anything in rendering so it had to be the way I updated deltaTime.
			QueryPerformanceCounter() returns a 64-bit integer, when I assign counter.QuadPart to
			the currentCounter and previousCounter, it loses precision because I converted the
			64-bit integer to float.
Outcome:	The game ran smoothly again.