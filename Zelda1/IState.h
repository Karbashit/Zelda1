#pragma once
class IState
{
public:
	IState();
	virtual ~IState();
	virtual void Enter();
	virtual void Exit();
	virtual void Update(float p_delta) = 0;
	virtual void Draw() = 0;
};

