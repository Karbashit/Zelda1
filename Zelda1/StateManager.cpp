#include "StateManager.h"
#include "IState.h"

StateManager::StateManager()
{
	m_currentState = nullptr;
}

StateManager::~StateManager()
{
	auto it = m_states.begin();
	while (it != m_states.end())
	{
		delete it->second;
		it->second = nullptr;
		it++;
	}
	m_states.clear();
}

void StateManager::Update(float p_delta)
{
	if (m_currentState != nullptr)
		m_currentState->Update(p_delta);
}

void StateManager::Draw()
{
	if (m_currentState != nullptr)
		m_currentState->Draw();
}

void StateManager::AddState(const std::string p_name, IState * p_state)
{
	assert(m_states.find(p_name) == m_states.end());
	m_states.insert(std::pair<std::string, IState*>(p_name, p_state));
}

void StateManager::SetState(const std::string p_name)
{
	//TODO: What if we are allrdy in the state we are switching to?

	auto it = m_states.find(p_name);
	if (it != m_states.end())
	{
		if (m_currentState != nullptr)
			m_currentState->Exit();
		m_currentState = it->second;
		m_currentState->Enter();
	}
}

IState * StateManager::GetState()
{
	return m_currentState;
}
