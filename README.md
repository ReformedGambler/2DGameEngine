# 2DGameEngine
Current architecture (.cpp and .h files):
main			->	Main entry point into the game loop
vector2			->	Base shared functionality
entity			->	Base shared functionality
player			->	Player-specific functionality
enemy			->	Enemy-specific functionality (controls its own bullet behaviour)
bullet			->	Bullet-specific functionality
bulletpatterns	->	Handles bullets and 
collision		->	Detects collision between player and objects
renderer		->	Main Rendering functions (renders debugging hitboxes)
update			->	Main Update functions (updates deltaTime)
window			->	Boilerplate for window application

Normal updates:
1.1) Moved bullet pattern handling to bulletpatterns files
1.2) Built an inheritance feature from bulletpatterns to unique patterns
1.3) Added setting offset of where bullets spawn according to centre of hitbox

Problem updates:
X