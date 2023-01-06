#pragma once

#include "DesignPatterns/SingletonTemplate.h"
#include <map>
#include <string>

#include "GameStateBase.h"

#include "CraftingState.h"
#include "../Scene2D/Player2D.h"

//class CGameState;

class CGameStateManager : public CSingletonTemplate<CGameStateManager>
{
	friend CSingletonTemplate<CGameStateManager>;
public:
	// Destroy this CGameStateManager
	void Destroy();

	// System Interface
	// Update this class instance
	bool Update(const double dElapsedTime);
	// Render this class instance
	void Render(void);

	// User Interface
	bool AddGameState(const std::string& _name, CGameStateBase* _scene);
	bool RemoveGameState(const std::string& _name);
	bool SetActiveGameState(const std::string& _name);
	bool CheckGameStateExist(const std::string& _name);


	bool SetPauseGameState(const std::string& _name);
	bool SetCraftingGameState(const std::string& _name);
	bool SetInventoryGameState(const std::string& _name);
	void OffPauseGameState(void);
	void OffCraftingGameState(void);
	void OffInventoryGameState(void);

	CGameStateBase* returnCraftingState();
	CGameStateBase* returnInventoryState();


protected:
	// Constructor
	CGameStateManager();
	// Destructor
	~CGameStateManager();

	CCraftingState* cCraftingState;
	CPlayer2D* cPlayer2D;



	// The map of CGameStates
	std::map<std::string, CGameStateBase*> GameStateMap;
	// The handlers containing the active and next CGameState
	CGameStateBase* activeGameState, *nextGameState, *prevGameState, *pauseGameState, *craftingGameState, *inventoryGameState;
};
