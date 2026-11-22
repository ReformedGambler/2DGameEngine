# 2DGameEngine
Current architecture (.cpp and .h files):
main			->	Main entry point into the game loop
|
vector2			->	Base shared functionality for inheritance of coordinates
|
entity			->	Base shared functionality for inheritance of characters
player			->	Player-specific functionality
playermovement	->	PlayerMovement input and physics (change physics next time)
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

To-do:
* Separate gravity from playermovement files
* Create a config struct for bullet-patterns

Normal updates:
No updates.

Problem updates:
1)
Problem:	Memory usage is still increasing slowly indefinitely.
Solution:	First, I commented out the attack system to determine whether it was
			responsible for the increasing memory usage. I ran the game for
			approximately 5 minutes. Memory usage stabilized at around 9.7 MB in
			Task Manager and did not continue increasing.
			Since I was using std::vector and erase() to remove bullet objects,
			and the erasing mechanism appeared to be working correctly, I suspected
			that the issue might be related to how Direct2D brushes were being managed
			and released.
			//
			A Direct2D brush is a COM (Component Object Model) object. Direct2D uses
			COM to manage resources such as brushes and render targets.
			COM objects use 2 methods:
			brush->AddRef();	This increases the object's reference count
			brush->Release();	This decreases the object's reference count
			When the reference count reaches zero, the COM object can destroy itself
			and release its resources.
			//
			WRL is Windows Runtime C++ Template Library. It provides a smart pointer
			specifically to manage COM objects.
			So instead of:
			"ID2D1SolidColorBrush* brush = nullptr;"
			I write:
			"#include <wrl/client.h>
			Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush;"
			This creates a ComPtr named brush, which automatically manages the COM
			object's reference count. For example, instead of manually calling Release()
			when the bullet object is destroyed, the bullet's ComPtr is destroyed. ComPtr
			automatically calls Release(). Then the reference count reaches 0, so the COM
			brush object is destroyed and its resources are safely released.
			//
			This follows the RAII (Resource Acquisition Is Initialization) principle in C++,
			where resource management is tied to an object's lifetime.
Outcome:	I ran it for another 5 mins and it no longer increments indefinitely.
			In conclusion, instead of manually releasing brushes when bullet objects are
			released, I use a ComPtr to automatically release the bullet when the bullet
			object is destroyed using erase. I used ChatGPT as a debugging aid to help
			investigate the memory issue. Through the process, I also learned about COM
			reference counting, ComPtr, and the RAII principle in C++, which gave me a better
			understanding of resource and memory management.