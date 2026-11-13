# 2DGameEngine
Current architecture:
main		->	Main entry point into the game loop
vector2		->	Base shared functionality
entity		->	Base shared functionality
player		->	Player-specific functionality
enemy		->	Enemy-specific functionality
collision	->	Detects collision between player and objects
renderer	->	Main Rendering functions (renders debugging hitboxes)
update		->	Main Update functions (updates deltaTime)
window		->	Boilerplate for window application