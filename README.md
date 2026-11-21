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

* Memory usage might be slowly incrementing indefinitely

Normal updates:
1)	Separated bullet class from entity class to split responsibilities.
2)	Each bullet-pattern now initializes with its own vector of bullets.
3)	Enemy now controls its own attack sequences.
4)	For now each bullet-pattern shall overload the bulletpatterns functions.
5)	Each bullet-patterns controls erasing its own bullets.
6)	Added back straightdown and spiral attack with cleaner handling.

Problem updates:
1) 
Problem:	Bullet was not centered when spawning.
Solution:	Take centre of enemyHitboxSize.x - (bulletHitboxSize.x / 2.0f)
			to shift it half of the length of bulletHitboxSize to the left.
Outcome:	Bullet now spawns completely centered to the enemyHitbox.
2)
Problem:	Memory usage is still increasing slowly indefinitely
Solution:	...
Outcome:	...