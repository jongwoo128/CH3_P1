

#include "P1GameMode.h"
#include "P1Character.h"
#include "P1PlayerController.h"

AP1GameMode::AP1GameMode() {
	DefaultPawnClass = AP1Character::StaticClass();
	PlayerControllerClass = AP1PlayerController::StaticClass();
}