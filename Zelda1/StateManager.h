#pragma once

#include <string>
#include "SDLSystem.h"

class IState;

class StateManager
{
public:
	StateManager();
	~StateManager();
	void Update(float p_delta);
	void Draw();
	void AddState(const std::string p_name, IState* p_state);
	void SetState(const std::string p_name);
	IState* GetState();

private:
	std::map<std::string, IState*> m_states;
	IState* m_currentState;
};

