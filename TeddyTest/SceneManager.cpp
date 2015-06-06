#include "SceneManager.h"


CSceneManager::CSceneManager()
{
}


CSceneManager::~CSceneManager()
{
}

CSceneManager &CSceneManager::GetInstance(void)
{
	static CSceneManager uniqueInstance;
	return uniqueInstance;
}

CSceneManager *CSceneManager::GetPointer(void)
{
	return &GetInstance();
}
